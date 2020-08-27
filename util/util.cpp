//
// Created by hl4080 on 2020/6/25.
//

#include "util.h"

vector<int> list2Vector(ListNode* l) {
    vector<int> result;
    while(l) {
        result.push_back(l->val);
        l = l->next;
    }
    return result;
}

ListNode* vector2List(vector<int>& vec) {
    ListNode* l = new ListNode(0);
    ListNode* pre = l;
    l->next = NULL;
    for(int i=0; i<vec.size(); ++i) {
        ListNode* tmp = new ListNode(vec[i]);
        tmp->next = l->next;
        l->next = tmp;
        l = l->next;
    }
    return pre->next;
}

void printListNode(ListNode* l) {
    while(l) {
        if(!l->next) cout<<l->val;
        else cout<<l->val<<"->";
        l = l->next;
    }
    cout<<endl;
}

int getTreeLayers(TreeNode* root) {
    return root? max(getTreeLayers(root->left), getTreeLayers(root->right))+1: 0;
}

void writeArrays(TreeNode* root, int row, int col, vector<vector<string>>& arrays, int depth) {
    if(!root) return;
    arrays[row][col] = to_string(root->val);
    int curLevel = (row+1)/2;
    if(curLevel == depth) return;
    int gap = depth - curLevel -1;
    if(root->left) {
        arrays[row+1][col-gap] = "/";
        writeArrays(root->left, row+2, col-gap*2, arrays, depth);
    }
    if(root->right) {
        arrays[row+1][col+gap] = "\\";
        writeArrays(root->right, row+2, col+gap*2, arrays, depth);
    }
}

void printTree(TreeNode* root) {
    if(!root) cout<<"EMPTY TREE!"<<endl;
    int depth = getTreeLayers(root);
    int height = depth*2-1;
    int width = (2 << (depth - 2)) * 3 + 1;
    vector<vector<string>> arrays(height, vector<string>(width, " "));
    writeArrays(root, 0, width/2, arrays, depth);
    for(int i=0; i<arrays.size(); ++i) {
        string s;
        for(int j=0; j<arrays[0].size(); ++j) {
            s += arrays[i][j];
            if(arrays[i][j].size() > 1 && j<=arrays[i].size()-1)
                j += arrays[i][j].size() > 4? 2: arrays[i][j].size() -1 ;
        }
        cout<<s<<endl;
    }
}

TreeNode* buildTree(vector<int>& vec, int left, int right) {
    int mid = left + (right-left)/2;
    if(vec[mid] == -1) return NULL;
    if(left > right) return NULL;
    TreeNode* root = new TreeNode(vec[mid]);
    root->left =  buildTree(vec, left, mid-1);
    root->right =  buildTree(vec, mid+1, right);
    return root;
}
