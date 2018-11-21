#ifndef CLIENT_H
#define CLIENT_H

#include "base.h"
#include "command.h"
#include "all.h"
#include "and.h"
#include "or.h"
#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <iostream>
#include <vector>







class Client{
    
    public:
        std::string fullCommand;
        Base* tempTree;
        char* cstr;
        
    public:
    
        Client(): fullCommand(""), tempTree(NULL){}
        Client(std::string temp): fullCommand(temp), tempTree(NULL){}
        
        void createTree();
        
        void destoryTree(){//destory the tree to prevent memory problem
            if(tempTree != NULL){
                delete tempTree;
            }
            return;
        }
        
        bool checkExit(){//have the ability to get out from the commend shell
            if(fullCommand == "exit"){
                // exit(0);
                return true;
            }
            else{
                return false;
            }
        }
        
        bool runTheCommand(){// run the tree from the top
            if(tempTree != NULL){
                return tempTree->run();
            }
            else{
                return false;
            }
        }
        
    
};




void runShell(){
    std::string fullCommand;
    bool done = false;
    
    while(done != true){
        std::cout << "$";
        getline(std::cin, fullCommand );
        Client* user = new Client(fullCommand);
        done = user->checkExit();
        if(!done){
            user->createTree();
            user->runTheCommand();
            user->destoryTree();
        }
    }
}
#endif
