//
//  main.cpp
//  StackShuffling
//
//  Created by shreyash kawle on 23/11/21.
//



#include <iostream>
#include <stack>
#include <queue>
using namespace std;
stack <int> A, S, cA;
queue <int> B;

void Clear(stack<int> temp){
    while(!temp.empty())
        temp.pop();
}

void QClear(queue<int> temp){
    while(!temp.empty())
        temp.pop();
}

void aTos(){
    S.push(A.top());
    A.pop();
    //cout<<"aTos"<<endl;
}
void sTob(){
    S.pop();
    B.pop();
    //cout<<"sTob"<<endl;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int N, i=0;
        cin>>N;
        Clear(A);Clear(cA);Clear(S);
        while(i<N){
            int temp;
            cin>>temp;
            cA.push(temp);
            i++;
        }
        int m;
        cin>>m;
        while(m-->0){
            A= cA;Clear(S);QClear(B);
            for(int i=0;i<N;i++){
//                cout<<"entered"<<endl;
                int a;
                cin>>a;
                B.push(a);
            }
            bool flg = true;
            while(flg){
                if(B.empty()){
                    cout<<"Aye"<<endl;
                    break;
                }
                if((!S.empty())&&(S.top()==B.front())){
                    sTob();
                    continue;
                }

                while((!A.empty())&&(B.front()!=A.top()))
                    aTos();
                if((!A.empty())&&(A.top()==B.front())){
                    aTos();
                    sTob();
                    continue;
                }
                if((S.empty())&&(A.top()!=B.front())){
                    cout<<"Impossible"<<endl;
                    break;
                }
                if((S.top()!=B.front())){
                    cout<<"Impossible"<<endl;
                    break;
                }

                cout<<B.size()<<endl;
            }

        }

    }
    return 0;
}

/*
1
5
1 2 3 4 5
3
1 2 3 4 5
1 5 4 2 3
3 2 1 4 5
 */
//
