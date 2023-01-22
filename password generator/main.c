#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() 
{
    // character arrays for different sets of characters
    char numbers[] = "0123456789";
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char special[] = "!@#$%^&*()_+-=[]{}\\|;':\",.<>/?";

    // user input for password length
    int length;
    printf("Enter desired password length (greater than 8 characters or less than 8 characters): ");
    scanf("%d", &length);
    while(length < 8 && length >= 8) {
        printf("Password length must be either greater than 8 characters or less than 8 characters. Please enter a valid length: ");
        scanf("%d", &length);
    }

    // user input for character sets to include
    int include_numbers, include_lowercase, include_uppercase, include_special;
    printf("Include numbers in password? (1 = yes, 0 = no): ");
    scanf("%d", &include_numbers);
    printf("Include lowercase letters in password? (1 = yes, 0 = no): ");
    scanf("%d", &include_lowercase);
    printf("Include uppercase letters in password? (1 = yes, 0 = no): ");
    scanf("%d", &include_uppercase);
    printf("Include special characters in password? (1 = yes, 0 = no): ");
    scanf("%d", &include_special);

    // check that at least one character set is selected
    while(include_numbers == 0 && include_lowercase == 0 && include_uppercase == 0 && include_special == 0) {
        printf("You must include at least one character set. Please make a selection.\n");
        printf("Include numbers in password? (1 = yes, 0 = no): ");
        scanf("%d", &include_numbers);
        printf("Include lowercase letters in password? (1 = yes, 0 = no): ");
        scanf("%d", &include_lowercase);
        printf("Include uppercase letters in password? (1 = yes, 0 = no): ");
        scanf("%d", &include_uppercase);
        printf("Include special characters in password? (1 = yes, 0 = no): ");
        scanf("%d", &include_special);
    }
        // initialize random seed
    srand((unsigned int)(time(NULL)));

    // generate password
    char password[length + 1];
    for(int i = 0; i < length; i++) {
        int random_set = rand() % 4;
        if(random_set == 0 && include_numbers == 1) {
            int random_index = rand() % 10;
            password[i] = numbers[random_index];
        } else if(random_set == 1 && include_lowercase == 1) {
            int random_index = rand() % 26;
            password[i] = lowercase[random_index];
        } else if(random_set == 2 && include_uppercase == 1) {
            int random_index = rand() % 26;
            password[i] = uppercase[random_index];
        } else if(random_set == 3 && include_special == 1) {
            int random_index = rand() % 32;
            password[i] = special[random_index];
        } else {
            // if the chosen character set is not selected by the user, decrement i and try again
            i--;
        }
    }
    password[length] = '\0'; // null-terminate the password string

    // print generated password
    printf("Generated password: %s\n", password);

    return 0;
}

