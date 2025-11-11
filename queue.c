#include <stdio.h>
#define SIZE 100

int queue[SIZE];
int front = -1;
int rear = -1;

void traverse() {
    if (front == -1) {
        printf("queue is empty\n");
        return;
    }
    for (int i=front; i<=rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void enqueue(int element) {
    if (front == -1) {
        front++;
    }
    if (rear + 1 == SIZE) {
        printf("overflow\n");
        return;
    }
    rear++;
    queue[rear] = element;
    printf("enqueue is successfull\n");
    traverse();
}

void dequeue() {
    if (front == -1) {
        printf("queue is empty\n");
        return;
    }
    if (front == rear) {
        front = -1;
        rear = -1;
        printf("dequeue is successfull\n");
        return;
    }
    front++;
    printf("dequeue is successfull\n");
    traverse();
}

int main() {
    traverse();
    enqueue(4);
    enqueue(2);
    enqueue(3);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    return 0;
}