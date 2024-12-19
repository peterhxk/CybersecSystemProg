#include <stdio.h>
#include <stdlib.h>

int size;
int cap;
char * arr;

void sb_init(int capacity)
{
        arr = (char*)malloc(capacity * sizeof(char));
        cap = capacity;
        size = 0;
}

void sb_append(char const *buff, int len){
        for (int i = 0; i < len; i++){
                arr[size] = buff[i];
                size += 1;
                if (size == cap){
                        char* temp = (char*)malloc(cap * 2 * sizeof(char));
                        cap = cap *2;
                        for (int j = 0; j<size; j++){
                                temp[j] = arr[j];
                        }
                        free(arr);
                        arr = temp;
                }
        }
}

char * sb_build(){
        char* result = (char*)malloc(size+1 * sizeof(char));
        for (int i = 0; i < size; i++){
                result[i] = arr[i];
        }
        result[size] = '\0';
        return result;
}

void sb_destroy(){
        free(arr);
}         
         
int main(){
        sb_init(8);
        sb_append("abcdefghi", 9);
        char * result = sb_build();
        printf("%s\n", result);
        sb_destroy(); 
        free(result);

        sb_init(8);
        sb_append("weareok", 7);
        char * result2 = sb_build();
        printf("%s\n",result2);
        sb_destroy();
        free(result2);

}
