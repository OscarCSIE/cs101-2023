#include <stdio.h>

int main(){
    char a[] = "-99acbc";
    char b[] = "99acbc";
    char c[] = "ac-99bc";
    int alen = (int)sizeof(a) / sizeof(char) - 1;
    int blen = (int)sizeof(b) / sizeof(char) - 1;
    int clen = (int)sizeof(c) / sizeof(char) - 1;
    for(int i = 0 ; i < alen ; i++){
        if((a[i] >= 48 && a[i] <= 57) || a[i] == 45){
            printf("%c", a[i]);
        }
    }
    printf("\n");
    for(int i = 0 ; i < blen ; i++){
        if((b[i] >= 48 && b[i] <= 57) || b[i] == 45){
            printf("%c", b[i]);
        }
    }
    printf("\n");
    for(int i = 0 ; i < clen ; i++){
        if((c[i] >= 48 && c[i] <= 57) || c[i] == 45){
            printf("%c", c[i]);
        }
    }
    printf("\n");
    return 0;
}
