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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res(k);
        int len = 0;
        for (ListNode *t = root; t; t = t->next) ++len;
        int avg = len / k, ext = len % k;
        for (int i = 0; i < k && root; ++i) {
            res[i] = root;
            for (int j = 1; j < avg + (i < ext); ++j) {
                root = root->next;
            }
            ListNode *t = root->next;
            root->next = NULL;
            root = t;
        }
        return res;
    }
};
