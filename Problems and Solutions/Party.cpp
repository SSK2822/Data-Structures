//
//  main.cpp
//  Party(CF)
//
//  Created by shreyash kawle on 13/11/21.
//

#include <iostream>
using namespace std;

int main() {
    // insert code here...
    int t;
    cin>>t;
    while(t>0){
        int temp;
        cin>>temp;
        (temp<=2) ? cout<<0<<endl : cout<<(temp-2)<<endl;
        t--;
    }
    return 0;
}
