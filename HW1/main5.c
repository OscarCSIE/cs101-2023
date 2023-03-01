#include <stdio.h>

void sort_array(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    char a[] = "-9 8 7 6 5 -4 3 -2 1";
    int m = 4;
    int len = (int)sizeof(a) / sizeof(char) - 1;
    int list[len];
    int temp;
    for(int i = 0,j = 0; i < len - 1; i += 2){
        if((int)a[i] == 32 && a[i + 1] == 45){
            i++;
        }
        if( (int)a[i] == 45){
            list[j] = -1*( ( (int)a[i + 1]) - 48);
            j++;
        }else{
            list[j]= ( ( (int)a[i + 1]) - 48);
            j++;
        }
        temp = j;
    }
    sort_array(list, temp);
    printf("%d",list[temp - m]);
    return 0;
}

