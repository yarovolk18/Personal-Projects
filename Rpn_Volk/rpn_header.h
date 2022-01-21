#ifndef RPN_H // include guard
#define RPN_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <math.h>

using namespace std;
// NODE STRUCTURE
struct NODE
{
    float num;
    NODE *next;
};
// CLASS DEFINITION
class stack
{
private:
    NODE *head;

public:
    stack();
    void push(float);
    float pop();
    int nElements();
    float display();
};
// CALCULATOR CLASS
class RPN: public stack
{
public:
    void add();
    void subtract();
    void multiply();
    void divide();
    void power();
};
// ADRESS
stack::stack()
{
    head = NULL;
}
// PUSH
void stack::push(float a_number)
{
    NODE *temp = new NODE;
    if (temp)
    {
        temp->num = a_number;
        temp->next = head;
        head = temp;
    }
}
// POP
float stack::pop()
{
    float number = 0;

    if (!head)
    {
        return 0;
    }
    else
    {
        NODE *temp = head;
        number = head->num;
        head = temp->next;
        delete temp;
    }
    return number;
}
// COUNTING THE NUMBER OF ELEMENTS
int stack::nElements()
{
    int counter=0;
    for (NODE *node = head; node; node=node->next)
    {
        counter++;
    }
    return counter;
}
// DISPLAY + PRINT
float stack::display()
{
    float temp = pop();
    cout << "ANSWER: " << temp << endl;
    return temp;
}
// ADDITION
void RPN::add()
{
    int maxi = nElements();
    for(int i = 0; i < maxi; i++)
    {
        push(pop() + pop());
    }
}
// SUBTRACTION
void RPN::subtract()
{
    float now;
    int maxi = nElements();
    for(int i = 0; i <= maxi; i++)
    {
        now = pop();
        push(now - pop());
    }
}
// MULTIPLICATION
void RPN::multiply()
{
    int maxi = nElements();
    for(int i = 0; i < maxi-1; i++)
    {
        push(pop() * pop());
    }

}
// DIVISION
void RPN::divide()
{
    float now;
    int maxi = nElements();
    for(int i = 0; i < maxi; i++)
    {
        now = pop();
        push(pop()/now);
    }
}
// POWER
void RPN::power()
{
    int maxi = nElements();
    for(int i =0; i < maxi - 1; i++)
    {
        push(pow(pop(), pop()));
    }
}
//Function prototype for isOperator
bool isOperator(const string& input);

//Function prototype for perforOperation
int performOperation(const string& input, RPN& calculator);
#endif

