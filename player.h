#ifndef PLAYER_H
#define PLAYER_H


extern int score , level;
extern const int noLevels;
using namespace std;

class PLAYER{
    public:
        char name[30];
        char passcode[12];
        int step;
        int score[50];         //score of each level
        int level;              //current level user is in. Starts from 1.

        PLAYER (){
            name[0]=0;
            level=1;
            for(int i=0;i<50;i++)
                score[i]=0;
        }

        void create(){
            char temp[12];
            level=1;
            cout<<"NAME: ";
            cin>>name;
            A:
            cout<<"Enter PASSCODE : ";
            cin>>(passcode);
            cout<<"Re-enter PASSCODE :";
            cin>>(temp);
            if(strcmp(temp , passcode)==0)
                cout<<"Your account has been created successfully"<<endl;
             else
             {
                    system("cls");
                    goto A;
             }


        }
        void login()
        {
            cout<<"Enter Your Name: ";
            cin>>name;
            cout<<"Enter Passcode: ";
            cin>>passcode;
        }

        int TotalScore(){
            int sum=0;
            for(int i=0;i<50;i++)
                sum+=score[i];
            return sum;
        }

        void display()
        {
            cout<<"NAME: "<<name<<endl<<endl;
            cout<<"PASSCODE: "<<passcode<<endl<<endl;
            if(level<=noLevels)
                cout<<"LEVEL: "<<level<<endl<<endl;
            else
                cout<<"LEVEL: "<<"Finished All Levels!!!"<<endl<<endl;

            for(int i=0;(i<level && i<noLevels);i++)
                cout<<"SCORE - LEVEL "<<(i+1)<<": "<<score[i]<<endl<<endl;
            cout<<"TOTAL SCORE: "<<TotalScore()<<endl<<endl;
        }

        void incrementLevel(){
            level++;
        }

        void SetScore(int lev){
            score[lev - 1]=::score;
        }

        void SetLevel(){
            level=::level;
        }


};


#endif
