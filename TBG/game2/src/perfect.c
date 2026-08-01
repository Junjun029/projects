#include <stdio.h>

int main() {
    printf("Perfect number\n");

    int N = 0;

    scanf("%d", &N);
    
    int sum = 0;

    for(int i = 1; i <= N/2; i++) {
        if(N % i == 0) {
            sum += i;
        }
    }

    if(sum == N) {
        printf("Perfecto!");
    }else {
        printf("Not a perfect number :(");
    }

    return 0;
}
