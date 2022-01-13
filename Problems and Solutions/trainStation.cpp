//
//  main.cpp
//  TrainStation
//
//  Created by shreyash kawle on 30/11/21.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 0x7fffffff
using namespace std;
int trn[1024];
bool available[1024];
int stations[1024];


//
//int n, m,k;
//bool different = true;
//int start, stop;
//
//void logic(int q, int* visit, int* last_visit, int* rank){
//    if (q != 0){
//        different = false;
//        for (int i = start; i <= stop; i++){
//            if ( visit[i] && !last_visit[i])
//                different = true;
//        }
//
//        if (different)
//            for (int i = start; i <= stop; i++)
//                if (visit[i])
//                    last_visit[i]++;
//
//    }else
//        for (int i = start; i <= stop; i++)
//            if (visit[i])
//                last_visit[i]++;
//
//
//    if (different)
//        for (int i = start + 1; i < stop; i++)
//            if (!visit[i])
//                rank[i]++;
//
//}


int main() {
    memset(stations, 0, sizeof(stations));
    int n, m;
    cin >> n >> m;
    vector<vector<int>> trnSts(n + 5);
    vector<vector<bool>> last_visit(n + 5, vector<bool>(n + 5));
    for (int i = 1; i <= n; i++) {
        fill(last_visit[i].begin(), last_visit[i].end(), 0);
    }
    for (int i = 0; i < m; i++) {
        memset(available, 0, sizeof(available));
        
        int trains;
        cin >> trains;
        vector<int> arr(trains);
        for (int j = 0; j < trains; j++) {
            cin >> arr[j];
            available[arr[j]] = 1;
        }
        int bgn = arr[0];
        int en = arr[trains - 1];
        for (int j = bgn; j < en; j++)
            if (available[j] != true)
                for (int k = 0; k < trains; k++)
                    if (last_visit[j][arr[k]] != true) {
                        last_visit[j][arr[k]] = 1;
                        trnSts[j].push_back(arr[k]);
                        stations[arr[k]]++;
                    }
                
            
        
    }
    queue <int> track;
    for (int i = 1; i <= n; i++) {
        if (stations[i] != 0) {
            trn[i] = INF;
        }else {
            track.push(i);
            trn[i] = 0;
           
        }
    }
    int rank = 0;
    while (!track.empty()) {
        int t1 = track.front();
        track.pop();
        rank = max(rank, trn[t1]);
        int statrank = trnSts[t1].size();
        for (int i = 0; i < statrank; i++) {
            stations[trnSts[t1][i]]--;
            if (stations[trnSts[t1][i]] == 0) {
                trn[trnSts[t1][i]] = min(trn[trnSts[t1][i]], trn[t1] + 1);
                track.push(trnSts[t1][i]);
            }
        }
    }
    cout << rank + 1 << "\n";
}

//
//int main(){
//
//    cin >> n >> m;
//
//    int* rank = new int[n+1]();
//    int* last_visit = new int[n+1]();
//
//    for (int q = 0; q < m; q++){
//        different = true;
//        cin >> k;
//
//        int* visit = new int[n+1]();
//
//        for (int i = 0; i < k; i++){
//            int temp;
//            cin >> temp;
//
//            if (i == k - 1)
//                stop = temp;
//
//            if (i == 0)
//                start = temp;
//
//            visit[temp]++;
//        }
//
//        logic(q,visit, last_visit, rank);
//
//    }
//    int max = 0;
//    for (int i = 1; i <= n; i++)
//        if (rank[i] > max)
//            max = rank[i];
//
//    cout << ++max << endl;
//
//    return 0;
//}
/*
9 2
4 1 3 5 6
3 3 5 6
----
 2
 
9 3
4 1 3 5 6
3 3 5 6
3 1 5 9
 -----
 3
 
 10 8
 3 1 2 3
 3 1 3 5
 3 7 8 9
 4 1 3 5 6
 3 3 5 6
 3 1 5 9
 5 4 5 6 7 9
 3 1 5 10
 -------
 5
 */
