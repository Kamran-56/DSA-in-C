    // INTRO TO DOUBLY LINKED LIST: CREATING A DOUBLY LINKED LIST AND DISPLAYING SAME

    #include<stdio.h>
    #include<stdlib.h>

    typedef struct node {
        int data;
        struct node* next;
        struct node* prev;
    }Node;

    Node *head, *current, *tail;

    void display(struct node* head) {
        current = head;
        printf("\nDoubly linked List:\t");
        while(current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
        }
    }

    int main()
{
    int choice = 1, count = 0;

    while(choice)
    {
        Node* newnode;
        newnode = (Node*)malloc(sizeof(Node));
        printf("\nEnter Data:\t");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        if(head == NULL)
        tail = head = current = newnode;
        else
        {
        current->next = newnode;
        newnode->prev = current;
        newnode->next = NULL;
              current = newnode;
                 tail = current;
        }
        printf("\nEntering any other data? (1 for yes / 0 for no)\t");
        scanf("%d", &choice);
        count++;
    }
    display(head);
    printf("\nNo of nodes:\t%d", count);
}
