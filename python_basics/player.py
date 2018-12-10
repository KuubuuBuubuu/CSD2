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
while True:
    try:
        numPlaybackTimes = int(input("How many samples do you want in your pattern? "))
        break
    except ValueError:
        print("ERROR: That's not a number. Please fill in a number.")
        print()
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
    while True:
        try:
            rhythm.append(float(input("Playback number " + str(x+1) + " will be multiplied by a factor ")))
            break
        except ValueError:
            print("ERROR: Please only fill in one number. Decimals are allowed.")
            print()

# Repetitions of chosen pattern
print()
print("I created your pattern. Now I need to know how often you want this pattern to be repeated...")
time.sleep(3)
while True:
    try:
        repeat = int(input("How often do you want your pattern to be repeated? "))
        break
    except ValueError:
        print("ERROR: Multiplying is math. Math works with numbers. Please use those.")
        print()
print("Your pattern will be repeated " + str(repeat) + " times.")
time.sleep(3)
print()
# deciding BPM
while True:
    try:
        bpm = int(input("what would you like to be the BPM of your sequence? "))
        break
    except ValueError:
        print("ERROR: Time only works with in seconds, defined by numbers. Please use those.")
        print()

noteLength = 30 / bpm
print()
print("Your sequence has been created!")
time.sleep(1)
print()

# sample picker
# ------------------------------------------- File list ----------------------------------------- # 'forked' from Jochem :)
audioFiles = []
listOfFiles = os.listdir('.')
pattern = "*.wav"
for entry in listOfFiles:
    if fnmatch.fnmatch(entry, pattern):
        audioFiles.append(entry)
# ----------------------------------------- end of 'fork' --------------------------------------- #

print("Finally, there are two sample slots available. You can choose between the following samples:")
time.sleep(2)
print()
for file in audioFiles:
    print(file)
time.sleep(1)
print()
print("They will be alternating every other sample. Please choose...")
time.sleep(3)
print()
while True:
    try:
        sample1Check = input("What sample do you want on every uneven samplenumber? ")
        if not sample1Check.endswith('.wav'):
            sample1Check+=".wav"
        sample1 = sa.WaveObject.from_wave_file(sample1Check)
        break
    except FileNotFoundError:
        print("ERROR: There's no such file in the directory. please use one of the filenames from the list above.")
        print()
while True:
    try:
        sample2Check = input("What sample do you want on every even samplenumber? ")
        if not sample2Check.endswith(".wav"):
            sample2Check+=".wav"
        sample2 = sa.WaveObject.from_wave_file(sample2Check)
        break
    except FileNotFoundError:
        print("ERROR: There's no such file in the directory. please use one of the filenames from the list above.")
        print()

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
