#include <cmath>
class Solution{
public:
    bool PredictTheWinner(vector<int>& nums)
    {
        int all_sum=0;
        for(int i=0;i<nums.size();i++) all_sum+=nums[i];
        return findAns(nums,0,nums.size()-1)*2>all_sum;
    }
    int findAns(vector<int>& nums,int left,int right){
        if(left==right) return nums[left];
        else{
            int s1=findAns(nums,left++,right);
            int s2=findAns(nums,left,right--);
            return s1>s2?s1:s2;
        }
    }
        /*
        int all_sum=0;
        for(int i=0;i<nums.size();i++) all_sum+=nums[i];
        int player1=0;
        int left=0,right=nums.size()-1;
        bool side=true;
        while(left<=right){
            if(side){
                if(nums[left]>nums[right]){
                    player1+=nums[left];
                    left++;
                }else{
                    player1+=nums[right];
                    right--;
                }
            }else{
                if(nums[left]<nums[right]){
                    player1+=nums[left];
                    left++;
                }else{
                    player1+=nums[right];
                    right--;
                }
            }
            side=!side;
        }
        return player1>(all_sum-player1);
        */
//    }
    // int player1=0,player2=0;
    /*
    int AlphaBate(int player1,int player2,int left,int right){
        if(left>right) return 0;

    }
    */
 /*
        int max_index=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]>num[max_index])
                max_index=i;
        int player1=0,player2=0;
        player1+=nums[max_index];
        int left=max_index-1;
        int right=max_index+1;
        int temp=0;
        if(nums%2==0){
            temp=2;
        }else{
            temp=1; 
        }
        while((left>=0||right<=nums.size()-1)&&(temp--)){
            if(left>=0;nums[left]>num[right]) {
                player2+=nums[left];
                left--;
            }
            else if(right<=nums.size()-1){
                player2+=nums[right];
                right++;
            }
        }
        bool who=1;
        while((left>=0||right<=nums.size()-1)){
            if(who){
                if(left>=0;nums[left]>num[right]) {
                    player1+=nums[left];
                    left--;
                }
                else if(right<=nums.size()-1){
                    player1+=nums[right];
                    right++;
                }
            }
            else{
                if(left>=0;nums[left]>num[right]) {
                    player2+=nums[left];
                    left--;
                }
                else if(right<=nums.size()-1){
                    player2+=nums[right];
                    right++;
                }
            }
            who=!who;
        }
        return player1>player2;
    }
    {
        if(PredictTheWinner(nums,1,nums.size()-1,nums[0],0,0)||PredictTheWinner(nums,0,nums.size()-2,nums[nums.size()-1],0,0)) return 1;
        return 0;
    };
    bool PredictTheWinner(vector<int>& nums,int left,int right,int player1,int player2,bool side) {
        if(left>right) return player1>player2;
        if(side){
            if(PredictTheWinner(nums,left,right-1,player1+nums[right],player2,!side)) return 1;
            if(PredictTheWinner(nums,left+1,right,player1+nums[left],player2,!side)) return 1;
        }
        else{
            if(PredictTheWinner(nums,left+1,right,player1,player2+nums[left],!side)) return 1;
            if(PredictTheWinner(nums,left,right-1,player1,player2+nums[right],!side)) return 1;
        }
    };
    */
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}