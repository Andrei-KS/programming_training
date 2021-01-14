#include "FindClosestElements.h"

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::vector;
using std::sort;

class Solution {
    bool IsAClosestThanB(vector<int>& arr, int a, int b, int x)
    {
        return (abs(arr[a] - x) < abs(arr[b] - x) ||
            (abs(arr[a] - x) == abs(arr[b] - x)) && a < b);
    }

public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int aSize = arr.size();
        k = k <= 0 ? 1 : k;
        k = k > aSize ? aSize : k;

        /* search low bound*/
        int left = 0;
        int right = aSize - 1;
        int mid = 0;
        while (left + 1 < right)
        {
            mid = left + (right - left) / 2;
            if (arr[mid] < x)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }

        int low_bound = IsAClosestThanB(arr, left, right, x) ? left : right;

        vector<int> ans(k, 0);
        ans[k - 1] = arr[low_bound];
        k--;
        left = low_bound - 1;
        right = low_bound + 1;
        while (k)
        {
            if (left >= 0 && right < aSize)
            {
                if (IsAClosestThanB(arr, left, right, x))
                {
                    ans[k - 1] = arr[left];
                    left--;
                }
                else
                {
                    ans[k - 1] = arr[right];
                    right++;
                }
            }
            else if (left >= 0)
            {
                ans[k - 1] = arr[left];
                left--;
            }
            else
            {
                ans[k - 1] = arr[right];
                right++;
            }
            k--;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

void test(vector<int>& nums, int k, int x)
{
    Solution s;
    vector<int> result = s.findClosestElements(nums, k, x);
    cout << nums.size() << " { ";
    for (auto el : result)
    {
        cout << el << ", ";
    }
    cout << "\b\b}\n\n";
}

int main() {
    test(vector<int>({ 1, 2, 3, 4, 5, 6 }), 1, 3);
    test(vector<int>({ 1, 2, 3, 4, 5, 6 }), 2, 3);
    test(vector<int>({ 1, 2, 3, 4, 5, 6 }), 3, 3);
    test(vector<int>({ 1, 2, 3, 4, 5, 6 }), 4, 3);
    test(vector<int>({ 1, 2, 3, 3, 4, 5, 6 }), 4, 3);
    test(vector<int>({ 1, 2, 3, 4, 4, 5, 6 }), 4, 3);
    test(vector<int>({ 1}), 1, 100);
    test(vector<int>({ 1}), 1, 1);
    test(vector<int>({ -4, -3, -2, -1, 0 ,1, 2, 3, 4, 5, 6 }), 200, 3);
    test(vector<int>({ -4, -3, -2, -1, 0 ,1, 2, 3, 4, 5, 6 }), -1, 3);
    return 0;
}