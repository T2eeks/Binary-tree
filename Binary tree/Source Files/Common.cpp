#include <iomanip>

#include "..\Header Files\Common.h"

int GetValue()
{
	int value;
	std::cout << " Enter value:" << std::endl;
	std::cin >> value;

	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Enter digits \n";
		return GetValue();
	}

	return value;
}


void BinaryTreeMenu(BinaryTree* binaryTree)
{
	enum class Menu
	{
		Exit = 0,
		Add = 1,
		Remove = 2,
		FindElement = 3,
		FindMaxElement = 4,
		FindMinElement = 5,
	};

	int userChoose;
	bool endProgramm = false;
	int data;

	while (!endProgramm)
	{
		std::cout << "Here is Binary Tree\n" << std::endl;
		ShowBinaryTree(binaryTree->GetRoot(), 3);

		std::cout	<< "\n 1 - Add in tree \n"
					<< " 2 - Remove form tree\n"
					<< " 3 - Find element\n"
					<< " 4 - Find maximum value \n"
					<< " 5 - Find minimum value \n"
					<< " 0 <- Back (You will lose tour data)\n"
					<< std::endl;
		
		int userChoose = GetValue();

		switch (static_cast<Menu>(userChoose))
		{
			case Menu::Add:
			{
				data = GetValue();

				binaryTree->AddElement(data);
				break;
			}
			case Menu::Remove:
			{
				data = GetValue();

				bool success = binaryTree->RemoveElement(data);
				if (!success)
				{
					std::cout	<< "Unsucessful removing. " 
								<< std::endl;

					system("pause");
				}
				break;
			}
			case Menu::FindElement:
			{
				data = GetValue();
				auto found = binaryTree->FindElement(data);

				if (!found)
				{
					std::cout << "Not found" << std::endl;
					system("pause");
					break;
				}
				system("pause");
				break;
			}
			case Menu::FindMaxElement:
			{
				auto biggest = binaryTree->FindBiggestElement();
				if (!biggest)
				{
					std::cout << "Empty tree!" << std::endl;
					system("pause");
					break;
				}

				std::cout << " Element: (" << biggest->GetData() << " )" << std::endl;
				system("pause");
				break;
			}
			case Menu::FindMinElement:
			{
				auto smallest = binaryTree->FindSmallestElement();
				if (!smallest)
				{
					std::cout << "Empty tree." << std::endl;
					system("pause");
					break;
				}
				std::cout << " Element: (" << smallest->GetData()<< " )" << std::endl;
				system("pause");
				break;
			}
			case Menu::Exit:
			{
				endProgramm = true;
				break;
			}
			default:
			{
				std::cout << "Unknown command." << std::endl;
				system("pause");
				break;
			}
		}
	}
}

void TreapMenu(Treap* treap)
{
	enum class TreapMenu
	{
		Exit = 0,
		AddNotOptimized = 1,
		Add = 2,
		RemoveNotOptimized = 3,
		Remove = 4,
		Find = 5
	};

	bool endProgramm = false;

	while (!endProgramm)
	{
		std::cout << "Here is TREAP\n" << std::endl;
		ShowTreap(treap->GetRoot(), 3);

		std::cout << "\n1 - Add (not optimized)\n"
			<< "2 - Add\n"
			<< "3 - Remove (not optimized)\n"
			<< "4 - Remove\n"
			<< "5 - Find element\n"
			<< "0 <- Back (You will lose your data)\n" << std::endl;

		int userInput = GetValue();

		switch (static_cast<TreapMenu>(userInput))
		{
		case TreapMenu::AddNotOptimized:
		{
			int key = GetValue();
			treap->AddNotOptimized(key);
			break;
		}
		case TreapMenu::Add:
		{
			int key = GetValue();
			treap->AddOptimized(key);
			break;
		}
		case TreapMenu::RemoveNotOptimized:
		{
			int key = GetValue();
			bool success = treap->RemoveNotOptimized(key);
			if (!success)
			{
				std::cout << "Unsuccessful removing. " << std::endl;
				system("pause");
			}
			break;
		}
		case TreapMenu::Remove:
		{
			int key = GetValue();
			bool success = treap->RemoveOptimized(key);
			if (!success)
			{
				std::cout << "Unsuccessful removing. " << std::endl;
				system("pause");
			}
			break;
		}
		case TreapMenu::Find:
		{
			int key = GetValue();
			auto found = treap->FindElement(key);
			if (!found)
			{
				std::cout << "Element not found" << std::endl;
				system("pause");
				break;
			}
			std::cout << "Element key = " << key << std::endl;
			system("pause");
			break;
		}
		case TreapMenu::Exit:
		{
			endProgramm = true;
			break;
		}
		default:
		{
			std::cout << "Unknown command." << std::endl;
			system("pause");
			break;
		}
		}
		system("cls");
	}
}

void ShowTreap(TreapNode* node, int indent)
{
	if (!node)
	{
		return;
	}
	if (node->GetRightNode())
	{
		ShowTreap(node->GetRightNode(), indent + 4);
	}
	if (indent)
	{
		std::cout << std::setw(indent) << ' ';
	}
	if (node->GetRightNode())
	{
		std::cout << " /\n" << std::setw(indent) << ' ';
	}

	std::cout << node->GetKey() << "(" << node->GetPriority() << ")" << "\n ";

	if (node->GetLeftNode())
	{
		std::cout << std::setw(indent) << ' ' << " \\\n";
		ShowTreap(node->GetLeftNode(), indent + 4);
	}
}


void ShowBinaryTree(TreeNode* node, int indent)
{
	if (!node)
	{
		return;
	}
	if (node->GetRightNode())
	{
		ShowBinaryTree(node->GetRightNode(), indent + 4);
	}
	if (indent)
	{
		std::cout << std::setw(indent) << ' ';
	}
	if (node->GetRightNode())
	{
		std::cout << " /\n" << std::setw(indent) << ' ';
	}

	std::cout << node->GetData() << "\n ";

	if (node->GetLeftNode())
	{
		std::cout << std::setw(indent) << ' ' << " \\\n";
		ShowBinaryTree(node->GetLeftNode(), indent + 4);
	}
}