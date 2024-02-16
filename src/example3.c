#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

int main(int argc, char** argv){
    char url[128] = "https://www.example.com";
    if(argc > 1){
	strcpy(url, argv[1]);
    } 
    return 0;
}

