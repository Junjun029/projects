#include <stdio.h>

int main() {
    int x = 0;
    scanf("%d", &x);
    
    printf("Divisors of %d: ", x);
    for(int i = 1; i <= x; i++) {
        if(x % i == 0) {
            printf("%d ", i);
        }
    }

    printf("\nStrict divisors of %d: ", x);

    if(x == 1) {
        printf("1");
        return 1;
    }

    for(int i = 1; i <= x/2; i++) {
        if(x % i == 0) {
            printf("%d ", i);
        }
    }

    return 0;
}
