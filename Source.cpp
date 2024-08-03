#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void reg()
{
	ofstream file;
	ifstream fileI;
	fileI.open("d:\\1\\PaswordAndName.txt");
	file.open("d:\\1\\PaswordAndName.txt", ofstream::app);

	string quantStr, name, pasword;
	bool coincidence = true;

	cout << "Введите имя акаунта: ";
	cin >> name;

	while (getline(fileI, quantStr))
	{
		if (quantStr == name)
		{
			coincidence = false;
			cout << "Такое имя уже занято!" << endl;
			break;
		}
	}
	if (coincidence == true)
	{
		file << name << endl;

		cout << "Введите пароль: ";
		cin >> pasword;
		file << "Pasword " << pasword << endl;

		cout << "Вы зарегистрировались!" << endl;
	}
	file.close();
	fileI.close();
}

void login()
{
	ofstream file;
	ifstream fileI;
	fileI.open("d:\\1\\PaswordAndName.txt");
	file.open("d:\\1\\PaswordAndName.txt", ofstream::app);

	string Name, quantStr, Pasword;
	bool coincidence = true;

	cout << "Введите имя акаунта: ";
	cin >> Name;

	while (getline(fileI, quantStr))
	{
		if (quantStr == Name)
		{
			coincidence = true;
			break;
		}
		else
		{
			coincidence = false;
		}
	}
	if (coincidence == false)
	{
		cout << "Такого имени нет!" << endl;
	}
	else if (coincidence == true)
	{
		cout << "Введите пороль: ";
		cin >>  Pasword;

		getline(fileI, quantStr);

		if (quantStr == "Pasword " + Pasword)
		{
			cout << "Такой пороль есть! Вы вошли в систему!" << endl;
		}
		else
		{
			cout << "Такого пороля нет! Вы не вошли в систему!" << endl;
		}
	}

	file.close();
	fileI.close();
}

int main()
{
	setlocale(LC_ALL, "ru");

	int LogAndReg, StartWork = 1;

	while (StartWork == 1)
	{
	    cout << "1. Зарегистрироваться в системе;\n"
			"2. Войти в систему;\n"
			"Ваш выбор: ";
		cin >> LogAndReg;

		ofstream fille;
		ifstream filleI;
		filleI.open("d:\\1\\PaswordAndName.txt");
		fille.open("d:\\1\\PaswordAndName.txt", ofstream::app);

		if (!fille)
		{
			cout << "Фаил не открылся!" << endl;
			return -1;
		}

		else
		{
			cout << "Фаил открылся!" << endl;
		}

		if (LogAndReg == 1)
		{
			reg();
		}

		else if(LogAndReg == 2)
		{
			login();
		}

		filleI.close();
		fille.close();
	}
}