#ifndef STACKUSER_H
#define STACKUSER_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <user.h>

using namespace std;
const int maxsize2 = 50;


class stackuser
{
    private:
       int Sidlist[maxsize2];
       int Sscorelist[maxsize2];
       int top;
       int average_score;
       int Count;

    public:
        stackuser(void);
        void Push(user &usr);
        void ClearStack(void);
        user Pop(void);

       // int Peek(void) const;  not need
        int Saverage(void) const;

        int StackEmpty(void) const;
        int StackFull(void) const;
        int StackLength(void) const;
        void averageOut(void);


};

    stackuser::stackuser():top(-1), average_score(1500), Count(0){};
    int stackuser::StackLength(void) const{
        return Count;
    }

    int stackuser::StackEmpty(void) const{
        return (top == -1);
    }

    int stackuser::StackFull(void) const{
        return(top == maxsize-1);
    }

    void stackuser::Push(user &usr){
        if(StackFull()){
            cerr<<"stack is full!"<<endl;
            exit(1);
        }

        top++;
        Sidlist[top] = usr.get_id();
        Sscorelist[top] = usr.get_score();
        int item = Sscorelist[top];
        Count++;
        // I take the average all users score after adding the score.
        average_score = (item+ (Count-1)*average_score)/Count;


    }
   user stackuser::Pop(void){
       user user12;
        if(StackEmpty()){
                //not need to next line so ı just comment
            //cerr<<"stack is empty!";
            exit(1);
        }

        int id_out = Sidlist[top];
        int score_out = Sscorelist[top];
        Count--;
        top--;
        user12.set_id_score(score_out , id_out);
    return user12;
    }
                              //İMPORTANT

// WHEN USERS ARE OUT OF THE GAME WE SHOULD USE THIS FUNCTİON TO GET AVERAGE

    void stackuser::averageOut(void){
        int score_out = Sscorelist[top];
        average_score = (Count*average_score-score_out)/(Count-1);
    }


    int stackuser::Saverage(void) const{
        return average_score;
    }
    void stackuser::ClearStack(void){
    top = -1;
    average_score = 1500;
    }


#endif // STACK_H
