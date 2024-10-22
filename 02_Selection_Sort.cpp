// Selection Sort : 
// 1. Reatedly finding the minimum element in unsorted array and place it at beginning or at the starting of the array.
// 2. Repeatedly means untill array is sorted.
// 3. Total number of passes = n-1.
// 4. For ith iteration we are selecting element for ith position that is why it is caled selection sort.

#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>&v)
{
    int n=v.size();
    for(int i=0;i<n-1;i++)   // i is for n-1 passes.
    {
        int min_index = i;
        // Finding the minimum element in unsorted array
        for(int j=i+1;j<n;j++)
        {
            if(v[j]<v[min_index])
            {
                min_index = j;
            }
        }
        // placing minimum element at the beginninga or swapping two values.
        if(i!=min_index)
        {
            swap(v[i],v[min_index]);
        }
    }
    return;
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
    selectionSort(v);

    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

// Time Complexity : O(n^2) worst, O(n^2) best, O(n^2) average.
// Space Complexity : O(1)
// Maximium Swaps : O(n)
// It is unstable sorting algorithm.
// Bubble sort has more swaps than selection sort so for swapping selection is good.