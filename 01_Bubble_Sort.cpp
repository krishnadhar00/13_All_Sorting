// what is Sorting :
// Ordering of element either in increasing or decreasing order.
// Bubble Sort : It basically see the adjacent element if they are in worng order the swapping will happen.
// 1. Repeatedly swap two adjacent element if it is in wrong order.
// 2. Traverse from left and compare adjacent elements and the higher one is placed at right side. 
// 3. This process is then continued to find the second largest and place it and so on until the data is sorted.

// For optimizing the bubble sort in the case of nearly sorted array like assume in first pass all the array element get sorted so we don't need to go for al the pases for that we have to use boolean to check if there is no any swap inside j loop then break the i loop and ans get printed.

// Stable or Unstable sorting :
// Stable means doesn't disturb the order of element with same value.
// Unstable means which disturb the order of element with same value.
// Eg : 20 30 40 50 30*   
// Stable : 20 30 30* 40 50     and unstable : 20 30* 30 40 50 
// So bubble sort is a stable sorting algorithm.

#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int> &v)
{
    int n= v.size();
    bool flag;
    // i will be consider as a no. of passes, so for n element n-1 no. of passes will be there.
    for(int i=0;i<n-1;i++)
    {
        flag = false;
        for(int j=0;j<n-i-1;j++)  // j is for checking the adjacent element order.
        {
            if(v[j]>v[j+1])
            {
                // swap(v[j],v[j+1]);    // Inbuilt Function

                // Swapping using another variable
                // int temp = v[j];
                // v[j]=v[j+1];
                // v[j+1] = temp;

                // Swapping by not using another varible.
                v[j]=v[j]+v[j+1];
                v[j+1]=v[j]-v[j+1];
                v[j] =v[j]-v[j+1];
                flag = true;
            }
        }
        if(flag==false)
        {
            break;
        }
    }
    return;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    bubbleSort(v);

    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

// Total number of passes : n-1;
// Total number of comparison : n*(n-1)/2
// Maximum number of swaps in worst case(means array in descending order) : n*(n-1)/2
// Time Complexity : O(n^2) worst, O(n) Best, O(n^2) Average
// Space Complexity : O(1)