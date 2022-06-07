#include "List.h"
#include <ctime>
#include <windows.h>

	int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	List list;

	for (int i = 0; i < rand() % 5 + 5; i++)
	{
		list.insert(rand() % 100, i);
	}

	std::cout << "Вміст списку:" << "\n";
	list.printlist();

	std::cout << "\n" << "Введіть порядковий номер елемента для видалення: ";
	int index;
	std::cin >> index;
	list.Delete(index - 1);

	std::cout << "\n" << "Вміст списку:" << "\n";
	list.printlist();

	std::cout << "\n" << "Введіть порядковий номер елемента для відображення вмісту: ";
	std::cin >> index;
	std::cout << list.retrieve(index - 1);
}