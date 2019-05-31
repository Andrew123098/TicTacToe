#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

void markArray(); //Takes in a number from the users, makes sure it is valid, and creates a new array
void drawBoard(); // Draws the board with the given array for each turn
bool checkForWin(); // checks for a win each time a new board is drawn

char nums[9] = {'1','2','3','4','5','6','7','8','9'}; //square numbers
char mark; // is equal to X or O based on player number
int playerNum = 1; // initialize the player number
bool winFound = 1; // initialize the that the win is not found


int main ()
{
    printf("Welcome to my TicTacToe Game!\n");
    printf("Player 1 is X \nPlayer 2 is O\n\n");
    drawBoard();

    while(winFound == 1)
    {
        markArray();
        drawBoard();
        checkForWin();
    }

    return 0;
}

/*************************************************************************
The function markArray;
1. Asks the user for a number.
2. Checks if the number is valid based on the current nums array.
*************************************************************************/

void markArray()
{
    char squareNum; //this is the user input variable for square number
    bool validNum = 1; // initialize the number to be invalid
    int i = 0; //initialize counter variable

    printf("\n\nPlayer %d, enter a number:", playerNum);
    scanf("%c", &squareNum);
    printf("\nChosen number is %c\n\n", squareNum);

    //This if else statement sets mark based on playerNum
    mark = (playerNum == 1) ? 'X' : 'O';

    //This loop makes sure the user enters a valid number

    /****************************************************
    Try typecasting the nums array to int for this loop
    and then immediately typecasting back to char.
    This may get rid of scanf bugs such as entering 12
    and getting back an entry of 1 and 2.
    *****************************************************/
    while(validNum == 1)
    {
        //This statement works when all of nums has been looped through.
        //It sets I back to 0 and asks for a different value of squareNum
        if (i == 9)
        {
        printf("\nPlease enter a valid number:");
        scanf("%c", &squareNum);
        i = 0;
        }

        //This if statement works if the number entered is not equal any of the square numbers and increases the counter
        if(squareNum != nums[i])
        {
        validNum = 1;
        i++;
        }

        //This statement sets validNum equal to 0 if squarenum is equal to any value of nums and resets the counter
        if (squareNum == nums[i])
        {
        validNum = 0;
        i = 0;
        }
    }

    int temp = squareNum - '0'; //typecast from char to int
    nums[temp-1] = mark; //changes the square chosen to the given mark

    //Switch the player number each turn
   playerNum = (playerNum == 1) ? 2 : 1;
}


/*******************************************************
The function drawBoard:
1. Prints out the new board using the nums array.
*******************************************************/

void drawBoard()
{
    //Print out the new board
    printf("\n     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", nums[0], nums[1], nums[2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", nums[3], nums[4], nums[5]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", nums[6], nums[7], nums[8]);
    printf("     |     |     \n\n");

}


/************************************************************
The Function checkForWin:
1. Checks the columns for a win
2. Checks the rows for a win
3. Checks the diagonal and anti-diagonal for a win
************************************************************/

bool checkForWin()
{
    int i;

    //Check for win in rows
    for (i = 0; i < 9; i+= 3)
    {
        if(nums[i] == nums[i+1] == nums[i+2] == mark)
        return winFound = 0;
    }

    //Check for win in columns
    for (i = 0; i < 3; i++)
    {
        if(nums[i]== nums[i+3] == nums[i+6] == mark)
        return winFound = 0;
    }

    //Check for win in diagonal
    if(nums[0] == nums[4] == nums[8] == mark)
    {
        return winFound = 0;
    }
    //Check for win in anti-diagonal
    if(nums[2] == nums[4] == nums[6] == mark)
    {
        return winFound = 0;
    }
    //Return whether or not someone won
    return winFound;
    printf("/n WinFound is %d\n", winFound);
}
