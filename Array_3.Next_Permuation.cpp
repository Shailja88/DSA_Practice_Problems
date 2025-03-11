/* A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
 https://leetcode.com/problems/next-permutation/description/
 */

/* Approach 1: TC ~ O(n * n!)
               1. Generate all sorted permutation
               2. Apply Linear Search
               3. Return next index


  Approach 2:  TC = O(n)
               stl function 
               next_permutation(nums.begin(),nums.end());   


  Approach 3:      //tc=O(n^2) and SC=O(1)
    */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int n=nums.size();
       bool flag=false;
       int v=-1;
       //traverse from backward and check if the jth element is greater than the ith element 
       for(int i=n-1;i>=0 && flag==false;i--){
        for(int j=n-1;j>i;j--){
            if(nums[j]>nums[i])
            { 
                swap(nums[i],nums[j]);
                v=i;
                flag=true;
                break;
            }
        }
       }
       reverse(nums.begin()+v+1,nums.end());
      
    }


};
