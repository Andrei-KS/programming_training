#include <vector>
#include <set>

class Solution {
public:
    std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k) {
        int M = mat.size();
        int N = mat[0].size();

        std::set<int> curSet;
        for (int i = 0; i < M; i++)
            curSet.insert(i);

        std::vector<int> ans(M, -1);
        int curIndexAns = 0;
        for (int i = 0; !curSet.empty() && i < N; i++)
        {
            for (auto it = curSet.begin(); it != curSet.end();)
            {
                if (mat[*it][i] == 0)
                {
                    ans[curIndexAns] = *it;
                    curIndexAns++;
                    it = curSet.erase(it);
                }
                else
                {
                    it++;
                }
            }
        }
        for (auto it = curSet.begin(); it != curSet.end(); it++)
        {
            ans[curIndexAns] = *it;
            curIndexAns++;
        }
        ans.resize(k);
        return ans;
    }
};

#include <iostream>

void test(std::vector<std::vector<int>>& mat, int k, std::vector<int> correctAns)
{
    Solution s;
    std::vector<int> ans = s.kWeakestRows(mat,k);
    std::cout << "TEST : \n"
        << "Answer : ";
    for (auto el : ans)
        std::cout << el << " ";
    std::cout << "\n"
        << "Correct answer = ";
    for (auto el : correctAns)
        std::cout << el << " ";
    std::cout << "\n";

    bool isCorrect = ans.size() == correctAns.size();
    if (isCorrect)
    {
        for (int i = 0; i < correctAns.size(); i++)
        {
            if (ans[i] != correctAns[i])
            {
                isCorrect = false;
                break;
            }
        }
    }

    if (isCorrect)
    {
        std::cout << "---ACCEPT---\n";
    }
    else
    {
        std::cout << "---FAIL---\n";
    }
    std::cout << "\n";
}


int main() {
    test(std::vector<std::vector<int>>{ {1, 1, 0, 0, 0}, { 1,1,1,1,0 }, { 1,0,0,0,0 }, { 1,1,0,0,0 }, { 1,1,1,1,1 }}, 3, std::vector<int>{2, 0, 3});
    test(std::vector<std::vector<int>>{ {1, 0, 0, 0}, { 1,1,1,1 }, { 1,0,0,0 }, { 1,0,0,0 }}, 2, std::vector<int>{0, 2});
    return 0;
}