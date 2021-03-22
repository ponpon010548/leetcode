#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> majorityElement(std::vector<int>& nums) {
        std::vector<int> res;
        int len = nums.size();
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
        int m1 = nums[0], m2 = nums[0] + 1, count1 = 1, count2 = 0;
        for(int i = 1; i < len; i++){
            if(m1 == nums[i])
                count1++;
            else if(m2 == nums[i])
                count2++;
            else if(count1 == 0){
                m1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0){
                m2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(int i = 0; i < len; i++){
            if(nums[i] == m1)
                count1++;
            if(nums[i] == m2)
                count2++;
        }
        len /= 3;
        if(count1 > len)
            res.push_back(m1);
        if(count2 > len && m1 != m2)
            res.push_back(m2);
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
