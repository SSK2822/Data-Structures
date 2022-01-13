//
//  main.cpp
//  Queue
//
//  Created by shreyash kawle on 15/11/21.
//

#include <iostream>
#include <queue>
using namespace std;


int main() {
    // insert code here...


    int n,a,o,l;
    queue<int> q;
    while(cin>>n){
        int ans=0, cnt=0;
        if(n!=1){
            for (int i = 0; i < n; i++) {
                cin >> a >> o >> l;
                if (q.empty()) {
                    ans = ans + o + a;
                    q.push(ans);
                    cnt++;
                }else{
                    if(a>=q.front()){
                        while(!q.empty() && a >= q.front()){
                            q.pop();
                            cnt--;
                        }
                        if(i == n-1 && (q.empty() || a>q.front())){
                            cout<<a<<endl;
                            break;
                        }else if(i == n - 1 && l >= cnt)
                            cout<<ans<<endl;
                        else if (l >= cnt){
                            if (q.empty())
                                ans = o + a;
                            else
                                ans = ans + o;
                            q.push(ans);
                            cnt++;
                        }
                    }else if (a < q.front()){
                        if (i == n - 1 && l >= cnt)
                            cout << ans << endl;
                        else if (l >= cnt) {
                            if (q.empty())
                                ans = o + a;
                            else
                                ans = ans + o;
                            q.push(ans);
                            cnt++;
                        }
                    }
                    if(l<cnt){
                        if (i == n - 1)
                            cout << "-1" << endl;
                        else
                            continue;
                    }
                }
            }
        }else{
            cin >> a >> o >> l;
            cout << a << endl;
        }
        while(!q.empty())
            q.pop();
    }
    

    return 0;
}



/*
 4
 0 9 0
 7 4 1
 9 3 1
 12 2 2
 */
