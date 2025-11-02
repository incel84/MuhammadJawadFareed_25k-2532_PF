#include <stdio.h>
#define MAX 5   

void push(int stack[], int *top) {
    int value;
    if (*top == MAX - 1) {
        printf("Stack Overflow! Cannot push more elements.\n");
    } else {
        printf("Enter value to push: ");
        scanf("%d", &value);
        (*top)++;
        stack[*top] = value;
        printf("Element %d pushed successfully.\n", value);
    }
}

void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow! No elements to pop.\n");
    } else {
        printf("Element %d popped successfully.\n", stack[*top]);
        (*top)--;
    }
}

void peek(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty! Nothing to peek.\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

void display(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Current Stack Elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int stack[MAX];
    int top = -1;
    int choice;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(stack, &top);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                peek(stack, top);
                break;
            case 4:
                display(stack, top);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
