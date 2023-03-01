#include<stdio.h>

int main(){
    char a[]="ABCabcABC";
    int shift = 5;
    int len = (int)sizeof(a)/sizeof(char) - 1;
    printf("%s\n", a);
    printf("%d\n", shift);
    for(int i = shift ; i < len ; i++){
        printf("%c",a[i]);
    }
    for(int i = 0 ; i < shift ; i++){
        printf("%c",a[i]);
    }
    return 0;
}
