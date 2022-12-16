#include <pthread.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
int sum;
void *runner(void * param){
	int i , upper = atoi((char *)param);
	sum = 0;
	for(int i = 1 ; i<=upper ;  i++){
		sum += i;
	}
	pthread_exit(0);
}
int main(int argc , char * argv[]){
	pthread_t tid;
	pthread_attr_t attr;
	if(argc!=2){
		cout << "please provide the number: "<< endl;
		return -1;
	}
	if(atoi(argv[1])<0){
		cout << "n must be greater than 0"<<endl;
		return -1;
	}
	pthread_attr_int(&attr);
	pthread_create(&tid , &attr ,runner , argv[1]);
	pthread_join(tid , NULL)// process waits for thread to finish and whatever thread returns is stored in the second variable. Here it is null which means that thread will not return anything
	cout << "sum: " << sum << endl;
}
