def method_decorator(method_to_decorate):
    def wrapper(self, num):
        print self
        num = num + 1
        return  method_to_decorate(self, num)
    return wrapper

class sum(object):
    def __init__(self):
        self.sum = 0

    @method_decorator
    def sum_(self, num):
        print num


f = sum()
f.sum_(0)
