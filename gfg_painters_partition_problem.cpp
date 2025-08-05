#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    bool isValid(vector<int> &arr, int k, int n, int maxAllowedTime)
    {
        int painters = 1;
        int time = 0;

        for (int i = 0; i < n; i++)
        {
            if (time + arr[i] <= maxAllowedTime)
            {
                time += arr[i];
            }
            else
            {
                painters++;
                time = arr[i];
            }
        }

        return painters <= k;
    }

    int minTime(vector<int> &arr, int k)
    {

        int minTime = INT_MIN, sum = 0, n = arr.size();

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            minTime = max(minTime, arr[i]);
        }

        int ceil = sum, floor = minTime, ans = -1;

        while (floor <= ceil)
        {
            int mid = floor + (ceil - floor) / 2;

            if (isValid(arr, k, n, mid))
            {
                ans = mid;
                ceil = mid - 1;
            }
            else
            {
                floor = mid + 1;
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> arr = {10, 20, 30, 40};
    int k = 2;
    Solution sol;

    int result = sol.minTime(arr, k);
    cout << "Minimum Time = " << result << endl;
    return 0;
}