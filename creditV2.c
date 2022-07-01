#include <C:\msys64\mingw64\include\cs50\cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    int placeholder = 0;

    int digits = 0;
    double CARD;
    do
    {
        //fflush(stdin);
        //while ((getchar()) != '\n');

        CARD = 0;

        printf("\nWhat is your credit card number?: ");

        scanf("%lf", &CARD);
        long long cardcopy = (long long)CARD;

        //count number of digits in the card number
        digits = digits - digits;

        do
        {
        cardcopy = cardcopy / 10;
        digits = digits + 1;
        }
        while (cardcopy != 0);
        //printf("digits: %i\n", digits);

    }
    while (placeholder != 0);

    //const long CARD = get_long("\nWhat is your credit card number?: ");
    printf("\n");

    //printf("card number is: %lf\n", CARD);

    ////applying my version of Luhn's algorythm to the card number to check the last digit for zero////


    //use number of digits as a way to iterate a loop a certain number of times that creates variables for each digit of CARD in question
    //array for first step, one index for each iteration of the first loop, starting from the second to last number
    int s = digits / 2;
    int stepone[s];

    for (int i = 0; i < s; i++)
    {
        stepone[i] = (fmod((double)CARD, (double)pow(100, i + 1))) / ((double)pow(100, i) * 10);
    }

    /**checking array
    printf("Array1 values are:\n");
    for (int i = 0; i < s; i++)
    {
        printf("%i ", stepone[i]);
    }
    printf("\n");
    */

    //sum the digits in each array number by number after multiplying by 2 (no single number time 2 is more than 2 digits so this is complex enough)
    int presum = 0;
    for (int i = 0; i < s; i++)
    {
        presum = presum + (((stepone[i] * 2) % 10) + ((stepone[i] * 2) / 10));
    }

    //printf("presum is: %i\n", presum);
    //now add this sum to the end of the same sequence but starting with the last digit instead of second to last
    //figure out the size of array and number of iterations by doing an odd or even check
    int d = digits;

    //printf("digits are: %i\n", d);
    //odd
    if (d % 2 != 0)
    {
        d = (d + 1) / 2;
    }
    //even
    else
    {
        d = d / 2;
    }
    //apply second step of the algorithym to a new array
    int steptwo[d];

    for (int i = 0; i < d; i++)
    {
        steptwo[i] = (fmod((double)CARD, ((double)pow(100, i + 1)) / 10)) / (((double)pow(100, i + 1)) / 100);
        //steptwo[(int)i] = (int)(fmod((double)CARD, (double)pow(100, i + 1))) / ((double)pow(100, i) * 10);
    }


    /**checking array
        *printf("Array2 values are:\n");
        *for (int i = 0; i < d; i++)
        *{
        *    printf("%i ", steptwo[i]);
        *}
        *printf("\n");
    */


    //now sum the first presum to the postsum for final number without multiplying the indicies
    int postsum = 0;
    for (int i = 0; i < d; i++)
    {
        postsum = postsum + (steptwo[i] % 10) + (steptwo[i] / 10);
    }
    int finalsum = postsum + presum;

    //printf("post sum is: %i\n", postsum);
    //printf("final sum is: %i\n", finalsum);

    //set variables for verification numbers and print to check them
    int checklast = finalsum % 10;
    //printf("last number: %i\n", checklast);
    int firsttwo = (int)(CARD / (double)pow(10, digits - 2));
    //printf("first two digits: %i\n", firsttwo);
    int firstnumber = (int)(CARD / (double)pow(10, digits - 1));
    //printf("first digit is: %i\n", firstnumber);

    //seperator
    printf("\n");

    //if formula works move on, if not print INVALID
    if (checklast != 0)
    {
        printf("Your card is\nINVALID\n");
    }
    //if the card number starts with 34 or 37 print American Express
    else if ((firsttwo == 34 || firsttwo == 37) && digits == 15)
    {
        printf("Your card is\nAMEX\n");
    }
    //else if the card number starts with 51, 52, 53, 54, or 55 print MasterCard
    else if (firsttwo >= 51 && firsttwo <= 55 && digits == 16)
    {
        printf("Your card is\nMASTERCARD\n");
    }
    //else if the card number starts with 4 print Visa
    else if (firstnumber == 4 && (digits == 13 || digits == 16))
    {
        printf("Your card is\nVISA\n");
    }
    else
    {
        printf("Your card is\nINVALID\n");
    }

    printf("\n\nType 1 and enter to try again, or type anything else and hit enter to exit ;)\n\n");

    fflush(stdin);
    //while ((getchar()) != '\n');
    double dummy;
    scanf("%lf", &dummy);

    //while ((getchar()) != '\n');
    //fflush(stdin);

    if (dummy == 1)
    {
        main();
    }
    else
    {
        return 0;
    }
}