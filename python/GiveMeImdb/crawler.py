import requests
from bs4 import BeautifulSoup


def DEBUG(content):
    print(content)


def get_picture(file_name):
    url = "https://www.imdb.com"
    search_path = url + "/find?q=" + file_name + "&s=tt&ttype=ft&ref_=fn_ft"
    search_result = requests.get(search_path)
    search_result.encoding = "UTF-8"
    search_result = BeautifulSoup(search_result.content, "lxml")

    find_list = search_result.find(name="table", attrs={"class": "findList"})
    find_result = find_list.find(attrs={"class": "findResult odd"})
    result_url = find_result.find(name="a").get("href")
    result_url = url + result_url + "?ref_=fn_tt_tt_1"

    film_page = requests.get(result_url)
    film_page.encoding = "UTF-8"
    film_page = BeautifulSoup(film_page.content, "lxml")
    image_path = film_page.find(name="a", attrs={"class": "ipc-lockup-overlay ipc-focusable"}).get("href")
    image_path = url + image_path

    DEBUG(image_path)


get_picture("Iron Man")
