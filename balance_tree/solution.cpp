#include <vector>

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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        traverse(root, inorder);


        return createNode(inorder, 0, inorder.size());
    }

private:
    TreeNode* createNode(vector<int>& ind, int left, int right){
        if(left >= right) return NULL;

        int mid = (left + right) / 2;

        TreeNode * currNode = new TreeNode(ind[mid]);

        currNode->left = createNode(ind, left, mid);
        currNode->right = createNode(ind, mid + 1, right);

        return currNode;
    }

    void traverse(TreeNode* root, vector<int>& inorder){
        if(root == NULL) return;

        traverse(root->left, inorder);
        inorder.push_back(root->val);
        traverse(root->right, inorder);
    }
};