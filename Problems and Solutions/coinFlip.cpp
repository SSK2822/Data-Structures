//
//  main.cpp
//  RecursionCoinFlip
//
//  Created by shreyash kawle on 29/11/21.
//

#include <iostream>
#include <string>
using namespace std;

int rw, cls, ans = 0;
int mtrx[100][10];

int rwC(int row){
    int cnt = 0;
    for(int i=0;i<cls;i++){
            cnt+=mtrx[row][i];
    }
    return cnt;
}

//void Algo(int stage);
void Algo(int stage){
    
    if(stage==cls){
        int cnt = 0;
        for(int i=0;i<rw;i++){
            
            for(int j=0;j<cls;j++){
                cnt+=mtrx[i][j];
            }
            
        }
        int x = cnt;
        for(int i=0;i<rw;i++){
            
            if(rwC(i)<cls/2)
                x+=cls-(2*rwC(i));
            
        }
        
        if(x>ans)
            ans = x;
    }
    
    if(stage<cls){
        stage++;
        Algo(stage);
        
        int tempC = stage;
        tempC-=1;
        for(int i=1;i<=rw;i++){
            
            if(mtrx[i-1][tempC]!=0)
                mtrx[i-1][tempC]=0;
            else
                mtrx[i-1][tempC]=1;
            
        }
        Algo(stage);
    }
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    while(cin>>rw>>cls){
        ans = 0;
        for(int i=0;i<rw;i++){
            string row;
            cin>>row;
            for(int j=0;j<cls;j++){
                mtrx[i][j]=(int)row.at(j)-'0';
            }
        }
        Algo(0);
        cout<<ans<<endl;
    }
    
    return 0;
}

/*
5 4
1010
0101
1010
1010
1010
 */

