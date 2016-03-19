import string, urllib2

def baidu_tieba(url, begin_page, end_page):
    for i in range(begin_page, end_page+1):
        sName = string.zfill(i, 5) + '.html'
        print 'downloading the ' + str(i) + ' page ,the name is ' + sName + '......'
        f = open(sName, 'w+')
        m = urllib2.urlopen(url + str(i)).read()
        f.write(m)
        f.close()

bdurl = str(raw_input(u'enter the tieba address \n'))
begin_page = int(raw_input(u'enter pagenumber: \n'))
end_page = int(raw_input(u'enter pagenumber of the end: \n'))

baidu_tieba(bdurl, begin_page, end_page)
