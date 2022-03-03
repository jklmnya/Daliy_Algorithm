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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head = list1;
        b = b - a;
        while (--a)
            head = head->next;
        ListNode* node1 = head->next;
        ListNode* node2 = node1;
        head->next = list2;
        while (list2->next)
            list2 = list2->next;
        while (b--)
            node2 = node2->next;
        list2->next = node2->next;
        node2->next = nullptr;
        while (node1) {
            ListNode* temp = node1;
            node1 = node1->next;
            delete temp;
        }
        return list1;
    }
};