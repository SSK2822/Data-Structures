//
//  main.cpp
//  AncientTree
//
//  Created by shreyash kawle on 24/11/21.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <map>

using namespace std;


int main(){
    int T,n,m;
    int in, i=0;
    string temp;

    cin >> T;

    for (int t = 0; t < T; t++){
        int rel = 0;
        cin >> n >> m;
        map<string, int> struc;
        
        i=1;
        while(i <= n){
            temp = "";
            cin >> in;

            while (in != -1){
                temp += to_string(in) + " ";
                struc[temp] += 1;
                cin >> in;
            }
            struc[temp] = -1;
            i++;
        }
        
        
        for (int i = 1; i <= m; i++){
            temp = "";
            cin >> in;

            while (in != -1){
                temp += to_string(in) + " ";
                struc[temp] = 0;
                cin >> in;
            }
        }

        
        string parent = "";

        auto i = struc.begin();
        while(i != struc.end()){
            
            string a = parent;
            string b = (*i).first;
            
            string retrn = "";
            int mn, aL = a.length(), bL = b.length();
            
            if (bL >= aL)
                mn = bL;
            else
                mn = aL;
            
            for (int i = 1; i <= mn; i++){
                if (a[i-1] == b[i-1])
                    retrn += a[i-1];
                else
                    break;
            }
            
            string lca = retrn;
            
            if ((lca.length() != parent.length() &&(*i).second == -1) || (parent.empty() && (*i).second == -1))
                rel++;

            if (((*i).second > 1 && !(lca.length() == parent.length())) || (parent.empty() &&(*i).second > 1))
                static_cast<void>(parent = (*i).first), rel++;
            i++;

        }
        

        cout << rel << endl;
    }
    return 0;
}


/*
2
3 0
2 4 -1
2 3 -1
3 -1
3 1
2 4 -1
2 3 -1
3 -1
2 2 -1
 ----
 2
 3
 */
