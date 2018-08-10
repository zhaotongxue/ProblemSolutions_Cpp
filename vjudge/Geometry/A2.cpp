//A2.cpp
#include <cstdio>
using namespace std;
int xstart,ystart,xend,yend,xleft,ytop,xright,ybottom;
int a,b,c;
bool is_in;
double diagonal2;
int main(int argc, char const *argv[])
{
    scanf("%d",&cases);
    while(cases--){
        is_in=0;
        scanf("%d%d%d%d%d%d%d%d",&xstart,&ystart,&xend,&yend,&xleft,&ytop,&xright,&ybottom);
        b=xstart-xend;
        a=yend-xstart;
        c=xstart*(ystart-yend)-ystart*(xstart-xend);

        diagonal2=(xright-xleft)*(xright-xleft)+(ytop-ybottom)*(ytop-ybottom);
        if(xstart-xend==0){
            if(xleft<=xstart&&xright>=xright){
                if(ystart>=ybottom&&ystart<=ytop) is_in=1;
                else if(yend>=ybottom&&yend<=ybottom) is_in=1;
                else if(ystart>=ytop&&yend<=ybottom) is_in=1;
                else if(ystart<=ybottom&&yend>=ytop) is_in=1;
            }
        }else if(ystart-yend==0){
            if(ybottom<=ystart&&ytop>=ystart){
                if(xstart>=xleft&&xstart<=xright) is_in=1;
                else if(xend>=xleft&&xend<=xright) is_in=1;
                else if(xstart<=xleft&&xend>=xright) is_in=1;
                else if(xend<=xleft&&xstart>=xright) is_in=1;
            }
        }else{
            if((xstart-xend)*(ystart-yend)>0){
                if(abs(a*xleft+b*ytop+c)*abs(a*xleft+b*ytop+c)<=(a*a+b*b)*diagonal2&&abs(a*xright+b*ybottom+c)*abs(a*xright+b*ybottom+c)<=(a*a+b*b)*diagonal2) is_in=1;
            }else{
                if(abs(a*xrigh+b*ytop+c)*abs(a*xright+b*ytop+c)<=(a*a+b*b)*diagonal2&&abs(a*xleft+b*ybottom+c)*abs(a*xleft+b*ybottom+c)<=(a*a+b*b)*diagonal2) is_in=1;
            }
        }
        if(is_in) printf("T\n");
        else printf("F\n");
    }
    return 0;
}
