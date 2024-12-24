// DELETION FROM A LINKED LIST

    #include<stdio.h>
    #include<stdlib.h>

    int main()
{
    struct node {
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

    // DELETE FROM BEGINING
    count = 0;
    temp = head;
    head = head->next;
    free(temp);

    temp = head;
    printf("\nlinked list:\t");
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
        count++;
    }

    //DELETE FROM END
    count = 0;
    struct node *prevnode;
    temp = head;
    while(temp->next != 0)
    {
        prevnode = temp;
        temp = temp->next;
    }
    if(temp == head)
    {
        head = 0;
    }
    else
    {
        prevnode->next = NULL;
    }
    free(temp);

    temp = head;
    printf("\nlinked list:\t");
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
        count++;
    }


    //DELETE FROM ANY POSITION
    struct node *nextnode;
    count = 0;
    int pos, i=1;
    printf("\n\nEnter position:\t");
    scanf("%d", &pos);
    if(pos = 1)
    {
    temp = head;
    head = head->next;
    free(temp);
    }
    else
    {
    temp = head;
    while(i < pos-1)
    {
        temp = temp->next;
        i++;
    }
        
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
    temp = head;
    }
    printf("\nlinked list:\t");
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("\nNumber of nodes: %d", count);

}