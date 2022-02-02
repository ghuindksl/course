#include "Ctech.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void mainmenu() //функция вызова меню
{
    system("cls");
    cout << "Введите пункт выбора : \n";
    cout << "1.Добавить устройство в список\n";
    cout << "2.Удалить устройство из списка\n";
    cout << "3.Просмотреть устройства\n";
    cout << "4.Найти устройство\n";
    cout << "5.Сохранить\n";
    cout << "6.Выход\n\n";
    cout << "Ввод : ";
}

void main(int argc, char* argv[])
{
    Ctech osn;
    ofstream file; //создание переменной файлового типа 
    setlocale(LC_ALL,"Rus"); 
    bool mainexit = false; 
    int choose; //выбор пункта
    string searchh; 
    osn.open();//открытие файла
    while (mainexit == false) //проверка на завершение программы
    {
        mainmenu(); //вывод пунктов меню
        cin >> choose; //вводим необх.пункт
        switch (choose) 
        {
        case 1:
            osn.add();//функция добавления техники
            break;
        case 2:
            system("cls");
            cout << "Введите id техники: ";
            cin >> searchh;
            osn.del(searchh); //функция удаления техники
            break;
        case 3:
            osn.show();//функция вывода списка
            break;
        case 4:
            system("cls");
            cout << "Введите id техники: ";
            cin >> searchh;
            osn.found(searchh);//функция поиска техники
            break;
        case 5: 
            osn.save(); //функция сохранения
            break;
        case 6:
            mainexit = true;
            osn.~Ctech();
            file.close();
            break;
        default: 
            system("cls"); 
            cout << "Недопустимый ввод\n"; 
            system("pause");
            continue; //продолжаем ввод
        }
    }   
}