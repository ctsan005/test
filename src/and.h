#ifndef AND_H
#define AND_H

#include "container.h"

class And : public Container{
    public:
        
        And(){
            leftChild = NULL;
            rightChild = NULL;
        }
        ~And(){
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
            if(leftChild->run() == true){
                return rightChild->run();
            }
            else{
                return false;
            }
        }
        bool isCommand(){
            return false;
        } 
          
};
#endif
