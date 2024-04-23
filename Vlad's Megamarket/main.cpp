#include<iostream>
#include<cstdlib>
#include<string>
#include<limits>
#include<iomanip>

// Вояж Маркет Продажа инвентаря для путешествий

//Глобальные массивы
int size = 10;
int receiptSize = 1;

int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
double* priceArr = new double[size];
//Массив для чека
std::string* nameReceiptArr = new std::string[receiptSize];
int* countReceiptArr = new int[receiptSize];
double* priceReceiptArr = new double[receiptSize];

template <typename ArrType>
void FillArray(ArrType staticArr, ArrType dinArr, int size);



//Основные функции
void Start();
void DeleteMainArrays();
void DeleteReceiptArrs();
void CreateStorage();
void ShowStorage();
void Shop();
void Selling();
void AddElToReceipt(int id,int count);
void PrintReceipt();


int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	CreateStorage();

	Start();

	DeleteMainArrays();
	DeleteReceiptArrs();
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
		else
		{
			Shop();
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
void DeleteReceiptArrs()
{
	delete[] nameReceiptArr;
	delete[] countReceiptArr;
	delete[] priceReceiptArr;
}
void CreateStorage()
{
	const int staticSize = 10;
	int id[staticSize]{ 0,1,2,3,4,5,6,7,8,9 };
	std::string name[staticSize]{ "Термос 0.5 литров","Термос 1 литр\t"
		,"Термос 2 литра\t","Палатка 'Одиночка'"
		,"Палатка 'Убежище'","Палатка 'Вояж Делюкс'"
		,"Походный нож 'Грибник'","Походный нож 'Веточник'"
		,"Анти-клещ 'Жижка'","Рюкзак 'Вояж Простор'" };
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
		} while (choose < 0 || choose > 6);
		if (choose == 1)
		{
			ShowStorage();
		}
		else if (choose == 2)
		{
			Selling();
		}
		else if (choose == 3)
		{
			PrintReceipt();
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

void Selling()
{
	int chooseId, chooseCount, confirm;
	bool isFirst = true;
	while (true)
	{
		do
		{
			std::cout << "Введите ID товара: ";
			std::cin >> chooseId;
			if (chooseId < 1 || chooseId > size)
			{
				std::cerr << "Данного товара нет.\n";
				continue;
			}
			if (countArr[chooseId - 1] > 0)
			{
				while (true)
				{
					std::cout << "\nВыбранный товар: " << nameArr[chooseId - 1] << "\n";
					std::cout << "Кол-во данного товара на складе: " << countArr[chooseId - 1] << "\n";
					std::cout << "Введите кол-во товара: ";
					std::cin >> chooseCount;
					if (chooseCount < 1 || chooseCount > countArr[chooseId - 1])
					{
						std::cerr << "Error\n";
					}
					else
					{
						break;
					}
				}
			}
			else
			{
				std::cerr << "Этот товар иссяк\n";
				continue;
			}

			std::cout << "Товар: " << nameArr[chooseId - 1] << "\nКол-во: " << chooseCount << "\n";
			std::cout << "1 - Подтвердить, 2 - Отмена";
			std::cin >> confirm;
			if (confirm == 1)
			{
				if (isFirst)
				{
					nameReceiptArr[receiptSize - 1] = nameArr[chooseId - 1];
					countReceiptArr[receiptSize - 1] = chooseCount;
					priceReceiptArr[receiptSize - 1] = priceArr[chooseId - 1] * chooseCount;
					countArr[chooseId - 1] -= chooseCount;
					isFirst = false;
				}
				else
				{
					AddElToReceipt(chooseId, chooseCount);
				}
			}
			else
			{
				continue;
			}

			std::cout << "Купить еще один товар?\n";
			std::cout << "1 - Да, 2 - Нет";
			std::cin >> confirm;
			if (confirm == 1)
			{
				continue;
			}
			else
			{
				PrintReceipt();
			}
			break;
		} while (true);

	}
}

void AddElToReceipt(int id, int count)
{
	std::string* tempNameReceiptArr = new std::string[receiptSize];
	int* tempCountReceiptArr = new int[receiptSize];
	double* tempPriceReceiptArr = new double[receiptSize];

	for (int i = 0; i < receiptSize; i++)
	{
		tempNameReceiptArr[i] = nameReceiptArr[i];
		tempCountReceiptArr[i] = countReceiptArr[i];
		tempPriceReceiptArr[i] = priceReceiptArr[i];
	}

	delete[] nameReceiptArr;
	delete[] countReceiptArr;
	delete[] priceReceiptArr;
	receiptSize++;
	nameReceiptArr = new std::string[receiptSize];
	countReceiptArr = new int[receiptSize];
	priceReceiptArr = new double[receiptSize];

	for (int i = 0; i < receiptSize - 1; i++)
	{
		nameReceiptArr[i] = tempNameReceiptArr[i];
		countReceiptArr[i] = tempCountReceiptArr[i];
		priceReceiptArr[i] = tempPriceReceiptArr[i];
	}

	

	nameReceiptArr[receiptSize - 1] = nameArr[id - 1];
	countReceiptArr[receiptSize - 1] = count;
	priceReceiptArr[receiptSize - 1] = priceArr[id - 1] * count;
	countArr[id - 1] -= count;

	delete[] tempNameReceiptArr;
	delete[] tempCountReceiptArr;
	delete[] tempPriceReceiptArr;
}

void PrintReceipt()
{
	std::cout << "Название товара\t\t\t\tКол-во\t\tЦена\n";
	for (int i = 0; i < receiptSize; i++)
	{
		std::cout << nameReceiptArr[i] << "\t\t\t" << countReceiptArr[i] << "\t\t" << priceReceiptArr[i] << "\n";
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