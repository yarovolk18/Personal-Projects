#include "rpn_header.h"

int main()
{
    // VARIABLES
    RPN calculator;
    string input;
    float num;
    // RULES AND INTERFACE
    cout << "RPN Calculator: " << endl;
    cout << "FORMAT:"<< endl << "num1 ENTER"<< endl << "num2 ENTER" << endl << "numN ENTER" << endl << "+-*/^ ENTER" << endl;

    while(input != "0")
    {
//Terminate program when 0 is entered by user
        while(true)
        {

// get input
            system("color a");
            cout << "ENTER: " ;
            cin >> input;

// check for being numeric value

            if(istringstream(input) >> num)
            {
//use push function
                calculator.push(num);
            }

// check for operator
            else if(isOperator(input))
            {
                system("CLS");

                 cout << "FORMAT:"<< endl << "num1 ENTER"<< endl << "num2 ENTER" << endl << "numN ENTER" << endl << "+-*/^ ENTER" << endl;
                performOperation(input, calculator);


            }// If user enters 0 on a line followed by a new line, the program exits     ????????????
            if(input == "0")
            {
                break;
            }

        }
    }
}

bool isOperator(const string& input)
{
    static const string operators ="-+*/^";
    if (input.length() == 1) // right size to be an operator.
    {
        return operators.find_first_of(input[0]) != string::npos;
// look in the operator string for the first (and only) character in input
    }
    return false;
}

int performOperation(const string& input, RPN& calculator)
{

    switch (input[0])
    {
    case '+':
        calculator.add();
        calculator.display();
        break;
    case '-':
        calculator.subtract();
        calculator.display();
        break;
    case '*':
        calculator.multiply();
        calculator.display();
        break;
    case '/':
        calculator.divide();
        calculator.display();
        break;
    case '^':
        calculator.power();
        calculator.display();
        break;
    }


    return 0;

}
