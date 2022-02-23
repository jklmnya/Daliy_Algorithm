/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* ans = new ListNode();
        ans->next = head;
        head = ans;
        while (head && head->next) {
            int val = head->next->val;
            if (val == 0) {
                ListNode* node = head->next;
                head->next = head->next->next;
                // delete node;
            } else {
                ListNode* node = head->next->next;
                while (node && val != 0) {
                    val += node->val;
                    node = node->next;
                }
                if (val == 0)
                    head->next = node;
                else
                    head = head->next;
            }
        }
        return ans->next;
    }
};