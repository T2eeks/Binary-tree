#pragma once

//! \brief Узел бинарного дерева
struct TreeNode
{
private:
    //! \brief Данные узла
    int Data;
    //! \brief Указатель на левый узел
    TreeNode* _leftNode = nullptr;
    //! \brief Указатель на правый узел
    TreeNode* _rightNode = nullptr;

public:
    //! \brief Получить данные узла
    //! \return Значение данных
    int GetData() const;

    //! \brief Установить данные узла
    //! \param data Значение для установки
    void SetData(int data);

    //! \brief Получить левый узел
    //! \return Указатель на левый узел
    TreeNode* GetLeftNode() const;

    //! \brief Установить левый узел
    //! \param leftNode Указатель на левый узел
    void SetLeftNode(TreeNode* leftNode);

    //! \brief Получить правый узел
    //! \return Указатель на правый узел
    TreeNode* GetRightNode() const;

    //! \brief Установить правый узел
    //! \param rightNode Указатель на правый узел
    void SetRightNode(TreeNode* rightNode);
};

