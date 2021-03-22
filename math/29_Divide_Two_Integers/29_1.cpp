#include <functional>
#include <iostream>
#include <iterator>
#include <pthread.h>
#include <string>
#include <bitset>

class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;
        if(divisor == 1)
            return dividend;
        if(divisor == -1)
            return dividend == INT32_MIN ? INT32_MAX : -dividend;
        int res = 0;
        if(divisor < 0){
            divisor = -divisor;
            sign *= -1;
        }
        if(dividend == INT32_MIN){
            dividend += divisor;
            res++;
            dividend--;
            dividend = -dividend;
            sign *= -1;
        }
        if(dividend < 0){
            dividend = -dividend;
            sign *= -1;
        }
        if(dividend < divisor)
            return 0;
        std::string binaryDividend = std::bitset<32> (dividend).to_string();
        std::cout << binaryDividend << std::endl;
        std::string binaryDivisor = std::bitset<32> (divisor).to_string();
        int begin = 0;
        while(binaryDividend[begin] == '0') begin++;
        binaryDividend = binaryDividend.substr(begin, 32 - begin);
        begin = 0;
        while(binaryDivisor[begin] == '0') begin++;
        binaryDivisor = binaryDivisor.substr(begin, 32 - begin);
        for(int i = 0; i < binaryDividend.size(); i++){
            bool flag = false;
            for(int j = 0; j < binaryDivisor.size(); j++){
                if(binaryDividend[i+j] > binaryDividend[j])
            }
        }

        return res * sign;
    }
};

int main(int argc, char *argv[])
{
    int dividend, divisor;
    Solution sol;
    std::cin >> dividend >> divisor;
    std::cout << "Your Input:\n" << "dividend = " << dividend << " ,divisor = " << divisor;
    std::cout << std::endl;
    dividend = sol.divide(dividend, divisor);
    std::cout << "Output:\n" << dividend << std::endl;
    return 0;
}
