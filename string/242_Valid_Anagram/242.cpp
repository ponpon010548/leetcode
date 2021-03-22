#include <iostream>
#include <iterator>
#include <string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if(s.size() != t.size())
            return false;
        int count[26] = {0};
        for(int i = 0; i < s.size(); i++){
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(count[i] != 0)
                return false;
        }
        return true;
    }
};

int main(int argc, char *argv[])
{
    std::string s, t;
    Solution sol;
    bool res;
    std::getline(std::cin, s);
    std::getline(std::cin, t);
    res = sol.isAnagram(s, t);
    std::cout << res << std::endl;
    return 0;
}
