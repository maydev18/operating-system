#include <iostream>
using namespace std;
void findWaitingTime(int processes[] , int n , int bt[] , int wt[]){
		wt[0] = 0;
		for(int i = 1 ; i<n ; i++){
			wt[i] = bt[i-1] + wt[i-1];
		}
}
void findTurnAroundTime(int processes[] , int n , int bt[] , int wt[] , int tat[]){
		for(int i = 0 ; i<n ; i++){
			tat[i] = bt[i] + wt[i];
		}
}
void findAverageTime(int processes[] , int n , int bt[]){
		int wt[n] , tat[n] , total_wt = 0 , total_tat = 0;
		findWaitingTime(processes , n , bt ,wt);
		findTurnAroundTime(processes ,  n , bt , wt , tat);
		cout << "Processes  " << "  Burst Time  " << "  Waiting Time  " << "Turn Around Time" << endl;
		for(int i = 0 ; i<n ; i++){
				total_wt += wt[i];
				total_tat += tat[i];
				cout << "  " << i+1 << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl; 
		}
		cout << "average waiting time = " << (float)total_wt/n << endl;
		cout << "average turn around time = " << (float)total_tat/n << endl;
}
int main(){
	int n;
	cout << "enter the number of processes : ";
	cin >>  n;
	int processes[n];
	for(int i =0  ; i<n ; i++) processes[i] = i+1;
	int bt[n];
	for(int i =0 ; i<n ; i++){
		cout << "Enter the burst time for " << i+1 << " process: ";
		cin >> bt[i];
	}
	findAverageTime(processes , n , bt);
	return 0;
	
}
