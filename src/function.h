#ifndef FUNCTION_H
#define FUNCTION_H
#include <string>
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