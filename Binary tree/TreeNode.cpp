#include "TreeNode.h"

int TreeNode::GetData() const
{
    return Data;
}

void TreeNode::SetData(int data)
{
    Data = data;
}

TreeNode* TreeNode::GetLeftNode() const
{
    return _leftNode;
}

void TreeNode::SetLeftNode(TreeNode* leftNode)
{
    _leftNode = leftNode;
}

TreeNode* TreeNode::GetRightNode() const
{
    return _rightNode;
}

void TreeNode::SetRightNode(TreeNode* rightNode)
{
    _rightNode = rightNode;
}
