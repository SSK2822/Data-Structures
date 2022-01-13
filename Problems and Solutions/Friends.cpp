//
//  main.cpp
//  Friends
//
//  Created by shreyash kawle on 14/11/21.
//

//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<int> ranking (30100,0);
//vector<int> parent;
//int maxi = 1;
//
//int root(int r){
//    if(parent.at(r) != r){
//        parent.at(r) = root(parent.at(r));
//    }
//    return parent.at(r);
//}
//
//void friends(int a, int b){
//    int rootA, rootB;
//
//    rootA = root(a);
//    rootB = root(b);
////    cout<<"Root of A: "<<rootA<<" Root of B: "<<rootB<<endl;
//    if(rootA==rootB)
//        return;
//
//    parent.at(rootB) = rootA;
////    cout<<"Rank of A: "<<ranking.at(rootA)<<" Rank of B: "<<ranking.at(rootB)<<endl;
//    ranking.at(rootA) += ranking.at(rootB);
//
//    if(ranking.at(rootA) > maxi)
//        maxi = ranking.at(rootA);
//}
//
//int main() {
//    // insert code here...
//
//    int T,N,M;
//    cin>>T;
//
//
//    while(T-->0){
//        cin>>N>>M;
//        parent.push_back(0);
//        for(int i=1;i<=N;i++){
//            parent.push_back(i);
//            ranking.at(i) = 1;
//        }
//
//        while(M-->0){
//            int f1,f2;
//            cin>>f1>>f2;
//            friends(f1,f2);
//        }
//        cout<<maxi<<endl;
//    }
//
////   for(vector<int>::iterator it = parent.begin(); it!=parent.end(); it++){
////        cout<<*it<<endl;
////    }
//
//    return 0;
//}
/*
 1
 10 12
 1 2
 3 1
 3 4
 5 4
 3 5
 4 6
 5 2
 2 1
 7 10
 1 2
 9 10
 8 9
 */

#include <iostream>
using namespace std;

int ranking [30000] = {0};
int parent[30000];
int maxi = 1;

int root(int r){
    if(parent[r] != r){
        parent[r] = root(parent[r]);
    }
    return parent[r];
}

void friends(int a, int b){
    int rootA, rootB;

    rootA = root(a);
    rootB = root(b);
//    cout<<"Root of A: "<<rootA<<" Root of B: "<<rootB<<endl;
    if(rootA==rootB)
        return;

    parent[rootB] = rootA;
//    cout<<"Rank of A: "<<ranking[rootA]<<" Rank of B: "<<ranking[rootB]<<endl;
    ranking[rootA] += ranking[rootB];

    if(ranking[rootA] > maxi)
        maxi = ranking[rootA];
}

int main() {
    // insert code here...

    int T,N,M;
    cin>>T;


    while(T-->0){
        cin>>N>>M;
//        parent.push_back(0);
        for(int i=1;i<=N;i++){
            parent[i] = i;
            ranking[i] = 1;
        }

        while(M-->0){
            int f1,f2;
            cin>>f1>>f2;
            friends(f1,f2);
        }
        cout<<maxi<<endl;
    }

//   for(vector<int>::iterator it = parent.begin(); it!=parent.end(); it++){
//        cout<<*it<<endl;
//    }
    
    return 0;
}
