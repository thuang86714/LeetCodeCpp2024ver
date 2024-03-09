struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <vector>
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        //bfs
        int curLevel = 0;
        std::vector<TreeNode*> nextLevelVec;
        nextLevelVec.push_back(root);
        while(!nextLevelVec.empty()){
            int curVal = -1;
            std::vector<TreeNode*> tempVec;
            for(auto &node:nextLevelVec){
                if(node->val%2 == curLevel%2){
                    return false;
                }
                if(curVal != -1 && ((curLevel%2 && curVal <= node->val)||(!(curLevel%2) && curVal >= node->val))){
                    return false;
                }
                curVal = node->val;
                if(node->left){
                    tempVec.push_back(node->left);
                }
                if(node->right){
                    tempVec.push_back(node->right);
                }
            }
            curLevel++;
            nextLevelVec = tempVec;
        }
        return true;
    }
};