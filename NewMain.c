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
int turnCounter = 0; // counts the number of moves that have been made

int main ()
{
    printf("Welcome to my TicTacToe Game!\n");
    printf("Player 1 is X \nPlayer 2 is O");
    drawBoard();

    while(winFound == 1 && turnCounter != 9)
    {
        markArray();
        drawBoard();
        checkForWin();
    }

    //Print out who won the game or if the game was a draw
    if (turnCounter == 9)
    {
    printf("The Game is a Draw\n\n");
    }
    else
    {
    playerNum = (playerNum == 1) ? 2 : 1;
    printf("Player %d Wins!\n\n", playerNum);
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
    unsigned char squareNumChar; //this is the user input variable for square number
    bool validNum = 1; // initialize the number to be invalid
    int i = 0; //initialize counter variable
    int squareNumInt; //used to check validity of input

    mark = (playerNum == 1) ? 'X' : 'O'; //This if else statement sets mark based on playerNum

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Ask the player to input a number as an integer
    printf("\n\nPlayer %d, enter a number: ", playerNum);
    scanf("%d", &squareNumInt);

    //Make a character variable out of the integer variable
    squareNumChar = squareNumInt + '0'; // create character variable of squareNumInt
//    printf("\nChosen number is %d\n\n", squareNumInt); // print out character variable to check

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   //This loop makes sure the user enters a valid number
    i = 0;
    while(validNum == 1)
    {
        //This statement works when all of nums has been looped through.
        //It sets i back to 0 and asks for a different value of squareNum
        if (i == 9)
        {
        printf("\nPlease enter a valid number: ");
        scanf("%d", &squareNumInt);
        squareNumChar = squareNumInt + '0';
        i = 0;
        }

        //This if statement works if the number entered is not equal any of the square numbers and increases the counter
        if(squareNumChar != nums[i])
        {
        validNum = 1;
        i++;
        }

        //This statement sets validNum equal to 0 if squarenum is equal to any value of nums and resets the counter
        if (squareNumChar == nums[i])
        {
            validNum = 0;
            i = 0;
            turnCounter++; //increase the turn counter each time a valid move is made
            system("cls"); //clear the console
        }
    }


    nums[squareNumInt-1] = mark; //changes the square chosen to the given mark

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
    printf("\n\n\n     |     |     \n");
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
        if(nums[i] == nums[i+1] && nums[i+1] == nums[i+2] && nums[i+2] == mark)
        {
            winFound = 0;
            turnCounter = 0;
        }

    }

    //Check for win in columns
    for (i = 0; i < 3; i++)
    {
        if(nums[i] == nums[i+3] && nums[i+3] == nums[i+6] && nums[i+6] == mark)
        {
            winFound = 0;
            turnCounter = 0;
        }
    }

    //Check for win in diagonal
    if(nums[0] == nums[4] && nums[4] == nums[8] && nums[8] == mark)
    {
        winFound = 0;
        turnCounter = 0;
    }
    //Check for win in anti-diagonal
    if(nums[2] == nums[4] && nums [4] == nums[6] && nums[6] == mark)
    {
        winFound = 0;
        turnCounter = 0;
    }
    //Return whether or not someone won
      return winFound;
}
