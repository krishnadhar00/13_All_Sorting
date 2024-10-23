// 1. Merge Sort follows the Divide and Conquer Algorithm.
// 2. Divide and Conquer : First divide the problem into sub problems then conquer(solve) the sub problems and finally combine sollutions to get the final output.
// Merge sort is a sorting algorithm that follows the divide-and-conquer approach. It works by recursively dividing the input array into smaller subarrays and sorting those subarrays then merging them back together to obtain the sorted array.

#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&v,int l, int mid, int r)
{
    int an = mid-l+1;
    int bn = r-mid;
    vector<int>a(an),b(bn);
    for(int i=0;i<an;i++)
    {
        a[i] = v[l+i];
    }
    for(int j=0;j<bn;j++)
    {
        b[j] = v[mid+1+j];
    }

    int i = 0;
    int j = 0;
    int k = l;
    while(i<an && j<bn)
    {
        if(a[i]<b[j])
        {
            v[k++] = a[i++];
        }
        else
        {
            v[k++] = b[j++];
        }
    }
    while(i<an)
    {
        v[k++] = a[i++];
    }
    while(j<bn)
    {
        v[k++] = b[j++];
    }
}

void mergeSort(vector<int>&v,int l, int r)
{
    // base case
    if(l>=r)
    {
        return;
    }
    int mid = (l+r)/2;
    mergeSort(v,l,mid);
    mergeSort(v,mid+1,r);
    merge(v,l,mid,r);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    mergeSort(v,0,n-1);

    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

// Time Complexity : O(nlogn) All the cases.
// Space Complexity : O(n) bcoz temporary array is used which takes n space. 
// Merge sort is stable sorting algorithm.

// Application of merge sort :
// 1. For large data sets. 

// Drawbacks of merge sort :
// 1. slower for smaller data sets or tasks.
// 2. It takes O(n) space .
// 3. Goes through whole process even if array is sorted.