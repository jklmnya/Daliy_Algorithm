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

int f[10005];

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        memset(f, 0, sizeof f);
        int res = 0;
        for (int num : nums)
            f[num] = true;
        while (head) {
            ListNode* node = head;
            while (node && f[node->val])
                node = node->next;
            if (head != node) {
                ++res;
                if (node)
                    head = node->next;
                else
                    head = node;
            } else {
                head = head->next;
            }
        }
        return res;
    }
};