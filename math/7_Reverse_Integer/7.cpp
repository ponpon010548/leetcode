#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        while(x){
            mod = x % 10;
            x /= 10;
            if(res < MAX && res > MIN)
                res = res * 10 + mod;
            else
                return 0;
        }
        return res;
    }
private:
    int mod, res = 0, MAX = INT32_MAX / 10 - 1, MIN = INT32_MIN / 10 + 1;
};

int main(int argc, char *argv[])
{
    int x;
    Solution sol;
    cin >> x;
    cout << "Your Input:\n" << x << endl;
    x = sol.reverse(x);
    cout <<"Output:\n" << x << endl;
    return 0;
}
