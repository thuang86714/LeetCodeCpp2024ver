struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <queue>
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        //bfs, TC O(n), SC O(n)
        if(!root){
            return -1;
        }
        std::queue<TreeNode*> treeNodePtrQueue;
        treeNodePtrQueue.push(root);
        int ans;
        while(!treeNodePtrQueue.empty()){
            int curSize = treeNodePtrQueue.size();
            for(int i = 0; i < curSize; i++){
                TreeNode *cur = treeNodePtrQueue.front();
                treeNodePtrQueue.pop();
                ans = cur->val;
                if(cur->right){
                    treeNodePtrQueue.push(cur->right);
                }
                if(cur->left){
                    treeNodePtrQueue.push(cur->left);
                }
            }
        }
        return ans;
    }
};

class Solution {
private:
    int curMaxDepth = 0, ans = 0;
    void findBottomLeftDfs(TreeNode *node, int curDepth){
        if(!node){
            return;
        }
        if(curMaxDepth <= curDepth){
            curMaxDepth = curDepth;
            ans = node->val;
        }
        findBottomLeftDfs(node->right, curDepth + 1);
        findBottomLeftDfs(node->left, curDepth + 1);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        //dfs, TC O(n), SC O(logn)
        findBottomLeftDfs(root, 0);
        return ans;
    }
};