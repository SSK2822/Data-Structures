//
//  main.cpp
//  quadTree
//
//  Created by shreyash kawle on 15/11/21.
//

#include <iostream>
#include <cmath>
using namespace std;

int root(int quad[1024][1024], int i0, int j0, int i1, int j1){
    
    int wh =0, blck=0;
    for(int i = i0; i<i1; i++){
        for(int j = j0; j<j1; j++){
            if(quad[i][j]==1)
                blck++;
            else
                wh++;
        }
    }
    
    if((wh==0) || (blck==0))
        return 1;
    else{
        return 1+ root(quad, i0, j0, (i0+i1)/2, (j0+j1)/2)+
        root(quad, (i0+i1)/2, j0, i1, (j0+j1)/2)+
        root(quad, (i0+i1)/2, (j0+j1)/2, i1, j1)+
        root(quad, i0, (j0+j1)/2, (i0+i1)/2, j1);
    }
    
    return 0;
}

int main() {
    // insert code here...
    
    int n;
    while(cin>>n){
        int table[1024][1024]; //as 1<=n<=10
        int i=0;
        n = pow(2, n);
        while(i<n){
            string bin;
            cin>>bin;
            int j=0;
            while(j<n){
                table[i][j] = (int)bin.at(j)-'0';
                j++;
            }
            i++;
        }
        cout<<root(table, 0, 0, n, n)<<endl;
    }
    
    return 0;
}
