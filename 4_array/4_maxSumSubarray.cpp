// Kadade Algorithm  only for positive nummbers

#include <iostream>
using namespace std;
int maxSumSubarray(int *arr, int n)
{
    int currSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    return maxSum;
}
int main()
{
    int arr[5] = {2, 4, -7, -3, 9};
    int n = sizeof(arr) / sizeof(int);
    cout << maxSumSubarray(arr, n);
    return 0;
}