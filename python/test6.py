def a_decorator_passing_arbitrary_arguments(function_to_decorate):
    def a_wrapper_accepting_arbitrary_arguments(*args, **kwargs):
        print "Do I have args?:"
        print args
        print kwargs
        function_to_decorate(*args, **kwargs)
    return a_wrapper_accepting_arbitrary_arguments

@a_decorator_passing_arbitrary_arguments
def function_with_no_argument():
    print "Python is cool, no arguments here."

#function_with_no_argument()

@a_decorator_passing_arbitrary_arguments
def function_with_arguments(a,b,c):
    print a, b, c

#function_with_arguments(1,2,3)

@a_decorator_passing_arbitrary_arguments
def function_with_named_arguments(a, b, c, platypus="why not ?"):
    print "Do %s, %s, and %s like platypus? %s" %\
    (a, b, c, platypus)

#function_with_named_arguments("Bill", "Linux", "Steve", platypus="Indeed!")

class Mary(object):
    def __init__(self):
        self.age = 31

    @a_decorator_passing_arbitrary_arguments
    def sayYourAge(self, lie=-3):
        print  "I am %s, what did you think ?" % (self.age + lie)

m = Mary()
m.sayYourAge()

