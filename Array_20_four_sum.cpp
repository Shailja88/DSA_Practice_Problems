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
                 if(j>i+1 && nums[j-1]==nums[j])continue;
                
                int k=j+1;
                int h=n-1;
                 while(k<h){
                    long long summ=(long long)nums[i]+nums[j]+nums[k]+nums[h];
                    
                   if(summ==target){
                    ans.push_back({nums[i],nums[j],nums[k],nums[h]});
                    k++;h--;
                    while(k<h && nums[k]==nums[k-1])k++;
                    while(k<h && nums[h]==nums[h+1])h--;
                }
                else if(summ>target){
                    h--;     
                }
                else{
                    //sum<tar
                     k++;
                          }
                }
            }
        }

        return ans;
    }
};
