#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define max_size 50

// Define a union for the stack items
typedef union {
    int integerVal;
    char stringVal[max_size];
} StackItem;

StackItem stack[max_size];
int top = -1, flag = 1;
int i, temp;
StackItem item, rev;
char str[max_size];

// Function prototypes
void push();
void pop();
void display();
void pali();

int main() {
    int choice;

    printf("\n\n--------STACK OPERATIONS ------ \n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Palindrome\n");
    printf("4.Display\n");
    printf("5.Exit\n");

    while (1) {
        printf("\nEnter your choice:\t");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                if (flag)
                    printf("\nThe popped element: %s\t", item.stringVal);
                temp = top;
                break;
            case 3:
                pali();
                top = temp;
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nInvalid choice:\n");
                break;
        }
    }

    return 0;
}

void push() {
    if (top == (max_size - 1)) {
        printf("\nStack Overflow:");
    } else {
        printf("Enter the element to be inserted (integer or string):\t");
        scanf("%s", str);

        // Try to convert input to an integer, if successful, store as integer, otherwise, store as a string
        if (sscanf(str, "%d", &item.integerVal) == 1) {
            // Input is an integer
            item.stringVal[0] = '\0';  // Set stringVal to an empty string
        } else {
            // Input is a string
            strcpy(item.stringVal, str);
        }

        top = top + 1;
        stack[top] = item;
    }
    temp = top;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow:");
        flag = 0;
    } else {
        item = stack[top];
        top = top - 1;
    }
}

void pali() {
    i = 0;
    if (top == -1) {
        printf("Push some elements into the stack first\n");
    } else {
        while (top != -1) {
            rev = stack[top];
            pop();
        }
        top = temp;
        for (i = 0; i <= temp; i++) {
            if ((item.integerVal == rev.integerVal && item.stringVal[0] == '\0' && rev.stringVal[0] == '\0') ||
                (strcmp(item.stringVal, rev.stringVal) == 0)) {
                if (i == temp) {
                    printf("Palindrome\n");
                    return;
                }
            }
        }
        printf("Not Palindrome\n");
    }
}

void display() {
    int i;
    top = temp;
    if (top == -1) {
        printf("\nStack is Empty:");
    } else {
        printf("\nThe stack elements are:\n");
        for (i = top; i >= 0; i--) {
            if (stack[i].stringVal[0] == '\0') {
                printf("%d\n", stack[i].integerVal);
            } else {
                printf("%s\n", stack[i].stringVal);
            }
        }
    }
}
