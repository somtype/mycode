import pymssql as ms

host = '127.0.0.1'
user = 'sa'
passwd = '102800'


if __name__ == '__main__':
    print("Hello python")
    with ms.connect(host, user, passwd, 'School') as conn:
        print(conn)
