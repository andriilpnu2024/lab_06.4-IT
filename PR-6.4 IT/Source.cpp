#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int* a, const int size, const int Low, const int High);
int Max(int* a, const int size);
void Print(int* a, const int size);
int indexdodat(int* a,int size , int idod);
int sum(int* a, int i, int size, int sum);
void Sort(int* a, const int size, int poch, int kinz);
int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	int n = 0;
	int a1;
	int b;
	int sum1 = 0;
	int idod = 0 ;

	cout << "Input size - ";
	cin >> n;
	cout << "Input a - ";
	cin >> a1;
	cout << "Input b - ";
	cin >> b;
	
	int imax;
	imax = n - 1;
	int* a = new int[n];
	int Low = -15; 
	int High = 15;
	
	Create(a, n, Low, High); 
	int c = indexdodat(a, n, idod);
	cout << "       sum" << setw(2) << "=" << setw(2) << sum(a,c, n,sum1) << endl;
	cout << "Ind of max" << setw(2) << "=" << setw(2) << Max(a, n) << endl;
	Print(a, n);
	Sort(a,n,a1,b);
	Print(a, n);
	delete[] a;
	return 0;
}
int sum(int* a, int i, int size , int sum )
{
	for (int j =i; j < size; j++)
		sum += a[j];
	return sum ;
}


int indexdodat(int* a, int size, int idod)
{
	int j = 0;
	for (int i = 0; i < size; i++)
	{  
		if (a[i] > 0) {
			idod = i;
			break;
		}
	}
	return idod;
}
void Create(int* a, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
}
int Max(int* a, const int size)
{
	int max = a[size - 1];
	int imax = -1; // індекс максимального елемента
	for (int i = 0; i < size - 1; i++)
		if (abs(max) < abs(a[i]))
		{
			max = a[i];
			imax = i;
		}
	if (imax == -1)
	{
		imax = size - 1;
	}
	return imax;
}
void Sort(int* a, const int size, int poch, int kinz)
{
	int n = 0;
	for (int j = 1; j < size; j++) // номер поточного елемента
		if (!(a[j] < kinz && a[j] > poch)) // якщо порушено умову впорядкування
		{
			int tmp = a[j];

			for (int k = size-1; k >= j; k--) 
			{ // зсув
				a[k + 1] = a[k];
			}
			a[n] = a[j];
			n++;
		}
}
	//for (int c = 0; c <= size - 1; c++) {
	//	for (int i = 0; i >= poch && i <= kinz; i++) {
	//		int temp = a[c];
	//		int s = kinz - poch;
	//		a[c] = i;
	//		a[c + s] = temp;
	//		temp = 0;
	//	}
	//}
	/*for (int i = 0; i <= size - 1; i++) {
		for (int j = i + 1; j < size; j++){
			if (!(a[j] >= poch && a[j] <= kinz) && (a[i] >= poch && a[i] <= kinz)|| (a[j] >= poch && a[j] <= kinz) && !(a[i] >= poch && a[i] <= kinz)) {
				int tmp = a[j];
				a[j] = a[i];
				a[i] = tmp;
			}
		};
	}*/
	
/*int cout = 0;

		if (a[c] >= poch && a[c] <= kinz) {
			if (a[cout] >= poch && a[cout] <= kinz)
				cout += 1;
			int temp;
			temp = a[cout];
			a[cout] = a[c]; 
			a[c] = temp; 
			cout++;*/

void Print(int* a, int size)
{
	cout << "a[" << setw(1);
	for (int i = 0; i < size; i++)
		if (i == size - 1)
			cout << setw(1) << a[i];
		else
			cout << setw(1) << a[i] << ", ";
	cout << "]" << endl;
}
