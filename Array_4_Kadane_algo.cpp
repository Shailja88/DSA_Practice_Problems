/*
https://leetcode.com/problems/maximum-subarray/description/

Given an integer array nums, find the subarray with the largest sum, and return its sum.

 */

//TC=O(n^2) 
//SC=O(1);

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //brute force
        int ans=INT_MIN;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=i;j<n;j++){
                   sum+=nums[j];
                  ans=max(ans,sum);
            }
        }
        return ans;
    }
};

//TC=O(n) SC=O(1);
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      bool flag=false;
      int n=nums.size();
      int sum=0;
      int ans=INT_MIN;
      for(int i=0;i<n;i++){
        if(nums[i]>=0){
            flag=true;
        }
        sum+=nums[i];
        sum=max(0,sum);
        ans=max(sum,ans);

      }
      if(flag==false){
        int mini=INT_MIN;
        for(auto in:nums){
            mini=max(in,mini);
        }
        return mini;
      }

return ans;

    }
};
