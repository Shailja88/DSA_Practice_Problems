// https://www.naukri.com/code360/problems/missing-and-repeating-numbers_6828164?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems

#include<bits/stdc++.h>
using namespace std;
vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // TC=O(n) SC=O(1)
    int n=a.size();
    int repeat=-1,missing=-1;
    unordered_set<int>st;
    for(auto in:a){
          if(st.find(in)!=st.end()){
              repeat=in;
             
          }
           st.insert(in);
    }

   for(int i=1;i<=n;i++){
       if(st.find(i)==st.end()){
           missing=i;
       }
   }
   return {repeat,missing};

}


// 
#include<bits/stdc++.h>
using namespace std;
vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // using math method
    int n=a.size();
     
     long long sum=0,sum_sq=0;
     long long sn=(long long)n*(n+1)/2;
     long long s2n=(long long)n*(n+1)*(2*n+1)/6;

    for(int i=0;i<n;i++){
        sum+=(long long)a[i];
        sum_sq+=(long long)a[i]*a[i];
       
    }
    long long diff=sn-sum;//M-R
    long long diff_sq=s2n-sum_sq;//M^2 - R^2
    
    long long sum_mr=diff_sq/diff; //M+R
    long long missing=(diff+sum_mr)/2;
    long long repeat=missing-diff; 
    return {(int)repeat,(int)missing};
}


/*
TC=O(n)
SC=O(1)
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> findMissingRepeatingNumbers(vector < int > a) {
  int n=a.size();
    int mxr=0;
    for(int i=1;i<=n;i++){
        mxr^=a[i-1]^i;
    }
    int db=0;
    for(int i=0;i<32;i++){
          if((mxr&(1<<i))!=0){
              db=i;
              break;
          }
    }
    int one=0,two=0;
     for(int i=1;i<=n;i++){
         
         if(i&(1<<db)){
             one=one^i;
         }
         else{
             two=two^i;
         }
    }
    for(int i=0;i<n;i++){
         
         if(a[i]&(1<<db)){
             one=one^a[i];
         }
         else{
             two=two^a[i];
         }
    }
    int missing=0,repeat=0;
    for(int i=0;i<n;i++){
        if(a[i]==one){
            repeat=one;
            missing=two;
            break;
        }
        else if(a[i]==two){
            repeat=two;
            missing=one;
            break;
        }
    }


return {repeat,missing};
}
