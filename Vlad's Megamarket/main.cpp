#include<iostream>
#include<cstdlib>
#include<string>
#include <Windows.h>

//#include<limits>
#include<iomanip>

// Вояж Маркет Продажа инвентаря для путешествий

//Глобальные массивы
int size = 10;
int receiptSize = 1;
double totalSum = 0;
double cash = 75009.33;
double nal = 0;
double beznal = 0;
double totalIncome = 0;

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
void AddElToReceipt(int id, int count);
void PrintReceipt();
void ChangePrice();
void AddItems();
void RemoveItems();
void ChangeStorage();
void AddElementToEnd();
void RemoveElementOnIndex();
void CashStatus();
void CreateNewStorage();



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//setlocale(LC_ALL, "ru");
	srand(time(NULL));

	Start();

	DeleteMainArrays();
	DeleteReceiptArrs();

	return 0;
}

void Start()
{
	std::cout << "\t\t\t\t\tДобро пожаловать в Вояж Маркет\n\n";

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
			std::cin.ignore(32000, '\n');
			//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Чистит буфер cin от конкретного кол-во символов в нём сейчас до терминирующего нуля(\n)
			if (choice == 2)
			{
				exit = true;
			}
			else
			{
				exit = true;


			}
		}
		else
		{
			int chooseStorageType;
			do
			{
				std::cout << "Введите формат склада: \n1 - Готовый склад\n2 - Создать склад вручную: ";
				std::cin >> chooseStorageType;
				std::cout << "\n\n";

			} while (chooseStorageType < 1 || chooseStorageType > 2);
			std::cin.ignore(32000, '\n');
			//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (chooseStorageType == 1)
			{
				exit = true;
				CreateStorage();
				Shop();

			}
			else if (chooseStorageType == 2)
			{
				do
				{
					CreateNewStorage();
					ShowStorage();
					std::cout << "Всё верно?\n1 - Да, 2 - Нет";
					std::cin >> choice;
				} while (choice != 1);
				Shop();
				
			}
			else
			{
				std::cerr << "Error chooseStorageType";
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
		std::cout << idArr[i] + 1 << "\t" << nameArr[i] << "\t\t\t" << countArr[i] << "\t\t" << priceArr[i] << "\n";
	}
}

void Shop()
{
	int choose;
	while (true)
	{
		do
		{
			std::cout << "\n";
			std::cout << "1 - Показать склад\n";
			std::cout << "2 - Начать продажу\n";
			std::cout << "3 - Изменить цену\n";
			std::cout << "4 - Списать товар\n";
			std::cout << "5 - Пополнить товар\n";
			std::cout << "6 - Изменение склада\n";
			std::cout << "7 - Показ Счёта\n";
			std::cout << "0 - Закончить смену\n";
			std::cin >> choose;
		} while (choose < 0 || choose > 7);
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
			ChangePrice();
		}
		else if (choose == 4)
		{
			RemoveItems();
		}
		else if (choose == 5)
		{
			AddItems();
		}
		else if (choose == 6)
		{
			ChangeStorage();
		}
		else if (choose == 7)
		{
			CashStatus();
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
	int chooseId, chooseCount, confirm, choice;
	
	bool isFirst = true;
	while (true)
	{
		totalSum = 0;
		do
		{
			totalSum = 0;
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
			std::cout << "1 - Да, 2 - Нет: ";
			std::cin >> confirm;
			if (confirm == 1)
			{
				continue;
			}
			break;
		} while (true);

		


		PrintReceipt();




		int pay = 0;
		std::cout << "\n\n\n";

		do
		{
			std::cout << "1 - Наличные\n2 - Картой: ";
			std::cin >> pay;
		} while (pay < 1 || pay > 2);
		if (pay == 1)
		{
			cash += totalSum;
			nal += totalSum;
			totalIncome += totalSum;
		}
		else if (pay == 2)
		{

			beznal += totalSum;
			totalIncome += totalSum;
		}


		do
		{
			std::cout << "Слейдущая покупка?\n1 - Да 2 - Нет: ";
			std::cin >> choice;
		} while (choice > 2 || choice < 1);
		if (choice == 2)
		{
			break;
		}
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
	int totalCount = 0;
	
	bool card = false;
	int cardChoice;
	
	do
	{
		std::cout << "Дисконтная карта? 1 - Да 2 - Нет: ";
		std::cin >> cardChoice;
	} while (cardChoice < 0 || cardChoice > 2);
	if (cardChoice == 1)
	{
		card = true;
	}
	else if (cardChoice == 2)
	{
		card = false;
	}
	std::cout << "Название товара\t\t\t\tКол-во\t\tЦена\n";
	for (int i = 0; i < receiptSize; i++)
	{
		std::cout << nameReceiptArr[i] << "\t\t\t" << countReceiptArr[i] << "\t\t" << priceReceiptArr[i] << "\n";
		totalSum += priceReceiptArr[i] * countReceiptArr[i];
		totalCount += countReceiptArr[i];
	}
	if (totalCount >= 5)
	{
		std::cout << "Скидка 10% за покупку 5 товаров и более\n";
		totalSum *= 0.90;
	}
	if (card)
	{
		std::cout << "Скидка по карте 5%\n";
		totalSum *= 0.95;
		
	}
	std::cout << "Итого:\t\t\t\t\t\t\t" << totalSum;
}

void ChangePrice()
{
	int id;
	double newPrice;
	do
	{
		std::cout << "Введите ID товара для изменения цены: ";
		std::cin >> id;
	} while (id<1 || id>idArr[size - 1]);

	std::cout << "\n\nВыбран товар: " << nameArr[id - 1] << " = " << priceArr[id - 1];
	do
	{
		std::cout << "\nВведите новую цену: ";
		std::cin >> newPrice;
	} while (newPrice < 0.01 || newPrice > 10000000.0);
	priceArr[id - 1] = newPrice;
	std::cout << "\nЦена успешно изменена\n\n";
}

void AddItems()
{
	int id;
	double newCount;
	do
	{
		std::cout << "Введите ID товара для пополнения: ";
		std::cin >> id;
	} while (id<1 || id>idArr[size - 1]);

	std::cout << "\n\nВыбран товар: " << nameArr[id - 1] << " = " << countArr[id - 1] << " штук";
	do
	{
		std::cout << "\nВведите кол-во товара: ";
		std::cin >> newCount;
	} while (newCount < 0 || newCount > 5000);
	countArr[id - 1] += newCount;
	std::cout << "\nТовар успешно пополнен\n\n";
}

void RemoveItems()
{
	int id;
	double newCount;
	do
	{
		std::cout << "Введите ID товара для списания: ";
		std::cin >> id;
	} while (id<1 || id>idArr[size - 1]);

	std::cout << "\n\nВыбран товар: " << nameArr[id - 1] << " = " << countArr[id - 1] << " штук";
	do
	{
		std::cout << "\nВведите кол-во товара: ";
		std::cin >> newCount;
	} while (newCount < 0 || newCount > countArr[id - 1]);
	countArr[id - 1] -= newCount;
	std::cout << "\nТовар успешно списан\n\n";
}

void ChangeStorage()
{
	int choose;
	do
	{
		std::cout << "1 - Добавить товар в склад\n2 - Убрать товар со склада\n0 - Выход\n";
		std::cin >> choose;
	} while (choose < 0 || choose > 2);
	if (choose == 1)
	{
		AddElementToEnd();
	}
	else if (choose == 2)
	{
		RemoveElementOnIndex();
	}
	else
	{
		std::cout << "Выхожу...";
	}
}

void AddElementToEnd()
{
	int* idArrTemp = new int[size];
	std::string* tempNameArr = new std::string[size];
	int* tempCountArr = new int[size];
	double* tempPriceArr = new double[size];

	for (int i = 0; i < size; i++)
	{
		idArrTemp[i] = idArr[i];
		tempNameArr[i] = nameArr[i];
		tempCountArr[i] = countArr[i];
		tempPriceArr[i] = priceArr[i];
	}
	delete[] idArr;
	delete[] nameArr;
	delete[] countArr;
	delete[] priceArr;
	size++;
	idArr = new int[size];
	nameArr = new std::string[size];
	countArr = new int[size];
	priceArr = new double[size];

	for (int i = 0; i < size - 1; i++)
	{
		idArr[i] = idArrTemp[i];
		nameArr[i] = tempNameArr[i];
		countArr[i] = tempCountArr[i];
		priceArr[i] = tempPriceArr[i];
	}
	idArr[size - 1] = size - 1;
	std::cout << "Введите имя нового товара: ";
	std::cin.ignore(32000, '\n');
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, nameArr[size - 1], '\n');
	std::cout << "Введите кол-во нового товара: ";
	std::cin >> countArr[size - 1];
	std::cout << "Введите цену нового товара: ";
	std::cin >> priceArr[size - 1];

	delete[] idArrTemp;
	delete[] tempNameArr;
	delete[] tempCountArr;
	delete[] tempPriceArr;
}

void RemoveElementOnIndex()
{
	int* idArrTemp = new int[size];
	std::string* tempNameArr = new std::string[size];
	int* tempCountArr = new int[size];
	double* tempPriceArr = new double[size];

	for (int i = 0; i < size; i++)
	{
		idArrTemp[i] = idArr[i];
		tempNameArr[i] = nameArr[i];
		tempCountArr[i] = countArr[i];
		tempPriceArr[i] = priceArr[i];
	}
	delete[] idArr;
	delete[] nameArr;
	delete[] countArr;
	delete[] priceArr;
	size--;
	idArr = new int[size];
	nameArr = new std::string[size];
	countArr = new int[size];
	priceArr = new double[size];
	int index = 0;
	do
	{
		std::cout << "Введите ID товара для удаления: ";
		std::cin >> index;
	} while (index < 1 || index > size+1);

	for (int i = 0, j = 0; i < size, j < size; i++, j++)
	{
		if (index - 1 == i)
		{
			i++;
			idArr[j] = idArrTemp[j];
			nameArr[j] = tempNameArr[i];
			countArr[j] = tempCountArr[i];
			priceArr[j] = tempPriceArr[i];
		}
		else
		{
			idArr[j] = idArrTemp[j];
			nameArr[j] = tempNameArr[i];
			countArr[j] = tempCountArr[i];
			priceArr[j] = tempPriceArr[i];
		}
	}

	/*
	for (int i = 0; i < size - 1; i++)
	{
		idArr[i] = idArrTemp[i];
		nameArr[i] = tempNameArr[i];
		countArr[i] = tempCountArr[i];
		priceArr[i] = tempPriceArr[i];
	}
	*/



	delete[] idArrTemp;
	delete[] tempNameArr;
	delete[] tempCountArr;
	delete[] tempPriceArr;
}

void CashStatus()
{
	std::cout << "Наличные в кассе: " << cash;
	std::cout << "\nВыручка наличными: " << nal;
	std::cout << "\nВыручка картой: " << beznal;
	std::cout << "\nВсё выручка: " << totalIncome << "\n";
	if (totalIncome > 40000)
	{
		std::cout << "\t\t\t\t$$$ Big Money $$$\n";
	}

}

void CreateNewStorage()
{
	DeleteMainArrays();
	
	std::cout << "Введите количество типов товаров на складе: ";
	std::cin >> size;
	int* idArr = new int[size];
	std::string* nameArr = new std::string[size];
	int* countArr = new int[size];
	double* priceArr = new double[size];

	for (int i = 0; i < size; i++)
	{
		std::cin.ignore(32000, '\n');
		std::cout << "Введите название товара номер" << i + 1 << ": ";
		std::getline(std::cin, nameArr[i]);
		std::cout << "Введите количество " << nameArr[i] << ": ";
		std::cin >> countArr[i];
		std::cout << "Введите цену " << nameArr[i] << ": ";
		std::cin >> priceArr[i];
		idArr[i] = i;
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