#ifndef CONTAINER_H
#define CONTAINER_H
 
#include "base.h"

class Container : public Base{
    public:
        Base* leftChild;
        Base* rightChild;
        
        virtual void setLeftChild(Base* left) = 0;
        virtual void setRightChild(Base* right) = 0;
        
    
};

#endif
