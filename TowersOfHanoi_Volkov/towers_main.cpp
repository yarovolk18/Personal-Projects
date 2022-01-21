// VOLKOV, YAROSLAV // ICS4U // TOWERS OF HANOI // 02/10/2020
#include "towers_header.h"

// function to create a stack of given capacity.
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> array = (int*) malloc(stack -> capacity * sizeof(int));
    return stack;
}
// Driver code
int main(int argc, char *argv[])
{
    int n = 3; // Number of disks
    int moves = 0;
    unsigned num_of_disks = n;
    int i = 0;
    // Allegro Initialize
    al_init();

    // Initialize display
    ALLEGRO_DISPLAY *display = nullptr;
    display = al_create_display(SCREEN_W, SCREEN_H);
    al_set_window_title(display, "Towers of Hanoi");
    struct Stack *src, *dest, *aux;

    // Create three stacks of size 'num_of_disks'
    // to hold the disks
    src = createStack(num_of_disks);
    aux = createStack(num_of_disks);
    dest = createStack(num_of_disks);

    for (int i = num_of_disks; i >= 1; i--)
    {
        push(src, i);
    }
    allegro_play(display, n, src, aux, dest, moves, i);
    // TESTING
    /*
    for(int j = 0; j < 3; j++)
    {
        cout << "SRC: " << src -> array[i] << endl;
        cout << "AUX: " << aux -> array[i] << endl;
        cout << "DEST: " << dest -> array[i] << endl;
    }*/
    al_rest(5);
    al_destroy_display(display);


    // FREE MEMORY
    delete(src);
    delete(aux);
    delete(dest);

    return 0;
}
