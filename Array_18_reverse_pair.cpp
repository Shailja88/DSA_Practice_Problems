// Reverse Pairs
// https://leetcode.com/problems/reverse-pairs/
class Solution {
public:

  void merge(vector<int>&nums,int l,int m,int h){
      vector<int>temp;
      int i=l;
      int j=m+1;
      while(i<=m && j<=h){
           if(nums[i]<=nums[j]){
            temp.push_back(nums[i]);
            i++;
           }
           else {
            temp.push_back(nums[j]);
            j++;
           }
      }
      while(i<=m){
         temp.push_back(nums[i]);
         i++;
      }
      while(j<=h){
          temp.push_back(nums[j]);
           j++;
      }
      for(int k=l;k<=h;k++){
        nums[k]=temp[k-l];
      }
  }
  int countpairs(vector<int>&nums,int l,int m,int h){
    int cnt=0;
    int j=m+1;
    for(int i=l;i<=m;i++){
       while(j<=h && nums[i]>2LL*nums[j]){
        j++;
       } 
       cnt=cnt+(j-(m+1));
    }
    return cnt;
  }
   int MergeSort(vector<int>&nums,int l,int h)
      { 
        int cnt=0;
        if(l>=h)return cnt;
        int mid=l+(h-l)/2;
        cnt+=MergeSort(nums,l,mid);
       cnt+= MergeSort(nums,mid+1,h);
       cnt+= countpairs(nums,l,mid,h);
        merge(nums,l,mid,h);
        return cnt;
       }
      int reversePairs(vector<int>& nums) {
        //write the code for merge sort
      int l=0;
      int h=nums.size();
  return  MergeSort(nums,l,h-1);
   
    }
};
