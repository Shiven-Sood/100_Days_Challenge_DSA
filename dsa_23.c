#include <stdio.h>
#include <stdlib.h>

struct Node
 {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

struct Node* buildList(int n)
 {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    for (int i = 0; i < n; i++)
     {
        int val;
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL)
         {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

struct Node* mergeLists(struct Node* l1, struct Node* l2) 
{
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;
    while (l1 != NULL && l2 != NULL)
     {
        if (l1->data <= l2->data)
         {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if (l1 != NULL) tail->next = l1;
    else tail->next = l2;
    return dummy.next;
}

void printList(struct Node* head)
 {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
 {
    int n, m;
    scanf("%d", &n);
    struct Node* list1 = buildList(n);
    scanf("%d", &m);
    struct Node* list2 = buildList(m);
    struct Node* mergedList = mergeLists(list1, list2);
    printList(mergedList);
    return 0;
}