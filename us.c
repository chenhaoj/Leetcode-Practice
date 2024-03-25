#include <stdio.h>
#include "add.h"

int main() {
    int num1 = 0;
    int num2 = 0;
    // cout << "--START--\n" << endl;
    printf("--START--\n");
    scanf("%d", &num1);
    scanf("%d", &num2);
    printf("received %d %d\n", num1, num2);
    printf("sum: %d\n", add(num1, num2));
    printf("--END--\n");
    return 0;
}