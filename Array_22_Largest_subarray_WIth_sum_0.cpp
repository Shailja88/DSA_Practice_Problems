// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

//tc=O(n^3) SC=O(1)
 int maxLen(vector<int>& arr) {
        // brute force
        int ans=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                 sum+=arr[j];
                if(sum==0){
                    ans=max(ans,j-i+1);
                }
            }      
        } 
        return ans;
    }

//prefix sum  tc=O(n) sc=O(n)
class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        int n=arr.size();
        int sum=0;
        int ans=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
            else{
                ans=max(ans,i-mp[sum]);
            }
        }
        return ans;
    }
};
