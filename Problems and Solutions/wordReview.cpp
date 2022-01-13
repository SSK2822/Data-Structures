//
//  main.cpp
//  WordRevire_UnorderedMap
//
//  Created by shreyash kawle on 16/11/21.
//

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n,m,len1,len2;
    vector<string> ess;
    unordered_set<string> acadAllSet, acadPresSet;
    unordered_map<string, int> dic, w;

    while(cin >> n) {
        
        len1=0; len2=0;
        if(!ess.empty())
            ess.clear();
        acadPresSet.clear();
        acadAllSet.clear();
        
        
        while(n--) {
            string temp;
            cin>>temp;
            acadAllSet.insert(temp);
        }
        
        cin >> m;
        len1 = m;
        while(m--) {
            string a;
            cin >> a;
            if (acadAllSet.find(a) != acadAllSet.end())
                acadPresSet.insert(a);
            
            ess.push_back(a);
        }
        
        len2 = (int) acadPresSet.size();
        if (len2 == 0 || len2 == 1)
            cout << len2 << endl << len2;
        else {
            
            dic.clear(); w.clear();
            for (auto i = acadPresSet.begin(); i != acadPresSet.end(); ++i)
                dic[*i]++;

            int ans[] = {-1, 0, 0};
            int l = 0, r = 0, formed = 0;
            long req = dic.size();

            while (r < ess.size()) {
                w[ess[r]]++;

                if(dic.count(ess[r]) && dic[ess[r]] == w[ess[r]])
                    formed++;

                while(l <= r && formed == req) {
                    w[ess[l]]--;
                    
                    if(dic.count(ess[l]) and dic[ess[l]] > w[ess[l]])
                        formed--;
                    
                    if(ans[0] == -1 || ans[0] > r - l + 1) {
                        ans[0] = r - l +1;
                        ans[1] = l;
                        ans[2] = r;
                    }
                    l++;
                    
                }
                r++;
            }
            if (ans[0] != -1)
                cout << len2 << "\n" << ans[0] << endl;
        }
    }
}



/*
3
analyze
initiates
split
14
when
a
nuclear
reaction
initiates
the
old
uranium
nucleus
will
split
into
two
nuclei
3
analyze
initiates
split
6
i
do
not
love
university
english
------------
 
2
7
0
0
*/


