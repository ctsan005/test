#ifndef COMMAND_H
#define COMMAND_H

#include "base.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>
 


class Command : public Base{
    public:
        // std::string operation;
        char* operation;
        // char* cstr;
        
    public:
        Command() : operation(NULL){};
        // ~Command(){
        //     if(cstr != NULL){
        //         delete cstr;
        //     }
        // }
        
        Command(char* temp): operation(temp){};
        
        bool run();
        
        bool isCommand(){
            return true;
        }
        
        
};

#endif
