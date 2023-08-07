// From https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem


#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node* next;
};


struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL && head2 == NULL)
    {
        return NULL;
    }

    struct Node* newNode = calloc(1, sizeof(struct Node));

    bool trivialCaseFound = false;

    if (head1 == NULL)
    {
        newNode->data = head2->data;
        newNode->next = head2->next;
        trivialCaseFound = true;
    }
    else if (head2 == NULL)
    {
        newNode->data = head1->data;
        newNode->next = head1->next;
        trivialCaseFound = true;
    }
    else if (head1->data <= head2->data)
    {
        newNode->data = head1->data;
        head1 = head1->next;
    }
    else // if (head1->data > head2->data)
    {
        newNode->data = head2->data;
        head2 = head2->next;
    }

    if (trivialCaseFound == false)
    {
        newNode->next = mergeLists(head1, head2);
    }

    return newNode;
}
