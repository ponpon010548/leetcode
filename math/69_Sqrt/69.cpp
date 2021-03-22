#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        int res = 1;
        while( res < x / res){
           res++;
        }
        return res - 1; 
    }
};
