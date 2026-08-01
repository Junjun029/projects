#include <stdio.h>

int power(int b, int e) {
    int result = 1;
    

    for(int i = 0; i < e;i++) {
        result *= b;
    }
    

    return result;
}

int main() {
    printf("power");

    int b = 0;
    int e = 0;
    
    scanf("%d%d", &b, &e);

    printf("%d",power(b, e));

    return 0;
}
