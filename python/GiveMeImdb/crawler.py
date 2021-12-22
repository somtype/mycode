import requests
from bs4 import BeautifulSoup

def DEBUG(content):
    print(content)

def getPicture(fileName):
    url = "https://www.imdb.com"
    searchPath = url + "/find?q=" + fileName + "&s=tt&ttype=ft&ref_=fn_ft"
    searchResult = requests.get(searchPath)
    searchResult.encoding = "UTF-8"
    searchResult = BeautifulSoup(searchResult.content, "lxml")

    findList = searchResult.find(name="table", attrs={"class": "findList"})
    findResult = findList.find(attrs={"class": "findResult odd"})
    resultUrl = findResult.find(name="a").get("href")
    resultUrl = url + resultUrl + "?ref_=fn_tt_tt_1"

    filmPage = requests.get(resultUrl)
    filmPage.encoding = "UTF-8"
    filmPage = BeautifulSoup(filmPage.content, "lxml")
    imagePath = filmPage.find(name="a", attrs={"class": "ipc-lockup-overlay ipc-focusable"}).get("href")
    imagePath = url + imagePath


    DEBUG(imagePath)
getPicture("Iron Man")