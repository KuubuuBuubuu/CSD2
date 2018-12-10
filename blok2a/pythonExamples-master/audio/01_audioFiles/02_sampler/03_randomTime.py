import simpleaudio as sa
import time
import random
import os, fnmatch
import sys

"""
An example project in which three wav files are played after eachother with a
break in between of a random duration.
Used durations are: 0.125, 0.25 and 0.5 seconds

------ HANDS-ON TIPS ------
- Alter the code:
  Add a noteDurations list, with the numbers 0.25, 0.5, 1.0. These values stand
  for a sixteenth, eighth and quarter note.
  Add a bpm value to the project and calculate the corresponding timeIntervals
  accordingly. Add these values to the timeIntervals list, instead of its
  current values.

- Alter the code:
  Write a function around the playback forloop, which takes two arguments:
  - a list with samples
  - a list with timeIntervals
  Use this function.
"""

audioFiles = []
listOfFiles = os.listdir('../audioFiles')
pattern = "*.wav"
for entry in listOfFiles:
    if fnmatch.fnmatch(entry, pattern):
        audioFiles.append(entry)
for file in audioFiles:
    print(file)

samples = []
while True:
    try:
        print("Please add as many samples as you'd please. Enter EXIT when done. ")
        sampleCheck = input()
        if not sampleCheck.endswith('.wav'):
            sampleCheck+=".wav"
            x = sa.WaveObject.from_wave_file('../audioFiles/'+sampleCheck)
            samples.append(x)
    except FileNotFoundError:
        break
# create a list to hold the timeIntervals 0.25, 0.5, 1.0
bpm = (60 / (int(input("What bpm bish? "))))
noteDurations = [0.25, 0.5, 1]
timeIntervals = [bpm * noteDurations[0], bpm * noteDurations[1], bpm * noteDurations[2]]
# play samples and wait in between (random duration)
def playBack(samples, timeIntervals):
    for sample in samples:
        # display the sample object
        print(sample)
        # play sample
        sample.play()
        # retrieve a random index value -> 0 till 2
        randomIndex = random.randint(0, 2)
        # dislay the selected timeInterval
        print("waiting: " + str(timeIntervals[randomIndex]) + " seconds.")
        # wait!
        time.sleep(timeIntervals[randomIndex])
playBack(samples, timeIntervals)
