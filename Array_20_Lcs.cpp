// https://leetcode.com/problems/longest-consecutive-sequence/description/
// Longest Consecutive Sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n==0)return 0;
        int ans=1;
        int actans=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1])continue;
            if(nums[i]==nums[i-1]+1){
                ans++;
                actans=max(actans,ans);
            }
            else{
                ans=1;
            }
        }
        return actans;
    }
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //TC=O(2n) SC=O(n)
        int n=nums.size();
        if(n==0)return 0;
        set<int>st;
        for(auto in:nums){
            st.insert(in);
        }
        int cnt=0,ans=1;
        for(auto in:st){
            //find the smallest possible number that is present  
            cnt=0;
            int val=in;
            if(st.find(val-1)!=st.end()){
            continue;
            }
            while(st.find(val)!=st.end()){
                cnt++;
                val=val+1;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};
