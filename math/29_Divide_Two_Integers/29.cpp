#include <iostream>

class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;
        if(divisor == 1)
            return dividend;
        if(divisor == -1)
            return dividend == INT32_MIN ? INT32_MAX : -dividend;
        if(dividend > 0){
            dividend = -dividend;
            sign *= -1;
        }
        if(divisor > 0){
            divisor = -divisor;
            sign *= -1;
        }
        int res = 0;
        while(dividend <= divisor){
            dividend -= divisor;
            res++;
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
