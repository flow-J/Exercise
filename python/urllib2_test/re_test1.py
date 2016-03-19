import re

#m = re.match(r'(\w+) (\w+)(?p<sign>.*)', 'hello world!')

rule = (r'(\w+) (\w+)(?P<sign>.*)')

m = re.match(rule, 'hello world!')

print 'm.string:', m.string
print 'm.re:', m.re
print 'm.pos:', m.pos
print 'm.endpos:', m.endpos
