#include "command.h"

bool Command::run(){//run the operation, if it does not run correctly, return false
    int status = 0;

    std::vector<char*> list;
            
    pid_t pid = fork();
    if(pid < 0){
        perror("fork");
    }
    if(pid == 0){//child, run the command
        // cstr = new char [operation.length()+1];
        // strcpy (cstr, operation.c_str());
                
        //char* str[] = operation;
        char * pch;
        //printf ("Splitting string \"%s\" into tokens:\n",cstr);
        pch = strtok (operation," ");
        while (pch != NULL){
            //printf ("%s\n",pch); //print for test, take it out later
            list.push_back(pch);
            pch = strtok (NULL, " ");//continue cutting the string if needed
        }
                
                
                
        char* args[list.size() + 1];
        for(unsigned i = 0; i < list.size(); ++i){
            args[i] = list.at(i);
        }
        args[list.size()] = NULL;
                
        if(execvp(args[0], args) == -1){
            perror("execvp");
            // kill(pid, SIGTERM);
            abort();
        }
                
                
    }

            
    if(pid >0){//parent
        wait(&status);
        if(WIFEXITED(status) == false){ //if child fail to run the command
    
           //printf("Children faile to run and return false\n");
           return false;
        }
        else{
               
            return true;
        }
    }
            // perror("too far");
    return false;
}