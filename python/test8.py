def decorator_maker():
    print "I make decorators! I am executed only once: "+\
            "when you make me create a decorator."

    def my_decorator(func):
        print "I am a decorator! I am executed only when you decorate a function."

        def wrapped():
            print ("I am the wrapper around the decorated function."
                    "I am called when you call the decorated function."
                    "As the wrapper, I return the RESYL of the decorated function.")
            return func()
        print "As the decorator, I return the wrapped function."
        return wrapped

    print "As a decorator maker, I return a decorator"
    return my_decorator


@decorator_maker()
def decorated_function():
    print "I am the func()"

decorated_function()
