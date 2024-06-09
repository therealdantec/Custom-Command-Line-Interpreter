// Custom UNIX/Linux Command Line Interpreter

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <bits/stdc++.h>
#include <cstring>
#include <vector>
#include <unistd.h>

using namespace std;

int main(){

	// declare string for user input
	char EnterCommand[100];
	vector<string> history;
	
	// create while loop so the program can run indefinitely
	while(1){
	
		// create prompt for user to enter a command
		cout << "$Project1: ";
		
		cin.getline(EnterCommand, 100);
		
		
		cout << " " << endl;
		
		string input(EnterCommand);
		
		// if command is 'quit' then exit program
		if (strcmp(EnterCommand, "quit") == 0){
		
			cout<<"LEAVE"<<endl;
			
			exit(0); 
			
		}
		
		// if command includes "cd" then change directory
		if (input.substr(0, 3) == "cd ") { // check if the input starts with "cd "
		
            		string dir = input.substr(3); // extract the directory path
            		
            		if (chdir(dir.c_str()) == 0) { // change the directory using chdir()
            		
                		cout << "Directory changed to " << dir << endl;
                		
            		}
            		
            	}
            	
		// if command is history, print previous commands
		else if (strcmp(EnterCommand, "history") == 0){
		
			for (string command : history) {
			
                		cout << command << endl;
                		
            		}
		
		}
		
		// else, tokenize and execute the command and push back command on the vector
		else {
		
			// include tokenizer to separate commands if there is a semicolon found
			char* token = strtok(EnterCommand, ";");
			
			// increment through user input and use system() to execute the commands found
			while (token != NULL) {
			
				system(token);
				
				token = strtok(NULL, ";");
				
			}
			
		}
		
		history.push_back(EnterCommand);
			
		cout << " " << endl;
		
	}

}