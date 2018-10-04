# -----Functionaliteiten----- #
# hij moet drie samples inladen, uit een lijst. deze zijn genaamd low mid en high;
# het moet via de console interactief zijn: de sample, maatsoort, en randomheid moet per object gekozen worden;
# De bpm moet ook random gekozen kunnen worden
# Voor regelmaat, moeten de eerste drie samples bestaan uit low high mid, elk een kwartnoot na elkaar;
# het console moet vragen of je wilt dat hij random een nieuw maatsoort elk maat kiest, of dat het een vaste waarde is;
# De random samplelengtes hebben een waarde van 0.125, 0.2, 0.25, 0.333, 0.5, of 0.75 kwartnoten;

# user input (bpm, samplekeuze, maatsoort, vraag voor vast of random maatsoort)
# bpm
# ritme genereren
# stop mogelijkheid
#
# beat afspelen
# midi exporteren
# locatie voor opslaan bepalen
# sample koppelen aan noot
#
# ritme omzetten naar midi
#
# -----stappenplan----- #

def get_bool(prompt):
    while True:
        try:
           return {"true":True,"false":False}[input(prompt).lower()]
        except KeyError:
           print("Invalid input please enter True or False!")

print(get_bool("Is Jonny Hungry?"))
