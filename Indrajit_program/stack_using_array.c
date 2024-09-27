#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int st[MAX],top=-1;
void push(int st[] ,int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);
int main(){
    int val,option;
    do{
        printf("\n\t\t\tMENU\n");
        printf("1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. EXIT");
        printf("\nEnter your choice: ");
        scanf("%d",&option);
        switch(option){
            case 1:
            {
            	printf("Enter the value you want to enter: ");
                scanf("%d",&val);
                push(st,val);
                break;
            }
            case 2:
            {
                val=pop(st);
                if(val!=-1)
                printf("The topmost value %d is deleted!",val);
                break;
            }
            case 3:
            {
                val=peek(st);
                if(val!=-1)
                printf("The topmost element in the stack is %d.",val);
                break;
            }
            case 4:
            {
                display(st);
                break;
            }
        }
    }
        while(option!=5);
    return 0;
}
void push(int st[],int n){
    if (top==MAX-1)
    printf("STACK OVERFLOW!");
    else{
        top++;
        st[top]=n;
        printf("The value has been entered successfully!\n");
    }
}
int pop(int st[]){
    int val;
    if(top==-1){
        printf("STACK IS EMPTY!");
        return -1;
    }
    else{
        val=st[top];
        top--;
        return val;
    }
}
int peek(int st[]){
    int val;
    if(top==-1){
        printf("STACK IS EMPTY!");
        return -1;
    }
    else{
        val=st[top];
        return val;
    }
}
void display(int st[]){
    int i;
    if(top==-1){
        printf("STACK IS EMPTY!");
    }
    else{
        for(i=top;i>=0;i--)
        printf("\n%d",st[i]);
    }
}