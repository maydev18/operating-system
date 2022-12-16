/*
I created a class for holes and assigned them random memory addresses in Findhole() constructor.
secondly I created an array of holes and did the basic thing for best , first and worst fit.
Like if a hole is found from 100 to 200 memory address and its size is 100 and we want to assign a process of size 50, so the hole will now truncate from 150 to 200 and will be of size 50 and the memory from 100 to 150 will be assigned to the process.
*/
#include <iostream>
#include <time.h>
using namespace std;
class Hole{
    public:
        int size;
        int starting_location;
        int ending_location;
        Hole(){
            size = 0;
            starting_location = 0;
            ending_location = 0;
        }
        Hole(int sz ,int sl ,int el){
            size = sz;
            starting_location = sl;
            ending_location = el;
        }
};
class Findhole{
    public:
        Hole * holes;
        int n;
        //constructor to initialize the holes array and the data members of each hole
        Findhole(){
            cout << "Enter the number of holes : ";
            cin >> n;
            holes = new Hole[n];
            for(int i = 0 ; i < n ; i++){
                cout << "Enter the size of " << i+1 << " hole " ;
                int sz;
                cin >> sz;
                // generating a random starting location of hole
                int starting_mem = rand()%30;
                if(i != 0) starting_mem = holes[i-1].ending_location + starting_mem;
                holes[i] = Hole(sz , starting_mem , starting_mem + sz);
            }
        }
        //function to display only those holes whose size is greater than 0
        void displayHoles(){
            cout << endl;
            for(int i = 0 ; i < n ; i++){
                if(holes[i].size != 0){
                    cout << i+1 << " hole of size " << holes[i].size <<  "  available from memory " << holes[i].starting_location << " to " << holes[i].ending_location << endl;
                }
            }
            cout << endl;
        }
        void firstFit(int process){
            for(int i = 0  ; i < n ; i++){
                if(holes[i].size >= process){
                    cout << "First fit of size " << holes[i].size << " found, allocating memory " << holes[i].starting_location << " till " << holes[i].starting_location + process << " to the process " << endl;
                    //changing the corresponding hole attributes
                    holes[i].starting_location += process; 
                    holes[i].size -= process;
                    return;
                }
            }
            cout << "Cannot find the space to allocate the process" << endl;
        }
        void bestfit(int process){
            int index = -1;
            //finding an initial fit for process
            for(int i = 0  ; i < n ; i++){
                if(holes[i].size >= process){
                   index = i;
                   break;
                }
            }
            int currsize = holes[index].size;
            int ansindex = index;
            //finding the best fit for process
            for(int i = index+1 ; i<n ; i++){
                if(holes[i].size >= process && holes[i].size < currsize){
                    currsize = holes[i].size;
                    ansindex = i;
                }
            }
            if(index == -1){
                cout << "Cannot find the space to allocate the process: " << endl;
            }
            else{
                cout << "best fit of size " << holes[ansindex].size << " found, allocating  memory " << holes[ansindex].starting_location << " till " << holes[ansindex].starting_location + process << " to the process " << endl;
                //updating corresponding hole attributes
                holes[ansindex].starting_location += process; 
                holes[ansindex].size -= process;
            }
        }
        void worstfit(int process){
            int maxi = 0;
            int index;
            //finding the maximum hole
            for(int i = 0 ; i < n ; i++){
                if(holes[i].size >= maxi){
                    maxi = holes[i].size;
                    index = i;
                }
            }
            if(maxi == 0){
                cout << "Cannot find the space to allocate the process: " << endl;
            }
            else{
                cout << "worst fit of size " << holes[index].size << " found, allocating  memory " << holes[index].starting_location << " till " << holes[index].starting_location + process << " to the process " << endl;
                //changing the corresponding hole attributes
                holes[index].starting_location += process; 
                holes[index].size -= process; 
            }
        }
};
int main(){
    srand(time(NULL));
    Findhole f;
    cout << "Dispaying all holes : ";
    f.displayHoles();
    int n; 
    cout << "enter the number of processes: "; cin >> n;
    for(int i = 0 ; i < n ; i++){
        cout << "Enter the process size for " << i+1 << " process: ";
        int sz; cin >> sz;
        cout << "choose memory allocation method : \n1.First Fit\n2.Best Fit\n3.Worst Fit" << endl;
        cout << "Your choice : ";
        int choice; cin >> choice;
        cout << endl;
        //taking user choice to choose the fit
        if(choice == 1){
            f.firstFit(sz);
        }
        else if(choice == 2){
            f.bestfit(sz);
        }
        else if(choice == 3){
            f.worstfit(sz);
        }
        else{
            cout << "Wrong choice entered , exiting program ";
            exit(100);
        }
        //displaying all holes after assigning process to memory
        f.displayHoles();
    }
}