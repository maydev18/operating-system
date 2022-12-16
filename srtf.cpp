#include <iostream>
using namespace std;
void findWaitingTime(int processes[] , int n , int bt[] , int wt[] , int at[] , int tat[]){
		int t = 0;
		int rembt[n];
		for(int i = 0 ; i<n ; i++) rembt[i] = bt[i];
		while(true){
				int small = 2147483647;
				int index = 0;
				bool over = 1;
				for(int j = 0 ; j<n ; j++){
						if(rembt[j] < small && at[j] <= t && rembt[j]!=0){
								index = j;
								small = rembt[j]; 
								over = 0;
						}
				}
				if(over) break; 
				t++;
				rembt[index]--;
				if(rembt[index] == 0){
						wt[index] = t - at[index] - bt[index];
						tat[index] = wt[index] + bt[index];
					
				}
		}
}
void findAverageTime(int processes[] , int n , int bt[] , int at[]){
		int wt[n] , tat[n] , total_wt = 0 , total_tat = 0;
		findWaitingTime(processes , n , bt ,wt , at , tat);
		cout << "Processes  " <<" Arrival Time " <<  "  Burst Time  " << "  Waiting Time  " << "Turn Around Time" << endl;
		for(int i = 0 ; i<n ; i++){
				total_wt += wt[i];
				total_tat += tat[i];
				cout << "  " << processes[i] << "\t\t" << at[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl; 
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
	int bt[n] , at[n];
	for(int i =0 ; i<n ; i++){
		cout << "Enter the burst time for " << i+1 << " process: ";
		cin >> bt[i];
	}
	for(int i =0 ; i<n ; i++){
		cout << "Enter the arrival time for " << i+1 << " process: ";
		cin >> at[i];
	}
	findAverageTime(processes , n , bt , at);
	return 0;
}


