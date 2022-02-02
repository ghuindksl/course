#include <string>
#include<fstream>
#include<iostream>
#include <iomanip>

using namespace std;
const int maxi = 10;
class Ctech
{
private:
	string techname[maxi] = {}; //массив для названий
	string techid[maxi] = {}; //массив для айди
public:
	Ctech();
	void open(); //функция открытия
	void save(); //save
	void add();
	void show();
	void del(string search);
	void found(string search);
	~Ctech();
};
