import simpleaudio as sa
import time
wave_obj = sa.WaveObject.from_wave_file("pling.wav")
n = int(input("How many bleeps do you want?"))

def repetition(n):
    if n == 0:
        print("GEEF MIJ EEN VOLDOENDE")
        time.sleep(1)
        return 1
    else:
        print(n)
        play_obj = wave_obj.play()
        play_obj.wait_done()
        repetition(n-1)

repetition(n)
