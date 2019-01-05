/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        int res = 0;
        unordered_set<int> nodeSet(G.begin(), G.end());
        while (head) {
            if (!nodeSet.count(head->val)) {
                head = head->next;
                continue;
            }
            ++res;
            while (head && nodeSet.count(head->val)) {
                head = head->next;
            }
        }
        return res;
    }
};
