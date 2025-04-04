//program to insert element at any position in a linked list 


#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* head;


void insert(struct node **head,int data, int position){
    int k = 1;
    struct node *p,*q;
    struct node* newdata;
    newdata = (struct node*)malloc(sizeof(struct node));

    newdata->data = data;
    newdata->next = NULL;
    p = *head;
    //insertion at first position 
    if (position==1)
    {
        newdata->next = p;
        *head = newdata;
    }
    else{
        while (p!=NULL && k<position)// using k to reach a specified position 
        {
            k++;
            q=p;//q is set to p to keep the track of previos node
            p=p->next;
        }
        q->next = newdata;
        newdata->next = p;
        
    }
    
}
void search(int key){
    struct node* ptr = head;
    int pos = 1;
    while (ptr->next!=NULL)
    {
        
        if (ptr->data==key)
        {
            printf("Found at position %d ",pos);
            return;

        }
        
        ptr = ptr->next;
        pos++;
        
    }
    printf("Item not found");

    
    
}
void display(){
    struct node *temp = head;
    while (temp !=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
}

int main()
{
   head = NULL;
    insert(&head,3,1);
    insert(&head,4,2);
    insert(&head,5,2);//it shifted 4 to position 3
    display();
    search(5);
   return 0;
}