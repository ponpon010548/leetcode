#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> majorityElement(std::vector<int>& nums) {
        std::vector<int> res;
        int len = nums.size(), count = 1;
        if(len == 1)
            return nums;
        if(len == 2){
            if(nums[0] == nums[1]){
                res.push_back(nums[0]);
                return res;
            }
            else
                return nums;
        }
        std::sort(nums.begin(), nums.end());
        for(int i = 1; i < len; i++){
            if(nums[i] == nums[i-1])
                count++;
            else if(count > len / 3){
                res.push_back(nums[i-1]);
                count = 1;
            }
            else
                count = 1;
        }
        if(count > len / 3)
            res.push_back(nums[len-1]);
        return res;
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
    nums = sol.majorityElement(nums);
    std::cout << std::endl;
    for(int i = 0; i < nums.size(); i++)
        std::cout << nums[i] << " ";
    std::cout << std::endl;
    return 0;
}
