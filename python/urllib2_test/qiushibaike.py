# coding:utf-8
import urllib
import urllib2
import re
from datetime import datetime

page = 1
url = 'http://www.qiushibaike.com/hot/page/' + str(page)
user_agent = 'Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)'
headers = {'User-Agent' : user_agent }



try:
    request = urllib2.Request(url, headers = headers)
    response = urllib2.urlopen(request)
    content = response.read().decode('utf-8')
    pattern = re.compile('<div.*?author clearfix>.*?<a.*?<img.*?>.*?</a>.*?<a.*?>.*?<h2>(.*?)</h2>.*?content>(.*?)<!--(.*?)-->.*?</div>(.*?)<div class=stats>.*?number>(.*?)</i>.*?number>(.*?)</i>',re.S)

    items = re.findall(pattern, content)
    for item in items:
        haveImg = re.search("img", item[3])
        time = int(item[2])
        time = datetime.fromtimestamp(time)
        time = str(time)
        if not haveImg:
            print item[0], item[1], time,item[4]
except urllib2.URLError, e:
    if hasattr(e, "code"):
        print e.code
    if hasattr(e, "reason"):
        print e.reason
