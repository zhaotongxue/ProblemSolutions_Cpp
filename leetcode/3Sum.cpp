#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            while(i>0&&nums[i]==nums[i-1]) i++;
            for(int j=i+1,k=nums.size()-1;j<k;){
                int temp=nums[i]+nums[j]+nums[k];
                if(temp<0) j++;
                else if(temp>0) k--;
                else{
                    int arr[3]={nums[i],nums[j],nums[k]};
                    vector<int> v(arr,arr+3);
                    j++;
                    k--;
                    while(k>j&&nums[j]==nums[j-1]) j++;
                    while(k>j&&nums[k]==nums[k+1]) k--;
                }
            }
        }
        return res;
    }
};
int main(){
    return 0;
}
