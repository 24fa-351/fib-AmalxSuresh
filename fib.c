#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void iterative_fibonacci (int input);
int recursive_fibonacci (int input);

int main(int argc, char *argv[]) {
    //get rid of compiler error for not using argc parameter
    (void)argc;

    int user_input, file_contents_number, total_number, j = 0;
    
    char fibonacci_method, file_name[50], file_contents[1000];

    FILE *open_file;

    // User input integer
    sscanf(argv[1], "%d", &user_input);

    // Iterative or recursive method
    fibonacci_method = argv[2][0];

    // File name input
    strncpy(file_name, argv[3], sizeof(file_name));

    open_file = fopen(file_name, "r");
    if (open_file == NULL) {
        return EXIT_FAILURE;
    }

    // Read the contents of the file
    fgets(file_contents, sizeof(file_contents), open_file);

    //Isolate integer as string 
    for (int i = 0; file_contents[i] != '\0'; i++) {
        if (file_contents[i] != '"') {
            file_contents[j++] = file_contents[i];

        }
    }
    file_contents[j] = '\0';

    file_contents_number = atoi(file_contents);

    total_number = user_input + file_contents_number;

    if (fibonacci_method == 'i') {
        iterative_fibonacci(total_number);
    } else {
        printf("%d", recursive_fibonacci(total_number));
    }

    fclose(open_file);
    return 0;
}

void iterative_fibonacci (int input) {
    int previous_one = 1, previous_two = 0, num = 0;

    for (int i = 0; i <= input; i++) {
       if (i > 2) {
          num = previous_one + previous_two;
          previous_two = previous_one;
          previous_one = num;
       }
    }

    printf("%d", num);
    return;
}

int recursive_fibonacci (int input) { 
    if (input == 1) {
       return 0;
    }
    else if (input == 2) {
       return 1;
    }
    else {
         return recursive_fibonacci (input-1) + recursive_fibonacci (input-2);
    }
}