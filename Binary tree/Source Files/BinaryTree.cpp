#include "..\Header Files\BinaryTree.h"
#include "..\Header Files\TreeNode.h"


void DeleteSubTree(TreeNode* node)
{
    if (!node)
        return;

    DeleteSubTree(node->GetLeftNode());
    DeleteSubTree(node->GetRightNode());

    delete node;
}

void InsertNode(TreeNode*& node, int data)
{
    if (!node)
    {
        node = new TreeNode();
        node->SetData(data);
        return;
    }

    if (data > node->GetData())
    {
        TreeNode* rightChild = node->GetRightNode();

        InsertNode(rightChild, data);
        node->SetRightNode(rightChild);
    }
    else
    {
        TreeNode* leftChild = node->GetLeftNode();
        InsertNode(leftChild, data);
        node->SetLeftNode(leftChild);
    }
}

void RemoveNode(TreeNode*& node, int data, bool& success)
{
    if (!node)
    {
        success = false;
        return;
    }

    if (data > node->GetData())
    {
        TreeNode* rightChild = node->GetRightNode();
        RemoveNode(rightChild, data, success);
        node->SetRightNode(rightChild);
    }
    else if (data < node->GetData())
    {
        TreeNode* leftChild = node->GetLeftNode();
        RemoveNode(leftChild, data, success);
        node->SetLeftNode(leftChild);
    }
    else
    {
        if (node->GetLeftNode() && node->GetRightNode())
        {
            TreeNode* rightChild = node->GetRightNode();
            TreeNode* smallestRight = rightChild;
            while (smallestRight->GetLeftNode())
            {
                smallestRight = smallestRight->GetLeftNode();
            }
            node->SetData(smallestRight->GetData());
            RemoveNode(rightChild, smallestRight->GetData(), success);
            node->SetRightNode(rightChild);
        }
        else
        {
            TreeNode* temp = node;
            if (node->GetRightNode())
            {
                node = node->GetRightNode();
            }
            else
            {
                node = node->GetLeftNode();
            }
            delete temp;
            success = true;
        }
    }
}


TreeNode* FindNode(TreeNode* node, int data)
{
    if (!node)
        return nullptr;

    if (node->GetData() == data)
        return node;

    if (data > node->GetData())
        return FindNode(node->GetRightNode(), data);

    return FindNode(node->GetLeftNode(), data);
}

TreeNode* FindMaxNode(TreeNode* node)
{
    if (!node)
        return nullptr;

    while (node->GetRightNode())
    {
        node = node->GetRightNode();
    }
    return node;
}

TreeNode* FindMinNode(TreeNode* node)
{
    if (!node)
        return nullptr;

    while (node->GetLeftNode())
    {
        node = node->GetLeftNode();
    }
    return node;
}

void BinaryTree::InitTree()
{
    _root = nullptr;
}

void BinaryTree::DeleteTree()
{
    DeleteSubTree(_root);
    _root = nullptr;
}

void BinaryTree::AddElement(int data)
{
    InsertNode(_root, data);
}

bool BinaryTree::RemoveElement(int data)
{
    bool success = false;
    RemoveNode(_root, data, success);
    return success;
}

TreeNode* BinaryTree::FindElement(int data) const
{
    return FindNode(_root, data);
}

TreeNode* BinaryTree::FindBiggestElement() const
{
    return FindMaxNode(_root);
}

TreeNode* BinaryTree::FindSmallestElement() const
{
    return FindMinNode(_root);
}