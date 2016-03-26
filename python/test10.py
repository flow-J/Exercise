import requests

r = requests.get('http://cuiqingcai.com')
print type(r)
print r.status_code
print r.encoding

print r.cookies
