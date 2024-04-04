#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int checkPassword() {
    char input[256];
    const char* correctPassword = "1309";
    fgets(input, sizeof(input), stdin);
    // Remove the newline character
    input[strcspn(input, "\n")] = 0;

    // Compare the inputted password with the correct one
    if (strcmp(input, correctPassword) == 0) {
        return 1; // Password is correct
    } else {
        return 0; // Password is incorrect
    }
}
//description:
//************
/*this function called first in main() is used to fetch a password from the user of the program
(password being [1309] as shown), if the password is correct, then the function will return the value "1" specifying
that the user can access the program, else the returned value will be "0" which indicates that the user doesn't know the 
password yet or is yet to be informed by it, which means that they will receive no access to the program*/