import simpleaudio as sa
import time
import random

"""
An example project in which a rhythmical sequence (one measure, 1 sample) is played.
  - Sixteenth note is the smallest used note duration.
  - One meassure, time signature: 3 / 4

Instead of using steps to iterate through a sequence, we are checking the time.
We will trigger events based on a timestamp.

------ HANDS-ON TIPS ------
- Run the code, read the code and answer the following question:
  - This script transforms a list of 'sixteenth notes timestamps' into a list of
    regular timestamps.
    In the playback loop, the time difference (currentTime minus startTime)
    is compared to the upcomming timestamp.
    Why is this a more accurate method then the methods used in the examples
    "04_randomNoteDuration.py" and "05_oneSampleSequenceSteps.py"?
    Notate your answer below this line (Dutch is allowed)!
    -----
    The other two examples play the sound file - which takes a small amount of
    time to run that code - before the next part of the code is being processed.
    In this code, the timestamp remains constant, and it checks if the file
    needs to be played. This eliminates that latency.
    -----

- Alter the code:
  Currently one sample is played. Add another sample to the script.
  When a sample needs to be played, choose one of the two samples
  randomly.
  (See the hint about the random package in script "02_timedPlayback".)

- Alter the code:
  Currently the sequence is only played once.
  Alter the code to play it multiple times.
  hint: The timestamps list is emptied using the pop() function.
  (multiple possible solutions)

"""
# --------------- init --------------- #

# load 1 audioFile and store it into a list
# note: using a list taking the next step into account: using multiple samples
samples = [sa.WaveObject.from_wave_file("pythonExamples-master/audio/01_audioFiles/audioFiles/Laser1.wav"),
sa.WaveObject.from_wave_file("pythonExamples-master/audio/01_audioFiles/audioFiles/Dog2.wav")]

# define durationsToTimestamps16th
def durationsToTimestamps16th(l1):
    l1.pop(0)
    for value in l1:
        timestamps16th.append(max(timestamps16th) + (value * 4))

# define timestampsin16th to timestampsintime
def realTimeStamps(l1, int):
    for timestamp in l1:
        timestamps.append(timestamp * ((60 / int) / 4.0))
# --------------- variables --------------- #

# set bpm
bpm = 120
while True:
    try:
        ask = input("The current BPM is " + str(bpm) + " beats per minute. would you like to change it? [Y/N] ").lower()
        if ask == "y":
            bpm = int(input("Please fill in what BPM you would like. "))
            break
        elif ask == "n":
            break
        else:
            print("That's not a yes or a no. Please use Y or N as your answer.")
            print()
    except:
        print("Error safecheck.")

# ask amount of repetitions
rep = int(input("How many times do you want your sequence to be repeated? "))
# create a list to hold the timestamps
timestamps = []
# create a list for 16th notes with a starting position
timestamps16th = [0]
# create a list with ‘note timestamps' in 16th at which we should play the sample,
print("Please fill in below, as many note durations as you'd like in your sequence.")
str_arr = input().split(' ')
noteDurations = [float(num) for num in str_arr]
# call the convertion-to-16th function
durationsToTimestamps16th(noteDurations)
# create a list to hold all timestamps after added repetitions
fullTimeStamps = []

# enlargen the timestamps16th list due to the requested amount of repetitions
for x in range(rep):
    for value in timestamps16th:
        fullTimeStamps.append(value + (1 * x) + (max(timestamps16th) * x))
# call the timestamps to real time function
realTimeStamps(fullTimeStamps, bpm)
print(fullTimeStamps)

# retrieve first timestamp
# NOTE: pop(0) returns and removes the element at index 0
timestamp = timestamps.pop(0)
# retrieve the startime: current time
startTime = time.time()
keepPlaying = True
# play the sequence
while keepPlaying:
    # retrieve current time
    currentTime = time.time()
    # check if the timestamp's time is passed
    if(currentTime - startTime >= timestamp):
        # play sample
        samples[random.randint(0,1)].play()

        # if there are timestamps left in the timestamps list
        if timestamps:
            # retrieve the next timestamp
            timestamp = timestamps.pop(0)
        else:

            # list is empty, stop loop
            keepPlaying = False
    else:
        # wait for a very short moment
            time.sleep(0.001)
