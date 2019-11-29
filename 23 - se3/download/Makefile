
CURL_CFLAGS=`pkg-config --cflags libcurl`
CURL_LIBS=`pkg-config --libs libcurl`

download: download.o
	gcc -g -o download download.o ${CURL_LIBS}

download.o: download.c
	gcc -Wall -pedantic -g ${CURL_CFLAGS} -c download.c

