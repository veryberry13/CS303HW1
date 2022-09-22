#include <iostream>
#include <fstream>
#include <vector>
#include "Database.h"

using namespace std;

/// this method displays all the value in the array /// 
void Database::display(int* data, int array_size) {
	cout << "the values in the array are:";
	for (int count = 0; count < array_size; count++)
		cout << " " << data[count];
	cout << endl;
};
/// this method checks if a value is in the array ///
int Database::valuechecker(int checker, int* data, int array_size) {
	int checker2 = 0;
	int count;
		for (count = 0; count < array_size; count++)
			if (checker == data[count]) {
				cout << "the integer is present and it's index is:" << count;
				cout << endl;
				checker2++;
				break;
			};
	if (checker2 == 0)
		cout << "the integer is not in the database.";

	return count;
}
/// this method replaces a value is in the array at a given index ///
int Database::valuereplacer(int index, int value, int* data, int array_size) {
	if (index > array_size) {
		cout << "that index is not in the database.";
		system("pause");
		return 0;
		cout << endl;
	}
	if (index < 0) {
		cout << "that index is not in the database.";
		system("pause");
		return 0;
		cout << endl;
	}

	int old_value = data[index];
	data[index] = value;
	return old_value;
}
/// this method appends a given value to the end of the array ///
void Database::append(int value, int* & data, int & size) {
		
		int appended_size = size + 1;
		int* data2 = new int[appended_size];
		data2[size] = value;
		for (int count = 0; count < size; count++) {
			data2[count] = data[count];
		}
		size = appended_size;
		data = data2;



}
void Database::remove(int index, int*& data, int& size) {

	int appended_size = size - 1;
	int* data2 = new int[appended_size];
	for (int count = 0; count < index; count++) {
		data2[count] = data[count];
	}
	for (int count = index; count < appended_size; count++) {
		data2[count] = data[count+1];
	}
	size = appended_size;
	data = data2;



}
int main()
{
	Database D;
	int val;
	int* data = new int[100];

	ifstream inputfile;
	inputfile.open("cs303hw1_data.txt");
	if (!inputfile)
	{
		cout << "error!! data file not found" << endl;
		system("pause");
		exit(-1);
	}

	int count = 0;
	while (!inputfile.eof())
	{
		inputfile >> data[count];
		count++;
	}
	int array_size = count;
	cout << "the array size is:" << array_size << endl;


	int checker;
	cout << "enter an integer to determine if it's in the database and it's index:";
	cout << endl;
	cin >> checker;
	D.valuechecker(checker, data, array_size);
	D.display(data, array_size);

	int index;
	cout << "enter the index of the array that you want replaced:";
	cout << endl;
	cin >> index;
	int value;
	cout << "enter the value that you want that index to be replaced with:";
	cout << endl;
	cin >> value;
	int old_value = D.valuereplacer(index, value, data, array_size);
	cout << "the value at that index was:" << old_value << endl;
	cout << "the value at that index was:" << data[index] << endl;

	D.display(data, array_size);

	cout << "what value would you like to add to the array:";
	cout << endl;
	cin >> value;
	D.append(value, data, array_size);

	D.display(data, array_size);

	cout << "what index would you like to remove from the array:";
	cout << endl;
	cin >> index;
	D.remove(index, data, array_size);

	D.display(data, array_size);

}
//#include <iostream>
//#include <fstream>
//#include <vector>
////#include "CS303HW1.h"
//
//using namespace std;
//
//
//void displayDatabase(int* data, int array_size) {
//	cout << "the values in the array are:";
//	for (int count = 0; count < array_size; count++)
//		cout << " " << data[count];
//	cout << endl;
//};
//
//int valuecheckerDatabase(int checker, int* data, int array_size) {
//	int checker2 = 0;
//	int count;
//	for (count = 0; count < array_size; count++)
//		if (checker == data[count]) {
//			cout << "the integer is present and it's index is:" << count;
//			cout << endl;
//			checker2++;
//			break;
//		};
//	if (checker2 == 0)
//		cout << "the integer is not in the database.";
//
//	return count;
//}
//int valuereplacerDatabase(int index, int value, int* data, int array_size) {
//	if (index > array_size) {
//		cout << "that index is not in the database.";
//		system("pause");
//		return 0;
//		cout << endl;
//	}
//	if (index < 0) {
//		cout << "that index is not in the database.";
//		system("pause");
//		return 0;
//		cout << endl;
//	}
//
//	int old_value = data[index];
//	data[index] = value;
//	return old_value;
//}
//void appendDatabase(int value, int*& data, int& size) {
//
//	int appended_size = size + 1;
//	int* data2 = new int[appended_size];
//	data2[size] = value;
//	for (int count = 0; count < size; count++) {
//		data2[count] = data[count];
//	}
//	size = appended_size;
//	data = data2;
//
//
//
//}
//void removeDatabase(int index, int*& data, int& size) {
//
//	int appended_size = size - 1;
//	int* data2 = new int[appended_size];
//	for (int count = 0; count < index; count++) {
//		data2[count] = data[count];
//	}
//	for (int count = index; count < appended_size; count++) {
//		data2[count] = data[count + 1];
//	}
//	size = appended_size;
//	data = data2;
//
//
//
//}
//int main()
//{
//
//	int val;
//	int* data = new int[100];
//
//	ifstream inputfile;
//	inputfile.open("cs303hw1_data.txt");
//	if (!inputfile)
//	{
//		cout << "error!! data file not found" << endl;
//		system("pause");
//		exit(-1);
//	}
//
//	int count = 0;
//	while (!inputfile.eof())
//	{
//		inputfile >> data[count];
//		count++;
//	}
//	int array_size = count;
//	cout << "the array size is:" << array_size << endl;
//
//
//	int checker;
//	cout << "enter an integer to determine if it's in the database and it's index:";
//	cout << endl;
//	cin >> checker;
//	valuecheckerDatabase(checker, data, array_size);
//	displayDatabase(data, array_size);
//
//	int index;
//	cout << "enter the index of the array that you want replaced:";
//	cout << endl;
//	cin >> index;
//	int value;
//	cout << "enter the value that you want that index to be replaced with:";
//	cout << endl;
//	cin >> value;
//	int old_value = valuereplacerDatabase(index, value, data, array_size);
//	cout << "the value at that index was:" << old_value << endl;
//	cout << "the value at that index was:" << data[index] << endl;
//
//	displayDatabase(data, array_size);
//
//	cout << "what value would you like to add to the array:";
//	cout << endl;
//	cin >> value;
//	appendDatabase(value, data, array_size);
//
//	displayDatabase(data, array_size);
//
//	cout << "what index would you like to remove from the array:";
//	cout << endl;
//	cin >> index;
//	removeDatabase(index, data, array_size);
//
//	displayDatabase(data, array_size);
//
//}
