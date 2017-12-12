#ifndef OBJECT_H
#define OBJECT_H


class OBJECT{
    protected:

        int area;
        int cox,coy;        //position coordinates
        char key;
        int step;           //movement

        void initialize();

    public:

        int getCOX(){
            return cox;
        }

        int getCOY(){
            return coy;
        }

        void Step();
};

#endif
