//
//  main.cpp
//  Customs_Queue
//
//  Created by shreyash kawle on 21/11/21.
//


#include <iostream>
#include <queue>
using namespace std;

int rec[100000] = {0, };


int main() {
    // insert code here...
    
    int n, tem, max=0, cnt=0;
    cin>>n;
    int* out = new int[n];
    
    auto arr = new long long int[n][2];
    queue<int> temp;
    queue<int> idx;
    
    
    int i=0;
    while(i<n){
        
        cin >> arr[i][0] >> arr[i][1];
        for(int j=0; j<arr[i][1]; j++){
            
            cin>>tem;
            if(tem>max)
                max = tem;
            rec[tem]++;
            if(rec[tem] == 1)
                cnt++;
            temp.push(tem);
            
        }
        idx.push(i);
        for(int j=idx.front(); j<=i; j++){
            if (!((arr[i][0] - 86400 < arr[j][0]) && (arr[j][0]) <= arr[i][0])){
                for (int k = 0; k < arr[j][1]; k++){
                    rec[temp.front()]--;
                    if (rec[temp.front()] == 0)
                        cnt--;
                    temp.pop();
                }
                idx.pop();
            }
        }
        out[i] = cnt;
        i++;
    }
    for (int i=0; i<n; i++)
        cout << out[i] << endl;
    
    return 0;
}

/*
3
1 4 4 1 2 2
2 2 2 3
10 1 3
 
 
3
3
4
*/
