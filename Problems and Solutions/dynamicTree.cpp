//
//  main.cpp
//  DynamicTree
//
//  Created by shreyash kawle on 01/12/21.
//

#include <iostream>

using namespace std;

const int MAXN = 10;
const int MAXD = 1 << MAXN;

//class Quadtree{
// public:
//    bool isWhite;
//    bool needsNewBranch;
//    Quadtree **child;
//    Quadtree *parent;
//
//    Quadtree() {needsNewBranch = false;}
//
//    void addNewBranch(Quadtree *b1, Quadtree *b2, Quadtree *b3, Quadtree *b4);
//    Quadtree* createQuadtree(Quadtree *root, bool **arr, int, int, int);
//    void modify(Quadtree *root, int row, int col, int size);
//};

class Node{
private:
    short color;
    int size;
    Node *kids[4];

    
    short getKid(short x, short y, short d){
        return (2 * this->getBit(x, d) + this->getBit(y, d));
    }
    
    short getBit(short l, short d){
        return (l >> (d - 1)) & 1;
    }

public:
    Node(short color = 0){
        kids[0] = NULL;
        kids[1] = NULL;
        kids[2] = NULL;
        kids[3] = NULL;
        
        this->color = color;
        size = 1;
    }

    int primitiveCountNodes(){
        if (this->color <= 1){
            return 1;
        }

        int s = 1;

        for (int i = 0; i < 4; i++){
            s += this->kids[i]->countNodes();
        }

        return s;
    }

    
    short getColor(short x, short y, short d){
        if (this->color <= 1){
            return this->color;
        }

        if (d == 0){
            return this->color;
        }

        short mask = (1 << (d - 1)) - 1;

        return this->kids[getKid(x, y, d)]->getColor(mask & x, mask & y, d - 1);
    }

    int setColor(short newColor, short x, short y, short d){
        int oldsize = this->size;
        if (newColor == this->color){
            return this->size - oldsize;
        }

        if (d == 0){
            this->size = 1;
            if (this->color > 1){
                this->reset();
            }
            this->color = newColor;

            return this->size - oldsize;
        }

        short kid = this->getKid(x, y, d);

        if (this->color <= 1){
            this->size = 5;
            for (short i = 0; i < 4; ++i){
                this->kids[i] = new Node(this->color);
            }
            this->color = 2;
        }

        short mask = (1 << (d - 1)) - 1;
        this->size += this->kids[kid]->setColor(newColor, mask & x, mask & y, d - 1);

        if (this->kids[0]->color == this->kids[1]->color &&
            this->kids[0]->color == this->kids[2]->color &&
            this->kids[0]->color == this->kids[3]->color &&
            this->kids[0]->color <= 1){
            this->size = 1;
            this->color = this->kids[0]->color;
            
            delete this->kids[3];
            delete this->kids[2];
            delete this->kids[1];
            delete this->kids[0];
        }

        return this->size - oldsize;
    }

    
    int countNodes(){
        return this->size;
    }

    
    void print(short d){
        int n = 1 << d;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++) {
                cout << this->getColor(i, j, d);
            }
            cout << endl;
        }
    }

    void reset(){
        for (int i = 0; i < 4; i++){
            if (this->color > 1){
                this->kids[i]->reset();
                delete this->kids[i];
            }
        }
        this->color = 0;
        this->size = 1;
    }
};
//void Quadtree::addNewBranch(Quadtree *b1, Quadtree *b2, Quadtree *b3, Quadtree *b4) {
//    child = new Quadtree *[4];
//    child[0] = b1;
//    child[1] = b2;
//    child[2] = b3;
//    child[3] = b4;
//}
//
//Quadtree* Quadtree::createQuadtree(Quadtree *root, bool **arr, int row, int coloumn, int len) {
//    Quadtree *t = new Quadtree();
//    t->parent = root;
//
//    bool needsMoreChildren = false;
//    bool flag = false;
//
//    for (int r = row; r < row + len; r++){
//        for (int c = coloumn; c < coloumn + len; c++)
//            if (arr[row][coloumn] != arr[r][c]) {
//                needsMoreChildren = true;
//                flag = true;
//                break;
//            }
//        if (flag)
//            break;
//    }
//    if (!needsMoreChildren)
//        t->isWhite = arr[row][coloumn];
//    else {
//        len /= 2;
//        t->needsNewBranch = true;
//        t->addNewBranch(createQuadtree(t, arr, row, coloumn, len), createQuadtree(t, arr, row, coloumn + len, len), createQuadtree(t, arr, row + len, coloumn, len),createQuadtree(t, arr, row + len, coloumn + len, len));
//    }
//    totalNodes++;
//    return t;
//}
//
//void Quadtree::modify(Quadtree *root, int row, int coloumn, int size) {
//    if (size > 1) {
//        if (!root->needsNewBranch) {
//            root->addNewBranch(new Quadtree(), new Quadtree(), new Quadtree(), new Quadtree());
//            totalNodes += 4;
//            root->child[0]->isWhite = root->child[1]->isWhite = root->child[2]->isWhite = root->child[3]->isWhite = root->isWhite;
//            root->needsNewBranch = true;
//            root->child[0]->parent = root->child[1]->parent = root->child[2]->parent = root->child[3]->parent = root;
//        }
//        int halfSize = size / 2;
//        if (row < halfSize) {
//            if (coloumn < halfSize)
//                modify(root->child[0], row, coloumn, halfSize);
//            else
//                modify(root->child[1], row, coloumn - halfSize, halfSize);
//        }
//        else {
//            if (coloumn < halfSize)
//                modify(root->child[2], row - halfSize, coloumn, halfSize);
//            else
//                modify(root->child[3], row - halfSize, coloumn - halfSize, halfSize);
//        }
//    }
//    else {
//        root->isWhite = !root->isWhite;
//        while (root->parent != nullptr) {
//            Quadtree *parentCpy = root->parent;
//            if (!parentCpy->child[0]->needsNewBranch && !parentCpy->child[1]->needsNewBranch && !parentCpy->child[2]->needsNewBranch && !parentCpy->child[3]->needsNewBranch && parentCpy->child[0]->isWhite == parentCpy->child[1]->isWhite && parentCpy->child[0]->isWhite == parentCpy->child[2]->isWhite && parentCpy->child[0]->isWhite == parentCpy->child[3]->isWhite ) {
//                root->parent->needsNewBranch = false;
//                root->parent->isWhite = root->isWhite;
//                root = root->parent;
//                totalNodes -= 4;
//            } else break;
//        }
//    }
//}


int main(){
    short w, n, d, i, j, k, x, y;
    char r[MAXD + 1];
    Node t;

    cin >> w;

    while (w > 0){
        cin >> n;
        d = 1 << n;
        for (i = 0; i < d; ++i){
            cin >> r;
            for (j = 0; j < d; ++j){
                t.setColor(r[j] - '0', i, j, n);
            }
        }

        cin >> k;
        for (i = 0; i < k; ++i){
            cin >> x >> y;
            t.setColor(1 - t.getColor(x - 1, y - 1, n), x - 1, y - 1, n);
            cout << t.countNodes() << endl;
        }

        t.reset();
        
        w--;
    }
}
