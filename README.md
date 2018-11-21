# Assignment 2 - basic command shell
 
## Introduction
This program we built is a command shell that could take in user input and run like a command shell. It could take in 3 connector, they are ";", "||", and "&&". Each have them have different function.  
For ";", it will run whatever command on its right.  
For "||", it will run the command on the right if and only if the left command fail to run.  
For "&&", it will run the command on the right if and only if the left command success to run.  
A extra command to exit the shell is exit, just type exit would allow you to exit the shell and end the program.  

## Example
For the most basic one,  
if user enter "echo hello", the shell will run and output "hello" at the end.  
if user enter "ls ; echo world has end", the shell will first list all the file and output "world has end".  
if user enter "abc && echo we need to run", the shell will run but this time because the first command does not exist, then the second part would not run which result running nothing.  
if user enter "ls || echo The world is not end yet", the shell will run the first command and list all the file but not run the second command.  
if user enter "exit", the shell would end.  

You can connect more than two command. it does not have number of limit on how many command you can connect together as long as your computer have enough memory.

## Known bug
When enter only '&' or '|', it will think it has complete connector.
