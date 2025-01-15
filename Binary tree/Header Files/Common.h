#pragma once
#include <iostream>

#include "BinaryTree.h"
#include "Treap.h"

/// @brief  Функция получения корректного значения для узла
///
/// @return Корректное целочисленное значение
int GetValue();

/// @brief Меню бинарного дерева 
///
/// @param binaryTree Указатель на бинарное дерево
void BinaryTreeMenu(BinaryTree* binaryTree);

/// @brief Меню Декартового дерева
///
/// @param traep Указатель на узел дерева
void TreapMenu(Treap* treap);

/// @brief Функция отображения Декартового дерева
///			на экране
/// 
/// @param node		Указатиель на узел дерева
/// @param indent	Отступ
void ShowTreap(TreapNode* node, int indent);

/// @brief  Функция отображения бинарного дерева
///
/// @param binaryTreeNode	Указатель на узел дерева
/// @param indent			Отступ
void ShowBinaryTree(TreeNode* binaryTreeNode, int indent);