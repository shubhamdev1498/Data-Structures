#include <stdio.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void traverse() {
    if (top == -1) {
        printf("stack is empty\n");
        return;
    }
    for(int i=0; i<=top; i++) {
        printf("%d ", stack[i]);
    } printf("\n");
}

void push(int element) {
    if (top + 1 >= SIZE) {
        printf("overflow; stack is full\n");
        return;
    }
    top++;
    stack[top] = element;
    printf("element added to stack successfully\n");
    traverse();
}

void pop() {
    if (top == -1) {
        printf("underflow; stack is empty\n");
        return;
    }
    top--;
    printf("elemented deleted successfully from stack\n");
    traverse();
}

void popFromIndex(int index) {
    for (int i=index; i<=top-1; i++) {
       stack[i] = stack[i+1]; 
    } top--;
    printf("element deleted successfully at index %d\n", index);
    traverse();
}

int main() {
    traverse();
    push(10);
    push(4);
    push(1);
    pop();
    pop();
    pop();
    pop();
    push(0);
    push(1);
    push(2);
    push(3);
    popFromIndex(1);
    return 0;
}