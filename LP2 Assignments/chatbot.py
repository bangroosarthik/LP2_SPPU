import nltk
from nltk.chat.util import Chat,reflections 

pairs=[(r"Hey|Hello|HII",["Hiiiiiiiiiiiiiii","Nice to meet you","How can i assist you"]),
       (r"\b(?:How are you?)\b",["I am great","WEll"])]

chatbot=Chat(pairs,reflections)


def chat_with_bot():
    print("WELCOME TO INDIAN RAILWAYS CHATBOT APPLICATION")
    while (True):
        userIp=input("YOU: ")
        if userIp.lower()=='quit':
            print("Thankyou for your assistance")
            break
        response=chatbot.respond(userIp)
        print("BOT: ",response)
        
chat_with_bot()