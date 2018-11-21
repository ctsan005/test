#ifndef OR_H
#define OR_H

#include "container.h"
 
class Or : public Container {
    public:
    
        Or(){
            leftChild = NULL;
            rightChild = NULL;
        }
        ~Or(){
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
            if(leftChild->run() == false){
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
