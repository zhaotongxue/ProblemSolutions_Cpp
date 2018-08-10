class Solution {
public:
    bool isNumber(string str) {
    vector<char> v;
    //char* str=new char(50);
    //cin>>str;
    int start,end;
    for(int k=0;k<str.length();k++){
        if(str.at(k)!=' '){
            start=k;
            break;
        }
    }
    for(int k=str.length()-1;k=0;k--){
        if(str.at(k)!=' '){
            end=k;
            break;
        }
    }
    for(int i=start;i<=end;i++){
        if(str.at(i)>='0'&&str.at(i)<='9'){
            v.push_back(str.at(i));
            continue;
        }
        if(str.at(i)!='.'&&str.at(i)!='e') return 0;
        if(str.at(i)=='e'&&v.empty()) return 0;
        else{
            for(int m=0;m<v.size();m++)
                if(v[m]=='e') return 0;
            v.push_back('e');
        }
        if(str.at(i)=='.'){
            for(int m=0;m<v.size();m++)
                if(v[m]=='.') return 0;
            v.push_back('.');
        }
    }
    if(v.empty()) return 0;
    if(v.size()==1&&v[0]=='.') return 0;
    return 1;
    }
};