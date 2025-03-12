/* 
https://leetcode.com/problems/majority-element-ii/description/
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
*/

//TC=O(n^2) SC=O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //brute force
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i;j<n;j++){
                if(nums[i]==nums[j])cnt++;
            }
            if(cnt>n/3){
                if(ans.size()<2&&(ans.size()==0 ||ans.back()!=nums[i]))
                ans.push_back(nums[i]);};
        }
        return ans;
    }
};

//tc=o(n) sc=o(n)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto in:nums){
            mp[in]++;
        }
        for(auto in:mp){
            if(in.second>n/3)ans.push_back(in.first);
        }
        return ans;
    }
};

//tc=O(n) SC=O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        int val=n/3;
        int ele1,ele2,cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(cnt1==0 && nums[i]!=ele2){
                cnt1=1;
                ele1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=ele1){
                cnt2=1;
                ele2=nums[i];
            }
            else if(nums[i]==ele1){
                cnt1++;
            }
            else if(nums[i]==ele2){
                cnt2++;
            }
            else{
                cnt1--;cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        for(auto in:nums){
            if(in==ele1){
                cnt1++;
            }
            else if(in==ele2){
                cnt2++;
            }
        }
        if(cnt1>val){
            ans.push_back(ele1);
        }
        if(cnt2>val){
            ans.push_back(ele2);
        }
return ans;
    }
};
