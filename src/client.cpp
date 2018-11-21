#include "client.h"


void Client::createTree(){//cut the long commend line into different node of the tree
        
        

    // pch = strtok (cstr,"#");
            
        
        
    cstr = new char [fullCommand.length()+1];
    char* temp;
    strcpy (cstr, fullCommand.c_str());
    temp = strtok (cstr, "#");
            // std::cout << temp;
            
    std::vector<char> connector;
    for(int i = 0; i < fullCommand.length() - 1; ++i){//scan the full command to see what connector is there
        if(temp[i] == '\0'){
            // std::cout << "hello";
        }
        else if(temp[i] == ';'){
            connector.push_back('A');//ALL connector
        }
        else if(temp[i] == '|'){
                     
            connector.push_back('B');//OR connector
            ++i;
                    
                    
        }
        else if(temp[i] == '&'){
            // if(cstr[i+1] == '&'){
                    
            connector.push_back('C');//AND connector
            ++i;
            // }
            // std::cout << "check";
        }
    }
            
            
    std::vector<Container*> indexConnector;
    for(int i = 0; i < connector.size(); ++i){//from the last scan, build the connector
        if(connector.at(i) == 'A'){
            indexConnector.push_back(new All());
        }
        else if(connector.at(i) == 'B'){
            indexConnector.push_back(new Or());
        }
        else if(connector.at(i) == 'C'){
            indexConnector.push_back(new And());
        }
    }
            
    std::vector<char*> listOp;
    char * pch;
    pch = strtok (temp,"|&;");
    while (pch != NULL){
            
        //printf ("%s\n",pch); //print for test, take it out later
        if(pch != ""){
            listOp.push_back(pch);
            pch = strtok (NULL, "|&;");//continue cutting the string if needed
        
        }
    }
            
            
            
            
        ////////////////3 base case//////////////
    
    if(listOp.size() == 1){//when there is only one command without any connector
        tempTree = new Command(listOp.at(0));
        return;
    }
    else if(listOp.size() == 0){//when the command is empty
        return;
    }
    else{//when there is connector
        indexConnector.at(0)->setLeftChild(new Command(listOp.at(0)));
        indexConnector.at(0)->setRightChild(new Command(listOp.at(1)));
            
        for(int i = 2; i < listOp.size(); ++i){
            indexConnector.at(i - 1)->setLeftChild(indexConnector.at(i - 2));
            indexConnector.at(i - 1)->setRightChild(new Command(listOp.at(i)));
        }
        tempTree = indexConnector.at(indexConnector.size() - 1);
    }
            
            
            
            
}