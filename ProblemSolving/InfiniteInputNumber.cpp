#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int num;
    struct node* next;
};

int feednumber(struct node**);
void release(struct node**);
void display(struct node*);

int main()
{
    struct node* p = NULL;
    int pcount = 0;

    printf("Enter number of any length\n");
    pcount = feednumber(&p);
    printf("Number of integers entered are: %d\n", pcount);
    printf("Displaying the number entered:\n");
    display(p);
    release(&p);

    return 0;
}

/*Function to create nodes of numbers*/
int feednumber(struct node** head)
{
    char ch, dig;
    int count = 0;
    struct node* temp, * rear = NULL;

    ch = getchar();
    while (ch != '\n')
    {
        dig = atoi(&ch);
        temp = (struct node*)malloc(sizeof(struct node));
        temp->num = dig;
        temp->next = NULL;
        count++;
        if ((*head) == NULL)
        {
            *head = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = rear->next;
        }
        ch = getchar();
    }

    return count;
}

/*Function to display the list of numbers*/
void display(struct node* head)
{
    while (head != NULL)
    {
        printf("%d", head->num);
        head = head->next;
    }
    printf("\n");
}

/*Function to free the allocated list of numbers*/
void release(struct node** head)
{
    struct node* temp = *head;

    while ((*head) != NULL)
    {
        (*head) = (*head)->next;
        free(temp);
        temp = *head;
    }
}
