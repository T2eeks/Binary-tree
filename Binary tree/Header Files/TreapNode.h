#pragma once

#include <cstdlib> 

// TODO: Полетела кодировка
//! \brief ���� ����������� ������
struct TreapNode
{
private:
    //! \brief ���� ����
    int _key = 0;

    //! \brief ��������� ����
    int _priority = 0;

    //! \brief ��������� �� ����� ����
    TreapNode* _leftNode = nullptr;

    //! \brief ��������� �� ������ ����
    TreapNode* _rightNode = nullptr;

public:
    //! \brief ����������� �� ���������
    //! \details �������������� ��������� ��������� � ���� �� ��������� (0)
    TreapNode();

    //! \brief ����������� � ��������� ������
    //! \param key �������� �����
    TreapNode(int key);

    //! \brief ���������� (�� ���������)
    ~TreapNode() = default;

    //! \brief �������� ���� ����
    //! \return ���� ����
    int GetKey() const;

    //! \brief ���������� ���� ����
    //! \param key ����� �������� �����
    void SetKey(int key);

    //! \brief �������� ��������� ����
    //! \return ��������� ����
    int GetPriority() const;

    //! \brief ���������� ��������� ����
    //! \param priority ����� �������� ����������
    void SetPriority(int priority);

    //! \brief �������� ����� ����
    //! \return ��������� �� ����� ����
    TreapNode* GetLeftNode() const;

    //! \brief ���������� ����� ����
    //! \param node ��������� �� ����� ����
    void SetLeftNode(TreapNode* node);

    //! \brief �������� ������ ����
    //! \return ��������� �� ������ ����
    TreapNode* GetRightNode() const;

    //! \brief ���������� ������ ����
    //! \param node ��������� �� ������ ����
    void SetRightNode(TreapNode* node);
};
