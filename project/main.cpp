// İBRAHİM GÜNGEN
//1936939

#include <iostream>
#include <fstream>
#include <user.h>
#include <stdio.h>
#include <stdlib.h>

#include <queue.h>
#include <stack.h>
#include <stackuser.h>
#include <queueuser.h>
#include <dynamicQueue.h>
#include <newqueue.h>
using namespace std;

//I have tried to make stack and queue dynamic but i have some mistakes and i design static stack and queue object.//
//Also stackuser and ququeusers are my static classes and newqueue is dynamic class whic ý tried.
//I used stack to get teams and used queueuser for queue as well.


int main()

{
    queueuser gamequeue;
    user userall;
    stackuser team1, team2;
    int average1;
    int average2 ;
    int average_bold;
    char output[100];
    int teamssize;
    int id;
    int score;
    int turn = 1;
    int teamsize_count=0;
    int j=0;
    int k=0;


    //taking data and putting appropriate team one by one, if there is a user at the queue and if this user is appropiriate
    // to teams i sen this user nex team.
   int i = 0;
    ifstream inputtxt;
        inputtxt.open("in.txt");


        if (inputtxt.is_open()) {
            inputtxt >> teamssize;

            while (!inputtxt.eof()) {

            average1 = team1.Saverage();
            average2 = team2.Saverage();
            average_bold = (average1+average2)/2;
            //cout<<"average_bold1:"<<average_bold<<" turn:"<<turn<<endl;



            int i = gamequeue.Qlength();


            //team 1 or queue push
            //I started team 1 and is program put a user at the team 1 turn is increase by 1 and is turn is odd
            //team 1 needs to get user, if turn is even next user put in team 2, stackuser and queue  user is take in and
            //take out data as user object.

            if(turn%2==1){
                if(!gamequeue.Qempty()&&((bool)(j<i))){
                    userall = gamequeue.Qdelete();
                    score = userall.get_score();
                    id=userall.get_id();
                    j++;

                    }

            else {  inputtxt >> output;
                    sscanf(output, "%d,%d" , &score, &id );
                    userall.set_id_score(score,id);
                    j=0;    }


        // if statement are designed as given.
                if(team1.StackLength()<teamssize){
                    if(average1<=average_bold){

                        if(score>=average_bold){

                            team1.Push(userall);
                            turn++;

                        }
                        else if(score<average_bold){
                            gamequeue.Qinsert(userall);
                        }
                    }
                    else if(average1>average_bold){
                        if(score<=average_bold){
                            team1.Push(userall);
                            turn++;
                        }
                        else if(score>average_bold){
                            gamequeue.Qinsert(userall);
                        }
                    }
                }
            }

            //team 2 push or push queue from queue or txt
            //when ququw is not empty and users at the queue is not approp.
            //I turn code check until queue size then take data from txt
            else if(turn%2==0){
                    int l= gamequeue.Qlength();//siize of queue
                    if(!gamequeue.Qempty()&&((bool)(l>k))){
                    userall = gamequeue.Qdelete();
                    score = userall.get_score();
                    id=userall.get_id();
            //increment k until queue size
                    k++;

                    }
                    else {
                            inputtxt >> output;
                        sscanf(output, "%d,%d" , &score, &id );
                        userall.set_id_score(score,id);
                        k=0;

                            }
            average1 = team1.Saverage();
            average2 = team2.Saverage();
            average_bold = (average1+average2)/2;

                if(team2.StackLength()<teamssize){
                    if(average2<=average_bold){

                        if(score>=average_bold){
                            team2.Push(userall);
                            turn++;

                        }
                        else if(score<average_bold){
                            gamequeue.Qinsert(userall);
                        }
                    }
                    else if(average2>average_bold){
                        if(score<=average_bold){
                            team2.Push(userall);
                            turn++;
                        }
                        else if(score>average_bold){
                            gamequeue.Qinsert(userall);
                        }
                    }
                }
            }

                    };
            };

  inputtxt.close();

        //normalize the values to take new user without range until given team size, just 1 time.

        int normalize = 0;
          average1 = average1/average_bold*1500;
          average2 = average2/average_bold*1500;
          average_bold = 1500;

        while(!gamequeue.Qempty()&& (!(team1.StackLength()==teamssize)|| !(team2.StackLength()==teamssize))){


            //team 1 or queue push same algorithm before except txt data
            if(turn%2==1){
                    userall = gamequeue.Qdelete();
                    id = userall.get_id();
                    score = userall.get_score();
            //I need to normilize just one before while loop the I take normal average data
                    if(normalize== 1){
                    average1 = team1.Saverage();
                    average2 = team2.Saverage();
                    average_bold = (average1+average2)/2;
                    }
                    userall.set_id_score(score,id);

                if(team1.StackLength()<(teamssize)){
                    if(average1<=average_bold){

                        if(score>=average_bold){

                            team1.Push(userall);
                            turn++;
                        }
                        else if(score<average_bold){
                            gamequeue.Qinsert(userall);
                        }
                    }
                    else if(average1>average_bold){
                        if(score<=average_bold){
                            team1.Push(userall);
                            turn++;
                        }
                        else if(score>average_bold){
                            gamequeue.Qinsert(userall);
                        }
                    }
                }
                normalize = 1;

            }
           ;
            //team 2 push

            if(turn%2==0){
                    userall = gamequeue.Qdelete();
                    id = userall.get_id();
                    score = userall.get_score();

                     if(normalize== 1){
                            average1 = team1.Saverage();
                            average2 = team2.Saverage();
                            average_bold = (average1+average2)/2;
                            }

                    userall.set_id_score(score,id);

                if(team2.StackLength()<teamssize){
                    if(average2<=average_bold){
                        if(score>=average_bold){
                            //cout<<"-----"<<turn<<endl;
                            team2.Push(userall);
                            turn++;
                            //cout<<"team 2 id"<<id<<endl;

                        }
                        else if(score<average_bold){
                            gamequeue.Qinsert(userall);
                        }
                    }
                    else if(average2>average_bold){
                        if(score<=average_bold){
                            team2.Push(userall);
                            turn++;
                        }
                        else if(score>average_bold){
                            gamequeue.Qinsert(userall);
                        }
                    }
                }
          }
          }





            ofstream outputtxt;
            outputtxt.open("out.txt");



            user userdeneme;
                outputtxt<<" "<<endl;
                outputtxt<<"Team 1"<<endl;


               while(!team1.StackEmpty()){
                userdeneme = team1.Pop();
                int a = userdeneme.get_id();
                int b= userdeneme.get_score();
                outputtxt<<b<<","<<a<<endl;
                }

                //average can write the txt if we want uncomment next two lines
                //outputtxt<<"  "<<endl;
                //outputtxt<<"average team 1: "<<team1.Saverage()<<endl;

                outputtxt<<"  "<<endl;
                outputtxt<<"Team 2"<<endl;
              while(!team2.StackEmpty()){
                userdeneme = team2.Pop();
                int a = userdeneme.get_id();
                int b= userdeneme.get_score();

                outputtxt<<b<<","<<a<<endl;
              }
                //average can write the txt if we want uncomment next two lines
                //outputtxt<<"  "<<endl;
                //outputtxt<<"average team 2: "<<team2.Saverage()<<endl;



                 outputtxt<<" "<<endl;
                 outputtxt<<"Waiting Queue"<<endl;


               while(!gamequeue.Qempty()){
                userdeneme = gamequeue.Qdelete();
                int a = userdeneme.get_id();
                int b= userdeneme.get_score();
                outputtxt<<b<<","<<a<<endl;

            }

                outputtxt.close();

    return 0;
}
