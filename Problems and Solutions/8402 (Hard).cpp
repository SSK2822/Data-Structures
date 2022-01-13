//
//  main.cpp
//  8402(Hard)
//
//  Created by shreyash kawle on 29/11/21.
//

/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 190849
 * Submitted at:  2021-11-29 17:41:04
 *
 * User ID:       1290
 * Username:      56318142
 * Problem ID:    827
 * Problem Name:  8402(Simple ver)
 */

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

int *arr, n, m, seed;
priority_queue<int, vector<int>, greater<int>> pqueue;
int arr_ptr = 1, mrgd_ptr = 0, mrgd_emp = 0;

bool condition(long long int* mrgd){
    return ((mrgd_ptr == mrgd_emp && arr_ptr <= n) || (arr[arr_ptr] <= mrgd[mrgd_ptr] && arr_ptr <= n));
}

int main(int argc, const char * argv[]) {
    // insert code here...

    cin >> n;
    arr = new int[n+1];
    
    cin >> m;
    cin >> seed;
    unsigned x = seed;
    
    int* bkt = new int[m+1]();
    long long int* mrgd = new long long int[n+1]();
    
    int i=0;
    while(i<n){
        
        x = x^x << 13;
        x = x^x >> 17;
        x = x^x << 5;
        
        int temp = x%m;
        arr[i+1] = ++temp;
        
        i++;
    }
    
    for (i = 0; i < n; i++)
        bkt[arr[i+1]]++;
    
    int p = 1;
    
    i=0;
    while(i < m){
        while (bkt[i+1] > 0){
            arr[p] = i+1;
            p++;
            bkt[i+1]--;
            
        }
        i++;
    }

//    for (int i = 0; i < n; i++)
//        pqueue.push(arr[i+1]);

//    while (pqueue.size() != 1){
//        int tmp = pqueue.top();
//        pqueue.pop();pqueue.pop();
//
//        int t = tmp+tmp;
//        pqueue.push(t);
//
//    }
//    cout << pqueue.top() << endl;
    
    long long int least = -1;

    

    for (i = 0; i < n-1; i++){
        
        if (condition(mrgd))
            least = arr[arr_ptr++];
        else
            least = mrgd[mrgd_ptr++];

        if (condition(mrgd))
            arr_ptr++;
        else
            mrgd_ptr++;

        mrgd[mrgd_emp++] = least * 2;
    }
    
    cout << mrgd[mrgd_emp-1] << endl;
    
    return 0;
}

/*
5 10 233
24
5 50 3
48
1000 1000 666
374784
 */
