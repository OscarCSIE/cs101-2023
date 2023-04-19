#include <stdio.h>

typedef struct my_mm {
    int* ptr[10];
    int status[10];
    int idx[10];
    int n_size[10];
} my_mm_t;
int g_mem[10];
my_mm_t mms;

int* my_calloc(int n, int size) {
    int i, j, k, l;
    int cnt = 0, start = 0;
    int space_requirement = n*size;
    for (i=0; i<10; i++) {
        if (mms.status[i] == 0) {
            if (cnt == 0) {
                start = i;
            }
            cnt++;
            if (cnt == space_requirement) {
                for (j = start; j < start+space_requirement; j++)
                    mms.status[j] = 1;

                for (k = 0; k < 10; k++) {
                    if (mms.ptr[i] == NULL) {
                        mms.ptr[i] = &g_mem[start];
                        mms.idx[i] = start;
                        mms.n_size[i] = space_requirement;
                        break;
                    }
                }
                for (l = 0; l<space_requirement; l++)
                    g_mem[start+l] = 0;
                    
                print_status();

                printf("\n");
                return &g_mem[start];
            }
        } else{
            cnt = 0;
        }
    }

    print_status();
    printf(" <- Out of space\n");
    return NULL;
}

void print_status() {
    for (int i=0; i<10; i++)
        printf("%d", mms.status[i]);
}

void my_free(int *p) {
    for (int i=0; i<10; i++) {
        if (mms.ptr[i] == p) {
            //reset the struct
            mms.ptr[i] = NULL;
            for (int j=0; j<mms.n_size[i]; j++)
                mms.status[mms.idx[i]+j] = 0;
            mms.n_size[i] = 0;
            mms.idx[i] = 0;

            print_status();
            printf("\n");
            return;
        }
    }
    print_status();
    printf(" %p Invalid pointer\n", p);
}

int main() {
    int* np1 = my_calloc(1, 1);
    int* np2 = my_calloc(1, 2);
    int* np3 = my_calloc(1, 3);
    int* np4 = my_calloc(1, 4);
    my_free(np1);
    my_free(np4);
    int* np5 = my_calloc(1, 5);
    int* np6 = my_calloc(1, 1);
    return 0;
}
