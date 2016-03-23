# coding: utf-8
import urllib
import sgmllib
import sys
reload(sys)
sys.setdefaultencoding('utf8')

class handle_html(sgmllib.SGMLParser):
    def unknown_starttag(self, tag, attrs):
            for attr in attrs:
                if attr[0] == "href":
                    print attr[0] + ":" + attr[1].encode('utf-8')

web = urllib.urlopen("http://freebuf.com/")
web_handler = handle_html()
web_handler.feed(web.read())
