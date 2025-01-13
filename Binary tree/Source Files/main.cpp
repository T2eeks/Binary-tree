#include <iostream>
#include "..\Header Files\BinaryTree.h"
#include "..\Header Files\Common.h"


enum class StartMenu
{
	Exit		= 0,
	BinaryTree	= 1,
	Treap		= 2
};


int main()
{
	int numberOfStruct;
	
	while (true)
	{
		std::cout	<< "1 - Binary tree \n"
					<< "2 - Treap\n"
					<< "0 - Exit\n" 
					<< "Choose struct to start:" << std::endl;

		numberOfStruct = GetValue();

		switch (static_cast<StartMenu>(numberOfStruct))
		{
		case StartMenu::BinaryTree:
		{
			BinaryTree binaryTree; 
			binaryTree.InitTree(); 

			BinaryTreeMenu(&binaryTree);

			binaryTree.DeleteTree();

			system("pause");
			break;
		}
			case StartMenu::Treap:
			{
				Treap treap;

				treap.InitTreap();
				TreapMenu(&treap);

				treap.DeleteTreap();

				system("pause");
				break;
			}
			case StartMenu::Exit:
			{
				return 0;
			}
			default:
			{
				std::cout << "Unknown command! Try again" << std::endl;
				system("pause");
				break;
			}
		}
		system("cls");
	}
	return 0;
}