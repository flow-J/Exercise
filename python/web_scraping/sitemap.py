import urllib
from bs4 import BeautifulSoup
import urlparse
import time
import urllib2
import sys
reload(sys)
sys.setdefaultencoding('utf8')



url = "http://www.freebuf.com/"
domain = "freebuf.com"
deep = 0
tmp = ""
sites = set()
visited = set()

def get_local_pages(url, domain):
    global deep
    global sites
    global tmp
    repeat_time = 0
    pages = set()

    while True:
        print "Ready to Open the web!"
        time.sleep(1)
        print "Opening the web", url
        web = urllib2.urlopen(url=url, timeout=3)
        print "success to Open the web"
        break

    print "Readint the web ..."
    soup = BeautifulSoup(web.read())
    print "..."
    tags = soup.findAll(name='a')
    for tag in tags:
        try:
            ret = tag['href']
        except:
            print "Maybe not the attr : href"
            continue
        o = urlparse.urlparse(ret)

        if o[0] is "" and o[1] is "":
            print "Fix Page: " + ret
            url_obj = urlparse.urlparse(web.geturl())
            ret = url_obj[0] + "://" + url_obj[1] + url_obj[2] + ret
            ret = ret[:8] + ret[8:].replace('//', '/')
            o = urlparse.urlparse(ret)

            if '../' in o[2]:
                paths = o[2].split('/')
                for i in range(len(paths)):
                    if paths[i] == '..':
                        paths[i] = ''
                        if paths[i-1]:
                            paths[i-1] = ''
                tmp_path = ''
                for path in paths:
                    if path == '':
                        continue
                    tmp_path = tmp_path + '/' + path
                ret = ret.replace(o[2], ret_path)
            print "FixedPage: " + ret

        if 'http' not in o[0]:
            print "Bad Page: " + ret.encode('ascii')
            continue

        if o[0] is "" and o[1] is not "":
            print "Bad Page: " + ret
            continue

        if domain not in o[1]:
            print "Bad Page: " + ret
            continue

        newpage = ret
        if newpage not in sites:
            print "Add New Page: " + newpage
            pages.add(newpage)

    return pages

def dfs(pages):
   if pages is set():
       return
   global url
   global domain
   global sites
   global visited
   sites = set.union(sites,pages)
   for page in pages:
       if page not in visited:
           print "Visiting",page
           visited.add(page)
           url = page
           pages = get_local_pages(url, domain)
           dfs(pages)
   
   print "sucess"
 
 
pages = get_local_pages(url, domain)
dfs(pages)
for i in sites:
print i
