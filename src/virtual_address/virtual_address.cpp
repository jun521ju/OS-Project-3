/**
 * This file contains implementations for methods in the VirtualAddress class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

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

using namespace std;


VirtualAddress VirtualAddress::from_string(int process_id, string address) {
  int page,offset;
  string p=address.substr(0,10);
  string o=address.substr(11,16);
  cout<<"p:"<<p<<endl;
   cout<<"0:"<<o<<endl;
  
  page=binaryTo10(stoi(p));
  offset=binaryTo10(stoi(o));
  return VirtualAddress(process_id, page, offset);
}


string VirtualAddress::to_string() const {
  // TODO: implement me
  return "";
}


ostream& operator <<(ostream& out, const VirtualAddress& address) {
  // TODO: implement me
  return out;
}

int binaryTo10(int n){
    int ans=0;
    for(int i=0 ; n ; i++){
         int t=n%10;
         ans+=t<<i;   
         n/=10;
    }
    return ans;
}