#ifndef USER_H
#define USER_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <user.h>

using namespace std;

// ý use only set and get id and score function for this object which are enough.
class user
{
    private:
        int id;
        int score;

    public:
        user();
        void set_id_score(int a,int b);
        int get_id();
        int get_score();

};
    user::user(){
    }
    void user::set_id_score(int scr,int idd){
        id = idd;
        //cout<<"dad"<<id<<endl;

        score = scr;
    }

    int user::get_id(){

        return id;}
    int user::get_score(){

        return score;}



#endif // USER_H
