#include<iostream>
#include<cstdlib>
#include<string>
#include<limits>
#include<iomanip>

//
void Start();


int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	// Вояж Маркет Продажа инвентаря для путешествий
	Start();


	return 0;
}

void Start()
{
	std::cout << "\t\tДобро пожаловать в Вояж Маркет\n\n";

	std::string adminLogin = "admin";
	std::string adminPassword = "overseer";
	std::string login, password;
	int choice;
	bool exit = false;

	do
	{
		std::cout << "Введите логин: ";
		std::getline(std::cin, login);
		std::cout << "Введите пароль:";
		std::getline(std::cin, password);
		if (login != adminLogin || password != adminPassword)
		{
			std::cerr << "Неверный логин или пароль\n";
			std::cout << "Попробовать еще раз? \n1 - Да\n2 - Выход из программы\n";
			std::cin >> choice;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Чистит буфер cin от конкретного кол-во символов в нём сейчас до терминирующего нуля(\n)
			if (choice == 2)
			{
				exit = true;
			}
			else
			{
				exit = true;
				int chooseStorageType;
				do
				{
					std::cout << "Введите формат склада: \n1 - Готовый склад\n2 - Создать склад вручную";
					std::cin >> chooseStorageType;

				} while (chooseStorageType < 1 || chooseStorageType > 2);
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				if (chooseStorageType == 1)
				{
					//создать склад и запстить магазин

				}
				else if (chooseStorageType == 2)
				{
					std::cout << "Ин прогресс...";
				}
				else
				{
					std::cerr << "Error chooseStorageType";
				}
				
			}
		}
	} while (!exit);
	
}
