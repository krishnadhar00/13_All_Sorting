// This algorithm also work on the divide and conquer algorithm.
// QuickSort is a sorting algorithm based on the Divide and Conquer that picks an element as a pivot and partitions the given array around the picked pivot by placing the pivot in its correct position in the sorted array.
// this is for commiting the github repository
#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>&v, int first, int last)
{
    int pivot = v[last]; 
    // For inserting element < pivot
    int i = first-1; 
    // For finding element < pivot
    int j = first;

    for(;j<last;j++)
    {
        if(v[j] < pivot)
        {
            i++;
            swap(v[i],v[j]);
        }
    }

    // now i is pointing to the last element < pivot
    // correct position for the pivot element is i+1
    swap(v[i+1],v[last]);
    return i+1;
}

void quickSort(vector<int>&v, int first, int last)
{
    // base case 
    if(first>=last)
    {
        return;
    }
    // recursive call
    int pi = partition(v,first,last);
    quickSort(v,first,pi-1);
    quickSort(v,pi+1,last);
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

    quickSort(v,0,n-1);

    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

// Time complexity : O(n^2) worst, O(nlogn) best, O(nlogn) average.
// space complexity : O(n) due to recursive call.
// Quick sort is not stable sorting algortihm. 
// Quick sort performs better in smaller data sets.
