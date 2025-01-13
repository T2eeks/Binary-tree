#pragma once

#include <cstdlib> 

//! \brief Узел декартового дерева
struct TreapNode
{
private:
    //! \brief Ключ узла
    int _key = 0;

    //! \brief Приоритет узла
    int _priority = 0;

    //! \brief Указатель на левый узел
    TreapNode* _leftNode = nullptr;

    //! \brief Указатель на правый узел
    TreapNode* _rightNode = nullptr;

public:
    //! \brief Конструктор по умолчанию
    //! \details Инициализирует случайный приоритет и ключ по умолчанию (0)
    TreapNode();

    //! \brief Конструктор с указанным ключом
    //! \param key Значение ключа
    TreapNode(int key);

    //! \brief Деструктор (по умолчанию)
    ~TreapNode() = default;

    //! \brief Получить ключ узла
    //! \return Ключ узла
    int GetKey() const;

    //! \brief Установить ключ узла
    //! \param key Новое значение ключа
    void SetKey(int key);

    //! \brief Получить приоритет узла
    //! \return Приоритет узла
    int GetPriority() const;

    //! \brief Установить приоритет узла
    //! \param priority Новое значение приоритета
    void SetPriority(int priority);

    //! \brief Получить левый узел
    //! \return Указатель на левый узел
    TreapNode* GetLeftNode() const;

    //! \brief Установить левый узел
    //! \param node Указатель на левый узел
    void SetLeftNode(TreapNode* node);

    //! \brief Получить правый узел
    //! \return Указатель на правый узел
    TreapNode* GetRightNode() const;

    //! \brief Установить правый узел
    //! \param node Указатель на правый узел
    void SetRightNode(TreapNode* node);
};
