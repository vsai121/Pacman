#ifndef MONSTER_H
#define MONSTER_H


class MONSTER : public OBJECT{

    private:

        void *monster , *m[1];
        time_t lastGenerated;

        void initialize(){
            NEXT=0;     //self referential

            cox=20;
            coy=20;
            step=10;
            key=0;
            lastGenerated=0;

            //monster image
            setcolor(WHITE);
            setfillstyle(SOLID_FILL,BLUE);
            sector(685 , 200 , 0 , 180 , 15 , 15);  //head
            bar(670,200,700,230);       //body
            setcolor(BLUE);
            line(671,199,699,199);
            setfillstyle(SOLID_FILL,WHITE);
            fillellipse(680,200,5,10);  //eye
            fillellipse(690,200,5,10);  //eye
            setcolor(WHITE);
            line(670,200,670,230);
            line(700,200,700,230);
            line(670,230,700,230);


            area = imagesize(0, 0, 30 , 45);
            monster = malloc(area);
            getimage(670 , 185 , 700 , 230 , monster);
            putimage(670 , 185 , monster , XOR_PUT);





            m[0]=monster;
        }

    public:

        MONSTER *NEXT;      //self referential class, queue

        MONSTER(){

            initialize();
            putimage(cox , coy , m[0] , COPY_PUT);

        }

        MONSTER(int x, int y){

            initialize();
            cox=x;
            coy=y;
            putimage(cox , coy , m[0] , COPY_PUT);

        }

        ~MONSTER(){

            eraseMonster();
            /*
            if(monster!=0)
                delete monster;
            if(m[0]!=0)
                delete m[0];
            */

        }

        void clearMonster(){

            putimage(cox , coy , m[0] , XOR_PUT);

        }

        void eraseMonster(){

            clearMonster();

        }

        int obstacleUp(){
            int colour=0;
            if((colour=getpixel(cox+15,coy-7))!=BLACK ){ //collided up-centre
                return colour;
            }else if((colour=getpixel(cox,coy-7))!=BLACK ){ //collided up-left
                return colour;
            }else if((colour=getpixel(cox+30,coy-7))!=BLACK ){ //collided up-right
                return colour;
            }else
                return 0;       //0 = no collision
        }

        int obstacleDown(){
            int colour=0;
            if((colour=getpixel(cox+15,coy+55))!=BLACK ){ //collided down-centre
                return colour;
            }else if((colour=getpixel(cox,coy+55))!=BLACK ){ //collided down-left
                return colour;
            }else if((colour=getpixel(cox+30,coy+55))!=BLACK ){ //collided down-right
                return colour;
            }else
                return 0;       //0 = no collision
        }

        int obstacleLeft(){
            int colour=0;
            if((colour=getpixel(cox-5,coy+15))!=BLACK ) //collided left-centre
                return colour;
            else if((colour=getpixel(cox-5,coy))!=BLACK ) //collided left-up
                return colour;
            else if((colour=getpixel(cox-5,coy+45))!=BLACK ) //collided left-bottom
                return colour;
            else
                return 0;       //0 = no collision
        }

        int obstacleRight(){
            int colour=0;
            if((colour=getpixel(cox+37,coy+15))!=BLACK ) //collided right-centre
                return colour;
            else if((colour=getpixel(cox+37,coy))!=BLACK ) //collided right-up
                return colour;
            else if((colour=getpixel(cox+37,coy+45))!=BLACK ) //collided right-bottom
                return colour;
            else
                return 0;       //0 = no collision
        }

        void Step(){       //auto move.... step by 1 frame forward

            {

                if((clock()-lastGenerated)>1000){       //time gap between generating random numbers... 1000 ms
                    key = rand() % 4 + 1;   //random number, 1 to 4...
                    lastGenerated=clock();
                }
                /*
                    up      =   1
                    down    =   2
                    left    =   3
                    right   =   4
                */

                {   //block structured just for style... :P ... K...
                    putimage(cox , coy , m[0] , XOR_PUT);   //erase old image
                    int colour=0;
                    if((key==1) &&  ((colour=obstacleUp())==0 || colour==RED)){             //up, if no obstacle or if obstacle is food
                        coy-=step;

                    }else if((key==2)  &&  ((colour=obstacleDown())==0 || colour==RED)){       //down
                        coy +=step;

                    }else if((key==4)  &&  ((colour=obstacleRight())==0 || colour==RED)){       //right
                        cox +=step;

                    }else if((key==3)  &&  ((colour=obstacleLeft())==0 || colour==RED)){       //left
                        cox -=step;

                    }else if(key==27){                  //Esc(escape) key: Exit
                        //break;
                    }

                    putimage(cox , coy , m[0] , XOR_PUT);   //put new image


                }


            }

        }

};

MONSTER *Front=0,*Rear=0;


void addToQueue(MONSTER &Node){
    if(Front==0){
        Front = Rear = &Node;
        Rear->NEXT=0;
    }else{
        Rear->NEXT= &Node;
        Rear = Rear->NEXT;
        Rear->NEXT=0;
    }
}

void deleteFromQueue(){
    if(Front==0){
        return;
    }else if(Front==Rear){
        MONSTER *t=Front;
        Rear = Front =0;
        delete t;
    }else{
        MONSTER *t=Front;
        Front = Front->NEXT;
        t->NEXT=0;
        delete t;
    }
}

void RefreshQueue(){
    Front=Rear=0;
}

#endif
