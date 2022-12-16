#include <iostream>
#include <stdlib.h>
using namespace std;
int main(){
	cout << endl << "The kernel version is : " << endl;
	system("cat /proc/sys/kernel/osrelease");
	cout << endl << "The cpu space :  "<< endl;
	system("cat /proc/cpuinfo | awk 'NR==3,NR==4{print}'\n");
	cout << endl << "amount of cpu time since system was last booted"<<endl;
	system("cat /proc/uptime");
	cout << endl << "the configured memory is "<< endl;
	system("cat /proc/meminfo | awk 'NR==1 {print $2}' \n");
	cout << endl << "Amount of free memory is :" << endl;
	system("cat /proc/meminfo | awk 'NR==2 {print $2}' \n");
	cout << endl << "Amount of used memory: "<< endl;
	system("cat /proc/meminfo | awk '{if(NR==1) a = $2 ; if(NR==2) b = $2;} END {print a-b}' \n");
	return 0;
}
