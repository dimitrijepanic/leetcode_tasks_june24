#include <cstddef>

using namespace std;
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
    TreeNode* bstToGst(TreeNode* root) {
        traverse(root, 0);
        return root;
    }

    int traverse(TreeNode* root, int update){
        if(root == NULL) return 0;
        // first do the right
        int addition = traverse(root->right, update);
        // update the left
        // cout << root->val << ":" << addition << " " << update << endl;
        int additionleft = traverse(root->left, addition + update + root->val);
        int tmp = root->val;
        root->val += update + addition;
        return addition + tmp + additionleft;
    }
};