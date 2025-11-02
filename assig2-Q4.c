#include <stdio.h>
#define MAX 5 

int stack[MAX];
int top = -1;

void push() {
    int val;
    if (top == MAX - 1)
        printf("Stack Overflow!\n");
    else {
        printf("Enter value to push: ");
        scanf("%d", &val);
        stack[++top] = val;
        printf("%d pushed into stack.\n", val);
    }
}

void pop() {
    if (top == -1)
        printf("Stack Underflow!\n");
    else
        printf("%d popped from stack.\n", stack[top--]);
}

void peek() {
    if (top == -1)
        printf("Stack is empty!\n");
    else
        printf("Top element: %d\n", stack[top]);
}

void display() {
    if (top == -1)
        printf("Stack is empty!\n");
    else {
        printf("Stack elements:\n");
        int i;
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

int main() {
    int ch;
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n0. EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 0: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

