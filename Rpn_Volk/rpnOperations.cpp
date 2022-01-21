#include "rpn_header.h"

stack::stack()
{
    head = NULL;
}

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

int stack::nElements()
{
    int counter=0;
    for (NODE *node = head; node; node=node->next)
    {
        counter++;
    }
    return counter;
}

float stack::display()
{
// Checking for too many operands
    if(nElements() !=1)
    {
        cout << "Error: too many operands" << endl;
        return 1;
    }
    else
    {
        float temp = pop();
        cout << temp << endl;
        //push(temp);
        return temp;
    }
}


void RPN::add()
{
    if (nElements()>=2)
    {
        push(pop() + pop());
    }
}

void RPN::subtract()
{
    if (nElements()>=2)
    {
        push(0 - pop() + pop());
    }
}

void RPN::multiply()
{
    if (nElements()>=2)
    {
        push(pop() * pop());
    }
}

void RPN::divide()
{
    if (nElements()>=2)
    {
        push(1 / pop() * pop());
    }
}

