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

	cout << "������� ��� �������: ";
	cin >> name;

	while (getline(fileI, quantStr))
	{
		if (quantStr == name)
		{
			coincidence = false;
			cout << "����� ��� ��� ������!" << endl;
			break;
		}
	}
	if (coincidence == true)
	{
		file << name << endl;

		cout << "������� ������: ";
		cin >> pasword;
		file << "Pasword " << pasword << endl;

		cout << "�� ������������������!" << endl;
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

	cout << "������� ��� �������: ";
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
		cout << "������ ����� ���!" << endl;
	}
	else if (coincidence == true)
	{
		cout << "������� ������: ";
		cin >>  Pasword;

		getline(fileI, quantStr);

		if (quantStr == "Pasword " + Pasword)
		{
			cout << "����� ������ ����! �� ����� � �������!" << endl;
		}
		else
		{
			cout << "������ ������ ���! �� �� ����� � �������!" << endl;
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
	    cout << "1. ������������������ � �������;\n"
			"2. ����� � �������;\n"
			"��� �����: ";
		cin >> LogAndReg;

		ofstream fille;
		ifstream filleI;
		filleI.open("d:\\1\\PaswordAndName.txt");
		fille.open("d:\\1\\PaswordAndName.txt", ofstream::app);

		if (!fille)
		{
			cout << "���� �� ��������!" << endl;
			return -1;
		}

		else
		{
			cout << "���� ��������!" << endl;
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