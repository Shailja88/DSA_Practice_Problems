/*Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.
https://leetcode.com/problems/set-matrix-zeroes/description/


*/

//Approach 1 - this code will work when values of matrix  are positive 
class Solution {
public:

      //updating val of row r with -1 where val!=0; 
    void mark_row(vector<vector<int>>&mat, int r,int n,int m){
           
           for(int i=0;i<m;i++){
            if(mat[r][i]!=0)
            mat[r][i]=-1;
           }
    }
          //updating val of col c with -1 where val!=0; 
    void mark_col(vector<vector<int>>&mat,int c,int n,int m){
            for(int j=0;j<n;j++){
                if(mat[j][c]!=0)
                mat[j][c]=-1;
            }
    }

    //updating val with 0 where val==-1
    void maxi_to_zero(vector<vector<int>>&mat,int n,int m){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==-1){
                    mat[i][j]=0;
                }
            }
        }
    }
    //set matrix zeroes
    void setZeroes(vector<vector<int>>& matrix) {
         int n=matrix.size(); //number of rows
         int m=matrix[0].size(); //number of colums

         //traversing through entire matrix using two for loops 
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    //call function that mark entire row and column where val!=0 with INT_MAX 
                       mark_row(matrix,i,n,m);
                       mark_col(matrix,j,n,m);
                }
            }
         }   

         //change LONG_MAX with 0
         maxi_to_zero(matrix,n,m); 
    }
};

//Time complexity O(n^3) and Space Complexity O(1);


//Approach 2-
class Solution {
public:
   // final step of updating the matrix with zero in rows or cols that contain zero
    void update_original_mat(vector<vector<int>>&matrix,vector<bool>&row,vector<bool>&col,int n,int m){
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(row[i]==true || col[j]==true){
                matrix[i][j]=0;
               }
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();//total rows
        int m=matrix[0].size();//total columns

        vector<bool>row_zero(n,false);
        vector<bool>col_zero(m,false);
        //traversing through matrix and marking row_zero and col_zero if val==0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row_zero[i]=true;
                    col_zero[j]=true;
                }
            }
        }
        //update original matrix where any values in entire row or column is zero 
        update_original_mat(matrix,row_zero,col_zero,n,m);
    }
};

//Time Complexity = O(n*m) Space Complexity = O(n+m)


class Solution {
public:
   void final_update(vector<vector<int>>&matrix,int n,int m,bool col0){
       //updating from backward so that i can preserve the markers 
       for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=1;j--){
            if(matrix[i][0]==0 || matrix[0][j]==0){
                matrix[i][j]=0;
            }
        }
       }

       //handling column 0 
       if(col0==true){
        for(int i=0;i<n;i++){
            matrix[i][0]=0;
        }
       }
   }
    void setZeroes(vector<vector<int>>& matrix) {
       //taking first row and col as marker 
       bool col0=false;
       int n=matrix.size();
       int m=matrix[0].size();
       for(int i=0;i<n;i++){
        if(matrix[i][0]==0)
           col0=true;
        for(int j=1;j<m;j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
       }
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
       }
    //    cout<<col0<<endl;
        //final updates of matrix with zeroes
        final_update(matrix,n,m,col0);
        // best approach where TC=O(n*m) SC=O(1)
    }
};




