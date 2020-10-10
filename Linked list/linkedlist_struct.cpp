#include<iostream>
using namespace std;

// Creating the Node using Structs
struct Node {
  double data;
  struct Node *next;
};

// Head pointer declaration
struct Node *head = NULL;
int list_length = 0;

// To supress GCC compiler warnings
// refer this link for more info : 
// https://www.fluentcpp.com/2019/08/30/how-to-disable-a-warning-in-cpp/
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnull-conversion"

//Data Insert Function - At the end
void Insert_At(struct Node *node,int data, int index = NULL)
{
  struct Node *temp = new Node();

  //If list does not exist
  if(head == NULL)
  {
    head = temp;
    temp->data = data;
    temp->next = NULL;
    list_length++;
  }

  //If insertion is at thr first index
  else if(index == 1)
  {
    temp->data=data;
    temp->next=head;
    head = temp;
    list_length++;
  }

  //If index is at the end or the index is more than list length
  else if(index==list_length || index>list_length)
  {
    while(node->next !=NULL)
    {
      node = node->next;
    }
    node->next = temp;
    temp->data = data;
    temp->next = NULL;
    list_length++;
  }

  //If index is in middle
  else
  {
    struct Node *before = node;
    struct Node *after = node->next;
    for(int i=2;i<index;i++)
    {
      before = node->next;
      after = node->next->next;
      node = node->next;
    }
    before->next = temp;
    temp->next = after;
    temp->data = data;
    list_length++;
  }
}

//Generic Insert Function to insert items at the end
void Insert(struct Node* node, int data)
{
  struct Node *temp = new Node();

  if(head == NULL)
  {
    head = temp;
    temp->data = data;
    temp->next = NULL;
    list_length++;
  }

  else{
  while(node->next!=NULL)
  {
    node = node->next;
  }
  temp->data = data;
  temp ->next = NULL;
  node->next = temp;
  list_length++;
  }
}

#pragma GCC diagnostic pop

//Linked List print Fuction
void Print(struct Node *node)
{
  while(node->next!=NULL)
  {
    cout<<node->data<<" ";
    node= node->next;
  }
  cout<<node->data;
  cout<<endl;
}

//Deletion of any element in the List
void Delete(struct Node *node, int data)
{
  struct Node *prev = node;
  
  // If first entry is the deletion node
  if(node->data == data)
  {
    head = node->next;
    delete node;
    list_length--;
    cout<<"Node was Deleted P.S : it was the first Node ;)"<<endl;
  }

  //If middle entry is the deletion node
  else
  {
    int flag=0;
    node= node->next;
    while(node->next!=NULL)
    {
      if(node->data == data)
      {
        prev->next = node->next;
        flag=1;
        list_length--;
        delete node;
        break;
      }
      prev = node;
      node = node->next;
    }
    if (flag==1)
    {
      cout<<"Node was Deleted"<<endl;
    }

    //If last entry is deletion node
    else if(flag ==0)
    {
      if(node->data == data && node->next == NULL)
      {
        prev->next = NULL;
        delete node;
        list_length--;
        cout<<"Node was Deleted P.S : it was the last Node ;)"<<endl;
      }

      //Entry was not found in List
      else 
      {
        cout<<"Could Not Find Entry"<<endl;
      }

    }
  }
}

//size of struct Node - to check after insertions and deletions
void size(struct Node *node)
{
  int count = 0;
  if(node == NULL)
  {
    cout<<"List is empty"<<endl;
  }
  else
  {
    while(node->next!=NULL)
    {
    count++;
    node= node-> next;
    }
    cout<<"Size is "<<++count<<endl;
  }

}

int main()
{
  Insert(head,5);
  Insert(head,10);
  Insert(head,15);
  Insert(head,20);
  Insert(head,25);
  Print(head);
  Insert_At(head,30,3);
  Print(head);
  Insert_At(head,35,6);
  Print(head);
  size(head);
  Delete(head,5);
  Insert_At(head,45,10);
  Print(head);
  size(head);
  return 0;
}