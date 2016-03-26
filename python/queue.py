import Queue

initial_page = "http://www.renminribao.com"

url_queue = Queue.Queue()
seen = set()

seen.insert(initial_page)
url_queue.put(initial_page)

while(True):
    if url_queue.size()>0:
        current_url = url_queue.get()
        store(current_url)
        for next_url in extract_urls(current_url):
            if next_url not in seen:
                seen.put(next_url)
                url_queue.put(next_url)
    else:
        break
