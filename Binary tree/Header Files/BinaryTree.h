#include "..\Header Files/TreeNode.h" 
#pragma once
//! \brief Бинарное дерево
struct BinaryTree
{
private:

    //! \brief Указатель на корневой узел дерева
    TreeNode* _root = nullptr;
public:

    //! \brief Инициализация бинарного дерева
    void InitTree();

    //! \brief Удаление бинарного дерева
    void DeleteTree();

    //! \brief Добавление элемента в дерево
    //! \param data Значение для добавления
    void AddElement(int data);

    //! \brief Удаление элемента из дерева
    //! \param data Значение для удаления
    //! \return true, если элемент был успешно удалён, иначе false
    bool RemoveElement(int data);

    //! \brief Поиск элемента в дереве
    //! \param data Значение для поиска
    //! \return Указатель на найденный элемент или nullptr
    TreeNode* FindElement(int data) const;

    //! \brief Поиск узла с наибольшим значением
    //! \return Указатель на узел с максимальным значением или nullptr
    TreeNode* FindBiggestElement() const;

    //! \brief Поиск узла с наименьшим значением
    //! \return Указатель на узел с минимальным значением или nullptr
    TreeNode* FindSmallestElement() const;

    //! \brief Получить корневой узел
    //! \return Указатель на корневой узел
    TreeNode* GetRoot() const { return _root; }
};