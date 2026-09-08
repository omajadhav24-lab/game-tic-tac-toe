#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void displayBoard()
{
    cout << "\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "\n";
    cout << "     |     |     \n\n";
}

bool checkWin(char player)
{
    // Rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;
    }

    // Columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

    // Diagonals
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] >= '1' && board[i][j] <= '9')
                return false;
        }
    }

    return true;
}

void makeMove(char player)
{
    int choice;

    while (true)
    {
        cout << "Player " << player << ", enter position (1-9): ";
        cin >> choice;

        if (choice < 1 || choice > 9)
        {
            cout << "Invalid position! Try again.\n";
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O')
        {
            cout << "Position already occupied! Try again.\n";
        }
        else
        {
            board[row][col] = player;
            break;
        }
    }
}

int main()
{
    char player = 'X';

    cout << "============================\n";
    cout << "       TIC TAC TOE\n";
    cout << "============================\n";

    while (true)
    {
        displayBoard();

        makeMove(player);

        if (checkWin(player))
        {
            displayBoard();
            cout << "Player " << player << " wins! 🎉\n";
            break;
        }

        if (checkDraw())
        {
            displayBoard();
            cout << "It's a draw! 🤝\n";
            break;
        }

        // Switch player
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    return 0;
}