import os

from dotenv import load_dotenv
import mosspy

###################################
# revised functions by chatgpt
# src: https://github.com/soachishti/moss.py/blob/master/mosspy/download_report.py
###################################
import logging
import time
from urllib.request import urlopen
from bs4 import BeautifulSoup
from collections import deque


def process_url(url, urls, processed_urls, base_url, path, on_read, max_retries=10, wait_time=5):
    logging.debug("Processing URL: " + url)

    for attempt in range(1, max_retries + 1):
        try:
            response = urlopen(url)
            html = response.read()
            break
        except ConnectionResetError as e:
            if attempt == max_retries:
                logging.error(f"Failed to download {url} after {max_retries} attempts: {e}")
                return
            logging.warning(f"Failed to download {url} (attempt {attempt}): {e}")
            time.sleep(wait_time)

    on_read(url)
    soup = BeautifulSoup(html, 'lxml')  # pyright: ignore
    file_name = os.path.basename(url)

    if not file_name or len(file_name.split(".")) == 1:
        file_name = "index.html"

    for more_url in soup.find_all(['a', 'frame']):
        if more_url.has_attr('href'):
            link = more_url.get('href')
        else:
            link = more_url.get('src')

        if link and (link.find("match") != -1):
            link_fragments = link.split('#')
            link = link_fragments[0]

            link_hash = ""
            if len(link_fragments) > 1:
                link_hash = "#" + link_fragments[1]

            basename = os.path.basename(link)

            if basename == link:
                link = base_url + basename

            if more_url.name == "a":
                more_url['href'] = basename + link_hash
            elif more_url.name == "frame":
                more_url['src'] = basename

            if link not in processed_urls:
                urls.append(link)
                processed_urls.add(link)

    with open(os.path.join(path, file_name), 'wb') as f:
        f.write(soup.encode(soup.original_encoding))  # pyright: ignore

def download_report(url, path, log_level=logging.DEBUG, on_read=lambda url: print(url)):
    logging.basicConfig(level=log_level)

    if len(url) == 0:
        raise Exception("Empty url supplied")

    if not os.path.exists(path):
        os.makedirs(path)

    base_url = url + "/"
    urls = deque([url])
    processed_urls = {url}

    logging.debug("=" * 80)
    logging.debug("Downloading Moss Report - URL: " + url)
    logging.debug("=" * 80)

    while urls:
        current_url = urls.popleft()
        process_url(current_url, urls, processed_urls, base_url, path, on_read)

    logging.debug("All URLs processed")
###################################


load_dotenv()

m = mosspy.Moss(os.getenv("MOSS_USER_ID"), language="cc")

# create a new folder called scaffold
if not os.path.exists('moss_report'):
    os.mkdir('moss_report')
# walk throught the files under the scaffold folder
for file in os.listdir('completement'):
    # clear the files in the moss object
    m.files.clear()
    # remove file subfix
    file_name = os.path.splitext(file)[0]
    if not os.path.exists('moss_report/' + file_name):
        print('handling file: ' + file)
        m.addFile('example/' + file)
        m.addFile('completement/' + file)
        url = m.send()
        # mosspy.download_report(url, 'moss_report/' + file_name)
        download_report(url, 'moss_report/' + file_name)
print('done')
