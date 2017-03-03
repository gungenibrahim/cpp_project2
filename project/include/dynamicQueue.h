#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H


#include<iostream>
#include<conio.h>


using namespace std;

struct node
{
      int data;
      node *next;
};

class queue
{
      node *rear,*front;

private:
    int Count;
public:
      queue()
      { rear=NULL;front=NULL;Count=0;}
      void Qinsert();
      void Qdelete();
      void Qdisplay();
      int Qempty();
      int Qlength();

      ~queue();
};

int queue::Qempty()
{
    return (Count==0);
}
int queue::Qlength()
{
    return Count;
}
void queue::Qinsert()
{
      node *temp;
      temp=new node;
      cout<<"Data :";
      cin>>temp->data;
      temp->next=NULL;
      if(rear==NULL)
      {
            rear=temp;
            front=temp;
      }
      else
      {
            rear->next=temp;
            rear=temp;
      }
      Count++;
}

void queue::Qdelete()
{
      if(front!=NULL)
      {
            node *temp=front;
            cout<<front->data<<"deleted \n";
            front=front->next;
            delete temp;
            if(front==NULL)
                  rear=NULL;
      }
      else
           {
               cout<<"Queue Empty..";
           }
    Count--;
}

void queue::Qdisplay()
{
      node *temp=front;
      while(temp!=NULL)
      {
            cout<<temp->data<<endl;
            temp=temp->next;
      }
}

queue::~queue()
{
      while(front!=NULL)
      {
            node *temp=front;
            front=front->next;
            delete temp;
      }
}

#endif // DYNAMICQUEUE_H
