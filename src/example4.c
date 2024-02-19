#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
int main(){
    const char *url = "http://127.0.0.1:5000/api/data";
    curl_global_init(CURL_GLOBAL_DEFAULT);
    CURL* curl_handle = curl_easy_init();
    if(curl_handle){
	struct curl_slist *headers = NULL;
	headers = curl_slist_append(headers, "Content-Type: application/json");
	curl_easy_setopt(curl_handle, CURLOPT_HTTPHEADER, headers);
	curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, "{}");
	curl_easy_setopt(curl_handle, CURLOPT_URL, url);
	CURLcode response = curl_easy_perform(curl_handle);
	if(response != CURLE_OK){
	    fprintf(stderr, "There was an error while doing the request.\nError->%s.\n", curl_easy_strerror(response));
	}
	curl_slist_free_all(headers);
    }
    curl_easy_cleanup(curl_handle);
    curl_global_cleanup();
}
