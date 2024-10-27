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
    vector<int> convert(ListNode* arr) {
        vector<int> ret;
        while (arr != nullptr) {
            ret.push_back(arr->val);
            arr = arr->next;
        }
        return ret;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) return list1;

        ListNode* ret = new ListNode();
        vector<int> all;
        vector<int> a1 = convert(list1);
        vector<int> a2 = convert(list2);
        int i=0, j=0;
        while (i<a1.size() && j<a2.size()) {
            if (a1[i] <= a2[j]) {
                all.push_back(a1[i]);
                i++;
            } else {
                all.push_back(a2[j]);
                j++;
            }
        }
        while (i < a1.size()) {
            all.push_back(a1[i]);
            i++;
        }
        while (j < a2.size()) {
            all.push_back(a2[j]);
            j++;
        }

        i = 0;
        ListNode* cur = ret;
        for (;i<all.size(); i++) {
            cur->val = all[i];
            if (i < all.size()-1) {
                cur->next = new ListNode();
                cur = cur->next;
            }
        }
        return ret;
    }
};