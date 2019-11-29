#include <stdio.h>
#include <curl/curl.h>
 
#include <errno.h>
#include <string.h>

size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
	FILE * fout = (FILE *)userdata;
	
	return fwrite(ptr, size, nmemb, fout);
}
 
int main(int argc, char * argv[])
{
	if (argc != 3) {
		fprintf(stderr, "use: %s URL filename\n", argv[0]);
		return -1;
	}
	
	FILE * fout = fopen(argv[2], "w+");
	if (fout == NULL) {
		fputs(strerror(errno), stderr);
		return -2;
	}

	CURL *curl;
	CURLcode res;
 
	curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
		/* example.com is redirected, so we tell libcurl to follow redirection */ 
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
 
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fout);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
 
		/* Perform the request, res will get the return code */ 
		res = curl_easy_perform(curl);
		/* Check for errors */ 
		if(res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
							curl_easy_strerror(res));
 
		/* always cleanup */ 
		curl_easy_cleanup(curl);
	}
	
	fclose(fout);
	return 0;
}