#include <stdio.h>
#include <stdlib.h>

struct queue
{
	int size;
	int f;
	int r;
	int *arr;
};

// Function to check if the queue is empty
int isEmpty(struct queue *q)
{
    return (q->f=q->r-1);
}

// Function to check if the queue is full
int isFull(struct queue *q) 
{
    return q->r == q->size - 1;
}

// Function to add an element to the queue
void enqueue(struct queue *q,int val) 
{
    if (isFull(q)) 
    {
        printf("Queue Overflow\n");
    }
    else 
    {
        if(q->f==-1&&q->r==-1)
        {
            q->r=q->f=0;
        }
        else
        {
            q->r=q->r+1;
        }
        q->arr[q->r] = val;
        printf("Inserted %d\n", val);
    }
}

// Function to remove an element from the queue
int dequeue(struct queue *q) 
{
    int element;
    if (isEmpty(q)) 
    {
        printf("Queue is empty\n");
    } 
    else 
    {
        element = q->arr[q->f];
        q->f=q->f+1;
    }
    return element;
}

// Function to display the elements of the queue
void display(struct queue *q) 
{
    if (isEmpty(q)) 
    {
        printf("Queue is empty\n");
    } 
    else 
    {
        printf("Queue elements are:\n");
        for (int i = q->f-1; i <= q->r; i++)
        {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main() 
{
	struct queue q;
	int n;
	printf("Enter the size of Queue: ");
	scanf("%d",&n);
	q.size=n;
	q.f=q.r=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));
    int f=0;
	do
	{
		printf("\n==============MAIN MENU==============\n\n");
		printf("1. \tENQUEUE OPERATION\t\n");
		printf("2. \tDEQUEUE OPERATION\n");
		printf("3. \tDISPLAY THE QUEUE\n");
		printf("4. \tEnd the program\n");
		printf("\nEnter your choice: ");
		int ch;
        int num;
        int element;
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1:
                printf("Enter number: ");
                scanf("%d",&num);
                enqueue(&q,num);
				break;
			case 2:
				element=dequeue(&q);
                printf("Removed %d\n", element);
				break;
			case 3:
				display(&q);
				break;
			case 4:
				f=1;
				break;
			default:
				printf("Enter your choice again\n");
				break;
		}	
	}while(f==0);
	return 0;
}
