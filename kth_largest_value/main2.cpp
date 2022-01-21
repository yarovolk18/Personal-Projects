#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct NODE
{
    float data;
    NODE *next;
    NODE *arb_ptr;
};

class AddStream
{
private:
    NODE *head = NULL;
    NODE *tail = NULL;

    NODE *head2 = NULL;
    NODE *tail2 = NULL;
public:
    void create_list()
    {
        srand(time(NULL));
        int items = rand() % 50 + 50;
        cout << "ITEMS: " << items << endl;
        int x = 0;
        while(x < items)
        {
            NODE *tmp = new NODE;
            tmp -> data = ((float) rand()) / (float) RAND_MAX;
            tmp -> next = NULL;

            if(head == NULL)
            {
                head = tmp;
                tail = tmp;
            }
            else
            {
                tail -> next = tmp;
                tail = tail -> next;
            }
            x++;
        }
        x = 0;
        int y = rand()% items + 1;

        while(x < items)
        {
            NODE *tmp = new NODE;
            NODE *node = head;
            for(int i = 0; i < y; i++)
            {
                node = node -> next;
            }
            tmp -> arb_ptr = node;
            x++;
        }
    }

    void find_k()
    {
        NODE* node = head2;
        float k = 0.0;

        while(node != NULL)
        {
            if(node->data > k)
            {
                k = node->data;
            }
            node = node -> next;
        }
        cout << "K: " << k << endl;

    }

    void copy_list()
    {

        NODE *node = head;

        while(node != NULL)
        {

            NODE *tmp2 = new NODE;
            tmp2 -> data = node -> data;
            // cout << tmp -> data << endl;
            tmp2 -> next = node -> next;
            tmp2 -> arb_ptr = node -> arb_ptr;
            //tmp2 -> next = NULL;

            if(head2 == NULL)
            {
                head2 = tmp2;
                tail2 = tmp2;
            }
            else
            {
                tail2 -> next = tmp2;
                tail2 = tail2 -> next;
            }
            node = node -> next;
        }

    }

};

int main()
{
    AddStream a;
    a.create_list();
    cout << "CREATED LIST" << endl;
    a.copy_list();
    cout << "COPIED LIST" << endl;
    a.find_k();
    cout << "FOUND K" << endl;
    return 0;
}
