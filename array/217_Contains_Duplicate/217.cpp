#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> s;
        std::unordered_set<int>::iterator it;
        for(int i = 0; i < nums.size(); i++){
            it = s.find(nums[i]);
            if(it == s.end()){
                s.insert(s.end(), nums[i]);
            }
            else
                return true;
        }
        return false;
    }
};
