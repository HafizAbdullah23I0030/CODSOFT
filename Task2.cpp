////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                      Task 2                                                                            //
//                                                                  Simple Calculator                                                                     //
//                                             Develop a calculator program that performs basic arithmetic                                                //
//                                        operations such as addition, subtraction, multiplication, and division.                                         //
//                                         Allow the user to input two numbers and choose an operation to perform.                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    char Another_operation;
    cout << setw(35) << setfill('-') << '-' << "Simple Calculator" << setw(35) << setfill('-') << '-' << '\n' ;

    do
    {
        float number1, number2;
        cout << "Enter your numbers:\n";
        cin >> number1 >> number2;

        char choice;
        cout << "Enter the Operation you want to perform (+, -, *, /):\n";

        do
        {
            cin >> choice;
            if (choice != '+' && choice != '*' && choice != '/' && choice != '-')
            {
                cout << "Enter a valid arithmetic operator!\n";
            }
        } while (choice != '+' && choice != '*' && choice != '/' && choice != '-');

        float result = 0;
        switch (choice)
        {
        case '+':
            result = number1 + number2;
            break;

        case '-':
            result = number1 - number2;
            break;

        case '*':
            result = number1 * number2;
            break;

        case '/':
            if (number2 != 0)
            {
                result = number1 / number2;
            }
            else
            {
                cout << "Error: Division by zero is not allowed.\n";
                return 1;
            }
            break;
        }

        cout << "Result is: " << result << endl;

        cout << "Do you want to perform another calculation? (Y/N): ";
        cin >> Another_operation;

    } while (Another_operation == 'Y' || Another_operation == 'y');

    return 0;
}
