//
//  main.cpp
//  Poker
//
//  Created by shreyash kawle on 14/11/21.
//

#include <iostream>
#include <stack>
using namespace std;

int main() {
    // insert code here...
    
    int test;
    cin>>test;
    while(test-->0){
        stack<int> pocker;
        stack<int> maxOnly;
        
        int num, curMax=0;
        cin>>num;
        
        while(num-->0){
            int temp;
            cin>>temp;
            if(temp>curMax)
                curMax = temp;
            pocker.push(temp);
            maxOnly.push(curMax);
        }
        
        int cmd;
        cin>>cmd;
        while(cmd-->0){
            char op;
            cin>>op;
            
            if(op == 'm')
                cout<<maxOnly.top()<<endl;
            else if(op == 'r'){
                pocker.pop();
                maxOnly.pop();
                if(maxOnly.empty())
                    curMax = 0;
                else
                    curMax = maxOnly.top();
            }
            else if(op == 'a'){
                int a;
                cin>>a;
                pocker.push(a);
                if(a>curMax)
                    curMax = a;
                maxOnly.push(curMax);
            }
        }
        
    }
    
    return 0;
}
