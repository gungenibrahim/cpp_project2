#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


// I write this code but ý modified it stackuser class.
using namespace std;

const int maxsize = 50;
template<class T>
class Queue
{
    private:
        int Rear, Front, Count;
        T qlist[maxsize];
    public:
        Queue(void);
        void Qinsert(const T &item);
        T Qdelete(void);
        void ClearQueue(void);
        T Qfront(void) const;


        int Qlength(void) const;
        int Qempty(void) const;
        int Qfull(void) const;
};


    template<class T>
    Queue<T>::Queue(void):Rear(0), Front(0), Count(0){}

    template<class T>
    int Queue<T>::Qlength(void) const{
    return Count;}

    template<class T>
    int Queue<T>::Qempty(void) const{
    return  (Count == 0);}

    template<class T>
    int Queue<T>::Qfull(void) const{
    return (Count == maxsize);}

    template<class T>
    void Queue<T>::Qinsert(const T &item){
        if(Qfull()){
            cerr<<"q is full!!"<<endl;

        }
        Count++;
        qlist[Rear] = item;
        Rear = Rear+1;
    }

    template<class T>
    T Queue<T>::Qdelete(void){
    T temp;
    if (Qempty()){
        cerr<<"empty queue!!"<<endl;

    }
    temp = qlist[Front];
    Count--;
    Front++;
    return temp;

    }





#endif // QUEUE_H
