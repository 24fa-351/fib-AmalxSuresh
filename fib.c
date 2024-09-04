#include <stdio.h>

int main() {
   int user_input;
   char fibonacci_method[1];
   char file_name[30];

   printf("Enter and integer > ");
   scanf("%d", &user_input);
   printf("\nEnter 'i' for iterative and 'r' for recursive > ");
   scanf("%s", fibonacci_method);
   printf("\nEnter a file name > ");
   scanf("%s", file_name);

   return 0;
}
