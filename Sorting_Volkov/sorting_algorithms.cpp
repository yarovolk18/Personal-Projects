#include "sorting_header.h"

// QUICK SORT CODE START
// SPLITTING
int partition (struct Stack* a, int p, int r, int &moves, int &comparisons, ALLEGRO_DISPLAY* display)
{
    int x = a -> array[r];
    int i = p - 1;

    for (int j = p; j <= r- 1; j++)
    {
        comparisons++;
        if (a -> array[j] <= x)
        {
            i++;
            swap (a->array[i], a->array[j]);
            moves++;
        }
    }
    swap (a->array[i + 1], a->array[r]);
    draw_quick(display, a, 200, x);
    moves++;
    return (i + 1);
}
// QUICKSORT
void quickSort(struct Stack* a, int p, int r, int &moves, int &comparisons, ALLEGRO_DISPLAY* display)
{
    if (p < r)
    {
        int q = partition(a, p, r, moves, comparisons, display);
        quickSort(a, p, q - 1, moves, comparisons, display);
        quickSort(a, q + 1, r, moves, comparisons, display);
    }
}
// QUICK SORT CODE END

// BUBBLE SORT CODE START
void bubbleSort(struct Stack* a, int n, int &moves, int &comparisons, ALLEGRO_DISPLAY* display)
{
    int i, j;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            // COMPARING
            comparisons ++;
            if (a->array[j] > a->array[j+1])
            {
                // SWAP
                moves++;
                swap(a->array[j], a->array[j+1]);
            }
            //draw_sort(display, a, n); -> Technically correct, but takes forever to display
        }
        draw_sort(display, a, n);
    }

}
// BUBBLE SORT CODE END

// SELECTION SORT CODE START
void selectionSort(struct Stack* a, int n, int &moves, int &comparisons, ALLEGRO_DISPLAY* display)
{
    int i, j, min_i;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_i = i;
        for (j = i+1; j < n; j++)
        {
            comparisons++;
            if (a->array[j] < a->array[min_i])
            {
                min_i = j;
            }
        }
        // Swap the found minimum element with the first element
        moves++;
        swap(a->array[min_i], a->array[i]);
        draw_sort(display, a, n);
    }
}
// SELECTION SORT CODE END

// BINARY SORT CODE START
void binarySort(struct Stack* a, int n, int &left, int &right, ALLEGRO_DISPLAY* display, ALLEGRO_FONT * fontL)
{
    if((a->array[(left + right)]/2 == n) || (left + right)/2 == left || (left + right)/2 == right)
    {
        al_draw_textf(fontL, BLUE, 10, 10, ALLEGRO_ALIGN_LEFT, "The number: %d is not present in this list.", n);
        al_flip_display();
        return;
    }
    else
    {
        if(n > a -> array[(left + right)/2])
        {
            if(left <=199)
            {
                left = ((left + right)/2);
            }
        }
        else if(a -> array[(left + right)/2] == n)
        {
            al_clear_to_color(BLACK);
            al_draw_textf(fontL, BLUE, 10, 10, ALLEGRO_ALIGN_LEFT, "The number: %d is present in this list.", n);
            al_draw_text(fontL, BLUE, 10, 40, ALLEGRO_ALIGN_LEFT, "The location is presented in ");
            al_draw_text(fontL, RED, 400, 40, ALLEGRO_ALIGN_LEFT, "red");
            al_flip_display();
            draw_binary(display, a, 200, n);
            return;
        }
        else
        {
            if(right >= 0)
            {
                    right = ((left + right)/2) ;
            }
        }
        // TESTING
        //cout << "LEFT:" << left << endl;
        //cout << "RIGHT:" << right << endl;
        //cout << (left+right)/2 << endl;
        //cout << "NUM: " << a->array[(left+right)/2] << endl;

        draw_quick(display, a, 200, (left+right)/2);
        binarySort(a, n, left, right, display, fontL);
    }
}
// BINARY SORT CODE END
