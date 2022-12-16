
#include <iostream>
using namespace std;
void findWaitingTime(int processes[] , int n , int bt[] , int wt[] , int at[] , int quantum){
		int rem_bt[n];
		for(int i = 0 ; i<n ; i++) rem_bt[i] = bt[i];
		int t = 0;
		while(1){
				bool done = true;
				for(int i = 0 ; i<n ; i++){
						if(rem_bt[i] > 0 && at[i] <= t){
								done = false;
								if(rem_bt[i] > quantum){
										t += quantum;
										rem_bt[i] -= quantum;
									
								}
								else{
										t += rem_bt[i];
										wt[i] = t - bt[i] - at[i];
										rem_bt[i] = 0;
								}
						}
				}
				if(done == true) break;
			
		}
}

void findTurnAroundTime(int n , int bt[] , int wt[] , int tat[]){
		for(int i = 0 ; i<n ; i++){
				tat[i] = bt[i] + wt[i];
		}
}
void findAverageTime(int processes[] , int n , int bt[] , int at[] , int quantum){
		int wt[n] , tat[n] , total_wt = 0 , total_tat = 0;
		findWaitingTime(processes , n , bt ,wt , at , quantum);
		findTurnAroundTime(n , bt , wt , tat);
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
	int bt[n],at[n];
	for(int i =0 ; i<n ; i++){
		cout << "Enter the burst time for " << i+1 << " process: ";
		cin >> bt[i];
	}
	for(int i =0 ; i<n ; i++){
		cout << "Enter the arrival time for " << i+1 << " process: ";
		cin >> at[i];
	}
	int quantum;
	cout << "Enter the time quamtum : ";
	cin >> quantum;
	findAverageTime(processes , n , bt , at, quantum);
	return 0;
	
}
