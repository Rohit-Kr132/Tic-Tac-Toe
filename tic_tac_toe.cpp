#include <iostream>
#include <ctime>
#include <stdlib.h>
// created 02-05-2022
// issue- no mechanism for draw
// tried fixing draw mechanism on 30-05-2022
// current issue- nothing prints if game draw, program exits after a while
// issue fixed 03-06-2022
using namespace std;

char gameBoard[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

void showBoard()
{
    cout << gameBoard[0] << " | " << gameBoard[1] << " | " << gameBoard[2] << endl;
    cout << "--|---|--" << endl;
    cout << gameBoard[3] << " | " << gameBoard[4] << " | " << gameBoard[5] << endl;
    cout << "--|---|--" << endl;
    cout << gameBoard[6] << " | " << gameBoard[7] << " | " << gameBoard[8] << endl;
}

void userMove()
{
    int n;
    cout << "Your Turn!" << endl;
    cout << "Enter Your Move Location: ";
    cin >> n;
    if (n >= 0 && n <= 8)
    {
        if (gameBoard[n] == ' ')
        {
            gameBoard[n] = 'X';
            showBoard();
        }

        else
        {
            cout << "Location Occupied!" << endl;
            cout << "Enter Another Location" << endl;
            showBoard();
            userMove();
        }
    }

    else
    {
        cout << "Invalid Location!" << endl;
        cout << "Enter Valid Location" << endl;
        showBoard();
        userMove();
    }
}

void computerMove()
{
    int n = rand() % 9;
    if (gameBoard[n] == ' ')
    {
        cout << "Computer's Move" << endl;
        gameBoard[n] = 'O';
        showBoard();
    }

    else
    {
        computerMove();
    }
}

int drawCheck();
int gameCheck()
{

    if (gameBoard[0] == gameBoard[1] && gameBoard[1] == gameBoard[2] && gameBoard[1] != ' ')
    {
        if (gameBoard[0] == 'X')
        {
            return 1;
        }

        else if (gameBoard[0] == 'O')
        {
            return 2;
        }
    }

    else if (gameBoard[3] == gameBoard[4] && gameBoard[4] == gameBoard[5] && gameBoard[3] != ' ')
    {
        if (gameBoard[3] == 'X')
        {
            return 1;
        }

        else if (gameBoard[3] == 'O')
        {
            return 2;
        }
    }

    else if (gameBoard[6] == gameBoard[7] && gameBoard[7] == gameBoard[8] && gameBoard[6] != ' ')
    {
        if (gameBoard[6] == 'X')
        {
            return 1;
        }

        else if (gameBoard[6] == 'O')
        {
            return 2;
        }
    }

    else if (gameBoard[0] == gameBoard[3] && gameBoard[3] == gameBoard[6] && gameBoard[0] != ' ')
    {
        if (gameBoard[0] == 'X')
        {
            return 1;
        }

        else if (gameBoard[0] == 'O')
        {
            return 2;
        }
    }

    else if (gameBoard[1] == gameBoard[4] && gameBoard[4] == gameBoard[7] && gameBoard[1] != ' ')
    {
        if (gameBoard[1] == 'X')
        {
            return 1;
        }

        else if (gameBoard[1] == 'O')
        {
            return 2;
        }
    }

    else if (gameBoard[2] == gameBoard[5] && gameBoard[5] == gameBoard[8] && gameBoard[2] != ' ')
    {
        if (gameBoard[2] == 'X')
        {
            return 1;
        }

        else if (gameBoard[2] == 'O')
        {
            return 2;
        }
    }

    else if (gameBoard[0] == gameBoard[4] && gameBoard[4] == gameBoard[8] && gameBoard[0] != ' ')
    {
        if (gameBoard[0] == 'X')
        {
            return 1;
        }

        else if (gameBoard[0] == 'O')
        {
            return 2;
        }
    }

    else if (gameBoard[2] == gameBoard[4] && gameBoard[4] == gameBoard[6] && gameBoard[2] != ' ')
    {
        if (gameBoard[2] == 'X')
        {
            return 1;
        }

        else if (gameBoard[2] == 'O')
        {
            return 2;
        }
    }

    else
    {

        return drawCheck();
    }
}

int drawCheck()
{
    if (gameBoard[0] != ' ' && gameBoard[1] != ' ' && gameBoard[2] != ' ' && gameBoard[3] != ' ' && gameBoard[4] != ' ' && gameBoard[5] != ' ' && gameBoard[6] != ' ' && gameBoard[7] != ' ' && gameBoard[8] != ' ')
    {
        return 3;
    }
    else
        return 0;
}

int main()
{
    srand(time(NULL));
    int result = 0;
    showBoard();
    do
    {
        cout << endl
             << endl;
        result = gameCheck();
        if (result == 0)
        {
            userMove();
        }
        system("cls");
        result = gameCheck();
        if (result == 0)
        {
            computerMove();
        }

        result = gameCheck();

    } while (result == 0);

    if (result == 1)
    {
        showBoard();
        cout << "Congratulations!" << endl;
        cout << "You Won!" << endl;
    }

    else if (result == 2)
    {
        showBoard();
        cout << "Game Over!" << endl;
        cout << "You Lose!" << endl;
        cout << "Computer Won!" << endl;
    }
    else
    {
        showBoard();
        cout << "Game Draw!" << endl
             << "No-one Won!";
    }
    return 0;
}
