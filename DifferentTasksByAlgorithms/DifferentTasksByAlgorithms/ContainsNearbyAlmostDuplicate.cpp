#include <map>
#include <iostream>
#include <vector>

using std::map;
using std::cout;
using std::vector;

class Solution {
    map<int, int> mp;

public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int maxIndex, int maxValue)
    {
        if (!maxIndex)
        {
            return false;
        }

        mp.clear();
        mp[nums[0]]++;
        maxIndex = maxIndex < nums.size() ? maxIndex : nums.size() - 1;
        for (int i = 1, j = 1; i < nums.size(); i++, j++)
        {

            mp[nums[i]]++;
            if (j > maxIndex) {
                auto it = mp.find(nums[i - maxIndex - 1]);
                if (it != mp.end())
                {
                    if (it->second > 1)
                        it->second--;
                    else
                        mp.erase(it);
                }
            }

            auto it = mp.upper_bound(nums[i]);
            if (it != mp.end() && abs((static_cast<long>(it->first) - static_cast<long>(nums[i])) <= maxValue))
                return true;

            if (it == mp.begin())
                continue;
            it--;

            if (it->first == nums[i])
            {
                if (it->second > 1)
                {
                    return true;
                }
                if (it == mp.begin())
                    continue;
                it--;
            }

            if (abs(static_cast<long>(it->first) - static_cast<long>(nums[i])) <= maxValue)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    cout << s.containsNearbyAlmostDuplicate(vector<int>({ 1,2,3,1 }), 3, 0) << "\n";
    cout << s.containsNearbyAlmostDuplicate(vector<int>({ 5,15,20,25,5,15,20,25 }), 4, 0) << "\n";
    cout << s.containsNearbyAlmostDuplicate(vector<int>({ 1,0,1,1 }), 1, 0) << "\n";
    cout << s.containsNearbyAlmostDuplicate(vector<int>({ 1 }), 1, 0) << "\n";
    cout << s.containsNearbyAlmostDuplicate(vector<int>({ 1,2 }), 1, 1) << "\n";
    return 0;
}