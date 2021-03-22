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
        std::vector<int> res;
        traversal(root, res);
        return res;
    }
private:
    void traversal(TreeNode* root, std::vector<int> &res){
        if(root == nullptr)
            return;
        res.push_back(root -> val);
        if(root -> left != nullptr)
            traversal(root -> left, res);
        if(root -> right != nullptr)
            traversal(root -> right, res);
    }
};

int main(int argc, char *argv[])
{
    std::cout << sizeof(Solution) << std::endl;
    return 0;
}
