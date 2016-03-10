def getTalk(type="shout"):
    def shout(word="yes"):
        return word.capitalize()+"!"

    def whisper(word="yes"):
        return word.lower()+ "..."

    if type == "shout":
        return shout
    else:
        return whisper

talk = getTalk()

#print talk

#print talk()

#print getTalk("whisper")()

def doSomethingBefore(func):
    print func()

doSomethingBefore(talk)

