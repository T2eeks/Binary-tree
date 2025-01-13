#include "..\Header Files\Treap.h"
#include "..\Header Files\TreapNode.h"


Treap::~Treap()
{
    DeleteTreap();
}

void Treap::InitTreap()
{
    _root = nullptr;
}

static void DeleteTreapRecursive(TreapNode* node)
{
    if (!node)
    {
        return;
    }
    DeleteTreapRecursive(node->GetLeftNode());
    DeleteTreapRecursive(node->GetRightNode());

    delete node;
}

void Treap::DeleteTreap()
{
    DeleteTreapRecursive(_root);
    _root = nullptr;
}

static TreapNode* FindElementRecursive(TreapNode* node, int key)
{
    if (!node)
    {
        return nullptr;
    }
    if (node->GetKey() == key)
    {
        return node;
    }
    if (key > node->GetKey())
    {
        return FindElementRecursive(node->GetRightNode(), key);
    }
    return FindElementRecursive(node->GetLeftNode(), key);
}

TreapNode* Treap::FindElement(int key)
{
    return FindElementRecursive(_root, key);
}

static void SplitRecursive(TreapNode* node, int key, TreapNode*& left, TreapNode*& right)
{
    if (!node)
    {
        left = nullptr;
        right = nullptr;
        return;
    }
    if (node->GetKey() < key)
    {
        TreapNode* rightNode = node->GetRightNode();
        SplitRecursive(rightNode, key, rightNode, right);
        node->SetRightNode(rightNode);
        left = node;
    }
    else
    {
        TreapNode* leftNode = node->GetLeftNode();
        SplitRecursive(leftNode, key, left, leftNode);
        node->SetLeftNode(leftNode);
        right = node;
    }
}

void Treap::Split(int key, TreapNode*& left, TreapNode*& right)
{
    SplitRecursive(_root, key, left, right);
}

static TreapNode* MergeRecursive(TreapNode* left, TreapNode* right)
{
    if (!left || !right)
    {
        return left ? left : right;
    }

    if (left->GetPriority() > right->GetPriority())
    {
        TreapNode* leftRight = left->GetRightNode();
        TreapNode* merged = MergeRecursive(leftRight, right);
        left->SetRightNode(merged);
        return left;
    }
    else
    {
        TreapNode* rightLeft = right->GetLeftNode();
        TreapNode* merged = MergeRecursive(left, rightLeft);
        right->SetLeftNode(merged);
        return right;
    }
}

TreapNode* Treap::Merge(TreapNode* left, TreapNode* right)
{
    return MergeRecursive(left, right);
}

void Treap::AddNotOptimized(int key)
{
    TreapNode* newNode = new TreapNode;
    newNode->SetKey(key);

    TreapNode* less = nullptr;
    TreapNode* bigger = nullptr;

    SplitRecursive(_root, key, less, bigger);

    TreapNode* mergedLeft = MergeRecursive(less, newNode);

    _root = MergeRecursive(mergedLeft, bigger);
}

void Treap::AddOptimized(int key)
{
    if (!_root)
    {
        _root = new TreapNode(key);
        return;
    }


    TreapNode* newNode = new TreapNode(key);

    if (_root->GetPriority() > newNode->GetPriority())
    {
        TreapNode* cur = _root;
        while (true)
        {
            if (key < cur->GetKey())
            {
                TreapNode* leftChild = cur->GetLeftNode();
                if (!leftChild)
                {
                    cur->SetLeftNode(newNode);
                    break;
                }
                cur = leftChild;
            }
            else
            {
                TreapNode* rightChild = cur->GetRightNode();
                if (!rightChild)
                {
                    cur->SetRightNode(newNode);
                    break;
                }
                cur = rightChild;
            }
        }
    }
    else
    {
        TreapNode* leftTemp = nullptr;
        TreapNode* rightTemp = nullptr;

        SplitRecursive(_root, key, leftTemp, rightTemp);

        newNode->SetLeftNode(leftTemp);
        newNode->SetRightNode(rightTemp);

        _root = newNode;
    }
}

static void RemoveRec(TreapNode*& node, int key, bool& success)
{
    if (!node)
    {
        success = false;
        return;
    }

    if (key > node->GetKey())
    {
        TreapNode* rightChild = node->GetRightNode();
        RemoveRec(rightChild, key, success);
        node->SetRightNode(rightChild);
    }
    else if (key < node->GetKey())
    {
        TreapNode* leftChild = node->GetLeftNode();
        RemoveRec(leftChild, key, success);
        node->SetLeftNode(leftChild);
    }
    else
    {
        TreapNode* temp = node;
        TreapNode* merged = MergeRecursive(node->GetLeftNode(), node->GetRightNode());
        node = merged;
        delete temp;
        success = true;
    }
}

bool Treap::RemoveOptimized(int key)
{
    bool success = false;
    RemoveRec(_root, key, success);
    return success;
}

bool Treap::RemoveNotOptimized(int key)
{
    bool success = true;

    TreapNode* less = nullptr;
    TreapNode* bigger = nullptr;
    TreapNode* equal = nullptr;

    SplitRecursive(_root, key, less, bigger);

    SplitRecursive(bigger, key + 1, equal, bigger);

    if (!equal)
    {
        success = false;
    }
    else
    {
        DeleteTreapRecursive(equal);
        equal = nullptr;
    }

    _root = MergeRecursive(less, bigger);

    return success;
}