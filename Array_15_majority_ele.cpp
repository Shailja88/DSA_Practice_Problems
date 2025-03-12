// https://leetcode.com/problems/majority-element/description/
// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /* 1. count each element occurence and if it is greater than n/2 then return that value . Tc=O(n^2) SC=O(1)
        2.use map and store the occrence in one go and in second pass check if it's value is greater than n/2 return that value 
        TC=O(2n) SC=O(n)
        
        Moore's voting algorithm TC=O(n) SC=O(1)*/
        int n=nums.size();
      int mele=nums[0];
      int cnt=1;
      for(int i=1;i<n;i++){
        if(nums[i]==mele){
            cnt++;
        }
        else{
            cnt--;
            if(cnt<=0){
                cnt=1;
                mele=nums[i];
            }
        }
      }
      cnt=0;
    for(auto in:nums){
        if(in==mele){
            cnt++;
        }
    }
    if(cnt>n/2)return mele;
    return -1;
    }
};
