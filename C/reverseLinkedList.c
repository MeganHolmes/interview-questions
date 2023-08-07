
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node
{
    int data;
    struct Node* next;
};

int getDataWithIndex(struct Node* linkedList, int index)
{
    int itr = 0;
    while (linkedList->next != NULL && index > itr)
    {
        linkedList = linkedList->next;
        itr++;
    }

    assert (index == itr);

    return linkedList->data;
}

void createNewNode(struct Node* linkedList, int newData)
{
    int idx = 0;
    while (linkedList->next != NULL)
    {
        linkedList = linkedList->next;
        idx++;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = newData;
    newNode->next = NULL;

    linkedList->next = newNode;
}

struct Node* reverseLinkedList(struct Node* linkedList, struct Node* previousNode)
{
    assert (linkedList != NULL);

    struct Node* returnNode = NULL;

    if (linkedList->next != NULL)
    {
        returnNode = reverseLinkedList(linkedList->next, linkedList);
    }
    else
    {
        returnNode = linkedList;
    }

    linkedList->next = previousNode;

    return returnNode;
}

void printSampleOf3(struct Node* linkedList)
{
    for (int idx = 0; idx < 3; idx++)
    {
        printf("Sample %d = %d\n", idx, getDataWithIndex(linkedList, idx));
    }
}

int main(void)
{
    struct Node linkedList;
    linkedList.data = 0; // Define initial node data.
    linkedList.next = NULL;

    for (int idx = 0; idx < 50; idx++)
    {
        createNewNode(&linkedList, idx);
    }

    printSampleOf3(&linkedList);

    struct Node* newList = reverseLinkedList(&linkedList, NULL);

    printSampleOf3(newList);

    return 0;
}
