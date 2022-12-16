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
	cout << endl << "parent process, pid = "<<getppid()<<endl;
	cout << endl << "process, pid = " << getpid() << endl; 
	return 0;
}
