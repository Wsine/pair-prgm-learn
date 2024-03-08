import os
import re
from pprint import pprint

from bs4 import BeautifulSoup


# scan the report folder
reports = {}
for root, dirs, files in os.walk('moss_report'):
    if root == 'moss_report':
        continue
    # print(root, dirs, files)
    filename = root.split('/')[-1]
    # calculate the line of code
    with open(os.path.join('example', f'{filename}.ino'), 'r') as f:
        num_lines = len(f.readlines())
    match_files = [f for f in files if f.startswith('match')]
    if len(match_files) == 0:
        reports[filename] = (num_lines, None)
        continue
    with open(os.path.join(root, 'match0-top.html')) as f:
        html = f.read()
    soup = BeautifulSoup(html, 'html.parser')
    ths = soup.find_all('th')
    pcs = []
    for th in ths:
        result = re.search(r'\((\d+)%\)', th.text)
        if result:
            percentage = int(result.group(1)) / 100.
            pcs.append(percentage)
    reports[filename] = (num_lines, max(pcs))
pprint(reports)
print('num_files:', len(reports))
