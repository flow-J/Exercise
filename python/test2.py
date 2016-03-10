def my_shiny_new_decorator(a_function_to_decorate):

    def the_wrapper_around_the_original_function():

        print "Before the function runs"

        a_function_to_decorate()

        print "After the function runs"

    return the_wrapper_around_the_original_function

def a_stand_alone_function():
    print "I am a stand alone function, don't you dare modify me"

a_stand_alone_function()

a_stand_alone_function_decorated = my_shiny_new_decorator(a_stand_alone_function)

a_stand_alone_function_decorated()

@my_shiny_new_decorator
def another_stand_alone_function_decorated():
    print "Leave me alone!"


another_stand_alone_function_decorated()
