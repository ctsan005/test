#ifndef BASE_H
#define BASE_H
 
class Base{
    public:
        Base(){};
        ~Base(){
            delete this;
        };
        virtual bool run() = 0;
};

#endif
