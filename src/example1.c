/*
    Code that performs a request using libcurl api. Setup the target url just passing it as first parameter of the program.
 */

#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

int main(int argc, char** argv){
    char url[128];
    if(argc > 1){
	strcpy(url, argv[1]);	
    }else{
	strcpy(url,"https://example.com");
    }
    curl_global_init(CURL_GLOBAL_DEFAULT);
    CURL *curl_handle = curl_easy_init();
    if(curl_handle){
	curl_easy_setopt(curl_handle, CURLOPT_URL, url);
	CURLcode response = curl_easy_perform(curl_handle);
	if(response != CURLE_OK){
	    fprintf(stderr, "There was an error while doing the request.\nError->%s.\n", curl_easy_strerror(response));
	}
    	curl_easy_cleanup(curl_handle);
    }else{
	fprintf(stderr, "It wasn't possible to create the curl handle.");
    }
    curl_global_cleanup();  

    return 0;
}
