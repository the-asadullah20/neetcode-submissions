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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>a;
        for(int i=0;i<lists.size();i++)
        {
            ListNode * head=lists[i];
            while(head)
            {
                a.push_back(head->val);
                head=head->next;
            }
        }
        ListNode * ans= new ListNode(0);
        ListNode * tail=ans;
        sort(a.begin(),a.end());
        for(int i=0;i<a.size();i++)
        {
            ListNode * temp=new ListNode(a[i]);
            tail->next=temp;
            tail=tail->next;
        }
        return ans->next;
    }
};
