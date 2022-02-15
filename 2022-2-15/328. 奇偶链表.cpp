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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* node = head;
        ListNode* even = head;
        while (node && node->next) {
            node = node->next;
            if (node->next) {
                ListNode* temp = node->next;
                node->next = node->next->next;
                temp->next = even->next;
                even->next = temp;
                even = even->next;
            }
        }
        return head;
    }
};