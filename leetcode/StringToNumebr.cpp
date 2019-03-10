long long int res=0;
int start=0,end=str.size()-1;
const int int_min=-2147483648;
const int int_max=+2147483647;
bool neg=0;
int sp=0;
for(int i=0;i<str.size();i++){
    if(str.at(i)!=' ') {
        sp=i;
        break;
    }
}
if(str.at(sp)=='-'){
    neg=1;
    sp++;
}
else if(str.at(sp)=='+'){
    sp++;
}
for(;sp<str.size();sp++){
    if(str.at(sp)>='0'&&str.at(sp)<='9'){
        res=res*10+(str.at(sp)-'0');
        if(res>int_max) return int_max;
        else if(res<int_min)return int_min;
    }else{
        break;
    }
}
return neg?-res:res;

