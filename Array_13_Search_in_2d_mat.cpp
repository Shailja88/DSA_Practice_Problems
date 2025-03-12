// https://leetcode.com/problems/search-a-2d-matrix/description/
// Search a 2D Matrix
//TC=O(n^2) SC=O(1)

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //brute force approach 
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==target)return true;
            }
        }
        return false;
    }
};

class Solution {
public:

    bool search(vector<int>&mat,int target){
        int l=0,h=mat.size()-1;
        while(l<=h){
           int mid=(l+(h-l)/2);
           if(mat[mid]==target)return true;
           if(mat[mid]>target){
            h=mid-1;
           }
           else{
            l=mid+1;
           }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //row is sorted in non descreasing order so apply binary search in row TC=O(nlogm) SC=O(1)
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
          if(search(matrix[i],target))return true;
        }
        return false;
    }
};


///TC=O(log(m*n)) SC=O(1);
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int l=0,h=m*n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(matrix[mid/m][mid%m]==target)return true;
            else if(matrix[mid/m][mid%m]>target){
                h=mid-1;
            }
            else{
               l=mid+1;
            }
        }
        return false;
    }
};


