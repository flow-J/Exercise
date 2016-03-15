def decorator(arg1, arg2):

    def my_decorator(func):
        def wrappe():
            func()
            print "hha"
            print "I make decorators! %s  %s" % (arg1, arg2)
        return wrappe
    return my_decorator

@decorator("arg1", "arg2")
def func():
    print "func()"

func()

