#include <iostream>
#include <string>
#include <vector>

class Solution {
    void nameProcessing(std::string& name, std::vector<std::string>& namesAlongPath)
    {
        if (name.length() == 1 && name == ".")
        {

        }
        else if (name.length() == 2 && name == "..")
        {
            if (!namesAlongPath.empty())
            {
                namesAlongPath.pop_back();
            }
        }
        else if (name.length() > 0)
        {
            namesAlongPath.push_back(name);
        }
    }

public:
    std::string simplifyPath(std::string& path) {
        std::vector<std::string> namesAlongPath;
        std::string name;
        const int LENGHT_PATH_NAME = 128;
        name.reserve(LENGHT_PATH_NAME);
        for (int i = 0; i < path.length(); i++)
        {
            if (path[i] == '/')
            {
                nameProcessing(name, namesAlongPath);
                name.clear();
            }
            else
            {
                name.push_back(path[i]);
            }
        }
        nameProcessing(name, namesAlongPath);

        name.clear();
        for (std::string nameAlongPath : namesAlongPath)
        {
            name.push_back('/');
            name.insert(name.end(), nameAlongPath.begin(), nameAlongPath.end());
        }
        if (name.empty())
            return "/";
        name.resize(name.size());
        return name;
    }
};

void test(std::string path, std::string correctAns)
{
    Solution s;
    std::string canonicalPath = s.simplifyPath(path);
    std::cout << "TEST : " << path << "\n"
        << "Answer = " << canonicalPath << "\n"
        << "Correct answer = " << correctAns << "\n";
    if (canonicalPath == correctAns)
    {
        std::cout << "---ACCEPT---\n";
    }
    else
    {
        std::cout << "---FAIL---\n";
    }
    std::cout << "\n";
}


int main()
{
    test("/", "/");
    test("/.", "/");
    test("/..", "/");
    test("/home/", "/home");
    test("/home///////","/home");
    test("/home/../", "/");
    test("/a//b////c/d//././/..", "/a/b/c");

    return 0;
}