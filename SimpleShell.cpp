/* Building a Simple Shell */
/*This simple shell reads user input, splits it into arguments, and then forks a child process to execute
the specified command. The execvp function is used to replace the child process's image with the specified command.
The parent process waits for the child process to finish using waitpid.
*/
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<cstdlib>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;

//Function to split a string into tokens
vector<string> splitString(const string& input, char delimeter){
  vector<string> tokens;
  istringstream tokenStream(input);
  string token;
  while(getline(tokenStream, token, delimeter)){
    tokens.push_back(token);
  }
  return tokens;
}

int main(){
  string input;
  while(true){
    cout<<"Shell> ";
    getline(cin, input);

    if(input == "exit"){
      break; //Exit the Shell
    }
    vector<string> args = splitString(input, ' ');
    
    //Convert args to char* array for execvp
    vector<char*> argv;
    for(const string& arg : args){
      argv.push_back(const_cast<char*>(arg.c_str()));
    }
    argv.push_back(nullptr); //Null-terminate the array

    pid_t pid = fork();
    if(pid == 0){
      //Child Process
      execvp(argv[0], argv.data());
      cerr<<"Error executing command." <<endl;
      exit(EXIT_FAILURE);
    }
    else if(pid > 0){
      //Parent Process
      int status;
      waitpid(pid, &status, 0);
    }
    else{
      cerr<<"Fork failed."<<endl;
      exit(EXIT_FAILURE);
    }
  }
  return 0;
}
