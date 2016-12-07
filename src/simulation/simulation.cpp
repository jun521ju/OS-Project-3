/**
 * This file contains implementations for the methods defined in the Simulation
 * class.
 *
 * You'll probably spend a lot of your time here.
 */

#include "simulation/simulation.h"
#include "virtual_address/virtual_address.h"
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
#include <sstream>
#include <vector>
#include <queue>
using namespace std;


void Simulation::run() {
	string filename="./inputs/sim_1";

	int proc_no=getProcNo(filename);
	int rowCount=0;
	string line;

	ifstream in(filename.c_str());

	if(in) {
		while (getline (in, line)) {
			if(line.length()==0)
				continue;
			else{
				rowCount++;//rowCount indicates current row
				if(rowCount>=proc_no+2){
					cout<<line<<endl;
					// spltInputLine(line): split line into pid and v_addr
					VirtualAddress va=VirtualAddress::from_string( stoi(spltInputLine(line).front()), spltInputLine(line).back());
					cout<<va.page<<endl;
					cout<<va.offset<<endl;
					break;
				}
				else{ //process   /inputs/process_id row
				 	if (rowCount==1)
				 		continue;
				 	else{//really begin to process   /inputs/process_id row
				 		
				 	}
				}
			}//else
		}//while (getline (in, line)) {
	}//if(in )
	else{
		cout <<"File not exists." << endl;
	}
}


char Simulation::perform_memory_access(const VirtualAddress& address) {
  // TODO: implement me
  return 0;
}


void Simulation::handle_page_fault(Process* process, size_t page) {
  // TODO: implement me
}

int* strToInt(string line){
	std::string o_str = line;
	std::vector<std::string> str_list;
	int comma_n = 0;
	do
	{
		std::string tmp_s = "";
		comma_n = o_str.find( " " );
		if( -1 == comma_n )
		{
			tmp_s = o_str.substr( 0, o_str.length() );
			str_list.push_back( tmp_s );
			break;
		}
		tmp_s = o_str.substr( 0, comma_n );
		o_str.erase( 0, comma_n+1 );
		str_list.push_back( tmp_s );
	}
	while(true);

	int tmp[str_list.size()];
	int j=0;
	for(unsigned int i=0;i<str_list.size();i++){
			int number;
			stringstream ss;
			ss << str_list[i];
			ss >> number;
			tmp[j]=number;
			j++;
		//cout<<tmp[i]<<endl;
	}
	return tmp;
}

int getProcNo(string filename){
	ifstream in(filename.c_str());
	string line;

	if(in) {
		while (getline (in, line)) {
			if(line.length()==0)
				continue;
			else{
				return strToInt(line)[0];
			}
		}//while (getline (in, line)) {
	}//if(in)
	else
		return 0;
}

vector<string> spltInputLine(string  line){
   	vector<string> strings;
    	istringstream f(line);
    	string s;    
    	while (getline(f, s, ' ')) {
        		// cout << s << endl;
        		strings.push_back(s);
    	}
    	return strings;
 }