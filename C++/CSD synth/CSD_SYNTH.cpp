#include <iostream>
#include <thread>
using namespace std;

#include "math.h"
#include "olcNoiseMaker.h"
#include "pch.h"
#include "Square.h"
#include "Sine.h"
#include "Triangle.h"
#include "Saw.h"
#include "MelodyGenerator.h"

int BPMtoSixteenth(int bpm)
{
	return 0;
}

struct Envelope
{
	double AttackTime;
	double DecayTime;
	double ReleaseTime;

	double Sustain;

	double StartAmplitude;
	double TriggerOn;
	double TriggerOff;

	bool NoteOn;

	Envelope()
	{
		AttackTime = 0.10;
		DecayTime = 0.05;
		ReleaseTime = 0.2;

		Sustain = 0.8;

		StartAmplitude = 1.0;
		TriggerOn = 0.0;
		TriggerOff = 0.0;
		NoteOn = false;
	}

	void NoteOnTrigger(double dTimeOn)
	{
		TriggerOn = dTimeOn;
		NoteOn = true;
	}

	void NoteOffTrigger(double dTimeOff)
	{
		TriggerOff = dTimeOff;
		NoteOn = false;
	}

	double GetAmplitude(double dTime)
	{
		double Amplitude = 0.0;
		double lifeTime = dTime - TriggerOn;

		if (NoteOn)
		{
			if (lifeTime <= AttackTime)
			{
				Amplitude = (lifeTime / AttackTime) * StartAmplitude;
			}

			if (lifeTime > AttackTime && lifeTime <= (AttackTime + DecayTime))
			{
				Amplitude = ((lifeTime - AttackTime) / DecayTime) * (Sustain - StartAmplitude) + StartAmplitude;
			}

			if (lifeTime > (AttackTime + DecayTime))
			{
				Amplitude = Sustain;
			}
		}
		else
		{
			Amplitude = ((dTime - TriggerOff) / ReleaseTime) * (0.0 - Sustain) + Sustain;
		}

		if (Amplitude >= 1)
		{
			Amplitude = 1;
		}
		if (Amplitude <= 0.0001)
		{
			Amplitude = 0.0;
		}

		return Amplitude;
	}

};


double dTime;
static int samplerate = 48000;

Envelope envelope;
Envelope envelope2;
Sine sine(dTime);
Square square(dTime);
Saw saw(dTime);
Triangle triangle(dTime);

Oscillator* osc;

double Hertz;

void MiditoFrequency(int input)
{
	Hertz = 440.0 * pow(2.0, (input - 69) / 12);
}

double render(double dTime)
{
	return (osc->calculate(dTime) * envelope.GetAmplitude(dTime) * 0.5);
}

int main()
{
	string q1;
	cout << "Give waveform for Ocs1\n";
	cin >> q1;
	
	if (q1 == "square")
	{
		osc = &square;
	}

	else if (q1 == "sine")
	{
		osc = &sine;
	}

	else if (q1 == "triangle")
	{
		osc = &triangle;
	}

	else if (q1 == "saw")
	{
		osc = &saw;
	}

	

	vector<wstring> devices = olcNoiseMaker<short>::Enumerate();

	for (auto d : devices) wcout << "Output Devices:" << d << "\n";

	olcNoiseMaker<short> sound(devices[0], samplerate, 1, 16, 512);

	sound.SetUserFunction(render);

	double BaseFrequency = 110;
	double calculateNote = pow(2.0, 1.0 / 12.0);

	int CurrentKey = -1;
	bool running = true;
	while (running)
	{

		bool KeyPressed = false;
		for (int k = 0; k < 15; k++)
		{
			if (GetAsyncKeyState((unsigned char)("ZSXCFVGBNJMK\xbcL\xbe"[k])) & 0x8000)
			{
				if (CurrentKey != k)
				{
					double FrequencyOut = BaseFrequency * pow(calculateNote, k);
					osc->setFrequency(FrequencyOut);
					envelope.NoteOnTrigger(sound.GetTime());
					wcout << "\rNote On : " << sound.GetTime() << "s " << FrequencyOut << "Hz";
					CurrentKey = k;
				}

				KeyPressed = true;

			}

		}

		if (!KeyPressed)
		{
			if (CurrentKey != -1)
			{
				wcout << "\rNote Off: " << sound.GetTime() << "s                        ";
				envelope.NoteOffTrigger(sound.GetTime());
				CurrentKey = -1;
			}
		}


	}

	return 0;
}

