#include "Ctech.h"
 

Ctech::Ctech()
{

}

void Ctech::open() //������� ��������
{
    string line;
    ifstream file("C://course/technika.txt", ios_base::binary); //��������� ���� ��� ������

    if (file.is_open()) //��������� �������� �������� �����
    {
        for (int i = 0; i < maxi; i++)
        {
            line = ""; //�� ��������� ������ ������
            file >> line; //��������� � ������ �������� �� �����
            if (i % 2 == 0) //�������� ������ �� ��������
            {
                techid[i] = line; //��������� ���� �� ������
            }
            else techname[i - 1] = line; //��������� �������� �� ������
        }

    }
}

void Ctech::save() //������� ����������
{
    ofstream file;
    file.open("C://course/technika.txt", ios_base::binary); //��������, �������� �����
    for (int i = 0; i < maxi; i++)
        file << techid[i] << endl << techname[i] << endl; //��������� � ������ ������ ������ �������� ����, � ������ �������� - ��������
}

void Ctech::add() //������� ���������� �������
{
    system("cls");
    string name; //��� ��������
    string id; //��� id
    cout << "������� �������� ������� : ";
    cin >> name; //���� ��������
    cout << "������� id ������� : ";
    cin >> id; //���� id
    for (int i = 0; i < maxi; i++)
    {
        if (techid[i] == "\0") //���� ������ ������� ������� id
        {
            techid[i] = id;
            techname[i] = name;
            break;
        }
    }
}

void Ctech::show()
{
    system("cls");
    int k = 1;//������� � ������
    cout << setw(5) << "C" << setw(8) << "ID" << setw(15) << "NAME\n" << endl;
    for (int i = 0; i < maxi; i++)
    {
        if (techid[i] != "\0") //���� � ������� ���-�� ����
        {
            cout << setw(5) << k << setw(8) << techid[i] << setw(15) << techname[i] << endl;
            k++;
        }
    }
    system("pause");
}

void Ctech::del(string search) //������� �������� �������
{
    system("cls");
    int s = 0;
    for (int i = 0; i < maxi; i++)
    {
        if (techid[i] == search) //�������� ���������� �������� ������� id �� ����������� id
        {
            techid[i] = "";
            techname[i] = "";
            cout << "�������";
            s++;
            break;
        }
    }
    if (s == 0)
    {
        cout << "������ ������� ��� � ������\n";
        system("pause");
    }
}

void Ctech::found(string search) //������� ������ �������
{
    system("cls");
    int k = 1; //������� � ������
    int s = 0; //������������� ������
    string fl, sl;
    for (int i = 0; i < maxi; i++)
    {
        if (techid[i] == search) //�������� ���������� �������� ������� id �� ����������� id
        {
            fl = techid[i];
            sl = techname[i];
            s++;
        }
        k++;
    }
    if (s == 0) //�������� ������
    {
        cout << "������ ������� ��� � ������\n";
    }
    else if (s == 1)
    {
        cout << setw(5) << "C" << setw(8) << "ID" << setw(15) << "NAME\n" << setw(5) << k << setw(8) << fl << setw(15) << sl << endl; //����� �������;
    }
    system("pause");
}

Ctech::~Ctech()
{

}