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
	// ���� ������ ������� ��������� ��� �����������
	Start();


	return 0;
}

void Start()
{
	std::cout << "\t\t����� ���������� � ���� ������\n\n";

	std::string adminLogin = "admin";
	std::string adminPassword = "overseer";
	std::string login, password;
	int choice;
	bool exit = false;

	do
	{
		std::cout << "������� �����: ";
		std::getline(std::cin, login);
		std::cout << "������� ������:";
		std::getline(std::cin, password);
		if (login != adminLogin || password != adminPassword)
		{
			std::cerr << "�������� ����� ��� ������\n";
			std::cout << "����������� ��� ���? \n1 - ��\n2 - ����� �� ���������\n";
			std::cin >> choice;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //������ ����� cin �� ����������� ���-�� �������� � �� ������ �� �������������� ����(\n)
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
					std::cout << "������� ������ ������: \n1 - ������� �����\n2 - ������� ����� �������";
					std::cin >> chooseStorageType;

				} while (chooseStorageType < 1 || chooseStorageType > 2);
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				if (chooseStorageType == 1)
				{
					//������� ����� � �������� �������

				}
				else if (chooseStorageType == 2)
				{
					std::cout << "�� ��������...";
				}
				else
				{
					std::cerr << "Error chooseStorageType";
				}
				
			}
		}
	} while (!exit);
	
}
