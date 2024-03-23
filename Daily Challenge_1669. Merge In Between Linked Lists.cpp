struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        //TC O(n), SC O(1)
        int nodeCount = -1;
        ListNode temp = ListNode(0, list1);
        ListNode *dummy = &temp;
        ListNode *left = dummy, *right = dummy, *prev, *nxt, *cur = list2;
        while(nodeCount < b){
            if(nodeCount < a){
                prev = left;
                left = left->next;
            }
            if(nodeCount < b){
                right = right->next;
            }
            nodeCount++;
        }
        nxt = right->next;

        prev->next = list2;
        while(cur->next){
            cur = cur->next;
        }
        cur->next = nxt;
        return dummy->next;
    }
};