#include <cs50.h>
#include <stdio.h>

void pyramid(int height);

int main(void)

{
//prompt for pyramid height and validate input
    int height;
    do
    {
      height = get_int("Height: ");     
    }
    while (height < 1 || height > 8);

//execute pyramid
    pyramid(height);      
}

//define function "pyramid"
void pyramid(int height)

{
    for (int row = 1; row < height + 1; row++)
    {
        for (int column = 0; column < height - row; column++)
            {
                printf(" ");        
            }
            
        for (int column = 0; column < row; column++)
            {
                printf("#");        
            }
            
        printf("  ");
            
        for (int column = 0; column < row; column++)
            {
                printf("#");        
            }
    printf("\n");    
    }
}
