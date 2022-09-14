#include "main.h"

/**
* Adds two integers
*/

int main() {    



    int number1, number2, sum;

    

    putchar("Enter two integers: ");

    scanf("%d %d", &number1, &number2);



    // calculating sum

    sum = number1 + number2;      

    

    putchar("%d + %d = %d", number1, number2, sum);

    return 0;

}
