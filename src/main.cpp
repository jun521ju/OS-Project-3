/**
 * This file contains the main() function that drives the simulation. You'll
 * need to add logic to this file to create a Simulation instance and invoke its
 * run() method.
 */
 #include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <getopt.h>
#include <string.h>
#include <queue>
#include <limits>
#include <unistd.h>
 

#include "simulation/simulation.h"
using namespace std;

int vflag;
int max_frames;

int argvHelper(int argc, char* argv[]);
int txtFileRead(string filename);


int main(int argc, char** argv) {

// VirtualAddress v=VirtualAddress(1,9,0);
// v.from_string(0,"000011110111111111");


	// txtFileRead("1");
 Simulation sm;
 sm.run();

 
	// string algo;
	// for(int i=0;i<argc;i++){
	// 		char txt[]="FIFO";
	// 		char txt1[]="LRU";
			 
	// 		if(strstr(argv[i],txt)!=NULL){
	// 			string tmp(argv[i]);
	// 			algo =tmp;
	// 			break;
	// 		}
	// 		if(strstr(argv[i],txt1)!=NULL){
	// 			string tmp(argv[i]);
	// 			algo =tmp;
	// 			break;
	// 		}
	// 	}

	// if(argvHelper(argc,argv)==0){ //if 0,exit.
	// 	cout<<"Arguments Error."<<endl;
	// 	return 0;
	// }

	// if(algo=="FIFO"){}
	// 	//fcfs(p);
	// else if(algo=="LRU"){}
	// 	//rr(p);
	// else{}
	// 	//fcfs(p);

	return 0;
}

int argvHelper(int argc, char* argv[]){

	const struct option longopts[] = {
		{"max-frames",   no_argument,         0, 'f'},
		{"strategy",      no_argument,        0, 's'},
		{"verbose",     no_argument,  	      0, 'v'},
		{"help",         no_argument,         0, 'h'},
		{0,0,0,0},
	};

	int index;
	int iarg=0;
	opterr=1;


	while(iarg != -1){
		iarg = getopt_long(argc, argv, "f:svh", longopts, &index);
		switch (iarg)
		{
		  case 'f':
			  vflag=true;break;
		  case 'v':
			  vflag=true;break;
		  case 's':
			break;
		  case 'h':
			cout<<"-v, --verbose\n"
			"Output information about every memory access.\n"
			"-s, --strategy (FIFO | LRU)\n"
			"The replacement strategy to use. One of FIFO or LRU.\n"
			"-f, --max-frames <positive integer>\n"
			"The maximum number of frames a process may be allocated.\n"
			"-h --help\n"
			"Display a help message about these flags and exit\n"<<endl;
			break;
		}
	}

	for (int i = optind; i < argc; i++) {
	 //   cout << "non-option arg: " << argv[j] << std::endl;
	}

	for(int i=0;optind<argc;i++,optind++){
		if(i>=1)
			return 0;
	}

	for(int i=0;i<argc;i++){
		char txt[]=".txt";
		if(strstr(argv[i],txt)!=NULL){
			string tmp(argv[i]);			
		}
	}
	return 1;
}
int txtFileRead(string filename){
	filename="./inputs/sim_1";


	ifstream in(filename.c_str());
	string line;


	if(in) {
		while (getline (in, line)) {
			if(line.length()==0)
				continue;
			else
				cout<<line<<endl;
		}//while (getline (in, line)) {
	}//if(in)
	else{
		cout <<"File not exists.By defualt, you can run ./simulator example.txt" << endl;
		return 0;
	}
	return 1;
  }



