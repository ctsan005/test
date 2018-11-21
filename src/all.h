#ifndef ALL_H
#define ALL_H
 
#include "container.h"

class All : public Container {
    public:
        
        All(){
            leftChild = NULL;
            rightChild = NULL;
        }
        ~All(){
            if(leftChild != NULL){
                delete leftChild;
            }
            if(rightChild != NULL){
                delete rightChild;
            }
        }
        void setLeftChild(Base* left){
            leftChild = left;
        }
        void setRightChild(Base* right){
            rightChild = right;
        }
        bool run(){
            bool temp = leftChild->run();
            if(temp == true){};
            return rightChild->run();
        }
        bool isCommand(){
            return false;
        }
};

#endif
