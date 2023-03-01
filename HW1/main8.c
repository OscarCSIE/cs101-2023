#include <stdio.h>

int main(){
    char a[]="Hello";
    //Hello turns into Olleh
    int len = (int)sizeof(a) / sizeof(char) - 1;
    char b[len];
    for(int i = 0 ; i < len ; i++){
        b[i] = a[len - i - 1];
    }
    if((int)b[0] >= 97 && (int)b[0] <= 122){
        b[0]-=32;
    }
    if((int)b[len - 1] >= 65 && (int)b[len - 1] <= 90){
        b[len - 1] += 32;
    }
    printf("%s",b);
}
