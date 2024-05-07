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
    ListNode* removeNodes(ListNode* head) {
        std::vector<int> curMaxValVec;
        ListNode dummy = ListNode(0);
        dummy.next = head;
        ListNode *dummyPtr = &dummy;
        ListNode *prevPtr = dummyPtr;
        int curMax = 0, idx = 0;
        while(head){
            curMaxValVec.push_back(head->val);
            head = head->next;
        }
        for(int i = curMaxValVec.size() - 1; i >= 0; i--){
            curMax = std::max(curMax, curMaxValVec[i]);
            curMaxValVec[i] = curMax;
        }

        while(prevPtr->next){
            if(prevPtr->next->val < curMaxValVec[idx]){
                prevPtr->next = prevPtr->next->next;
            }else if(prevPtr->next->val == curMaxValVec[idx]){
                prevPtr = prevPtr->next;
            }
            idx++;
        }
        return dummyPtr->next;
    }
};