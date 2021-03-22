#include <iostream>
#include <string>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        int c1 = 0, c2 = 0, v;
        std::string res = num1 + num2;
        for(int i = 0; i < res.size(); i++)
            res[i] = '0';
        for(int i = num1.size() - 1; i >= 0; i--){
            c1 = 0;
            for(int j = num2.size() - 1; j >= 0; j--){
                v = (num1[i] - '0') * (num2[j] - '0') + res[i+j+1] - '0';
                if(v > 9){
                    c1 = v / 10;
                    v %= 10;
                    res[i+j] += c1;
                }
                res[i+j+1] =  v + '0';
            }
        }
        return res[0] > '0' ? res : res.substr(1, res.size() - 1);
    }
};

int main(int argc, char *argv[])
{
    std::string num1, num2;
    Solution sol;
    std::getline(std::cin, num1);
    std::getline(std::cin, num2);
    std::cout << "Your Input:\nnum1 = " << num1 << ", num2 = " << num2 << std::endl;
    num1 = sol.multiply(num1, num2);
    std::cout << "Output:\n" << num1 << std::endl;
    return 0;
}
