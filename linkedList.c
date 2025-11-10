#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *linkedList = NULL;

void traverse() {
    if (linkedList == NULL) {
        printf("empty linked list\n");
        return;
    }
    struct node *p = linkedList;
    while (p->link != NULL) {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("%d\n", p->data);
}

struct node* createNode(int data) {
    printf("creating node ...\n");
    struct node *newNode = (struct node *) malloc (sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;
    if (newNode) {
        printf("node created successfully\n");
        printf("node -> data = %d\n", newNode->data);
        printf("node -> link = %d\n", newNode->link);
    }
    else {
        printf("failed to create node\n");
        exit(1);
    }
    return newNode;
}

void insertionAtLast(int data) {
    struct node *newNode = createNode(data);
    if (linkedList == NULL) {
        linkedList = newNode;
        printf("node inserted successfully\n");
        traverse();
        return;
    }
    struct node *p = linkedList;
    while (p->link != NULL) {
        p = p->link;
    }
    p->link = newNode;
    printf("node inserted successfully\n");
    traverse();
}

void deletionAtLast() {
    printf("deletion started...\n");
    if (linkedList == NULL) {
        printf("linked list is already empty\n");
        return;
    }
    struct node *p = linkedList;
    if (p->link == NULL) {
        linkedList = NULL;
        printf("deletion successfull linked list is now empty\n");
        return;
    }
    while(p->link->link != NULL) p = p->link;
    p->link = NULL;
    printf("deletion successfull\n");
    traverse();
}

void insertionAtStart(int data) {
    struct node *newNode = createNode(data);
    printf("insertion started...\n");
    if (linkedList == NULL) {
        linkedList = newNode;
        printf("first node inserted\n");
        traverse();
        return;
    }
    newNode->link = linkedList;
    linkedList = newNode;
    printf("insertion successful\n");
    traverse();
}

void deletionAtStart() {
    if (linkedList == NULL) {
        printf("empty linked list\n");
        return;
    }
    linkedList = linkedList -> link;
    printf("deletion successfull\n");
    traverse();
}

void find(int element) {
    int i = 1;
    if (linkedList == NULL) {
        printf("linked list is empty\n");
        return;
    }
    struct node *p = linkedList;
    do {
        if (p->data == element) {
            printf("element is present at index %d\n", i);
            return;
        }
        p = p -> link;
        i++;
    } while (p->link != NULL);
    printf("element is not present\n", i);
    return;
}

int main() {
    traverse();
    insertionAtLast(5);
    insertionAtLast(6);
    deletionAtLast();
    deletionAtLast();
    deletionAtLast();
    deletionAtLast();
    insertionAtStart(8);
    insertionAtStart(9);
    insertionAtStart(6);
    deletionAtStart();
    deletionAtStart();
    deletionAtStart();
    insertionAtLast(6);
    insertionAtLast(8);
    insertionAtLast(8);
    insertionAtLast(4);
    insertionAtLast(9);
    find(5);
    find(4);
    return 0;
}