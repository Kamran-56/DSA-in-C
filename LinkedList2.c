 //INSERTION IN LINKED LIST   
    
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
        newnode -> next = NULL;         // ist node created
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
    temp = head;                            //traversing a linked list
    printf("\nlinked list:\t");
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("\nNumber of nodes: %d", count);

    count = 0;
    newnode = (struct node*)malloc(sizeof(struct node));                  //insert at begining
    printf("\n\nEnter the data to be inserted at the begining :\t");
    scanf("%d", &newnode->data);
    newnode->next=head;
    head=newnode;
    temp = head;
    printf("linked list:\t");
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("\nNumber of nodes: %d", count);

    count=0;
    newnode = (struct node*)malloc(sizeof(struct node));                  //insert at end
    printf("\n\nEnter the data to be inserted at the end :\t");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }
    temp->next = newnode;
    temp = head;
    printf("linked list:\t");
    count = 0;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("\nNumber of nodes: %d", count++);

    
    // INSERT AT ANY POSITION
    
    count = 0;
    int pos, i = 1;
    temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    printf("\nEnter the position at which element has to be inserted:\t");
    scanf("%d", &pos);
    if (pos <= 0 || pos > count + 1)
    printf("\nInvalid position");
    else
    {
        newnode = (struct node*) malloc(sizeof(struct node));
        
    if (newnode == NULL)
    {
    printf("Memory allocation failed!\n");
    exit(1);  // Exit the program if memory allocation fails
    }

        printf("\nEnter data to be inserted:\t");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

         // Insert at the beginning if position is 1
        if (pos == 1) {
            newnode->next = head;
            head = newnode;
        }
        else {
            temp = head;
            while(i < pos-1)
            {
                temp = temp->next;
                i++;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }

        printf("linked list:\t");
        count = 0;
        temp = head;
        while(temp != NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
            count++;
        }
        printf("\nNumber of nodes: %d", count);
    }

}

