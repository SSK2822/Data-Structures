//
//  main.cpp
//  HuffmanCode
//
//  Created by shreyash kawle on 29/11/21.
//

#include <iostream>
#include <queue>
using namespace std;

int arr[200000][3];

struct node {
    int idx;
    int freq;
    
    node(int x, int y){
        idx = x;
        freq = y;
    }
};



bool operator < (const node& n1, const node& n2){
    int f1 = n1.freq, f2 = n2.freq;
    return f2 < f1;
}


int calcHuffman(int pos, int dist){
    if (arr[pos][1] != -1)
        return calcHuffman(arr[pos][1], dist + 1) + calcHuffman(arr[pos][2], dist + 1);
    else
        return arr[pos][0] * dist;
}



int main(){
    int stringLen;
    while (cin >> stringLen){
        
        priority_queue<node> pqueue;
        int pos = stringLen, i=0;
        
        while(i<stringLen){
            int temp;
            cin >> temp;
            
            node n = node(i, temp);
            pqueue.push(n);
            
            int j=2;
            while(j!=0){
                arr[i][j] = -1;
                j--;
            }
            arr[i][j] = temp;
            
            i++;
        }
        
        bool flg= true;
        while (flg) {
            
            node nd1 = pqueue.top();
            pqueue.pop();
            if (pqueue.empty()) break;
            
            node nd2 = pqueue.top();
            pqueue.pop();
            
            pqueue.push(node(pos, nd1.freq + nd2.freq));
            
            int j=2;
            while(j!=0){
                if(j == 2)
                    arr[pos][j] = nd2.idx;
                else
                    arr[pos][j] = nd1.idx;
                j--;
            }
            arr[pos][j] = nd1.freq + nd2.freq;
            
            pos++;
            
        }
        cout << calcHuffman(--pos, 0) << endl;
    }
}

/*
5
15 7 6 6 5
4
3 4 7 7
6
8 6 5 5 4 3
10
8 1 7 3 6 9 4 2 3 3
 */
