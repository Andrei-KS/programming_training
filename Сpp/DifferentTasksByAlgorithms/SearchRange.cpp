#include "SearchRange.h"

#include <vector>
#include <iostream>

using std::vector;
using std::cout;

class Solution {
    int search(vector<int>& nums, int target, int& left, int& right)
    {
        if (nums.size() == 0)
            return -1;
        int mid = -1;
        while (left + 1 < right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid;
            else
                right = mid;
        }
        if (nums[left] == target) return left;
        if (nums[right] == target) return right;
        return -1;
    }

    bool leftCmp(int left, int right) { return left < right; }
    bool rightCmp(int left, int right) { return left <= right; }

    int findBound(vector<int>& nums, int target,Solution* obj, bool (Solution::*cmp)(int,int), int left, int right)
    {
        int mid = 0;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            //cout << mid << " " << nums[mid] << "\n";
            if ((obj->*cmp)(nums[mid],target))
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left]==target?left:left-1;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        //cout << "searchRange(...):\n";
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        //cout << "left = " << left << ", right = " << right << "\n";
        int mid = search(nums, target, left, right);
        //cout << mid << "\n";
        //cout << "left = " << left << ", right = " << right << "\n";
        if (mid == -1)
            return vector<int>({ -1,-1 });
        else
            return vector<int>({ findBound(nums,target, this, &Solution::leftCmp, left, mid),findBound(nums,target, this, &Solution::rightCmp, mid,right) });

    }
};

void test(vector<int>& nums, int target)
{
    Solution s;
    vector<int> result = s.searchRange(nums, target);
    cout << nums.size() << " { ";
    for (auto el : result)
    {
        cout << el << ", ";
    }
    cout << "\b\b}\n\n";
}

int main() 
{
    test(vector<int>{ 1,2,3,3,4,5,6 }, 3);
    test(vector<int>{ 1,2,3,3,3,3,3,3,3,3,3,3,3,4,5,6 }, 3);
    test(vector<int>{ 1,2,3,3,3,3,3,3,3,3,3,3,4,5,6 }, 3);
    test(vector<int>{5, 7, 7, 8, 8, 10}, 8);
    return 0;
}