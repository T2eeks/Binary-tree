#include "..\Header Files/TreeNode.h" 
#pragma once

// TODO: Полетела кодировка
//! \brief �������� ������
struct BinaryTree
{
private:
    //! \brief ��������� �� �������� ���� ������
    TreeNode* _root = nullptr;

public:
    //! \brief ������������� ��������� ������
    void InitTree();

    //! \brief �������� ��������� ������
    void DeleteTree();

    //! \brief ���������� �������� � ������
    //! \param data �������� ��� ����������
    void AddElement(int data);

    //! \brief �������� �������� �� ������
    //! \param data �������� ��� ��������
    //! \return true, ���� ������� ��� ������� �����, ����� false
    bool RemoveElement(int data);

    //! \brief ����� �������� � ������
    //! \param data �������� ��� ������
    //! \return ��������� �� ��������� ������� ��� nullptr
    TreeNode* FindElement(int data) const;

    //! \brief ����� ���� � ���������� ���������
    //! \return ��������� �� ���� � ������������ ��������� ��� nullptr
    TreeNode* FindBiggestElement() const;

    //! \brief ����� ���� � ���������� ���������
    //! \return ��������� �� ���� � ����������� ��������� ��� nullptr
    TreeNode* FindSmallestElement() const;

    //! \brief �������� �������� ����
    //! \return ��������� �� �������� ����
    TreeNode* GetRoot() const { return _root; }
};

