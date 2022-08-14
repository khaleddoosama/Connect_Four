#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
char board[7][6];
int j[7] = { 5,5,5,5,5,5,5 };
char Is_Winning(char board[6][7])
{
    char win = ' ';
    for (int j = 0; j < 6; j++)
    {
        for (int i = 0; i < 7; i++)
        {
            if (board[j][i] == 'X' && board[j + 1][i + 1] == 'X' && board[j + 2][i + 2] == 'X' && board[j + 3][i + 3] == 'X')
                win = 'X';
            else if (board[j][i] == 'X' && board[j + 1][i - 1] == 'X' && board[j + 2][i - 2] == 'X' && board[j + 3][i - 3] == 'X')
                win = 'X';
            else if (board[j][i] == 'O' && board[j + 1][i - 1] == 'O' && board[j + 2][i - 2] == 'O' && board[j + 3][i - 3] == 'O')
                win = 'O';
            else if (board[j][i] == 'O' && board[j - 1][i - 1] == 'O' && board[j - 2][i - 2] == 'O' && board[j - 3][i - 3] == 'O')
                win = 'O';
            else if (board[j][i] == 'X' && board[j][i - 1] == 'X' && board[j][i - 2] == 'X' && board[j][i - 3] == 'X')
                win = 'X';
            else if (board[j][i] == 'X' && board[j - 1][i] == 'X' && board[j - 2][i] == 'X' && board[j - 3][i] == 'X')
                win = 'X';
            else if (board[j][i] == 'O' && board[j][i - 1] == 'O' && board[j][i - 2] == 'O' && board[j][i - 3] == 'O')
                win = 'O';
            else if (board[j][i] == 'O' && board[j - 1][i] == 'O' && board[j - 2][i] == 'O' && board[j - 3][i] == 'O')
                win = 'O';
        }
    }
    return win;
}
void print(char board[6][7])
{
    cout << "0 1 2 3 4 5 6 " << endl;
    for (size_t i = 0; i < 6; i++)
    {
        for (size_t j = 0; j < 7; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}
bool insert(char board[6][7], char player, int column)
{
    board[j[column]][column] = player;
    if (j[column] == -1)
        return false;
    j[column]--;
    return true;
}
int main()
{
    int column;
    char  player, board[6][7];
    for (size_t i = 0; i < 6; i++)
    {
        for (size_t j = 0; j < 7; j++)
            board[i][j] = ' ';
    }
    for (size_t i = 0; i < 42; i++)
    {
        cout << "Please, Enter the number of column from ZERO to SIX" << endl;
        cin >> column;
        if (i % 2 == 0)
            player = 'X';
        else
            player = 'O';
        while (column > 6 || column < 0)
        {
            cout << "Wrong Answer,Please try again" << endl;
            cin >> column;
        }
        while (insert(board, player, column) == false)
        {
            cout << "Wrong Answer,Please try again" << endl;
            cin >> column;
        }
        print(board);
        if (Is_Winning(board) != ' ')
        {
            cout << "The Winner is " << Is_Winning(board);
            return 0;
        }
    }
}