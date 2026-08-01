#include <stdio.h>

int main() {
    FILE *my_file = fopen("file.txt", "w");
    
    fprintf(my_file, "Jack Sparrow");
    
    fclose(my_file);

    return 0;
}
