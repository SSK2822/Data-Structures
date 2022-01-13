//
//  main.cpp
//  814
//
//  Created by shreyash kawle on 09/11/21.
//

#include <iostream>

using namespace std;

class Node
{
public:
    int data = -1; Node* right = NULL; Node* left = NULL; Node* bottom = NULL; Node* top = NULL;

    void cTop(Node * p)
    {
      top = p;
      if (p != NULL)
         p->bottom = this;
    }

    void cRight(Node* p)
    {
      right = p;
      if (p != NULL)
         p->left = this;
    }

    void cBottom(Node* p)
    {
       bottom = p;
       if (p != NULL)
          p->top = this;
    }

    void cLeft(Node* p)
    {
      left = p;
      if(p != NULL)
         p->right = this;
    }

    void set_data(int dt) { data = dt; }
    int get_data() { return data; }
};

Node* find(Node* p, int r, int c)
{
    Node* ret = p;
    if (p != NULL)
    {
      for (int i = 1; i < c; i++)
         ret = ret->right;
         
      for (int i = 1; i < r; i++)
         ret = ret->bottom;
    }
    return ret;
}


int main()
{
    int n, m, q,dt, rw1, cl1, rw2, cl2, ht,wd;

    Node* arr;
    Node dummy;
    Node* p;

    Node* temp_bottom, * temp_top, * temp_left, * temp_right;


    while (cin >> n >> m >> q)
    {
      arr = new Node[n * m];

      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < m; j++)
         {

            cin >> dt;
            Node* base = arr + i * m + j;
            (arr + i * m + j)->set_data(dt);

            if (i > 0)
               base->cTop(arr + (i-1)*m + j);
            if (i < n - 1)
               base->cBottom(arr + (i + 1)*m + j);
            if (j > 0)
               base->cLeft(arr+ i*m + j - 1);
            if (j < m - 1)
               base->cRight(arr + i*m + j + 1);


         }
      }

      dummy.cRight(arr);
      
      for (int t = 0; t < q; t++)
      {
         cin >> rw1 >> cl1 >> rw2 >> cl2 >> ht >> wd;

         p = dummy.right;

         Node* s1 = find(p,rw1,cl1);
         Node* s2 = find(p, rw2, cl2);
         Node* s1_b = s1;
         Node* s2_b = s2;

         Node* s1_right = find(s1,0,wd);
         Node* s1_bottom = find(s1,ht,0);
         Node* s2_right = find(s2,0,wd);
         Node* s2_bottom = find(s2,ht,0);


         for (int i = 0; i < ht; i++)
         {
            temp_left = s1->left;
            temp_right = s1_right->right;

            s1->cLeft(s2->left);
            s2->cLeft(temp_left);
            s1_right->cRight(s2_right->right);
            s2_right->cRight(temp_right);

            s1 = s1->bottom;
            s2 = s2->bottom;
            s1_right = s1_right->bottom;
            s2_right = s2_right->bottom;
         }

         s1 = s1_b;
         s2 = s2_b;

         for (int i = 0; i < wd; i++)
         {
            temp_top = s1->top;
            temp_bottom = s1_bottom->bottom;

            s1->cTop(s2->top);
            s2->cTop(temp_top);
            s1_bottom->cBottom(s2_bottom->bottom);
            s2_bottom->cBottom(temp_bottom);

            s1 = s1->right;
            s2 = s2->right;
            s1_bottom = s1_bottom->right;
            s2_bottom = s2_bottom->right;
         }
      }

      p = dummy.right;
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < m; j++)
         {
            cout << p->get_data();
            if (j < m - 1)
               cout << " ";
            p = p->right;
         }
         cout << endl;
         p = find(dummy.right, i + 2, 0);
      }
    }
    return 0;
}

/*
4 4 2
1 1 2 2
1 1 2 2
3 3 4 4
3 3 4 4
1 1 3 3 2 2
3 1 1 3 2 2
 */
