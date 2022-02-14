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
    ListNode* partition(ListNode* head, int x) {
        ListNode* _head = new ListNode();
        _head->next = head;
        ListNode* smaller = nullptr;
        if (_head->next) {
            if (_head->next->val < x)
                smaller = _head->next;
            else
                smaller = _head;
        }
        ListNode* node = smaller;
        while (node && node->next) {
            while (node->next && node->next->val >= x)
                node = node->next;
            if (node->next) {
                if (smaller != node->next) {
                    ListNode* temp = node->next;
                    node->next = node->next->next;
                    temp->next = smaller->next;
                    smaller->next = temp;
                    smaller = smaller->next;
                } else {
                    node = node->next;
                }  
            }
        }
        return _head->next;
    }
};