#include "TreapNode.h"
#pragma once

//! \brief Декартово дерево
struct Treap
{
private:
    //! \brief Корневой узел дерева
    TreapNode* _root = nullptr;

public:
    //! \brief Конструктор по умолчанию
    Treap() = default;

    //! \brief Деструктор
    ~Treap();

    //! \brief Инициализация декартового дерева
    void InitTreap();

    //! \brief Удаление декартового дерева
    void DeleteTreap();

    //! \brief Поиск элемента в декартовом дереве
    //! \param key Искомое значение
    //! \return Указатель на найденный элемент или nullptr
    TreapNode* FindElement(int key);

    //! \brief Разделение дерева на 2 дерева по значению (split)
    //! \param key   Критерий для разделения
    //! \param left  Левое дерево
    //! \param right Правое дерево
    void Split(int key, TreapNode*& left, TreapNode*& right);

    //! \brief Слияние двух деревьев (merge)
    //! \param left  Левое дерево
    //! \param right Правое дерево
    //! \return Слитое дерево
    TreapNode* Merge(TreapNode* left, TreapNode* right);

    //! \brief Функция добавления узла (неоптимизированная)
    //! \param key Значение для добавления
    void AddNotOptimized(int key);

    //! \brief Функция добавления узла (оптимизированная)
    //! \param key Значение для добавления
    void AddOptimized(int key);

    //! \brief Функция удаления узла (оптимизированная)
    //! \param key Значение для удаления
    //! \return true, если удалён успешно, иначе false
    bool RemoveOptimized(int key);

    //! \brief Функция удаления узлов (неоптимизированная)
    //! \param key Значение для удаления
    //! \return true, если удалён хотя бы один элемент, иначе false
    bool RemoveNotOptimized(int key);

    //! \brief Получить корневой узел
    //! \return Указатель на корневой узел
    TreapNode* GetRoot() const { return _root; }

};