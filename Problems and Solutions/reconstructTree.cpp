//
//  main.cpp
//  ReconstructTree
//
//  Created by shreyash kawle on 21/11/21.
//

#include <iostream>
#include <vector>
using namespace std;

int num;

void postOrder(vector<int> pre, vector<int> in, int n){
    int root;
//    cout<<x<<endl;
    for (int i = 0; i < n; i++)
        if (in[i] == pre[0])
            root = i;
//    cout<<root<<" - Root"<<endl;

    if(root!=0){
        vector<int> newpre(pre.begin()+1, pre.begin()+1+root);
        postOrder(newpre, in, root);
    }
    if(root != n-1){
        vector<int> newpre(pre.begin()+1+root, pre.begin()+1+n);
        vector<int> newin(in.begin()+1+root, in.begin()+1+n);
        postOrder(newpre, newin, n-root-1);
    }
    cout<<pre[0];
    if (num != n)
        cout << " ";

}


int main() {
    // insert code here...

    int test, temp, temp1, temp2;
    cin>>test;
    vector<int> preOrder, inOrder;

    while(test-->0){
        preOrder.clear();
        inOrder.clear();
        cin>>num;
        temp1 = num;
        temp2 = num;

        while(temp2-->0){
            cin>>temp;
            preOrder.push_back(temp);
        }
        while(temp1-->0){
            cin>>temp;
            inOrder.push_back(temp);
        }
        
        
        postOrder(preOrder, inOrder, num);
        cout << endl;

    }
    return 0;
}


/*
2
8
1 2 4 7 3 5 6 8
4 7 2 1 5 3 8 6
5
1 2 4 5 3
4 2 5 1 3
*/



