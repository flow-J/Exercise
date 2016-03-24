import urllib
from bs4 import BeautifulSoup
import re
url = 'http://shop.freebuf.com/'
print "prepare&reading to read theweb"
data = urllib.urlopen(url).read()
soup = BeautifulSoup(data)

print soup

itemlist = soup.findAll(name='div', attrs={'class':'col-sm-6 col-md-4 col-lg-4 mail-product-list'})
print itemlist
for item in itemlist:
#    urllib.urlretrieve(url=item.img['src'], filename=item.img['alt']+item.img['src'][-4:])
    print item.img['src'][-4:]
