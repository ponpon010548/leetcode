#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int len = nums.size(), count = 1;
        if(len < 3)
            return nums[0];
        std::sort(nums.begin(), nums.end());
        for(int i = 1; i < len; i++){
            nums[i] == nums[i-1] ? count++ : count = 1;
            if(count > len / 2){
                count = nums[i];
                break;
            }
        }
        return count;
    }
};

int main(int argc, char *argv[])
{
    std::vector<int> nums;
    Solution sol;
    int x;
    std::cout << "Your Input:\n";
    while(std::cin.peek() != '\n'){
        std::cin >> x;
        std::cout << x << " ";
        nums.insert(nums.end(), x);
    }
    x = sol.majorityElement(nums);
    std::cout << "\nOutput:\n" << x << std::endl;
    return 0;
}
