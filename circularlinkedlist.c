#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* head;

struct node* create(struct node* head,int data){
    struct node* temp = malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation failed");
        return head;
    }
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        temp->next = temp;
        head = temp;
    }
    else{
        struct node* p = head;//pointer to head
        while (p->next!=head)
        {
            p = p->next;
        }
        p->next = temp;
        temp->next = head;
        
    }
    
    return head;
    
}

void displayList() {
    if (head == NULL) {
        printf("Circular Linked List is empty\n");
        return;
    }

    struct node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}


int main()
{
    head = NULL;
    int numNodes, data;

    printf("Enter the number of nodes to be created: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        head = create(head,data);
    }

    // Display the circular linked list
    displayList();
   return 0;
}