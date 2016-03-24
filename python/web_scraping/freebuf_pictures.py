#-*-coding:utf8-*-
import sys

reload(sys) 
sys.setdefaultencoding('utf-8')
import urllib
from bs4 import BeautifulSoup
import re
url = 'http://shop.freebuf.com/'
print "prepare&reading to read theweb"
data = urllib.urlopen(url).read()
soup = BeautifulSoup(data, "html5lib")
#<div class="col-sm-6 col-md-4col-lg-4 mall-product-list">
itemlist = soup.findAll(name='div',attrs={'class':'col-sm-6 col-md-4 col-lg-4 mall-product-list'})
print itemlist
for item in itemlist:
	print item.img['src'][-4:]
