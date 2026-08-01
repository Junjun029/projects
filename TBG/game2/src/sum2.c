#include <stdio.h>

int main() {
    printf("Sum 2\n");
    
    int input = 0;
    
    int sum = 0, product = 1;
    

    while(1) {
        printf("Input: ");
        scanf("%d", &input);
        
        if(input < 0)
            break;

        sum += input;
        product *= input;
    }

    printf("sum = %d\nproduct = %d\n", sum, (sum == 0)? 0:product);


    return 0;
}
