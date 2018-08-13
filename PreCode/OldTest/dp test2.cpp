int dp[n];
int pos=0,max_right=0;

for(int i=0;i<n;i++){
    if(i<max_right){
        dp[i]=min(dp[pos*2-i],max_right-i);
    }
    while(i+dp[i]+1<n&&i-dp[i]-1>0&&str[i+dp[i]+1]==str[i-dp[i]-1]) dp[i]++;
    if(i+dp[i]>max_right){
    pos=i;
    max_right=i+dp[i];
    }
}
