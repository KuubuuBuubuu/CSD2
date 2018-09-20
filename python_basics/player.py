# ----------imports----------
import simpleaudio as sa
import time
import os, fnmatch
import sys

# ----------init & Formal introduction----------
print("---------------Kuubuu Sequencer 2018---------------")
print()
print("Hi, welcome to this most amazing sequencer!")
time.sleep(2)
print()
print("Before I can let you create your own sequence, I've got to ask you a few questions...")
time.sleep(3)
print()
print("First, I'd like to ask you how many samples you want in your repeating pattern...")
time.sleep(3)

# ----------variables----------
# Number of samples in the pattern
numPlaybackTimes = int(input("How many samples do you want in your pattern? "))
print("You've chosen to have " + str(numPlaybackTimes) + " samples in your pattern.")
time.sleep(2)
print()

# Rhythm of the pattern
print("Next, I need to know how long each sample will take. Every note is a quarter second, ")
print("so please fill in a factor by which every quarter note will be multiplied by.")
time.sleep(5)
print()
rhythm = []
for x in range(numPlaybackTimes):
    rhythm.append(float(input("Playback number " + str(x+1) + " will be multiplied by a factor ")))

# Repetitions of chosen pattern
print("I created your pattern. Now I need to know how often you want this pattern to be repeated...")
time.sleep(3)
repeat = int(input("How often do you want your pattern to be repeated? "))
print("Your pattern will be repeated " + str(repeat) + " times.")
time.sleep(3)

# deciding BPM
bpm = int(input("what would you like to be the BPM of your sequence? "))
noteLength = 30 / bpm
print(...)
print("Your sequence has been created!")
time.sleep(1)
print()

# sample picker
# ------------------------------------------- File list ----------------------------------------- # forked from Jochem :)
audioFiles = []
listOfFiles = os.listdir('.')
pattern = "*.wav"
for entry in listOfFiles:
    if fnmatch.fnmatch(entry, pattern):
        audioFiles.append(entry)

print("Finally, there are two sample slots available. You can choose between the following samples:")
time.sleep(1)
for file in audioFiles:
    print(file)
time.sleep(1)
print("They will be alternating every other sample. Please choose the name of the sample without .wav added.")
time.sleep(2)
sample1 = sa.WaveObject.from_wave_file(input("What sample do you want on every uneven samplenumber? ")+".wav")
sample2 = sa.WaveObject.from_wave_file(input("What sample do you want on every even samplenumber? ")+".wav")


# ----------sequence----------
print("Okay, i'll play your sequence now...")
for times in range(repeat):
    for index, value in enumerate(rhythm):
        if index % 2 == 0:
            play_obj = sample1.play()
            time.sleep(noteLength * value)
        else:
            play_obj = sample2.play()
            time.sleep(noteLength * value)

print()
print("Done! Have a good day <3")
time.sleep(1)
