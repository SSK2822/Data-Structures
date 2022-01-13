//
//  main.cpp
//  List_CardShuffle
//
//  Created by shreyash kawle on 29/11/21.
//

#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> deck;
    int test_cases;
    cin >> test_cases;
    
    while (test_cases-->0) {
        deck.clear();
        
        int inst;
        cin >> inst;
        
        while (inst-->0) {
            char cmd;
            cin >> cmd;
            
            if (cmd == 'R'){
                char sym;
                cin >> sym;
                
                if (sym == 'H')
                    deck.erase(deck.begin());
                else
                    deck.pop_back();
            }
            
            else if (cmd == 'I'){
                char sym;
                cin >> sym;
                
                int value;
                cin >> value;
                
                if (sym == 'H')
                    deck.insert(deck.begin(), value);
                else
                    deck.push_back(value);
            }
            
            else {
                int pos;
                cin >> pos;
                
                for (auto i:deck){
                    if (pos == 1){
                        cout << i << endl; break;
                    }
                    else
                        pos--;
                }
            }
        }
    }
    
    return 0;
}
