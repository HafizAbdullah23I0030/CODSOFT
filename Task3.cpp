#include <iostream>
#include <cstdlib>
using namespace std;

char board_array[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int choice;
char turn_player = 'X'; // X is for Player 1 and O is for Player 2.

void display_board()
{
    // Displays the board
    system("clear");
    cout << endl
         << endl;
    cout << "\t\t"
         << "    |   "
         << "  |    \n";
    cout << "\t\t"
         << " " << board_array[0][0] << "  |  " << board_array[0][1] << "  |  " << board_array[0][2] << " \n";
    cout << "\t\t"
         << "____|___"
         << "__|____\n";
    cout << "\t\t"
         << "    |   "
         << "  |   \n";
    cout << "\t\t"
         << " " << board_array[1][0] << "  |  " << board_array[1][1] << "  |  " << board_array[1][2] << " \n";
    cout << "\t\t"
         << "____|___"
         << "__|____\n";
    cout << "\t\t"
         << "    |   "
         << "  |   \n";
    cout << "\t\t"
         << " " << board_array[2][0] << "  |  " << board_array[2][1] << "  |  " << board_array[2][2] << " \n";
    cout << "\t\t"
         << "    |   "
         << "  |   \n";
    cout << "\nPlayer 1 - [X]\nPlayer 2 - [O]\n";
}

bool is_winner()
{
    // This Function checks rows, columns, and diagonals for a winner
    for (int i = 0; i < 3; i++)
    {
        if (board_array[i][0] == board_array[i][1] && board_array[i][1] == board_array[i][2])
            return true; // Checks if the elements of rows are same
        if (board_array[0][i] == board_array[1][i] && board_array[1][i] == board_array[2][i])
            return true; // Checks if the elements of columns are same
    }

    // Checks if the diagonals are same
    if (board_array[0][0] == board_array[1][1] && board_array[1][1] == board_array[2][2])
        return true;
    if (board_array[0][2] == board_array[1][1] && board_array[1][1] == board_array[2][0])
        return true;

    return false;
}

bool is_board_full()
{
    // Checks if the board is full
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board_array[i][j] != 'X' && board_array[i][j] != 'O')
                return false; // Board is not fulls
        }
    }
    return true; // Board is full
}

void switch_turn()
{
    // Switches between players
    turn_player = (turn_player == 'X') ? 'O' : 'X';
}

void turn()
{
    cout << "Player " << ((turn_player == 'X') ? "1" : "2") << " choose a number (1-9): ";
    cin >> choice;

    // Input Validation
    if (choice < 1 || choice > 9)
    {
        cout << "Enter a valid number (1-9)" << endl;
        return;
    }

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    // Checks if the chosen Position is already taken or not
    if (board_array[row][col] == 'X' || board_array[row][col] == 'O')
    {
        cout << "Spot already taken. Please choose another number." << endl;
        return;
    }

    // Updates the board
    board_array[row][col] = turn_player;

    // Switches player's turn
    switch_turn();
}

int main()
{   
    while (is_board_full)
    {
        display_board();
        turn();

        // Checks for a winner
        if (is_winner())
        {
            display_board();
            cout << "Congratulations! Player " << ((turn_player == 'X') ? "2" : "1") << " wins!" << endl;
            break;
        }

        // Checks for a tie
        if (is_board_full())
        {
            display_board();
            cout << "It's a tie!" << endl;
            break;
        }
    }
}
