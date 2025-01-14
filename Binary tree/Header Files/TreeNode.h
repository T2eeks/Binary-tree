#pragma once

// TODO: Полетела кодировка
//! \brief ���� ��������� ������
struct TreeNode
{
private:
    //! \brief ������ ����
    int _data;
    //! \brief ��������� �� ����� ����
    TreeNode* _leftNode = nullptr;
    //! \brief ��������� �� ������ ����
    TreeNode* _rightNode = nullptr;

public:
    //! \brief �������� ������ ����
    //! \return �������� ������
    int GetData() const;

    //! \brief ���������� ������ ����
    //! \param data �������� ��� ���������
    void SetData(int data);

    //! \brief �������� ����� ����
    //! \return ��������� �� ����� ����
    TreeNode* GetLeftNode() const;

    //! \brief ���������� ����� ����
    //! \param leftNode ��������� �� ����� ����
    void SetLeftNode(TreeNode* leftNode);

    //! \brief �������� ������ ����
    //! \return ��������� �� ������ ����
    TreeNode* GetRightNode() const;

    //! \brief ���������� ������ ����
    //! \param rightNode ��������� �� ������ ����
    void SetRightNode(TreeNode* rightNode);

};


