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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* _head = new ListNode(10000);
        _head->next = head;
        ListNode* insertPos = _head;
        while (insertPos->next) {
            ListNode* node = insertPos;
            ListNode* temp = nullptr;
            int minV = INT_MAX;
            while (node->next) {
                if (node->next->val < minV) {
                    temp = node;
                    minV = node->next->val;
                }
                node = node->next;
            }
            if (temp->next && minV < INT_MAX) {
                if (temp == insertPos) {
                    insertPos = insertPos->next;
                } else {
                    ListNode* node2 = temp->next;
                    temp->next = node2->next;
                    node2->next = insertPos->next;
                    insertPos->next = node2;
                    insertPos = insertPos->next;
                }
            }
        }
        return _head->next;
    }
};