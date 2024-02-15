/*
    Code that performs some requests using the libcurl api and save their responses in files. The program will do requests to all urls passed as parameters.
*/

#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

int main(int argc, char** argv){
    char url[128];
    curl_global_init(CURL_GLOBAL_ALL);
    CURL* curl_handle = curl_easy_init();
    if(curl_handle){
	CURLcode response;
	FILE* file;
	char file_path[32];
	for(int i = 1; i < argc; i++){
	    strcpy(url, argv[i]);
	    sprintf(file_path,"./bin/%d", i);
	    file = fopen(file_path, "w+"); 
	    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
	    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, file);
	    response = curl_easy_perform(curl_handle);
	    if(response != CURLE_OK){
		fprintf(stderr, "There was an error while doing the request.\nError->%s.\n", curl_easy_strerror(response));	
	    }
	} 
    }else{
	fprintf(stderr, "It wasn't possible to create the curl handle.");  
    }
    curl_easy_cleanup(curl_handle);
    curl_global_cleanup();
    return 0;
}
