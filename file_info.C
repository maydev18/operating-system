#include <sys/types.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
using namespace std;

int main(int argc , char * argv[]){
		int i;
		struct stat s;
		if(argc < 2){
				cout << "Enter the file name: " << endl;
				exit(0);
		}
		for(int i = 1 ; i<argc ;i++){
				cout << "file is: " << argv[i] << endl;
				if(stat(argv[i],&s)<0){
							cout << "error in obtaining stats" << endl;
				}
				else{
						cout << "owner UID :" << s.st_uid << endl;
						cout << "group ID: " << s.st_gid << endl;
						cout << "Access permissions : " << s.st_mode << endl;
						cout << "Access time: " << s.st_atime << endl;
						cout << "File size: " << s.st_size << endl;
						cout << "File size in blocks: " << s.st_blksize << endl;
				}
		}
		return 0;
}
