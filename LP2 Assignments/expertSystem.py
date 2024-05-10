#Expert System Program by sarthik bangroo 
def ask_question(question:str)->bool:
    response=input(question+" ").lower().strip()[0]
    if response=="y":
        return
    
def haveAllergies()->bool:
    return ask_question("Do you have allergies") or("Do you feel itchy?")


def haveFever()->bool:
    return (ask_question(("Do you h  ave body temperature above 100 degree celcius") and ask_question("Are you feeling cold")))


if haveAllergies():
    print("You have allergies")
    
if haveFever():
    print("You have Fever")