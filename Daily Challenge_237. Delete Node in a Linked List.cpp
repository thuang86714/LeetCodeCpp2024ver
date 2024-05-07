#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        //TC O(n), SC O(n)
        std::vector<int> nodeValVec;
        ListNode *cur = node;
        while(cur){
            nodeValVec.push_back(cur->val);
            cur = cur->next;
        }

        for(int i = 1; i < nodeValVec.size(); i++){
            node->val = nodeValVec[i];
            if(i == nodeValVec.size() - 1){
                node->next = nullptr;
                break;
            }
            node = node->next;
        }

    }
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        //TC O(n), SC O(1)
        while(node){
            int nextVal = node->next->val;
            node->val = nextVal;
            if(!node->next->next){
                node->next = nullptr;
            }
            node = node->next;
        }
    }
};