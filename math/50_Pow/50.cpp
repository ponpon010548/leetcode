#include <iostream>
#include <ostream>
//non-recursion version

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        if (n == 0 || x == 1 || x == 0)
            return 1;
        if (n < 0){
            x = 1 / x;
            ++n;
            n = -n;
            res *= x;
        }
        while(n > 0){
            if(n % 2 != 0)
                res *= x;
            x*=x;
            n/=2;
        }
        return res;
    }
};


int main(int argc, char *argv[])
{
    double x;
    int n;
    Solution sol;
    std::cin >> x >> n;
    std::cout << "Your Input:\nx = " << x << ", n = " << n << std::endl;
    x = sol.myPow(x, n);
    std::cout << "Output:\n" << x << std::endl;
    return 0;
}
