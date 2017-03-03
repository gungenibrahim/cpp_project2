#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
const int maxsize1 = 50;


class Stack
{
    private:
       int slist[maxsize1];
       int top;
       int average;
       int Count;

    public:
        Stack(void);
        void Push(const int &item);
        void ClearStack(void);
        int Pop(void);

        int Peek(void) const;
        int Saverage(void) const;

        int StackEmpty(void) const;
        int StackFull(void) const;



};

    Stack::Stack():top(-1), average(1500), Count(0){};

    int Stack::StackEmpty(void) const{
        return (top == -1);
    }

    int Stack::StackFull(void) const{
        return(top == maxsize1-1);
    }

    int Stack::Peek(void) const{
        int a = slist[top];
        return a;

    }
    void Stack::Push(const int &item){
        if(StackFull()){
            cerr<<"stack is full!"<<endl;
            exit(1);
        }

        top++;
        slist[top] = item;
        Count++;
        average = (item+ (Count-1)*average)/Count;


    }
    int Stack::Pop(void){
        if(StackEmpty()){
            cerr<<"stack is empty!";
            exit(1);
        }
        int out;
        out = slist[top];

        average = (Count*average-out)/(Count-1);
        Count--;
        top--;
    return out;
    }

    int Stack::Saverage(void) const{
        return average;
    }
    void Stack::ClearStack(void){
    top = -1;
    average = 1500;
    }


#endif // STACK_H
