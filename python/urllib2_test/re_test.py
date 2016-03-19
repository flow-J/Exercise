import re

pattern = re.compile(r'hello')

match1 = pattern.match('hello world!')
match2 = pattern.match('hello world!')
match3 = pattern.match('helllo world!')

if match1:
    print match1.group()
else:
    print 'match1 error!'

if match2:
    print match2.group()
else:
    print 'match error!'

if match3:
    print match3.group()
else:
    print 'match3 error!'
