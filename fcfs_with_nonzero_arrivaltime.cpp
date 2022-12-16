#include <iostream>
using namespace std;
void findWaitingTime(int processes[] , int n , int bt[] , int wt[] , int at[] , int tat[]){
		wt[0] = 0;
		tat[0] = bt[0];
		for(int i = 1 ; i<n ; i++){
				int sum = tat[i-1] + at[i-1];
				if(sum-at[i]<=0) wt[i] = 0;
				else wt[i] =  sum- at[i];
				tat[i] = wt[i] + bt[i];
		}
}
void sort(int processes[] , int at[] , int bt[] , int n){
		for(int i = 0 ; i<n-1 ; i++){
			for(int j = 0 ; j<n-i-1 ; j++){
				if(at[j]>at[j+1]){
					
					int temp = at[j];
					at[j] = at[j+1];
					at[j+1] = temp;
					
					temp = bt[j];
					bt[j] = bt[j+1];
					bt[j+1] = temp;
					
					temp = processes[j];
					processes[j] = processes[j+1];
					processes[j+1] = temp;
				}
				
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
	sort(processes , at , bt , n);
	findAverageTime(processes , n , bt , at);
	return 0;
	
}

