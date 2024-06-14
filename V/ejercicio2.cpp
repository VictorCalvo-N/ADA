#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//==============================================
//PARTE A Y B
struct Program
{
	int id;
	int size;
};

bool comparar(Program a, Program b) {
	return a.size < b.size;
}
//==============================================
//PARTE B

int main() {
	//PARTE A
	cout << "PARTE A" << endl;
	int n; //cantidad de programas
	int D; //cantidad de disco
	cout << "Ingrese la cantidad de programas: ";
	cin >> n;
	cout << "Ingrese la cantidad del disco: ";
	cin >> D;

	vector<Program> programas(n);
	cout << "Ingrese los tamanos de los programas: " << endl;
	for(int i = 0; i < n; i++) {
		programas[i].id = i + 1;
		cout << "Tamano " << i + 1 << ": ";
		cin >> programas[i].size;
	}

	//Ordenar los programas por tamaño
	sort(programas.begin(), programas.end(), comparar);

	int totalSize = 0;
	vector<int> selector;

	for(int i = 0; i < n; i++) {
		if(totalSize + programas[i].size <= D) {
			totalSize += programas[i].size;
			selector.push_back(programas[i].id);
		}
		else {
			break;
		}
	}

	cout << "Numero maximo de programas almacenados: " << selector.size() << endl;
	cout << "Programas almacenados: ";
	for(auto id : selector) {
		cout << id << " ";
	}
	cout << endl;
	//==============================================
	//PARTE B
	cout << "PARTE B" << endl;
	int n2;
	int D2;
	cout << "Ingrese la cantidad de programas: ";
	cin >> n2;
	cout << "Ingrese la cantidad del disco: ";
	cin >> D2;

	vector<Program> programas2(n2);
	cout << "Ingrese los tamanos de los programas: " << endl;
	for (int i = 0; i < n; i++) {
		programas2[i].id = i + 1;
		cout << "Tamano " << i + 1 << ": ";
		cin >> programas2[i].size;
	}

	sort(programas2.begin(), programas2.end(), comparar);

	int totalSize2 = 0;
	vector<int> selector2;

	for (int i = 0; i < n2; i++)
	{
		if (totalSize+programas2[i].size <= 10)
		{
			totalSize2 += programas2[i].size;
			selector2.push_back(programas2[i].id);
		}
		else
		{
			break;
		}
	}

	cout << "Cantidad maxima utilizada: " << totalSize2 << "MB" << endl;
	cout << "Programas seleccionados: ";
	for (auto id : selector2)
	{
		cout << id << " ";
	}

	cout << endl;
	return 0;
}