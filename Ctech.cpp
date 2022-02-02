#include "Ctech.h"
 

Ctech::Ctech()
{

}

void Ctech::open() //функция открытия
{
    string line;
    ifstream file("C://course/technika.txt", ios_base::binary); //открываем файл для чтения

    if (file.is_open()) //проверяем успешное открытие файла
    {
        for (int i = 0; i < maxi; i++)
        {
            line = ""; //по умолчанию строка пустая
            file >> line; //вписываем в строку значение из файла
            if (i % 2 == 0) //проверка строки на чётность
            {
                techid[i] = line; //вписываем айди из строки
            }
            else techname[i - 1] = line; //вписываем название из строки
        }

    }
}

void Ctech::save() //функция сохранения
{
    ofstream file;
    file.open("C://course/technika.txt", ios_base::binary); //создание, открытие файла
    for (int i = 0; i < maxi; i++)
        file << techid[i] << endl << techname[i] << endl; //сохраняем в каждую чётную строку значение айди, в каждую нечётную - название
}

void Ctech::add() //функция добавления техники
{
    system("cls");
    string name; //для названий
    string id; //для id
    cout << "Введите название техники : ";
    cin >> name; //ввод названия
    cout << "Введите id техники : ";
    cin >> id; //ввод id
    for (int i = 0; i < maxi; i++)
    {
        if (techid[i] == "\0") //ищем пустой элемент массива id
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
    int k = 1;//порядок в списке
    cout << setw(5) << "C" << setw(8) << "ID" << setw(15) << "NAME\n" << endl;
    for (int i = 0; i < maxi; i++)
    {
        if (techid[i] != "\0") //если в массиве что-то есть
        {
            cout << setw(5) << k << setw(8) << techid[i] << setw(15) << techname[i] << endl;
            k++;
        }
    }
    system("pause");
}

void Ctech::del(string search) //функция удаления техники
{
    system("cls");
    int s = 0;
    for (int i = 0; i < maxi; i++)
    {
        if (techid[i] == search) //проверка очередного элемента массива id на необходимый id
        {
            techid[i] = "";
            techname[i] = "";
            cout << "Удалено";
            s++;
            break;
        }
    }
    if (s == 0)
    {
        cout << "Данной техники нет в списке\n";
        system("pause");
    }
}

void Ctech::found(string search) //функция поиска техники
{
    system("cls");
    int k = 1; //порядок в списке
    int s = 0; //устанавливаем флажок
    string fl, sl;
    for (int i = 0; i < maxi; i++)
    {
        if (techid[i] == search) //проверка очередного элемента массива id на необходимый id
        {
            fl = techid[i];
            sl = techname[i];
            s++;
        }
        k++;
    }
    if (s == 0) //проверка флажка
    {
        cout << "Данной техники нет в списке\n";
    }
    else if (s == 1)
    {
        cout << setw(5) << "C" << setw(8) << "ID" << setw(15) << "NAME\n" << setw(5) << k << setw(8) << fl << setw(15) << sl << endl; //вывод нужного;
    }
    system("pause");
}

Ctech::~Ctech()
{

}