#include <stdio.h>
#define SIZE 100

int array[SIZE];
int top = -1;

void display() {
    for (int i=0; i<= top; i++) {
        printf("%d ", array[i]);
    } printf("\n");
}

// insertion
void push(int element) {
    // overflow
    if (top + 1 >= SIZE) printf("overflow...\n");
    else {
        top++;
        array[top] = element;
    }
}

// deletion
void pop() {
    if (top - 1 < -1) printf("underflow...\n");
    else top--;
}

int search(int element) {
    for (int i=0; i<=top; i++) {
        if (array[i] == element) return i;
    } return -1;
}

void merge(int arr[], int size) {
    for(int i=0; i<size; i++) push(arr[i]);
}

int main() {
    display();
    push(1);
    push(2);
    push(3);
    push(4);
    pop();
    pop();
    display();
    int arr[] = {0,2,0};
    int len = sizeof(arr)/sizeof(arr[0]);
    merge(arr, len);
    display();
    printf("%d %d %d", search(1), search(2), search(3));
    return 0;
}