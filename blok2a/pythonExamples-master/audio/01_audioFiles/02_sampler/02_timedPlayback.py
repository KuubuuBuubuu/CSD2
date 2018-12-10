import simpleaudio as sa
import time
from random import choice

"""
An example project in which three wav files are played after eachother with a
minor break in between.

------ HANDS-ON TIPS ------
- Alter the code:
  Write a function that plays the samples a given number of times.
  Use this function.

- Alter the code:
  Change the time in between samples into a random value.
  E.g. wait 0.25, 0.5, or 1 second.
  hint:  there is a standard random package available with a random function
         https://docs.python.org/2/library/random.html
         A standard package does not need to be installed with pip, but it does
         need to be imported.
"""

# load 3 audioFiles into a list
samples = [ sa.WaveObject.from_wave_file("../audioFiles/Pop.wav"),
            sa.WaveObject.from_wave_file("../audioFiles/Laser1.wav"),
            sa.WaveObject.from_wave_file("../audioFiles/Dog2.wav")]
rep = input("How many bitch? ")

# play samples, wait 1 second in between

for x in rep:
    for sample in samples:
        print(sample)
        sample.play()
        time.sleep(choice([0.25, 0.5, 1.0]))
