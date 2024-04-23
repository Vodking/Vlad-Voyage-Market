#include<iostream>
#include<cstdlib>
#include<string>
#include<limits>
#include<iomanip>

// ���� ������ ������� ��������� ��� �����������

//���������� �������
int size = 10;
int receiptSize = 1;

int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
double* priceArr = new double[size];
//������ ��� ����
std::string* nameReceiptArr = new std::string[receiptSize];
int* countReceiptArr = new int[receiptSize];
double* priceReceiptArr = new double[receiptSize];

template <typename ArrType>
void FillArray(ArrType staticArr, ArrType dinArr, int size);



//�������� �������
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
					CreateStorage();
					Shop();

				}
				else if (chooseStorageType == 2)
				{
					std::cout << "�� ��������...\n";
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
	std::string name[staticSize]{ "������ 0.5 ������","������ 1 ����\t"
		,"������ 2 �����\t","������� '��������'"
		,"������� '�������'","������� '���� ������'"
		,"�������� ��� '�������'","�������� ��� '��������'"
		,"����-���� '�����'","������ '���� �������'" };
	int count[staticSize]{ 5, 13, 10, 3, 4, 2, 7, 14, 6, 10 };
	double price[staticSize]{ 539.99,749.99,999.99,769.99,1199.99,2499.99,199.99,499.99,899.99,1699.99 };

	FillArray(id, idArr, staticSize);
	FillArray(name, nameArr, staticSize);
	FillArray(count, countArr, staticSize);
	FillArray(price, priceArr, staticSize);
}

void ShowStorage()
{
	std::cout << "ID\t�������� ������\t\t\t\t���-��\t\t����\n";
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
			std::cout << "1 - �������� �����\n";
			std::cout << "2 - ������ �������\n";
			std::cout << "3 - �������� ����\n";
			std::cout << "4 - ������� �����\n";
			std::cout << "5 - ��������� �����\n";
			std::cout << "6 - ��������� ������\n";
			std::cout << "0 - ��������� �����\n";
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
			std::cout << "������� ID ������: ";
			std::cin >> chooseId;
			if (chooseId < 1 || chooseId > size)
			{
				std::cerr << "������� ������ ���.\n";
				continue;
			}
			if (countArr[chooseId - 1] > 0)
			{
				while (true)
				{
					std::cout << "\n��������� �����: " << nameArr[chooseId - 1] << "\n";
					std::cout << "���-�� ������� ������ �� ������: " << countArr[chooseId - 1] << "\n";
					std::cout << "������� ���-�� ������: ";
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
				std::cerr << "���� ����� �����\n";
				continue;
			}

			std::cout << "�����: " << nameArr[chooseId - 1] << "\n���-��: " << chooseCount << "\n";
			std::cout << "1 - �����������, 2 - ������";
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

			std::cout << "������ ��� ���� �����?\n";
			std::cout << "1 - ��, 2 - ���";
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
	std::cout << "�������� ������\t\t\t\t���-��\t\t����\n";
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