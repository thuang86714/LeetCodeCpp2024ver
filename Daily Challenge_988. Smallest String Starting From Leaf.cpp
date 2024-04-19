#include <string>
#include <set>
#include <algorithm>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void findSmallestString(TreeNode* node, std::set<std::string> &stringSet,std::string curString){
        if(!node){
            return;
        }
        curString += std::string(1, node->val + 'a');
        if(!node->left && !node->right){
            std::string temp = curString;
            std::reverse(temp.begin(), temp.end());
            stringSet.insert(temp);
        }
        findSmallestString(node->right, stringSet, curString);
        findSmallestString(node->left, stringSet, curString);
    }
public:
    std::string smallestFromLeaf(TreeNode* root) {
        std::set<std::string> stringSet;
        findSmallestString(root, stringSet, "");
        return *stringSet.begin();
    }
};


class Solution {
private:
    void findSmallestString(TreeNode* node, std::string curString, std::string &ans){
        if(!node){
            return;
        }
        curString = std::string(1, node->val + 'a') + curString;
        if(!node->left && !node->right){
            if(ans == "" || ans > curString){
                ans = curString;
            }
            return;
        }
        findSmallestString(node->right, curString, ans);
        findSmallestString(node->left, curString, ans);
    }
public:
    std::string smallestFromLeaf(TreeNode* root) {
        std::string ans = "";
        findSmallestString(root, "", ans);
        return ans;
    }
};