// VOLKOV, YAROSLAV // ICS4U // TOWERS OF HANOI // 02/10/2020
#include "towers_header.h"

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
    return (stack->top == stack->capacity - 1);
}
// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
    return (stack->top == -1);
}
// Function to add an item to stack. It increases
// top by 1
void push(struct Stack *stack, int item)
{
    //if (isFull(stack))
        //return;
    stack -> array[++stack -> top] = item;

}
// Function to remove an item from stack. It
// decreases top by 1
int pop(struct Stack* stack)
{
    //if (isEmpty(stack))
        //return INT_MIN;
    //delete stack[stack -> top];
    return stack -> array[stack -> top--];
}
// RECURSIVE FUNCTION
void moveTower(int height, char fromPole, char toPole, char withPole, struct Stack *src, struct Stack *aux,
               struct Stack *dest, ALLEGRO_DISPLAY *display, int disks, int &moves, ALLEGRO_FONT * font, int optMoves, int &i)
{
    if (height >= 1)
    {
        moveTower(height-1, fromPole, withPole, toPole, src, aux, dest, display, disks, moves, font, optMoves, i); //Recursive call
        moveDisk(fromPole, toPole, src, aux, dest, disks, display, moves, font, optMoves, i);
        moveTower(height-1, withPole, toPole, fromPole, src, aux, dest, display, disks, moves, font, optMoves, i); //Recursive call
    }
}
// MOVING THE DISKS BETWEEN THE TOWERS
void moveDisk(char fp, char tp, struct Stack *src, struct Stack *aux, struct Stack *dest,
              int disks, ALLEGRO_DISPLAY *display, int &moves, ALLEGRO_FONT * font, int optMoves, int &i)
{
    cout << "moving disk from " << fp << " to " << tp << endl;
    if(fp == 'A')
    {
        if(tp == 'B')
        {
            push(aux, src -> array[src -> top]);
        }
        else
        {
            push(dest, src -> array[src -> top]);
        }
        pop(src);
    }
    else if(fp == 'B')
    {
        if(tp == 'A')
        {
            push(src, aux -> array[aux -> top]);
        }
        else
        {
            push(dest, aux -> array[aux -> top]);
        }
        pop(aux);
    }
    else
    {
        if(tp == 'A')
        {
            push(src, dest -> array[dest -> top]);
        }
        else
        {
            push(aux, dest -> array[dest -> top]);
        }
        pop(dest);
    }
    moves++;
    allegro_draw(display, disks, src, aux, dest, moves, font, optMoves, i);
}
// CHECKING BORDERS, FOR PLAYABLE GAME
void click_check(int mx, int my, int mx2, int my2, struct Stack *src, struct Stack *aux,
                 struct Stack *dest, int num_of_disks)
{
    if((my >=200 && my <= 560) && (my2 >=200 && my2 <= 560)) //Y - level
    {
        if((mx >=0 && mx <=300) && src -> top != -1)//FROM FIRST PILLAR
        {
            if(mx2 >= 330 && mx2 <= 630) // TO MIDDLE PILLAR
            {
                if((src -> array[src -> top] < aux -> array[aux -> top]) || aux -> top == -1)
                {
                    push(aux, src -> array[src -> top]);
                    pop(src);
                }
            }
            else if(mx2 >= 660 && mx2 <= 960) // TO LAST PILLAR
            {
                if((src -> array[src -> top] < dest -> array[dest -> top]) || dest -> top == -1)
                {
                    push(dest, src -> array[src -> top]);
                    pop(src);
                }
            }
        }
        else if((mx >= 330 && mx <= 630) && (aux -> top != -1)) // FROM MIDDLE PILLAR
        {
            if(mx2 >=0 && mx2 <=300)
            {
                if((aux -> array[aux -> top] < src -> array[src -> top]) || src -> top == -1)
                {
                    push(src, aux -> array[aux -> top]); // TO FIRST PILLAR
                    pop(aux);
                }

            }
            else if(mx2 >= 660 && mx2 <= 960)
            {
                if((aux -> array[aux -> top] < dest -> array[dest -> top]) || dest -> top == -1)
                {
                    push(dest, aux -> array[aux -> top]); // TO LAST PILLAR
                    pop(aux);
                }
            }

        }
        else if((mx >= 660 && mx <= 960) || (dest -> top != -1)) // FROM LAST PILLAR
        {
            if(mx2 >=0 && mx2 <=300) // TO FIRST PILLAR
            {
                if((dest -> array[dest->top] < src -> array[src -> top]) || src -> top == -1)
                {
                    push(src, dest -> array[dest -> top]);
                    pop(dest);
                }
            }
            else if (mx2 >= 330 && mx2 <= 630) // TO MIDDLE PILLAR
            {
                if((dest -> array[dest -> top] < aux -> array[aux -> top]) || aux -> top == -1)
                {
                    push(aux, dest -> array[dest -> top]);
                    pop(dest);
                }
            }
        }
    }
    // TESTING
    /*
    cout << src -> top << endl;
    cout << aux -> top << endl;
    cout << dest -> top << endl << endl;
    */

}
//EMPTYING THE STACKS WHEN CHANGING SIZES // TESTING ONLY
void empty_it(struct Stack *temp){
    int lim = temp->top + 1;
    for(int i = 0; i < lim; i++)
    {
        pop(temp);
    }
}
