import urllib
import sgmllib

class handle_html(sgmllib.SGMLParser):

    #attrs is tag's value
    def unknown_starttag(self, tag, attrs):
        print '------'+tag+' start------'
        print attrs

    def unknow_entag(self, tag):
        print "------"+tag+" end---------"

web = urllib.urlopen("http://freebuf.com/")
web_handler = handle_html()

web_handler.feed(web.read())

