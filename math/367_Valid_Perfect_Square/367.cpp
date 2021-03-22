#include <iostream>

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1)
            return true;
        int l = 1, r = num - 1;
        while(r >= l){
            int mid = (l + r) / 2;
            if(mid == num / mid && num % mid == 0)
                return true;
            if(mid > num / mid)
                r = mid - 1;
            else
                l = mid + 1;
            }
        return false;
    }
};
