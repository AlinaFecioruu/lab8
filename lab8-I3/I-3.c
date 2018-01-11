#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createList(int x,int y,struct Node*pr,struct Node*ul)
{
    int i;
    struct Node* newElement=NULL;
    pr->data=1;
    pr->next=NULL;
    ul=pr;
    if(x>1)
        for(i=0; i<x-1; i++)
        {
            newElement=(struct Node*)malloc(sizeof(struct Node));
            scanf("%d",&y);
            newElement->data=y;
            ul->next=newElement;
            newElement->next=NULL;
            ul=newElement;
        }
}

void PrintList(struct Node *node)
{
    if (!node) printf ("Empty list!");
    else
    {
        while(node)
        {
            printf("%d ", node->data);
            node = node->next;
        }
    }
}

void deleteList(struct Node** head)
{
   struct Node* current = *head;
   struct Node* next;

   while (current != NULL)
   {
       next = current->next;
       free(current);
       current = next;
   }

   *head = NULL;
}

int main()
{
    struct Node* p=NULL;
    struct Node* u=NULL;
    p=(struct Node*)malloc(sizeof(struct Node));
    u=(struct Node *)malloc(sizeof(struct Node));

    int n;
    int m;

    printf("Enter the number of elements from the list: ");
    scanf("%d",&n);

    printf("Enter the elements from the list: ");

    createList(n,m,p,u);
    PrintList(p);
    printf("\n");

    deleteList(&p);
    PrintList(p);

    return 0;
}

