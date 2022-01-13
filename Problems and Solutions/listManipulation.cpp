//
//  main.cpp
//  ListManipulation
//
//  Created by shreyash kawle on 14/11/21.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> table;
static int current;

//static void output();

static void insert(int value, int position){
    current++;
    table.insert(table.begin() + position, value);
}

static void deleteValue(int position){
    table.erase(table.begin() + position - 1);
}

static void reverse(int i, int j){
    reverse(table.begin() + i - 1, table.begin() + j);
}

static void output(int position){
    position--;
    cout<<table.at(position)<<endl;
}


int main() {
    int N, temp;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>temp;
        table.push_back(temp);
    }
        
    current = N;
    int Q;
    cin>>Q;
    for(int i=0; i<Q; i++){
        int choice;
        cin>>choice;
        int a,b;
        switch(choice){
            case 1:
                cin>>a>>b;
                insert(b, a);
                break;
            case 2:
                cin>>a;
                deleteValue(a);
                break;
            case 3:
                cin>>a>>b;
                reverse(a,b);
                break;
            case 4:
                cin>>a;
                output(a);
                break;
            default:
                cout<<"Wrong choice"<<endl;
        }
    }
    
    return 0;
}


/*
6
1 2 3 4 5 6
12
1 3 10
2 1
4 4
3 3 5
4 3
2 2
1 2 7
3 1 4
4 2
2 5
3 2 5
4 4
 */

