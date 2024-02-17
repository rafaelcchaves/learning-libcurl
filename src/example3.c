/*
    Code that performs a request using libcurl and save the response in Memory. Pass the url target as program parameter.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#define DEFAULT_URL "https://www.example.com"


struct Memory {
    char *response;
    size_t size;
};

static size_t write_data(void *data, size_t size, size_t nmemb, void *write_data){
    size_t realsize = size * nmemb;
    struct Memory *mem = (struct Memory *) write_data;
    char *ptr = realloc(mem->response, mem->size + realsize + 1);
    if(ptr == NULL){
	return 0;
    } 
    mem->response = ptr;
    memcpy(&(mem->response[mem->size]), data, realsize);
    mem->size += realsize;
    mem->response[mem->size] = 0;
    return realsize;
}   

int main(int argc, char** argv){
    char url[128] = DEFAULT_URL;
    if(argc > 1){
	strcpy(url, argv[1]);
    } 
    curl_global_init(CURL_GLOBAL_DEFAULT);
    CURL* curl_handle = curl_easy_init();
    if(curl_handle){
	struct Memory chunck = {0};
	curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);
	curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunck);
	curl_easy_setopt(curl_handle, CURLOPT_URL, url);
	CURLcode response = curl_easy_perform(curl_handle);
	if(response != CURLE_OK){
	    fprintf(stderr, "There was an error while doing the request.\nError->%s.\n", curl_easy_strerror(response));
	}else{
	    printf("%s\n--->Response\n", chunck.response);
	}
    } else {
	fprintf(stderr, "It wasn't possible to create the curl handle.");	    
    }
    curl_easy_cleanup(curl_handle);
    curl_global_cleanup();
    return 0;
}

