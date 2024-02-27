#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    cout << "\n\n------------------   NUMBER GUESSING GAME   ------------------\n\n";

    int random_number = rand() % 50 + 1; // The System Generated Random Number

    cout << "Number Generated!\n";
    int guessed_number; // The Number Guessed by the User
    cout << "Guess the number!\n";

    int attempts = 0; // The Number of attempts user takes
    do
    {
        cin >> guessed_number;
        // Feedback for Every Attempt
        if (guessed_number > random_number)
        {
            cout << "Too high! Try again.\n";
        }
        else if (guessed_number < random_number)
        {
            cout << "Too low! Try again.\n";
        }
        attempts++;
    } while (guessed_number != random_number);

    cout << "Congratulations! You guessed the correct number in " << attempts << " attempts.\n";
}
