//
//  main.cpp
//  855
//
//  Created by shreyash kawle on 29/11/21.
//

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    int size;
    int height;

    Node* lson;
    Node* rson;


    Node(int data) {
        this->data = data;
        size = 1;
        height = 1;
        lson = NULL;
        rson = NULL;
    }

    void update() {
        size = (lson ? lson->size : 0) + (rson ? rson->size : 0) + 1;
        height = max(lson ? lson->height : 0, rson  ? rson->height : 0) + 1;
    }
    
    Node* rotateR() {
        Node* x = lson;
        lson = lson->rson;
        x->rson = this;
        this->update();
        x->update();
        return x;
    }

    Node* rotateL() {
        Node* x = rson;
        rson = rson->lson;
        x->lson = this;
        this->update();
        x->update();
        return x;
    }

    
};

class AVL {
public:
    Node* root;
    int size;

    AVL() {
        root = NULL;
    }


    // Supporting Functions

    Node* smallestNode(Node* t) {
        Node* tmp = t;
        while (tmp->lson != NULL) {
            tmp = tmp->lson;
        }
        return tmp;
    }

    int getBalance(Node* root) {
        return (root->lson != NULL ? root->lson->height : 0) - (root->rson != NULL ? root->rson->height : 0);
    }

    // Operations

    //Insert

    Node* insert(Node* t, int data) {
        if (t == NULL)
            return (new Node(data));

        if (data <= t->data)
            t->lson = insert(t->lson, data);
        else if (data > t->data)
            t->rson = insert(t->rson, data);

        int balance = (t->lson != NULL ? t->lson->height : 0) - (t->rson != NULL ? t->rson->height : 0);

        t->update();
        
        if (balance <= -2){
            if (data > t->rson->data)
                return t->rotateL();
            else if (data < t->rson->data){
                t->rson = t->rson->rotateR();
                return t->rotateL();
            }
        }


        if (balance >= 2){
            if (data < t->lson->data)
                return t->rotateR();
            else if (data > t->lson->data){
                t->lson = t->lson->rotateL();
                return t->rotateR();
            }
        }

        return t;
    }
    
    void Insert(int x) {
        root = insert(root, x);
    }

    //Delete

    Node* deleteNode(Node* p, int x) {
        if (p == NULL) return p;

        if (x < p->data)
            p->lson = deleteNode(p->lson, x);
        else if (x > p->data)
            p->rson = deleteNode(p->rson, x);
        else {
            if (p->lson == NULL || p->rson == NULL) {
                Node* temp = p->lson ? p->lson : p->rson;
                if (temp == NULL){
                    temp = p;
                    p = NULL;
                }else{
                    *p = *temp;
                }

                free(temp);
            }else {
                Node* temp = smallestNode(p->rson);
                p->data = temp->data;
                p->rson = deleteNode(p->rson, temp->data);
            }
        }

        if (p == NULL) return p;

        int balance = getBalance(p);
        p->update();

        if (balance >= 2){
            if (getBalance(p->lson) >= 0)
                return p->rotateR();
            else{
                p->lson = p->lson->rotateL();
                return p->rotateR();
            }
        }

        if (balance <= -2){
            if (getBalance(p->rson) <= 0)
                return p->rotateL();
            else{
                p->rson = p->rson->rotateR();
                return p->rotateL();
            }
        }

        return p;
    }
    
    void Delete(int x) {
        root = deleteNode(root, x);
    }

    //Order

    int order(Node* p, int x) {
        
        if (p == NULL)
            return 1;
        
        if (p->data >= x)
            return order(p->lson, x);
        
        else
            return (p->lson != NULL ? p->lson->size : 0) + order(p->rson, x) + 1;
    }

    void Order(int x) {
        cout << order(root, x) << endl;
    }
    
    // nth smallest number
    int nodeAtOrder(int i) {
        Node* tmp = root;

        int left = 0;
        if (tmp->lson != NULL) left = tmp->lson->size;
        else left = 0;

        while (left != i) {
            if (left < i) {
                i -= left + 1;
                tmp = tmp->rson;

                if (tmp->lson) left = tmp->lson->size;
                else left = 0;
            } else {
                tmp = tmp->lson;

                if (tmp->lson) left = tmp->lson->size;
                else left = 0;
            }
        }

        return tmp->data;
    }
    void Minimum(int x) {
        cout << nodeAtOrder(x - 1) << endl;
    }

    // Precursor
    int precursor(int x) {
        Node* p = root;
        int cnt = (p->lson ? p->lson->size : 0);

        while (p) {
            if (p->data >= x) {
                if (p->lson != NULL)
                    cnt -= p->lson->size;

                p = p->lson;

                if (p != NULL) {
                    if (p->lson != NULL) {
                        cnt += p->lson->size;
                    }
                }else{
                    cnt--;
                }
            }else {
                cnt += p->rson ? 1 : 0;

                p = p->rson;
                if (p != NULL) {
                    if (p->lson != NULL) {
                        cnt += p->lson->size;
                    }
                }
            }
        }
        
        return cnt;
    }
    
    void Precursor(int x){
        cout << nodeAtOrder(precursor(x)) << endl;
    }

    // Successor

    int successor(int x) {
        Node* p = root;
        int cnt = 0;

        while (p != NULL) {
            if (p->data > x)
                p = p->lson;
            else {
                if (p->lson != NULL)
                    cnt += p->lson->size + 1;
                else
                    cnt += 1;

                p = p->rson;
            }
        }
        return cnt;
    }
    
    void Successor(int x){
        cout << nodeAtOrder(successor(x)) << endl;
    }
};

int main() {



    int n;
    cin >> n;

    AVL bbst;

    int op, x;
    while(n--) {
        cin >> op >> x;
        switch(op){
            case 1: bbst.Insert(x);
                break;
            case 2: bbst.Delete(x);
                break;
            case 3: bbst.Order(x);
                break;
            case 4: bbst.Minimum(x);
                break;
            case 5: bbst.Precursor(x);
                break;
            case 6: bbst.Successor(x);
                break;
            default:
                cout<<"Invalid"<<endl;
            
        }
            
    }

    return 0;
}


/*
10
1 106465
4 1
1 317721
1 460929
1 644985
1 84185
1 89851
6 81968
1 492737
5 493598
 
50
1 577793
1 408221
1 880861
2 408221
1 460353
1 223489
6 577713
4 2
5 889905
2 880861
1 100033
1 73956
1 22575
5 583761
6 571549
1 812645
4 3
1 643621
1 451623
6 14895
1 556691
4 1
1 225789
2 22575
1 632329
3 73956
1 316785
5 101413
4 11
5 639414
6 636353
1 272382
1 434049
2 643621
1 99617
2 577793
1 921581
1 894033
3 223489
1 767367
3 272382
1 642721
1 272033
3 632329
1 737721
1 864513
5 746457
1 877545
1 51097
1 484817
 
 
 out:
 577793
 460353
 880861
 577793
 577793
 100033
 22575
 22575
 1
 100033
 643621
 632329
 643621
 4
 6
 13
 737721

 */
