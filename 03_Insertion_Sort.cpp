// Repeatedly take element from unsorted subarray and insert in sorted subarray at its correct position.
// We start with second element of the array as first element in the array is assumed to be sorted.
// Compare second element with the first element and check if the second element is smaller then swap them.
// Move to the third element and compare it with the second element, then the first element and swap as necessary to put it in the correct position among the first three elements.
// Continue this process, comparing each element with the ones before it and swapping as needed to place it in the correct position among the sorted elements.
// Repeat until the entire array is sorted.

#include<iostream>
#include<vector>
using namespace std;
void insertionSort(vector<int>&v)
{
    int n = v.size();
    for(int i=1;i<n;i++)
    {
        int current_element = v[i];
        int j = i-1;
        while(j>=0 && v[j]>current_element)
        {
            v[j+1] = v[j];
            j--; 
        }
        v[j+1] = current_element;
    }
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

    insertionSort(v);

    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

// Time Complexity : O(n^2) worst, O(n^2) average, O(n) best
// Space complexity : O(1)
// It is stable sorting algorithm.