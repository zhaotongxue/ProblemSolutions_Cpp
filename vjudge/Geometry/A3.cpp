#include <cstdio>
#include <algorithm>
using namespace std;
int xstart,ystart,xend,yend,xleft,ytop,xright,ybottom,cases,x_max,x_min,y_max,y_min;
int a,b,c;
bool is_in;
int main(int argc, char const *argv[])
{

    scanf("%d",&cases);
    while(cases--){
        is_in=0;
        scanf("%d%d%d%d%d%d%d%d",&xstart,&ystart,&xend,&yend,&xleft,&ytop,&xright,&ybottom);
        a=yend-ystart;
        b=xstart-xend;
        c=xstart*(ystart-yend)-ystart*(xstart-xend);
        // printf("%d\n",xright>=min(xstart,xend));
        // printf("%d\n",xright<=max(xstart,xend));
        // printf("%d b*min:%d\n",0-(a*xright+c),b*min(ytop,ybottom));
        // printf("%d b*max:%d\n",0-(a*xright+c),b*max(ytop,ybottom));
        if(xstart>=min(xleft,xright)&&xstart<=max(xleft,xright)&&ystart>=min(ybottom,ytop)&&ystart<=max(ybottom,ytop)) is_in=1;
        else if(xend>=min(xleft,xright)&&xend<=max(xleft,xright)&&yend>=min(ytop,ybottom)&&yend<=max(ybottom,ytop)) is_in=1;
        else if(b!=0&&xleft>=min(xstart,xend)&&xleft<=max(xstart,xend)&&-(a*xleft+c)>=min(b*ytop,b*ybottom)&&-(a*xleft+c)<=max(b*ybottom,b*ytop)) is_in=1;
        else if(b!=0&&xright>=min(xstart,xend)&&xright<=max(xstart,xend)&&-(a*xright+c)>=min(b*ytop,b*ybottom)&&-(a*xright+c)<=max(b*ybottom,b*ytop)) is_in=1;
        else if(a!=0&&ybottom>=min(ystart,yend)&&ybottom<=max(ystart,yend)&&-(b*ybottom+c)>=min(a*xright,a*xleft)&&-(b*ybottom+c)<=max(a*xleft,a*xright)) is_in=1;
        else if(a!=0&&ytop>=min(ystart,yend)&&ytop<=max(ystart,yend)&&-(b*ytop+c)>=min(a*xright,a*xleft)&&-(b*ytop+c)<max(a*xleft,a*xright))is_in=1;
        if(is_in) printf("T\n");
        else printf("F\n");
    }
}


