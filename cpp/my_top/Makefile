main.cgi: main.cpp libread_load.so libmy_list.so
	g++ main.cpp -L. -lread_load -lmy_list -o main.cgi
libread_load.so: read_load.h read_load.cpp
	g++ read_load.cpp -fPIC -shared -o libread_load.so
libmy_list.so: my_list.h my_list.cpp
	g++ my_list.cpp -fPIC -shared -o libmy_list.so
.PHONY: clean
clean:
	-rm main.cgi /var/www/html/cgi-bin/main.cgi
	-rm libread_load.so /usr/lib/libread_load.so	
	-rm libmy_list.so /usr/lib/libmy_list.so
.PHONY: install
install: main.cgi libread_load.so
	-cp main.cgi /var/www/html/cgi-bin
	-cp libread_load.so /usr/lib
	-cp libmy_list.so /usr/lib
