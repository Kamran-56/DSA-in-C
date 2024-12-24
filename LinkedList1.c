// INTRODUCTION TO LINKED LIST

    #include<stdio.h>
    #include<stdlib.h>


    int main()
{
    struct node
    {
    int data;
    struct node *next;
    };
    struct node *head = NULL, *newnode, *temp;
    int choice = 1, count = 0;

    while(choice)
    { 
        newnode = (struct node*) malloc(sizeof(struct node));
        printf("\nEnter data: ");
        scanf("%d", &newnode -> data);
        newnode -> next = NULL;                    // ist node created
        if(head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Another entry? (1/0)");
        scanf("%d", &choice);
    }
    temp = head;
    printf("\nlinked list:\t");
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("\nNumber of nodes: %d", count);
}
