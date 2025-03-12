// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
// https://leetcode.com/problems/powx-n/description/


class Solution {
public:
    double myPow(double x, int n) {
        //stl function TC=O(logn)
        double ans=pow(x,n);
        return ans;
    }
};

//tc=O(logn) SC=O(1)
class Solution {
public:
    double myPow(double x, int nn) {
        long long n=nn;
        double ans=1;
          if(x==1)return x;
        bool neg_flag=0;
       if(n<0){
        neg_flag=true;
        n=-1*n;
       }
       while(n){
        if(n%2==0){
            x=x*x;
            n=n/2;
        }
        else{
            ans=x*ans;
            n=n-1;
        }
       }
       if(neg_flag==true){
        ans=1/ans;
       }
return ans;
    }
};
