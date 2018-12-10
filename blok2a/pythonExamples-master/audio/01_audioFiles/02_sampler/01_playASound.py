# simpleaudio is imported as sa -> shorter name
import simpleaudio as sa

"""
An example project in which three wav files are played after eachother.

------ HANDS-ON TIPS ------
- Answer the following question before running the code:
  Do you expect to hear the samples played simultaniously or after eachother?
  Why?

- Alter the code:
  Play the sounds simultaniously.

- Alter the code:
  Ask the user to choice which one of the three samples should be played and
  only play the chosen sample.
"""

# load 3 audioFiles
sampleHigh = sa.WaveObject.from_wave_file("../audioFiles/Pop.wav")
sampleMid = sa.WaveObject.from_wave_file("../audioFiles/Laser1.wav")
sampleLow = sa.WaveObject.from_wave_file("../audioFiles/Dog2.wav")

# play high sample
sampleHighPlay = sampleHigh.play()

# play mid sample
sampleMidPlay = sampleMid.play()

# play low sample
sampleLowPlay = sampleLow.play()
