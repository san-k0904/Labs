#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char input[] = "Sankalp";
    char check[] = "kal";
    int flag = 0;
    int i = 0;
    int j = 0;
    int length_main = strlen(input);
    int length_sub = strlen(check);
    
    for (i = 0; i <= length_main - length_sub; i++) {
        for (j = 0; j < length_sub; j++) {
            if (input[i + j] != check[j])
                break;
        }
        if (j == length_sub) {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        printf("Found at index: %d\n", i);
    } else {
        printf("Not found.\n");
    }
    
    return 0;
}
