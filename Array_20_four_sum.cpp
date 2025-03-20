// https://leetcode.com/problems/4sum/
//tc= O(n^3)+ O(nlogn) SC = O(1)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
             if(i!=0 && nums[i]==nums[i-1] )continue;
            for(int j=i+1;j<n;j++){
                 if(j>1 && nums[j-1]==nums[j])continue;
                int tar=target-(nums[i]+nums[j]);
                int k=j+1;
                int h=n-1;
                while(k<h){
                int summ=nums[k]+nums[h];
                if(summ==tar){
                    ans.push_back({nums[i],nums[j],nums[k],nums[h]});
                    k++;h--;
                }
                else if(summ>tar){
                    h--;
                    while(h>0 && nums[h]==nums[h+1]){
                        h--;
                    }
                }
                else{
                    //sum<tar
                     k++;
                     while(k<h && nums[k]==nums[k-1]){
                        k++;
                     }
                          }
                }
            }
        }

        return ans;
    }
};
