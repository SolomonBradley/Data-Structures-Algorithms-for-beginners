#include<stdio.h>
#include<stdlib.h>
//Creating a node using Structs
struct Node {
	int data;
	struct Node *next;
};
//Initialising front and back as NULL,if front == back == NULL, Queue is empty
struct Node *front = NULL;
struct Node *back = NULL;

// (1) INSERT an element in a queue - Insertion is always done at Back end [ENQUEUE]
int insert (int x){

//Creating memory for new node	
struct Node *temp =(struct Node*)malloc(sizeof(struct Node));

//Check whether queue is empty	
if(front==NULL)  
        {         
        //If queue is empty, Set the new node as both front and rear
            temp->data = x;  
            temp -> next = NULL; 
            front=temp;
            back=temp;
            front->next = NULL;
            back->next=NULL;
        }   
        else   
        { 
		
		//If queue is not empty ,the new inserting node is updated as rear. 
		
            temp->data = x;  
            temp->next = NULL;
            
            back->next=temp;
            back=temp;
            back->next=NULL;
            
			  
               
        }  
}

//(2) REMOVE elements from front in a queue [DEQUEUE]
int delt(){
	
	struct Node *temp;
//Check whether queue is empty
if (front == NULL)  
    {  
        printf("Queue is empty \n");  
    }  
    else  
    {  //Front value remains same , unless front element is deleted.
       //Then the next value becomes front.
        temp=front;
        
        int item = front->data;  
          
        front = front->next;
		
		free(temp);
		
		 
         
        printf("Item deleted is %d \n", item);  
        return item;
    }  
}

//3 PEEK - To see the front element

void peek(){
    
//Check whether Queue is empty

if(front==NULL){
printf("Queue empty- No elements to display");
}else{
	
printf("Front element is %d \n",front->data);
}
}

//(4) To display all elements in queue

void display(){
    
struct Node *temp;  
    temp=front;  
    if(temp == NULL)  
    {  
        printf("\n\nThe queue is empty\n");  
    }  
    else  
    {  
        printf("The queue elements are \n");  
        printf("This is Front -> ");
        while(temp!=NULL)  
        {  
            printf("%d  ",temp->data);  
            temp = temp->next;  
        }
        printf("->This is Back\n\n");
    }  

}

int main(){
insert(10);
insert(7);
insert(5);
insert(3);
insert(1);
display();
delt();
delt();
display();
peek();
delt();
delt();
delt();
delt();
peek();
return 0;


}

