/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

https://leetcode.com/problems/pascals-triangle/description/
*/
//Approach 1 (Brute Force)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;//2d vector for storing the answer 
        for(int i=0;i<numRows;i++){
            vector<int>nrow(i+1,1);//initializing nth row with 1 

            for(int j=1;j<i;j++){

                   //calculating the value by adding  two elements of previous row 
                    int prerow=ans[i-1][j-1]+ans[i-1][j];
                    nrow[j]=prerow;               
            }
            //storing the nth row value into answer vector 
            ans.push_back(nrow);
        }
        return ans;

        //Time Complexity is O(n^2) and SC=O(n);
    }
};
  //Approach 2

class Solution {
public:
/*  n=5;
    row=5-1;
    1 4/1 (4*3)/(1*2) (4*3*2)/(1*2*3) (4*3*2*1)/(1*2*3*4)
 => 1 4 6 4 1   
*/
    vector<int>generateNthRow(int n){
       int row=n-1;
       int val=1;
       vector<int>temp;
       temp.push_back(1);
       for(int i=1;i<n;i++){
            val=(val*(row--))/i;
            temp.push_back(val);
       }
       return temp;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
       for(int i=1;i<=numRows;i++){
        vector<int>temp=generateNthRow(i);
        ans.push_back(temp);
       }
        return ans;
    }
    //tc=O(n^2) SC=O(n)
};



