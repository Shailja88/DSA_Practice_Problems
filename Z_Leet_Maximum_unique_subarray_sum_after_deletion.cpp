// https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/description
class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int sum=0,nemax=INT_MIN;
        bool contPosi=false;
        for(auto in:st){
            if(in>=0){
                sum+=in;
                contPosi=true;
            }
            else{
                nemax=max(nemax,in);
            }
        }
        return contPosi?sum:nemax;
    }
};
