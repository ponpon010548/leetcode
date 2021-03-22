#include <iostream>
#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int len = nums.size(), count = 1, majority = nums[0];
        if(len < 3)
            return nums[0];
        for(int i = 1; i < len; i++){
            if(count == 0){
                majority = nums[i];
                count = 1;
            }
            else if(majority == nums[i])
                count++;
            else
                count--;
        }
        return majority;
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
