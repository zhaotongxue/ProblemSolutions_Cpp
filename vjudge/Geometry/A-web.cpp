#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct Point{
    Point(double a,double b):x(a),y(b){}
    Point(){}
    double x,y; 
};
typedef Point Vector;
struct Segment{
    Segment(Point a,Point b):start(a),end(b){}
    Segment(){}
    Point start,end;    
};
Vector operator-(Point a,Point b){
    return Vector(a.x-b.x,a.y-b.y);
}
bool operator==(Point a,Point b){
    return a.x==b.x&&a.y==b.y;
}
double Cross(Vector a,Vector b){
    return a.x*b.y-a.y*b.x; 
}
double Dot(Vector a,Vector b){
    return a.x*b.x+a.y*b.y;
}
Segment line,seg[4];
Point rect[4];
const double eps=1e-10;
int dcmp(double x)
{   if(fabs(x)<eps) return 0;
    return x>0?1:-1;
}
bool JudgePointOnSegment(Point a,Segment Line)
{   if(dcmp(Cross(Line.start-a,Line.end-a))==0&&dcmp(Dot(Line.start-a,Line.end-a)<0))
        return 1;
    if(a==Line.start||a==Line.end)  return 1;
    return 0;
}
bool JudgeIntersection(Segment a,Segment b)
{   double c1=Cross(a.end-a.start,b.end-a.start),c2=Cross(a.end-a.start,b.start-a.start),   
        c3=Cross(b.end-b.start,a.start-b.start),c4=Cross(b.end-b.start,a.end-b.start);
    return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}
bool PointOnRect(Point a)
{   if((rect[0].x<a.x&&a.x<rect[2].x)&&(rect[2].y<a.y&&a.y<rect[0].y))
        return 1;
    return 0;
}
bool Judge()
{   int i;
    for(i=0;i<4;++i)
        if(JudgePointOnSegment(line.start,seg[i])||
            JudgePointOnSegment(line.end,seg[i]))
            return 1;
    for(i=0;i<4;++i)
        if(JudgePointOnSegment(rect[i],line))
            return 1;
    for(i=0;i<4;++i)
        if(JudgeIntersection(line,seg[i]))
            return 1;
    if(PointOnRect(line.start)&&PointOnRect(line.end))
        return 1;
    return 0;
}
int main()
{   int n,i;
    double a,b,c,d;
    bool flag;
    scanf("%d",&n);
    while(n--)
    {   scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        line=Segment(Point(a,b),Point(c,d));
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        if(a>c)
        {   swap(a,c);
            swap(b,d);
        }
        if(b<d)     swap(b,d);
        rect[0]=Point(a,b);
        rect[1]=Point(c,b);
        rect[2]=Point(c,d);
        rect[3]=Point(a,d);
        seg[0]=Segment(rect[0],rect[1]);
        seg[1]=Segment(rect[1],rect[2]);
        seg[2]=Segment(rect[2],rect[3]);
        seg[3]=Segment(rect[3],rect[0]);
        if(Judge())     puts("T");
        else            puts("F");
    }
    return 0;
}
