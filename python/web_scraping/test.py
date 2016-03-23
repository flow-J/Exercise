from bs4 import BeautifulSoup
import urllib
import re

web = urllib.urlopen("http://www.cnblogs.com")
soup = BeautifulSoup(web.read())
tags_a = soup.findAll(name="a", attrs={'href': re.compile("^https?://")})
for tag_a in tags_a:
    print tag_a["href"]
