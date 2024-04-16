#include<iostream>
#include<cstdlib>
#include<string>
#include<limits>
#include<iomanip>

// Вояж Маркет Продажа инвентаря для путешествий

//Глобальные массивы
int size = 10;

int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
double* priceArr = new double[size];


template <typename ArrType>
void FillArray(ArrType staticArr, ArrType dinArr, int size);



//Основные функции
void Start();
void DeleteMainArrays();
void CreateStorage();
void ShowStorage();
void Shop();


int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

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
					CreateStorage();
					Shop();

				}
				else if (chooseStorageType == 2)
				{
					std::cout << "Ин прогресс...\n";
				}
				else
				{
					std::cerr << "Error chooseStorageType";
				}
				
			}
		}
	} while (!exit);
	
}

void DeleteMainArrays()
{
	delete[] idArr;
	delete[] nameArr;
	delete[] countArr;
	delete[] priceArr;
}

void CreateStorage()
{
	const int staticSize = 10;
	int id[staticSize]{ 0,1,2,3,4,5,6,7,8,9 };
	std::string name[staticSize]{ "Термос 0.5 литров","Термос 1 литр\t"
		,"Термос 2 литра\t","Палатка 'Одиночка'"
		,"Палатка 'Убежище'","Палатка 'Вояж Делюкс'"
		,"Походный нож 'Грибник'","Походный нож 'Веточник'"
		,"Мультитул 'Швейц Вояж'","Рюкзак 'Вояж Простор'" };
	int count[staticSize]{ 5, 13, 10, 3, 4, 2, 7, 14, 6, 10 };
	double price[staticSize]{ 539.99,749.99,999.99,769.99,1199.99,2499.99,199.99,499.99,899.99,1699.99 };

	FillArray(id, idArr, staticSize);
	FillArray(name, nameArr, staticSize);
	FillArray(count, countArr, staticSize);
	FillArray(price, priceArr, staticSize);
}

void ShowStorage()
{
	std::cout << "ID\tНазвание товара\t\t\t\tКол-во\t\tЦена\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << idArr[i] << "\t" << nameArr[i] << "\t\t\t" << countArr[i] << "\t\t" << priceArr[i] << "\n";
	}
}

void Shop()
{
	int choose;
	while (true)
	{
		do
		{
			std::cout << "1 - Показать склад\n";
			std::cout << "2 - Начать продажу\n";
			std::cout << "3 - Изменить цену\n";
			std::cout << "4 - Списать товар\n";
			std::cout << "5 - Пополнить товар\n";
			std::cout << "6 - Изменение склада\n";
			std::cout << "0 - Закончить смену\n";
			std::cin >> choose;
		} while (choose < 0|| choose > 6);
		if (choose == 1)
		{
			ShowStorage();
		}
		else if (choose == 2)
		{

		}
		else if (choose == 3)
		{

		}
		else if (choose == 4)
		{

		}
		else if (choose == 5)
		{

		}
		else if (choose == 6)
		{

		}
		else if (choose == 0)
		{
			break;
		}
		else
		{
			std::cerr << "Error";
		}

	}
}

template<typename ArrType>
void FillArray(ArrType staticArr, ArrType dinArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		dinArr[i] = staticArr[i];
	}
}
