/*
 Created by Shreyash KAWLE on 13.11
 
 SID : 56318142
 */


#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

class pnt
{
public:
    long long int x;
    long long int y;
    double ang;

    pnt(long long int a, long long int b)
    {
        x = a; y = b;
        ang = 0;
    }
    pnt(){ pnt(0,0);}

    void calcAng(pnt p){ ang = atan2(x-p.x,y-p.y);}
};

int cmp(pnt a, pnt b, pnt c)
{
    long long value = (b.x - a.x) * (c.y - a.y) - (c.x-a.x) * (b.y-a.y);

    if (value > 0) return 1;
    if (value < 0) return -1;
    return 0;
}

long long int dist(pnt p, pnt q)
{
    return sqrt(pow(p.x-q.x,2) + pow(p.y-q.y,2));
}

void swch(pnt& a, pnt& b)
{
    pnt temp = a;
    a = b;
    b = temp;
}

pnt p0;

int cmp(const void *p, const void *q)
{
    pnt* a = (pnt*)p;
    pnt* b = (pnt*)q;
    a->calcAng(p0);
    b->calcAng(p0);
    
    if (a->ang == b->ang)
        return ((dist(p0, *a) > dist(p0, *b))?- 1: 1);
    return ((a->ang > b->ang) ? -1:1);
}

int nextTop(stack<int>& s)
{
    int temp = s.top();
    s.pop();
    int ret = s.top();
    s.push(temp);
    return ret;
}

int main()
{
    long long int T, n, minY,minX,minI,size;
    pnt* coordi;
    pnt* result;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        cin >> n;
        coordi = new pnt[n];
        
        for (int i = 0; i < n; i++)
            cin >> coordi[i].x >> coordi[i].y;

        static_cast<void>(minY = coordi[0].y), minI = 0;
        for (int i = 0; i < n; i++)
            if (coordi[i].y < minY || ((coordi[i].y == minY) && (coordi[i].x < coordi[minI].x)))
                static_cast<void>(minY = coordi[i].y), minI = i;

        swch(coordi[0],coordi[minI]);
        p0 = coordi[0];
        qsort(&coordi[1],n-1,sizeof(pnt),cmp);
        
        stack<int> s;
        s.push(0);
        s.push(1);
        s.push(2);
        for (int i = 3; i < n; i++)
        {
            while (cmp(coordi[nextTop(s)], coordi[s.top()], coordi[i]) <= 0)
                s.pop();
            s.push(i);
        }

        size = s.size();
        cout << size << endl;
        result = new pnt[size];
        for (int i = 0; i < size; i++)
            static_cast<void>(result[i] = coordi[s.top()]), s.pop();
        
        static_cast<void>(minX = result[0].x), minI = 0;
        
        for (int i = 1; i < size; i++)
            if (((result[i].x == minX) && (result[i].y < result[minI].y)) || result[i].x < minX)
                static_cast<void>(minX = result[i].x), minI = i;

        swch(result[0],result[minI]);
        p0 = result[0];
        qsort(&result[1],size-1,sizeof(pnt),cmp);

        int i =0;
        while(i<size){
            cout << result[i].x << " " << result[i].y << endl;
            i++;
        }
    }
    return 0;
}


/*
1
5
1 1
1 -1
0 0
-1 -1
-1 1
 */
