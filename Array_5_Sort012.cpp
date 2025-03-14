/*Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
https://leetcode.com/problems/sort-colors/description/
*/
//TC=O(n) SC=(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
       int mid=0,low=0,n=nums.size();
       int high=n-1;
       while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;mid++;
            }
            else if(nums[mid]==1){
                   mid++;
            }
            else{
                //nums[mid]==2
                swap(nums[mid],nums[high]);
                high--;
            }
       }
    }
};
