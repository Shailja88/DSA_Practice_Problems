// https://leetcode.com/problems/rotate-image/description/
/*
   mat[i][j]=mat[n-j-1][i];
   mat[j][n-1-i]=mat[i][j];
*/
//tc=O(n^2) SC=O(n^2)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>v;

        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                temp.push_back(matrix[n-1-j][i]);
            }
            v.push_back(temp);
        }
     matrix=v;
     v.clear();
    }
};


//tc=O(n^2) SC=O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //transpose and row reverse
        int n=matrix.size();
        for(int i=0;i<n;i++){
          for(int j=0;j<i;j++){
            swap(matrix[i][j],matrix[j][i]);
          }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
