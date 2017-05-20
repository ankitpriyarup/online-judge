import requests
from bs4 import BeautifulSoup

BASE_URL = 'https://cdn.hackerrank.com/hackerrank/static/contests/capture-the-flag/infinite/'
seen = set()

def scrape(url):
    if url in seen:
        return

    seen.add(url)

    result = requests.get(BASE_URL + url)

    html = result.content

    soup = BeautifulSoup(html, 'html.parser')
    data = soup.find_all('font')
    links = soup.find_all('a')

    if data:
        print(data)
    for link in links:
        scrape(link.attrs['href'])

def main():
    scrape('qds.html')

main()
