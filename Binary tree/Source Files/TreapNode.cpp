#include "..\Header Files\TreapNode.h"
#include <cstdlib> 

TreapNode::TreapNode()
    : _key(0)
    , _priority(std::rand())
    , _leftNode(nullptr)
    , _rightNode(nullptr)
{
}

TreapNode::TreapNode(int key)
    : _key(key)
    , _priority(std::rand())
    , _leftNode(nullptr)
    , _rightNode(nullptr)
{
}

int TreapNode::GetKey() const
{
    return _key;
}

void TreapNode::SetKey(int key)
{
    _key = key;
}

int TreapNode::GetPriority() const
{
    return _priority;
}

void TreapNode::SetPriority(int priority)
{
    _priority = priority;
}

TreapNode* TreapNode::GetLeftNode() const
{
    return _leftNode;
}

void TreapNode::SetLeftNode(TreapNode* node)
{
    _leftNode = node;
}

TreapNode* TreapNode::GetRightNode() const
{
    return _rightNode;
}

void TreapNode::SetRightNode(TreapNode* node)
{
    _rightNode = node;
}
