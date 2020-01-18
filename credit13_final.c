#include <cs50.h>
#include <stdio.h>

//variables declarations

long ccnumber, shorter;
int digit, i, j, k, sum1, sum2, totalsum;
int sdigit(long whichone, long number);
void cardtype(), checksum();

// main code

int main(void)

{
    ccnumber = get_long("Number: ");
    shorter = ccnumber;
    
// calculate checksum (Luhn’s Algorithm)    
    
    checksum();
    
// checks if checksum is correct and if so, prints creditor
    
    if (totalsum % 10 == 0)  
    {
        cardtype();    
    }
    
// if checksum is incorrect, prints "INVALID"

    else
    {
        printf("INVALID\n");
    }
    
}


// -------------------------- function cardtype

// function cardtype checks creditor

void cardtype()
{
    
    if 
        (
        (sdigit(13, ccnumber) == 4 && sdigit(14, ccnumber) == false) || 
        (sdigit(16, ccnumber) == 4 && sdigit(17, ccnumber) == false)
        )
    {
        printf("VISA\n");
    }

    else if
    
        (
        (sdigit(15, ccnumber) == 3 && sdigit(14, ccnumber) == 4 && sdigit(16, ccnumber) == false) ||
        (sdigit(15, ccnumber) == 3 && sdigit(14, ccnumber) == 7 && sdigit(16, ccnumber) == false)
        )
    {
        printf("AMEX\n");
    }
    
    else if
    
        ((sdigit(16, ccnumber) == 5 && sdigit(15, ccnumber) == 1 && sdigit(17, ccnumber) == false) || 
         (sdigit(16, ccnumber) == 5 && sdigit(15, ccnumber) == 2 && sdigit(17, ccnumber) == false) || 
         (sdigit(16, ccnumber) == 5 && sdigit(15, ccnumber) == 3 && sdigit(17, ccnumber) == false) || 
         (sdigit(16, ccnumber) == 5 && sdigit(15, ccnumber) == 4 && sdigit(17, ccnumber) == false) || 
         (sdigit(16, ccnumber) == 5 && sdigit(15, ccnumber) == 5 && sdigit(17, ccnumber) == false))
    {
        printf("MASTERCARD\n");
    }
    
    else
    {
        printf("INVALID\n");
    }
}



// -------------------------- function checksum
//
// function checksum execute Luhn’s Algorithm

void checksum()
{
    sum1 = 0;
    sum2 = 0;
    totalsum = 0;
    
// this loop:
// 1. chooses every other digit, starting with the ccnumber’s second-to-last digit
// 2. multiply each digit by 2
// 3. adds those product's digits together returning sum "sum1"
    
    for (j = 2; j <= 16; j = j + 2)
    {
        sum1 = sum1 + sdigit(1, sdigit(j, ccnumber) * 2) + sdigit(2, sdigit(j, ccnumber) * 2);
    }
    
    
// this loop:
// 1. chooses every other digit, starting with the ccnumber’s last digit
// 2. sums up those digits
    
    for (k = 1; k <= 16; k = k + 2)
    {
        sum2 = sum2 + sdigit(k, ccnumber);
    }
    
    totalsum = sum1 + sum2;
    
}


// -------------------------- function sdigit
//
// sdigit (specific digit) function returns requested digit from number, counting from the end of the number

int sdigit(long whichone, long number)
{
    shorter = number;
    for (i = 1; i <= whichone; i++)
    {    
        //caclulates last digit in shortened ccnumber
        digit = shorter % 10;
        //shortens cc number
        shorter = (shorter - (shorter % 10)) / 10;
        //moves digit position 1 to left
    }
    return digit;
}
