#include <stdio.h>
#include <curl/curl.h>
int main(){
    curl_global_init(CURL_GLOBAL_DEFAULT);
    CURL *curl_handle = curl_easy_init();
    if(curl_handle){
	curl_easy_setopt(curl_handle, CURLOPT_URL, "https://example.com");
	CURLcode res = curl_easy_perform(curl_handle);
    	curl_easy_cleanup(curl_handle);
    }else{
	fprintf(stderr, "It's not possible to create the curl handle.");
    }
    curl_global_cleanup();  

    return 0;
}
