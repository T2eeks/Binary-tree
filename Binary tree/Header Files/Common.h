#pragma once

#include <iostream>

#include "BinaryTree.h"
#include "Treap.h"

// TODO: Полетела кодировка
/// @brief  ������� ��������� ����������� �������� ��� ����
///
/// @return ���������� ������������� ��������
int GetValue();

/// @brief ���� ��������� ������ 
///
/// @param binaryTree ��������� �� �������� ������
void BinaryTreeMenu(BinaryTree* binaryTree);

/// @brief ���� ����������� ������
///
/// @param traep ��������� �� ���� ������
void TreapMenu(Treap* treap);

/// @brief ������� ����������� ����������� ������
///			�� ������
/// 
/// @param node		���������� �� ���� ������
/// @param indent	������
void ShowTreap(TreapNode* node, int indent);

/// @brief  ������� ����������� ��������� ������
///
/// @param binaryTreeNode	��������� �� ���� ������
/// @param indent			������
void ShowBinaryTree(TreeNode* binaryTreeNode, int indent);
