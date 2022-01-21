//  NAME: YAROSLAV

#include <iostream>

using namespace std;
// COMPLETE THE FOLLOWING PROGRAM SO THAT IT WILL SORT THE GIVEN
// DATA USING A BUBBLE-SORT ALGORITHM.
// YOU WILL BE EVALUATED ON THE CLARITY OF YOUR CODE, THE USE OF VARIABLES,
// WHETHER YOUR PROGRAM WORKS, COMMENTS AND COMPLETENESS.
int main()
{
    const int n = 20;
    int a[n] = {3,7,9,2,32,22,19,2,13,17,31,24,8,6,23,4,99,36,12,25};
    int comparisons = 0;
    int moves = 0;

    //Displays unsorted list
    cout << "UN-SORTED LIST" << endl;
    for(int j = 0; j<n; j++)
    {
        cout << a[j] << " ";
    }
    cout << endl;

    // BUBBLE-SORT  (enter code here)
    int i, j;
    int temp;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            // COMPARING
            comparisons ++;
            if (a[j] > a[j+1])
            {
                // SWAP
                moves++;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }

    }

// END OF BUBBLE SORT

//Displays sorted list
    cout << "SORTED LIST" << endl;
    for(int j = 0; j<n; j++)
    {
        cout << a[j] << " ";
    }

// Displays number of comparisons and number of moves
    cout << "COMPARISONS: " << comparisons << "  MOVES: " << moves << endl << endl;

    cout << endl;
    return 0;
}
