#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <stdio.h>

using namespace std;

class Point
{
public:
    double x, y;
    Point *origin;

    Point(double cx, double cy)
    {
        x = cx;
        y = cy;
        origin = nullptr;
    }
    void setOrigin(Point *org)
    {
        origin = org;
    }
    void show()
    {
        cout<<x<<", "<<y<<endl;
    }

};

void printPoints(vector<Point> &val)
{
    for(int i=0; i<val.size(); i++) val[i].show();
}

double getDirection(Point pi, Point pj, Point pk)
{
    double x1, x2, y1, y2;
    x1 = (pk.x - pi.x);
    y1 = (pk.y - pi.y);
    x2 = (pj.x - pi.x);
    y2 = (pj.y - pi.y);
    return (x1*y2 - x2*y1);
    
}


/**
let p0 be the point in Q with the minimum y-coordinate,
or the leftmost such point in case of a tie
*/
bool condition1(Point p1, Point p2)
{
    if (p1.y == p2.y) return p1.x < p2.x;
    return p1.y<p2.y;
}
/**
let (p1, p2,....,pm) be the remaining points in Q,
sorted by polar angle in counterclockwise order around p0
(if more than one point has the same angle, remove all but
the one that is farthest from p0)
 */
bool condition2(Point p1, Point p2)
{
    Point *org = p1.origin;
    Point p0 = Point(org->x, org->y);
    double d = getDirection(p0, p2, p1);
    
    if (d == 0) return p1.x<p2.x;
    return d>0;

}

vector<Point> Graham_Scan(vector<Point> &P)
{
    printPoints(P);
    sort(P.begin(), P.end(), condition1);
    cout<<"Sorting -- y increasing is compelted"<<endl;
    printPoints(P);

    Point *origin = new Point(P[0].x, P[0].y);
    for(int i=0; i<P.size(); i++) P[i].setOrigin(origin);
    sort(P.begin()+1, P.end(), condition2);
    cout<<"Sorting -- polor angle increasing by origin p0"<<endl;
    printPoints(P);

    stack<Point> S;
    S.push(P[0]);
    S.push(P[1]);
    S.push(P[2]);

    int i = 3;
    while(i<P.size())
    {
        Point p2 = P[i];
        Point p1 = S.top(); S.pop();
        Point p0 = S.top(); S.pop();
        double d = getDirection(p0, p1, p2);
        if(d<0)
        {
            S.push(p0);
            S.push(p1);
            S.push(p2);
            i++;
        }
        else if (d==0)
        {
            S.push(p0);
            S.push(p2);
            i++;
        }
        else
        {
            S.push(p0);
            S.push(p2);
            i++;
        }

    }
    vector<Point> ans;
    while(!S.empty())
    {
        ans.push_back(S.top());
        S.pop();
    }
    return ans;
}

int main()
{
    double xx, yy;
    freopen("data.txt", "r", stdin);
    vector<Point> P;
    while(cin >>xx >> yy)
    {
        P.push_back(Point(xx,yy));
    }
    cout<<"Reading from file is completed.."<<endl;
    vector<Point> ret = Graham_Scan(P);
    cout<<"Answers: "<<endl;
    printPoints(ret);

    return 0;
}