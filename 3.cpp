#include "3.h"


class Square {
private:
	int side;
	int corner;
	int x;
	int y;

public:
	Square() {

	}


	Square(int valueSide, int valueCorner, int valueX, int valueY) {
		side = valueSide;
		corner = valueCorner;
		x = valueX;
		y = valueY;
	}


	bool operator ==(const Square& other) {

		return this->side == other.side;
	}


	bool operator !=(const Square& other) {

		return !(this->side == other.side);
	}


	bool operator <(const Square& other) {

		return this->side < other.side;
	}


	bool operator >(const Square& other) {

		return this->side > other.side;
	}



	Square operator *(const Square& other) {


		Square temp;

		temp.side = this->side * other.side;

		return temp;
	}


	Square operator +(const Square& other) {

		Square temp1;

		temp1.x = this->x + other.x;

		temp1.y = this->y + other.y;

		return temp1;
	}

	int GetX() {
		return x;
	}

	int GetY() {
		return y;
	}


	int GetSide() {
		return side;
	}

};


class Array {
private:
	int size;
	int *array;

public:

	Array() {

	}

	Array(int scale) {
		size = scale;
		array = new int[size];

		for (int i = 0; i < size; i++) {
			array[i] = i;
		}
	}

	int operator +(const Array& other) {

		int size1 = this->size + other.size;


		int* array1 = new int[size1];

		int j = 0;

		for (int i = 0; i < size1; i++) {
			if (i < this->size) {
				array1[i] = this->array[i];
			}
			else {
				array1[i] = other.array[j];
				j++;
			}
		}


		for (int i = 0; i < size1; i++) {
			cout << array1[i] << " ";
		}


		return *array1;

	}

	bool operator ==(const Array& other) {

		return this->size == other.size;
	}


	bool operator !=(const Array& other) {

		return !(this->size == other.size);
	}


	bool operator <(const Array& other) {

		return this->size < other.size;
	}


	bool operator >(const Array& other) {

		return this->size > other.size;
	}

	~Array() {
		delete[] array;
	}


};


int main() {


	int value1, value2, value3, value4;

	cout << "Please, enter value of side: " << endl;

	cin >> value1;


	cout << "Please, enter value of corner: " << endl;

	cin >> value2;


	cout << "Please, enter coordinates: " << endl;

	cin >> value3;

	cin >> value4;


	Square square(value1, value2, value3, value4);

	cout << "Please, fill in the secind square for the equality function: " << endl;

	int value5, value6, value7, value8;

	cout << "Please, enter value of side: " << endl;

	cin >> value5;


	cout << "Please, enter value of corner: " << endl;

	cin >> value6;


	cout << "Please, enter coordinates: " << endl;

	cin >> value7;

	cin >> value8;

	Square square1(value5, value6, value7, value8);

	cout << "Enter the size of the array1: " << endl;

	int root1;

	cin >> root1;

	Array array1(root1);


	cout << "Enter the size of the array2: " << endl;

	int root2;

	cin >> root2;

	Array array2(root2);


	bool check = true;


	while (check) {

		cout << "Please, enter function number: " << endl;

		cout << "1 - equality, 2 - multiplication, 3 - bias, 4 - union, 5 - compare" << endl;

		int choice;

		cin >> choice;


		switch (choice) {
		case 1:
		{
			bool result = square == square1;

			cout << "==: " << result << endl;



			bool result1 = square != square1;

			cout << "!=: " << result1 << endl;



			bool result2 = square < square1;

			cout << "<: " << result2 << endl;




			bool result3 = square > square1;

			cout << ">: " << result3 << endl;
		}
		break;


		case 2:
		{

			Square multiplication = square * square1;

			int resume = multiplication.GetSide();

			cout << resume << endl;

		}
		break;


		case 3:
		{

			Square bias = square + square1;

			int totalX = bias.GetX();

			int totalY = bias.GetY();

			cout << totalX << " " << totalY << endl;
			 
		}
		break;


		case 4:
		{
			Array array_union = array1 + array2;

		}
		break;

		case 5:
		{
			bool result = array1 == array2;

			cout << "==: " << result << endl;



			bool result1 = array1 != array2;

			cout << "!=: " << result1 << endl;



			bool result2 = array1 < array2;

			cout << "<: " << result2 << endl;




			bool result3 = array1 > array2;

			cout << ">: " << result3 << endl;
		}
		break;



		default:
			cout << "Error" << endl;
		}

		int choice1;

		cout << "Do you want to continue work?" << endl;
		cout << "Enter 1, if yes and enter 0, if no" << endl;

		cin >> choice1;

		if (choice1 == 1) {
			continue;
		}
		else if (choice1 == 0) {
			break;
		}
		else {
			cout << "Error" << endl;
			break;
		}
	}



	return 0;
}