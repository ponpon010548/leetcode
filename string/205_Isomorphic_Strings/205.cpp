#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        std::unordered_map<char, char> m;
        std::unordered_map<char, bool> check;
        std::unordered_map<char, char>::iterator it;
        for(int i = 0; i < s.size(); i++){
            it = m.find(s[i]);
            if(it == m.end()){
                if(check.find(t[i]) != check.end())
                    return false;
                m[s[i]] = t[i];
                check[t[i]] = true;
            }
            else
                if(it -> second != t[i])
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
    std::cout << "Your Input\ns = " << s << ", t = " << t << std::endl;
    res = sol.isIsomorphic(s, t);
    std::cout << res << std::endl;
    return 0;
}
