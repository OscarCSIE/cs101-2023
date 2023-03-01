#include <stdio.h>

int main(){
    char a[] = "10001111";
    char b[] = "10011110";
    char ans[2];
    int alen = (int)sizeof(a) / sizeof(char) - 1;
    int blen = (int)sizeof(b) / sizeof(char) - 1;
    int num = 0;
    for(int i = 0 ; i < alen ; i += 4){
        if((int)a[i] == 49){
            num += 8;
        }
        if((int)a[i + 1] == 49){
            num += 4;
        }
        if((int)a[i + 2] == 49){
            num += 2;
        }
        if((int)a[i + 3] == 49){
            num += 1;
        }
        if(num < 10){
            printf("%d", num);
        }else{
            printf("%X\n",num);
        }
        num = 0;
    }
    for(int i = 0 ; i < blen ; i += 4){
        if((int)b[i] == 49){
            num += 8;
        }
        if((int)b[i + 1] == 49){
            num += 4;
        }
        if((int)b[i + 2] == 49){
            num += 2;
        }
        if((int)b[i + 3] == 49){
            num += 1;
        }
        if(num < 10){
            printf("%d", num);
        }else{
            printf("%X\n",num);
        }
        num = 0;
    }
    printf("\n");
    return 0;
}
