#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using std::map;
using std::vector;
using std::cout;
using std::sort;
using std::unique;

class Solution {
    int Cn2(int num)
    {
        if (num < 2) return 0;
        int a = 1, b = 2;
        num -= 2;
        while (num)
        {
            a += b;
            b += 1;
            num--;
        }
        return a;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int lo = 0;
        int hi = nums[nums.size() - 1] - nums[0];
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            int count = 0, left = 0;
            for (int right = 0; right < nums.size(); ++right) {
                while (nums[right] - nums[left] > mi) left++;
                count += right - left;
            }
            //count = number of pairs with distance <= mi
            if (count >= k) hi = mi;
            else lo = mi + 1;
        }
        return lo;
    }
};

void test(vector<int>& nums, int k)
{
    Solution s;
    cout << s.smallestDistancePair(nums, k) << "\n";
}

int main()
{
    test(vector<int>({ 1,3,3,2,1 }), 1);
    test(vector<int>({ 1,3,3,2,1 }), 2);
    test(vector<int>({ 1,3,3,2,1 }), 3);
    test(vector<int>({ 1,3,3,2,1 }), 4);
    test(vector<int>({ 1,3,3,2,1 }), 5);
    test(vector<int>({ 1,3,3,2,1 }), 6);
    test(vector<int>({ 1,3,3,2,1 }), 7);
    test(vector<int>({ 1,3,3,2,1 }), 8);
    test(vector<int>({ 1,1 }), 1);
    test(vector<int>({ 1,3,1 }), 1);
    test(vector<int>({ 1,3,1 }), 2);
    test(vector<int>({ 1,3,1 }), 3);
    return 0;
}