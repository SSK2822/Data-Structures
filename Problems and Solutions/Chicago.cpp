//
//  main.cpp
//  DisjoinSetChicago
//
//  Created by shreyash kawle on 22/11/21.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void Joint(int arr[], int x, int y, int n){
    int temp = arr[y];
    if (!temp){
        arr[y] = arr[x];
        return;
    }
    
    for (int i = 0; i < n; i++)
        if (arr[i+1] == temp)
            arr[i+1] = arr[x];
    
}

int main(){
    int n, m, x, y;
    cin >> n;
    cin >> m;

    int* arr = new int[n+1]();
    int* cnt = new int[n + 1]();
    vector<priority_queue<int, vector<int>>> enemy(n+1);

    for (int i = 0; i < n; i++)
        arr[i+1] = i+1;

    for (int i = 0; i < m; i++){
        char sym;
        cin >> sym >> x >> y;

        if (sym == 'E'){
            
            enemy[x].push(y);
            enemy[y].push(x);
            Joint(arr, enemy[x].top(), y, n);
            Joint(arr, enemy[y].top(), x, n);
            
        }else{

            if (x > y)
                Joint(arr, y, x, n);
            else
                Joint(arr, x, y, n);
        }
    }
    
    for (int i = 0; i < n; i++)
        cnt[arr[i+1]]++;

    int max = 0;
    for (int i = 0; i < n; i++)
        if (cnt[i+1])
            max++;

    cout <<max << endl;
    

}


/*
6
4
E 1 4
F 3 5
F 4 6
E 1 2
 */
