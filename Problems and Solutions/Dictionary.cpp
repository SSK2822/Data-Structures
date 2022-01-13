//
//  main.cpp
//  Strings
//
//  Created by shreyash kawle on 13/11/21.
//

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <set>
#include <algorithm>
#include <string.h>
using namespace std;

set<string> dict;
int main(){
    string s,b;
    while(cin>>s){
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i])){
                s[i]=tolower(s[i]);
            }
            else{
                s[i]=' ';
            }
        }
        stringstream ss(s);
        while(ss>>b){
            dict.insert(b);
        }
    }
    for(set<string>::iterator it=dict.begin();it!=dict.end();it++)
    cout<<*it<<endl;
    return 0;
}
