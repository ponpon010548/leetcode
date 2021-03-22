#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        size_t len = nums.size();
        int p = 0, end = len - 1;
        while(p <= end){
            if(nums[p] == val){
                swap(nums[p], nums[end]);
                end--;
            }
            else
                p++;
        }
        return end + 1;
    }

private:
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums;
    string line;
    int num, val;
    Solution sol;
    cout << "Your input:\n";
    while(cin.peek()!= '\n'){
        cin >> num;
        cout << num;
        nums.push_back(num);
    }
    cin >> val;
    cout << endl << val << endl << "Output: " << endl;
    val = sol.removeElement(nums, val);
    for(int i = 0; i < val; i++)
        cout << nums[i];
    cout << endl;
    return 0;
}
