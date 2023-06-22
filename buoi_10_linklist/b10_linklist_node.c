#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct Node {
    uint8_t value;
    struct Node* next;
};

typedef struct Node Node;

Node *createNode(uint8_t value)
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->value =value;
    node->next = NULL;
    return node;
}

void pushback(Node **array, uint8_t value)
{
    Node *temp, *p;
    temp = createNode(value);
    if(array == NULL)
    {
        *array = temp;
    }
    else
    {
        p = array;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}
int main(int argc, char const *argv[])
{
    Node *array = NULL;
    

    pushback(&array, 6);
    pushback(&array, 2);
    pushback(&array, 3);
    return 0;
}
