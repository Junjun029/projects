#include <stdio.h>

int main() {
    printf("sum\n");
    int input = 0;
    int sum = 0;
    while(sum <= 100) {
        scanf("%d", &input);
        sum += input;
        printf("Sum = %d\n", sum);
    }

    printf("\nSum exceeded 100\nFinal sum = %d", sum);

    return 0;
}
