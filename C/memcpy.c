#include <stdio.h>
#include <string.h>

int main() {
    int arr1[] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[20] = {0};
    memcpy(arr2, arr1, 40);
    for(int i = 0; i < 20; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    return 0;
}