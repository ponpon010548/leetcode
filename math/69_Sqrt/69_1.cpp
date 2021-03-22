#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
            return 0;
        if(x == 1)
            return 1;
        return BinSearch(0, x, x);
    }
private:
    int BinSearch(const int a, const int b, const int &target){
        int mid = (a + b) / 2;
        int l = target / mid, r = target / (mid + 1);
        if(mid <= l && (mid + 1) >= r)
            return r == (mid + 1) ? mid + 1 : mid;
        else if(mid < l)
            return BinSearch(mid + 1, b, target);
        else
            return BinSearch(a, mid - 1, target);
    }
};
