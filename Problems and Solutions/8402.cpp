//
//  main.cpp
//  8402
//
//  Created by shreyash kawle on 29/11/21.
//

#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...

    int *arr, n, m, seed;
    priority_queue<int, vector<int>, greater<int>> pqueue;

    cin >> n;
    arr = new int[n+1];
    
    cin >> m;
    cin >> seed;
    unsigned x = seed;
    

    int i=0;
    while(i<n){
        
        x = x^x << 13;
        x = x^x >> 17;
        x = x^x << 5;
        
        int temp = x%m;
        arr[i+1] = ++temp;
        
        i++;
    }

    for (int i = 0; i < n; i++)
        pqueue.push(arr[i+1]);

    while (pqueue.size() != 1){
        int tmp = pqueue.top();
        pqueue.pop();pqueue.pop();
        
        int t = tmp+tmp;
        pqueue.push(t);
        
    }
    cout << pqueue.top() << endl;
    
    return 0;
}

/*
5 10 233
24
 */
//support from GeeksforFeeks XD
