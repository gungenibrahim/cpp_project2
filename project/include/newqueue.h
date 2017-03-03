#ifndef NEWQUEUE_H
#define NEWQUEUE_H
#include<iostream>
#include<conio.h>
#include<user.h>

// this claas ý have tried to make my queue class dynamic, but ý didnot use is without errors.



using namespace std;

// made a node to connect data as a linklist
struct node1
{
      user data;
      node1 *next;
};

class newqueue
{
      node1 *rear,*front;

private:
    int Count;
public:
      newqueue()
      { rear=NULL;front=NULL;Count=0;}
      void Qinsert(user &usr);
      user Qdelete();
      void Qdisplay();
      int Qempty();
      int Qlength();

      ~newqueue();
};

int newqueue::Qempty()
{
    return (Count==0);
}
int newqueue::Qlength()
{
    return Count;
}
void newqueue::Qinsert(user &usr)
{
      node1 *temp;
      temp=new node1;
      temp->data=usr;

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
      cout<<usr.get_id()<<endl;
}

user newqueue::Qdelete()
{
      if(front!=NULL)
      {
            node1 *temp=front;
            front=front->next;

           return temp->data;
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

void newqueue::Qdisplay()
{
      node1 *temp=front;
      while(temp!=NULL)
      {

            temp=temp->next;
      }
}

newqueue::~newqueue()
{
      while(front!=NULL)
      {
            node1 *temp=front;
            front=front->next;
            delete temp;
      }
}

#endif // NEWQUEUE_H


