#include <iostream>
#include <ostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return res;
        res.push_back(root -> val);
        if(root -> left != nullptr)
            preorderTraversal(root -> left);
        if(root -> right != nullptr)
            preorderTraversal(root -> right);
        return res;
    }
private:
    std::vector<int> res;
};

int main(int argc, char *argv[])
{
    std::cout << sizeof(Solution) << std::endl;
    return 0;
}
