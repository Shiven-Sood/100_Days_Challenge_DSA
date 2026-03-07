#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node
 {
    int data;
    struct Node* next;
};

void push(struct Node** top, int value)
 {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) 
{
    if (*top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

int evaluatePostfix(char* exp)
 {
    struct Node* stack = NULL;
    char* token = strtok(exp, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            push(&stack, atoi(token));
        } else {
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            int result;
            switch (token[0]) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                default: exit(1);
            }
            push(&stack, result);
        }
        token = strtok(NULL, " ");
    }
    return pop(&stack);
}

int main()
 {
    char exp[100];
    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);
    exp[strcspn(exp, "\n")] = '\0';
    int result = evaluatePostfix(exp);
    printf("Result: %d\n", result);
    return 0;
}