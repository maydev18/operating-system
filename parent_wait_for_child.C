#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fstream>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	pid_t pid;
	
	pid = fork();
	
	if(pid == -1){
		cout << "cant fork error occured :"<<endl;
		exit(0);
	}
	else if(pid == 0){
		ofstream out;
		out.open("file.dat");
		out << '\n' << "parent of child, pid = " <<getppid();
		out << '\n' << "child process, pid = " << getpid();
		out.close();
		execlp("/bin/ls" , "ls" , NULL);
	}
	else{
		wait(NULL);
		cout << endl << "child complete" << endl;
		cout << endl << "parent of parent process, pid = "<<getppid()<<endl;
		cout << endl << "parent process, pid = " << getpid() << endl; 
	}
	return 0;
}
