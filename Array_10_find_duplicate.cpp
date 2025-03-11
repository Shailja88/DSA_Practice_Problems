//https://leetcode.com/problems/find-the-duplicate-number/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //brute force tc=O(n^2) SC=O(1)
        int n=nums.size();
        for(int i=0;i<n;i++){
             for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j])return nums[i];
             }
        }
        return -1;
    }
};


//Tc=O(nlogn) Sc=O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1])return nums[i];
        }
        return -1;
    }
};

//TC=O(n) SC=O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        while(slow!=fast);
         fast=nums[0];
         while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
         }

        return slow;
    }
};
