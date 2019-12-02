#include <stdio.h>
#include "_string.h"  ///this must be included

size_t strlen(const char* str);
int strcmp(const char* str1, const char* str2);
char* strcpy(char* dest, const char* src);
char* strncpy(char* dest, const char* src, size_t n);
char* strcat(char* dest, const char* src);
char* strncat(char* dest, const char* src, size_t n);
const char* strchr(const char* str, int c);
const char* strrchr(const char* str, int c);

///ststr is the hardest function.  It uses a tricky nested loop and must return an address.
///Here are some hints:
 /// Loop thru str1, looking for the first char of str2
 /// if(str1[i] == str2[0]) Then start inner loop, j=0
 /// loop while str1[i+j] is not null and str2[j] is not null
 /// inside loop, if(str1[i+j] != str2[j]) Then break out of inner loop
 /// when inner loop completes, if(str2[j] == '\0') Then return &str1[i]
 /// if outer loop completes, then return NULL
const char* strstr(const char* str1, const char* str2);
int isalnum(int c );

int main(void){}  ///Add your own unit tests here.  When uploading, you can leave it blank.

///Server unit testers will only tell you if it failed or not
///Unit test your own code and study the specifications provided in the description
size_t strlen(const char* str){
    int sum = 0;
    for (int i = 0; str[i] != 0; i++){
        sum++;
    }
    return sum;
}

int strcmp(const char* str1, const char* str2){
	while(*str1 == *str2){
		if(*str1 == '\0'){
			return 0;
		}
		str1++;
		str2++;
	}
	return(*str1-*str2);
}

char* strcpy(char* dest, const char* src){
    char* res = dest;
    if ((NULL != dest) && (NULL != src)){
        while (NULL != *src){
        *dest++ = *src++;
        }
        *dest = NULL;
    }
    return res;
}

char* strncpy(char* dest, const char* src, size_t n){
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    while (i < n) {
        dest[i++] = '\0';
    }
    return dest;
}

char* strcat(char* dest, const char* src){
    char* ret = dest;
    if((NULL != dest) && (NULL != src)){
        while(NULL != *dest){
            dest++;
        }
        while(NULL != *src){
            *dest++ = *src++;
        }
    *dest = NULL;
    }
    return ret;
}

char* strncat(char* dest, const char* src, size_t n){
    char* ret = dest;
    strncpy(dest + strlen(dest), src, n);
    return ret;
}

const char* strchr(const char* str, int c){
    for (;; str++){
        if (*str == c){
            return str;
        }
        if (!*str){
            return NULL;
        }
    }
    return NULL;
}

const char* strrchr(const char* str, int c){
    const char *found, *p;
    c = (unsigned char) c;
    if (c == '\0'){
        return strchr (str, '\0');
    }
    found = NULL;
    while ((p = strchr (str, c)) != NULL){
      found = p;
      str = p + 1;
    }
  return (char *) found;
}

const char* strstr(const char* str1, const char* str2){
    while (*str1){
        char* start = str1;
        char* end = str2;
        while (*str1 && *end && *str1 == *end){
            str1++;
            end++;
        }
        if (!*end){
            return start;
        }
        str1 = start + 1;
    }
    return NULL;
}

int isalnum(int c ){
    if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)){
        return 1;
    }
    return 0;
}
