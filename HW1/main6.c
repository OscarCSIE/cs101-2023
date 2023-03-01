#include <stdio.h>

int main(){
    char a[] = "81c8g8u168";
    int len = (int)sizeof(a) / sizeof(char) - 1;
    for(int i = 0 ; i < len ; i++){
        if((int)a[i]>=48 && (int)a[i]<=57){
            if((int)a[i]==49){
                printf("I ");
            }
            if((int)a[i]==50){
                printf("II ");
            }
            if((int)a[i]==51){
                printf("III ");
            }
            if((int)a[i]==52){
                printf("IV ");
            }
            if((int)a[i]==53){
                printf("V ");
            }
            if((int)a[i]==54){
                printf("VI ");
            }
            if((int)a[i]==55){
                printf("VII ");
            }
            if((int)a[i]==56){
                printf("VIII ");
            }
            if((int)a[i]==57){
                printf("IX ");
            }
        }else{
            printf("%c ",a[i]);
        }
    }
    return 0;
}

