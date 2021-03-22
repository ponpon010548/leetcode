#include <iostream>
#include <string>
#include <vector>

class Solution{
public:
    std::vector<std::string> generatePossibleNextMoves(std::string s){
        std::vector<std::string> res;
        for(int i = 1; i < s.size(); i++){
            if(s[i-1] == '+' && s[i] == '+'){
                s[i - 1] = s[i] = '-';
                res.push_back(s);
                s[i - 1] = s[i] = '+';
            }
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    std::vector<std::string> res;
    Solution sol;
    std::string s;
    std::getline(std::cin, s);
    std::cout << "Your Input: \n" << s << std::endl;
    res = sol.generatePossibleNextMoves(s);
    std::cout << "Output:\n";
    for(int i = 0; i < res.size(); i++){
        std::cout << res[i] << std::endl;
    }
    return 0;
}
