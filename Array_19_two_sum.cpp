// https://leetcode.com/problems/two-sum/description/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //brute force
        // tc=O(n^2) sc=O(1)
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               if(nums[i]+nums[j]==target){
                return {i,j};
               }
            }
        }
        return {-1,-1};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //better force
        // tc=O(n) sc=O(n)
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
          int khojo=target-nums[i];
          if(mp.find(khojo)!=mp.end()){
            return {mp[khojo],i};
          }
          mp[nums[i]]=i;
        }
      return {-1,-1};
    }
};

