
#include <cstdio>
using namespace std;
int cases;
double k;
int xstart,ystart,xend,yend,xleft,ytop,xright,ybottom;
bool res=0;
bool point_is_in_rectangle(double x,double y){
    if(x>=xleft&&x<=xright&&y>=ybottom&&y<=ytop) return 1;
    return 0;
}
double get_x(int x1,int x2,int y1,int y2){
    return k*(y2-y1)/(k*k+1)/(x2-k*k*x1);
}
double(get_y)(int x1,int x2,int y1,int y2){
    return (k*(x2-x1)+y1+k*k*y2)/(k*k+1);
}
int main(int argc, char const *argv[])
{
    scanf("%d",&cases);
    while(cases--){
        res=0;
        scanf("%d%d%d%d%d%d%d%d",&xstart,&ystart,&xend,&yend,&xleft,&ytop,&xright,&ybottom);
        if(point_is_in_rectangle(xstart,xend)||point_is_in_rectangle(xend,yend)) res=1;
        else{
            k=(ystart-yend)/(xstart-xend);
            if(point_is_in_rectangle(get_x(xstart,xleft,ystart,ytop),get_y(xstart,xleft,ystart,ytop))) res=1;
            else if(point_is_in_rectangle(get_x(xstart,xleft,ystart,ybottom),get_y(xstart,xleft,ystart,ybottom))) res=1;
            else if(point_is_in_rectangle(get_x(xstart,xright,ystart,ytop),get_y(xstart,xright,ystart,ytop))) res=1;
            else if(point_is_in_rectangle(get_x(xstart,xright,ystart,ybottom),get_y(xstart,xright,ystart,ybottom))) res=1;
        }
        if(res) printf("T\n");
        else printf("F\n");
    }
    return 0;
}