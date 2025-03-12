 // https://www.naukri.com/code360/problems/count-inversions_615?leftPanelTabValue=SUBMISSION
//brute force approach TC = O(n^2) SC = O(1) 

#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    // Write your code here.
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                count++;
            }
        }
    }
    return count;
}

//using merge sort algorithm  TC=O(nlogn) SC=O(1)
#include <bits/stdc++.h> 
// int cnt=0;
long long merg(long long *a, int l, int m,int h,long long &cnt){
    vector<long long>temp;
    int i=l,j=m+1;
    while(i<=m && j<=h){
        if(a[j]>=a[i]){
            temp.push_back(a[i]);
            i++;
        }
        else {
            cnt+=(m-i+1);
            temp.push_back(a[j]);
            j++;
        }
    }
    while(i<=m){
        temp.push_back(a[i]);
        i++;
    }
    while(j<=h){
        temp.push_back(a[j]);
        j++;
    }
    for(int k=l;k<=h;k++){
        a[k]=temp[k-l];
    }
    return cnt;
}
long long mergeSort(long long * arr, int low,int high,long long &cnt)
 {
     if(low>=high)return cnt ;
     int mid=low+(high-low)/2;
     mergeSort(arr,low,mid,cnt);
     mergeSort(arr,mid+1,high,cnt);
     merg(arr,low,mid,high,cnt);
    return cnt;
 }
long long merge(long long *arr, int n){
    int low=0,high=n-1;
    long long cnt=0;
    mergeSort(arr,low,high,cnt);
     return cnt;
}
long long getInversions(long long *arr, int n){
    // long long cnt=0;
    merge(arr,n);
    // return cnt;

}
