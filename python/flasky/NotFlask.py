import re

route_regex = re.compile("^/hello/(.+)$")
match = route_regex.match("/hello/ains")

#print match.groups()

route_regex = re.compile(r'^/hello/(?P<username>.+)$')
match = route_regex.match("/hello/ains")

#print match.groupdict()

def build_route_pattern(route):
    route_regex = re.sub(r'(<\w+>)', r'(?P\1.+)', route)
    return re.compile("^{}$".format(route_regex))

print build_route_pattern('/hello/<username>')
