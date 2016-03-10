def sum(func):
    def wrapper():
        func()
        return 1 + 1
    return wrapper

@sum
def func():
    pass

print func()
