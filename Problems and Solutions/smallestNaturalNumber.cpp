//
//  main.cpp
//  Hash_SmallestNatural
//
//  Created by shreyash kawle on 24/11/21.
//

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...

    int n,temp;
//    cin>>n;

    while(cin>>n){
        set<int> Hash;
        int arr[n+1];
        

        for(int i=0; i<n; i++){
            cin>>temp;
    //        Hash.insert(temp);
            arr[i] = temp;
        }

        sort(arr, arr+n);
    //    while(Hash.find(res) != Hash.end())
    //        res++;
        set<int>::iterator itr;
        int j=0;
    //    for (itr = Hash.begin(); itr != Hash.end();){
        for(j=0;j<n;j++){
    //        cout<< *Hash.begin()<<" ";
    //        temp = *itr;
    //        advance(itr, 1);
            
            if(j == 0 && arr[j] != 0){
                cout<<0<<endl; break;
            }
            else if(j == n-1){
                cout<<n<<endl; break;
            }else if(arr[j] - arr[j-1] >1){
                cout<<arr[j-1]+1<<endl; break;
            }
        }
    }
    

    return 0;
}

/*
11
10 1 4 11 5 9 2 4 6 0 1
10, 1, 4, 11, 5, 9, 2, 4, 6, 0, 1
4
3 2 1 0
2
1 2
*/


