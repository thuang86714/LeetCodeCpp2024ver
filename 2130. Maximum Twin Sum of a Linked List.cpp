#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        //TC O(n), SC O(n)
        std::vector<int> nodeValVec;
        while(head){
            nodeValVec.push_back(head->val);
            head = head->next;
        }
        int maxSum = 0, n = nodeValVec.size();
        for(int i = 0; i <= n/2 - 1; i++){
            maxSum = std::max(maxSum, nodeValVec[i] + nodeValVec[n - 1- i]);
        }
        return maxSum;
    }
};