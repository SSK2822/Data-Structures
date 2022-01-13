//
//  main.cpp
//  Stack
//
//  Created by shreyash kawle on 12/10/21.
//

#include <iostream>
#include <stack>
using namespace std;
long long int arr[100000];

void maxArea(long long int days){
    stack <long long int> grp;
    long long int mxAr = 0, height, curAr, i=0;
    
    while(i<days){
        if(grp.empty() || (arr[grp.top()] <= arr[i]))
            grp.push(i++);
        else{
            height = arr[grp.top()];
            grp.pop();
            if(grp.empty())
                curAr = height*i;
            else
                curAr = height*(i-grp.top()-1);
            if (curAr>mxAr)
                mxAr = curAr;
        }
    }
    while(!grp.empty()){
        height = arr[grp.top()];
        grp.pop();
        if(grp.empty())
            curAr = height*i;
        else
            curAr = height*(i-grp.top()-1);
        if (curAr>mxAr)
            mxAr = curAr;
    }
    cout<<mxAr<<endl;
}


int main() {
    // insert code here...
    int test;
    cin>>test;
    while(test-- > 0){
        long long int n; cin>>n;
        for(long long int i=0;i<n;i++)
            cin>>arr[i];
        maxArea(n);
    }
    
    return 0;
}
