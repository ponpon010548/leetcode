#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> m;
        std::unordered_map<int, int>::iterator it;
        int index;
        for(int i = 0; i < nums.size(); i++){
            it = m.find(nums[i]);
            if(it == m.end())
                m[nums[i]] = i;
            else{
                index = m[nums[i]];
                if(i - index <= k)
                    return true;
                else
                    m[nums[i]] = i;
            }
        }
        return false;
    }
};
