//
//  main.cpp
//  819
//
//  Created by shreyash kawle on 21/09/21.
//

#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main() {
    // insert code here...
    
    int n;
    cout<<"enter : ";
    cin>>n;
    
    list <int> arr;
    
    for(int i = 0; i<n; i++) {
        arr.push_back(i+1);
    }

    int eli;
    cin>>eli;
    
    auto start = arr.begin();
    
    while(arr.size() != 1) {
        auto temp = start;
        for (auto itr = ++temp; itr != arr.end(); itr++) {
            advance(itr, eli-1);
            cout<<*itr<<" ";
            arr.erase(itr);
            temp = itr;
           }
        *start = (*(temp)%n);
//        start++;
        cout<<arr.size()<<" - size "<<endl;
        cout<<*start<<endl;
    }
    
    return 0;
}
