// LeetCode.cpp : Defines the entry point for the application.
//

#include "TheSkylineProblem.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int, int> mp;

        for (int i = 0; i < buildings.size(); i++) {
            int left = buildings[i][0];
            int right = buildings[i][1];
            int height = buildings[i][2];

            cout << left << " " << right << " " << height << "\n";
            auto it = mp.begin();
            while (it != mp.end()) {
                cout << "{ " << it->first << ", " << it->second << "} ";
                it++;
            }
            cout << "\n";

            if (mp.empty()) {
                mp[left] = height;
                mp[right] = 0;
            } else {
                /*processing the right edge of the new building*/
                auto itR = --mp.upper_bound(right);
                if (itR->second >= height) 
                    continue;
                else{
                    mp[right] = itR->second;
                }
                if (itR->first == right) --itR;
                if (itR != mp.begin()) {
                    auto itRR = itR;
                    itRR--;
                    while (itRR->first > left && itRR->second < height) {
                        cout << "*";
                        mp.erase(itR);
                        itR = itRR;
                        itRR--;
                    }
                    if (itRR->second > height) {
                        if (itR->first > left && itR->second < height) itR->second = height;
                    }
                    else {
                        if (itR->first > left) mp.erase(itR);
                    }
                    cout << "itRR " << itRR->first << "\n";
                }

                auto it = mp.begin();
                while (it != mp.end()) {
                    cout << "{ " << it->first << ", " << it->second << "} ";
                    it++;
                }
                cout << "\n";

                /*processing the left edge of the new building*/
                auto itL = mp.upper_bound(left);
                itL--;
                if (left != itL->first) {
                    if (itL->second < height) mp[left] = height;
                }
                else {
                    if (itL->second < height) {
                        if (itL != mp.begin()) {
                            itL--;
                            if (itL->second == height)
                                mp.erase(++itL);
                            else if (itL->second < height)
                                mp[left] = height;
                            else {
                                itL++;
                                if (itL->second < height)
                                    itL->second = height;
                            }
                        }
                        else {
                            if (itL->second < height) mp[left] = height;
                        }
                    }
                }
            }
        }
        cout << "\n-<>-\n";
        auto it = mp.begin();
        while (it != mp.end()) {
            cout << "{ " << it->first << ", " << it->second << "} ";
            it++;
        }
        cout << "\n";

        //cout << "\n";
        vector<vector<int>> ret(mp.size(), vector<int>(2, 0));
        int i = 0;
         it = mp.begin();
        while (it != mp.end()) {
            ret[i][0] = it->first;
            ret[i++][1] = it->second;
            it++;
        }
        ret.resize(i);
        return ret;
    }
};

void printV(const vector<vector<int>>& b) {
    cout << "\n{";
    for (int i = 0; i < b.size(); i++) {
        cout << "{ " << b[i][0] << ", " << b[i][1] << "}, ";
    }
    cout << "}\n";
    cout << "----------------\n";
}

int main()
{
    vector<vector<int>> exmp1({ {0,2,1}});
    vector<vector<int>> exmp2({ {0,2,1}, {1,3,1} });
    vector<vector<int>> exmp3({ {0,2,1}, {2,4,1} });
    vector<vector<int>> exmp4({ {0,2,2}, {2,4,1} });
    vector<vector<int>> exmp5({ {0,2,2}, {1,3,1} });
    vector<vector<int>> exmp6({ {0,2,2}, {0,2,1},{0,2,3}, });
    vector<vector<int>> exmp7({ {0,2,1}, {0,2,2},{0,2,3}, });
    vector<vector<int>> exmp8({ {0,2,3}, {0,2,1},{0,2,2}, });
    vector<vector<int>> exmp9({ {0,2,3}, {0,2,1},{0,2,2}, {2,4,3}, {2,4,1},{2,4,2}, });
    vector<vector<int>> exmp10({ {0,2,3}, {0,2,1},{0,2,2}, {2,4,1}, {2,4,2},{2,4,3}, });
    vector<vector<int>> exmp11({ {0,2,3}, {0,2,1},{0,2,2}, {3,4,1}, {3,4,2},{3,4,3}, });
    vector<vector<int>> exmp12({ {0,1,2}, {0,3,1},{2,3,2}, });
    vector<vector<int>> exmp13({ {0,1,3}, {0,2,2},{0,3,1}, });
    vector<vector<int>> exmp14({ {0,3,1}, {0,1,3},{0,2,2}, });
    vector<vector<int>> exmp15({ {0,3,1}, {1,3,2},{2,3,3}, });
    vector<vector<int>> exmp16({ {0,3,1}, {1,3,2},{1,2,3}, });
    vector<vector<int>> exmp17({ {0,3,2}, {1,2,2} });
    vector<vector<int>> exmp18({ {1,10,5}, {2,10,6},{3,9,7},{3,11,4} });
    vector<vector<int>> exmp19({ {1,38,219},{2,19,228},{2,64,106},{3,80,65},{3,84,8},{4,12,8},{4,25,14},{4,46,225},{4,67,187},{5,36,118},{5,48,211},{5,55,97},{6,42,92},{6,56,188},{7,37,42},{7,49,78},{7,84,163},{8,44,212},{9,42,125},{9,85,200},{9,100,74},{10,13,58},{11,30,179},{12,32,215},{12,33,161},{12,61,198},{13,38,48},{13,65,222},{14,22,1},{15,70,222},{16,19,196},{16,24,142},{16,25,176},{16,57,114},{18,45,1},{19,79,149},{20,33,53},{21,29,41},{23,77,43},{24,41,75},{24,94,20},{27,63,2},{31,69,58},{31,88,123},{31,88,146},{33,61,27},{35,62,190},{35,81,116},{37,97,81},{38,78,99},{39,51,125},{39,98,144},{40,95,4},{45,89,229},{47,49,10},{47,99,152},{48,67,69},{48,72,1},{49,73,204},{49,77,117},{50,61,174},{50,76,147},{52,64,4},{52,89,84},{54,70,201},{57,76,47},{58,61,215},{58,98,57},{61,95,190},{66,71,34},{66,99,53},{67,74,9},{68,97,175},{70,88,131},{74,77,155},{74,99,145},{76,88,26},{82,87,40},{83,84,132},{88,99,99} });
    vector<vector<int>> exmp20{ {0, 5, 7}, { 5,10,7 }, { 5,10,12 }, { 10,15,7 }, { 15,20,7 }, { 15,20,12 }, { 20,25,7 } };
    Solution s;

    printV(s.getSkyline(exmp1));
    printV(s.getSkyline(exmp2));
    printV(s.getSkyline(exmp3));
    printV(s.getSkyline(exmp4));
    printV(s.getSkyline(exmp5));
    printV(s.getSkyline(exmp6));
    printV(s.getSkyline(exmp7));
    printV(s.getSkyline(exmp8));
    printV(s.getSkyline(exmp9));
    printV(s.getSkyline(exmp10));
    printV(s.getSkyline(exmp11));
    printV(s.getSkyline(exmp12));
    printV(s.getSkyline(exmp13));
    printV(s.getSkyline(exmp14));
    printV(s.getSkyline(exmp15));
    printV(s.getSkyline(exmp16));
    printV(s.getSkyline(exmp17));
    printV(s.getSkyline(exmp18));
    printV(s.getSkyline(exmp19));
    printV(s.getSkyline(exmp20));
    return 0;
}