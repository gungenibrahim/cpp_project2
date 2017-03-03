
#ifndef QUEUEUSER_H
#define QUEUEUSER_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <user.h>



using namespace std;

//this class can be used for a teams but ý dont use, because of the order situations.

const int maxsize3 = 50;
class queueuser
{
    private:
        int Rear, Front, Count;
        int q_id_list[maxsize3];
        int q_score_list[maxsize3];
        int average11;
    public:
        queueuser(void);
        void Qinsert(user &usr);
        user Qdelete(void);
        void ClearQueue(void);
        user Qfront(void) const;


        int Qlength(void) const;
        int Qempty(void) const;
        int Qfull(void) const;
};



    queueuser::queueuser(void):Rear(0), Front(0), Count(0),average11(1500){}


    int queueuser::Qlength(void) const{
    return Count;}


    int queueuser::Qempty(void) const{
    return  (Count == 0);}


    int queueuser::Qfull(void) const{
    return (Count == maxsize3);}

//take inpus as a user
    void queueuser::Qinsert(user &usr){


        if(Qfull()){
            cerr<<"queue is full!!"<<endl;

        }
        Count++;
        int scoreav = usr.get_score();
        average11 = ((Count-1)*average11+scoreav)/(Count);

        q_id_list[Rear] = usr.get_id();
        q_score_list[Rear] = usr.get_score();

        Rear=(Rear+1);

    }


    user queueuser::Qdelete(void){
    user user11;
    char temp;
    if (Qempty()){
        cerr<<"empty queue!!"<<endl;

    }
    int delete_id = q_id_list[Front];
    int delete_score = q_score_list[Front];
    //temp = (char)(delete_id,delete_score);
    //cout<< delete_id <<endl;
    int x = q_score_list[Front];
    //average11 = ((Count)*average11-x)/(Count-1);

    Count--;
    Front++;



    user11.set_id_score(delete_score,delete_id);

    return user11;

    }





#endif // QUEUE_H
