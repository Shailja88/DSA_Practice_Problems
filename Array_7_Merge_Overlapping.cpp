//https://leetcode.com/problems/merge-intervals/
//Tc=O(2*n) SC=O(1)

/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back({intervals[0][0],intervals[0][1]});
         int n=intervals.size();
         for(int i=0;i<n;i++){
             if(intervals[i][0]<=ans.back()[1]){
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
             }
             else{
                ans.push_back({intervals[i][0],intervals[i][1]});
             }
         }
         return ans;
    }
};
