#include <iostream>
#include <string>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        int m[128] = {0};
        bool check[128] = {false};
        for(int i = 0; i < s.size(); i++){
            if(m[s[i]] == 0){
                if(check[t[i]])
                    return false;
                m[s[i]] = t[i];
                check[t[i]] = true;
            }
            else
                if(m[s[i]] != t[i])
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
