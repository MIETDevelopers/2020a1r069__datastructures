#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void push(int element) // function for pushing an element in the stack
{
    struct node *temp = head;
    if (temp == NULL) // condition for checking if the stack is empty
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = element;
        temp->next = NULL;
        head = temp;
    }
    else // else inserting the node at the beginning of the linked list
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = element;
        temp->next = head;
        head = temp;
    }
}
int pop() //   function to pop an element from the stack
{
    int removed = INT_MIN;
    struct node *temp = head;
    if (temp == NULL)
    {
        return removed;
    }
    else if (temp->next == NULL)
    {
        removed = head->data;
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;
        head = head->next;
        removed = temp->data;
        free(temp);
    }
    return removed; // returning the removed element
}
void print() // function for printing the stack
{
    struct node *temp;
    // condition for empty list
    if (head == NULL)
        printf("\nStack is empty\n");
    // Else print the LL
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d --> ", temp->data);
            temp = temp->next;
        }
        printf("NULL");
    }
}
int main()
{
    int choice, element, poppedElement;
    do
    {
        printf("\nchoose any below options\n");
        printf("1.To Push an element in stack.\n");
        printf("2.To Pop an element in stack.\n");
        printf("3.To Print the elements of the stack.\n");
        printf("4.To Quit\n");
        scanf("%d", &choice);
        switch (choice)
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Element\n");
            scanf("%d", &element);
            push(element);
            break;
        case 2:
            poppedElement = pop();
            if (poppedElement != INT_MIN)
            {
                printf("%d was popped successfully", poppedElement);
            }
            else
            {
                printf("Stack is Empty!");
            }
            break;

        case 3:
            print();
            break;
        case 4:
            printf("Quitting the program\n");
            break;
        default:
            printf("Please Enter from the above options\n");
            break;
        }
    } while (choice != 4);
    return 0;
} 