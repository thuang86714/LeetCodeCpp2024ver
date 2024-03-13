#include <unordered_map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        //credit to hiepit, TC O(n), SC O(n)
        ListNode temp(0, head);
        ListNode *dummy = &temp;
        ListNode *cur = dummy;
        int prefix = 0;
        std::unordered_map<int, ListNode*> seen;//<curPrefix, ListNode*>
        while(cur){
            seen[prefix += cur->val] = cur;//this way we will only store the last node that have the same prefix sum
            cur = cur->next;
        }
        prefix = 0;
        cur= dummy;
        while(cur){
            cur->next = seen[prefix += cur->val]->next;//connect to the last node with the same prefix sum
            cur = cur->next;
        }
        return dummy->next;
    }
};