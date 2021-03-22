#include <iostream>
#include <ostream>
#include <vector>
#include <string>

class Solution{
public:
    bool canWin(std::string s){
        for(int i = 1; i < s.size(); i++){
            if(s[i] == '+' && s[i - 1] == '+'){
                s[i] = s[i - 1] = '-';
                if(!canWin(s))
                    return true;
                s[i] = s[i - 1] = '+';
            }
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    bool res;
    Solution sol;
    std::string s;
    std::getline(std::cin, s);
    std::cout << "Your Input: \n" << s << std::endl;
    res = sol.canWin(s);
    std::cout << "Output:\n" << res << std::endl;
    return 0;
}
