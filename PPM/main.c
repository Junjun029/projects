#include <stdio.h>
#include <openssl/evp.h>
#include <string.h>

const char* filename = "user_ident.txt";

void sha256_compute(const char* message, unsigned char* digest, unsigned int* digest_len) {
    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    if (ctx == NULL) {
        fprintf(stderr, "Failed to create EVP_MD_CTX\n");
        return;
    }

    if (EVP_DigestInit_ex(ctx, EVP_sha256(), NULL) != 1) {
        fprintf(stderr, "EVP_DigestInit_ex failed\n");
        EVP_MD_CTX_free(ctx);
        return;
    }

    if (EVP_DigestUpdate(ctx, message, strlen(message)) != 1) {
        fprintf(stderr, "EVP_DigestUpdate failed\n");
        EVP_MD_CTX_free(ctx);
        return;
    }

    if (EVP_DigestFinal_ex(ctx, digest, digest_len) != 1) {
        fprintf(stderr, "EVP_DigestFinal_ex failed\n");
        EVP_MD_CTX_free(ctx);
        return;
    }

    EVP_MD_CTX_free(ctx);
}

int is_file_empty(const char* file) {
    FILE *fileo = fopen(file, "r");
    if (fileo == NULL) {
        return -1;
    }

    fseek(fileo, 0, SEEK_END);

    long size = ftell(fileo);

    fclose(fileo);

    return (size == 0) ? 1 : 0;
}

void Initialize() {
    FILE *file = fopen(filename, "w");
    char input_buffer[1000];
    char* text = input_buffer;
    unsigned int hash_len = 0;
    unsigned char hash[EVP_MAX_MD_SIZE];
    fgets(text, sizeof(input_buffer), stdin);
    sha256_compute(text, hash, &hash_len);
    for(unsigned int i = 0; i < hash_len; i++) {
        fprintf(file, "%02x", hash[i]);
    }
    fprintf(file, "initialized");
}

int check_initialization(const char* filename) {
    FILE *fileo = fopen(filename, "r");

    if (fileo == NULL) {
        perror("Error opening file");
        return 0;
    }
    
    char buffer[1024];
    int found = 0;

    while (fgets(buffer, sizeof(buffer), fileo) != NULL) {
        if (strstr(buffer, "initialized") != NULL) {
            found = 1;
            printf("Welcome back boss.");
            break;
        }
    }

    if (!found) {
        printf("Please register, boss.\n");
    }

    return found;
}

int main() {
    FILE *file = fopen(filename, "r");   
    
    if (!check_initialization(filename)) {
        Initialize();
    }

    if (check_initialization(filename)) {

    }

    if (file == NULL) {
        perror("Error opening file for writing\n");
        return 1;
    }   


    return 0;
}
