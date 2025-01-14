#include "TreapNode.h"
#pragma once


// TODO: Полетела кодировка
// TODO: Комментарий
struct Treap
{
private:
    //! \brief �������� ���� ������
    TreapNode* _root = nullptr;

public:
    //! \brief ����������� �� ���������
    Treap() = default;

    //! \brief ����������
    ~Treap();

    //! \brief ������������� ����������� ������
    void InitTreap();

    //! \brief �������� ����������� ������
    void DeleteTreap();

    //! \brief ����� �������� � ���������� ������
    //! \param key ������� ��������
    //! \return ��������� �� ��������� ������� ��� nullptr
    TreapNode* FindElement(int key);

    //! \brief ���������� ������ �� 2 ������ �� �������� (split)
    //! \param key   �������� ��� ����������
    //! \param left  ����� ������
    //! \param right ������ ������
    void Split(int key, TreapNode*& left, TreapNode*& right);

    //! \brief ������� ���� �������� (merge)
    //! \param left  ����� ������
    //! \param right ������ ������
    //! \return ������ ������
    TreapNode* Merge(TreapNode* left, TreapNode* right);

    //! \brief ������� ���������� ���� (������������������)
    //! \param key �������� ��� ����������
    void AddNotOptimized(int key);

    //! \brief ������� ���������� ���� (����������������)
    //! \param key �������� ��� ����������
    void AddOptimized(int key);

    //! \brief ������� �������� ���� (����������������)
    //! \param key �������� ��� ��������
    //! \return true, ���� ����� �������, ����� false
    bool RemoveOptimized(int key);

    //! \brief ������� �������� ����� (������������������)
    //! \param key �������� ��� ��������
    //! \return true, ���� ����� ���� �� ���� �������, ����� false
    bool RemoveNotOptimized(int key);

    //! \brief �������� �������� ����
    //! \return ��������� �� �������� ����
    TreapNode* GetRoot() const { return _root; }

};