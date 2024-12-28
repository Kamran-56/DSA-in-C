// IMPLEMENTING DOUBLY CIRCULAR LINKED LIST

    #include<stdio.h>
    #include<stdlib.h>

    struct node {
        int data;
        struct node *prev;
        struct node *next;
    };

    struct node *head = NULL, *tail = NULL;

    void CreateList() {
        int choice = 1;
        struct node *newnode;

        while(choice)
        {
            newnode = (struct node*) malloc(sizeof(struct node));
            printf("\nEnter data:\t");
            scanf("%d", &newnode->data);
        
            if(head == NULL)
            {
                head = tail = newnode;
                newnode->next = newnode;
                newnode->prev = newnode;
            }
            else
            {
                newnode->prev = tail;
                newnode->next = head;
                tail->next = newnode;
                head->prev = newnode;
                tail = newnode;
            }
            printf("\nAny other element? (1 for yes / 0 for NO)");
            scanf("%d", &choice);
        }
        //printf("\n%d\t%d\t", tail->next->data, head->prev->data);
    }

    void display() {
        struct node *temp;
        temp = head;
        do
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        while(temp != tail->next);

        printf("%d", temp->data);
    }

    int main()
{
    
    CreateList();
    printf("original list\t");
    display();

    return 0;
}
