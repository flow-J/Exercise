from urllib2 import Request, urlopen, URLError, HTTPError

old_url = 'http://rrurl.cn/b1UZup'
req = Request(old_url)
response = urlopen(req)
print 'Old url :' + old_url
print 'Real url :' + response.geturl()
