#include <iostream>

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    // ���캯��
    TreeNode(int val):val(val),left(nullptr),right(nullptr)
    {}
};

TreeNode *find_val(TreeNode* head,int val)
{
    if (head == nullptr || head->val == val)
    {
        return head;
    }
    // �ݹ����������
    TreeNode* leftResult = find_val(head->left, val);
    if (leftResult) {
        return leftResult;  // ������������ҵ�Ŀ��ڵ㣬��������
    }
    return find_val(head->right, val);
}


int main_01013() {
   
     // ���Ĺ���
    TreeNode* root = new TreeNode(1);
   /* root->left = new TreeNode(2);
    root->right = new TreeNode(2);*/
    TreeNode* p1 = new TreeNode(2);
    TreeNode* p2 = new TreeNode(3);
    TreeNode* p3 = new TreeNode(4);
    TreeNode* p4 = new TreeNode(5);

    // ������
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p2->left = p4;

    // ����
    int val = 6;
    TreeNode* temp = find_val(root, val);
    if (temp)
    {
        std::cout << "�ҵ���,ֵ�Ĵ�СΪ��" << temp->val << std::endl;
    }
    else {
        std::cout << "û�ҵ�!" << std::endl;
    }
    return 0;
}