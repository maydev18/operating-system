#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
int main(int argc , char*argv[]){
		if(argc!=3) exit(0);
		ifstream in;
		ofstream out;
		in.open(argv[1]);
		if(!in) exit(1);
		out.open(argv[2]);
		if(!out)exit(1);
		while(!in.eof()){
				char ch = in.get();
				if(!in.eof())
				out << ch ;
		}
		in.close();
		out.close();
}

