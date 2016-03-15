def my_decorator(func):
    print "I am a ordinary function"
    def wrapper():
        print "I am function returned by the decorator"
        func()
    return wrapper

def lazy_function():
    print "zzzzz"

#foo = my_decorator(lazy_function)
#foo()

@my_decorator
def foo():
    print "zzzz"

foo()

@my_decorator
def lazy_function():
    print "zzzzz"

#lazy_function()
