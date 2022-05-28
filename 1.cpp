#include "1_1.h"

int main() {

	int variable1, variable2;

	cout << "Please, enter the value of the first variable: " << endl;

	cin >> variable1;


	cout << "Please, enter the value of the second variable: " << endl;

	cin >> variable2;

	int* pvariable1 = &variable1;

	int* pvariable2 = &variable2;


	change_pointer(pvariable1, pvariable2);


	change_link(variable1, variable2);

	




	float variable;

	cout << "Please, enter the value of the variable: " << endl;

	cin >> variable;

	float* pvariable = &variable;

	change_back_pointer(pvariable);

	change_back_link(variable);


	








	int radius, number;

	cout << "Please, enter the value of the radius: " << endl;

	cin >> radius;

	cout << "Please, enter the number you want to decrease the radius by: " << endl;

	cin >> number;

	int* pradius = &radius;

	int* pnumber = &number;


	reduce_pointer(pradius, pnumber);


	reduce_link(radius, number);
	
	








	int line, column;

	cout << "Please, enter size of matrix: " << endl;

	cout << "Please, enter necessary amount lines int the matrix: " << endl;

	cin >> line;


	cout << "Please, enter necessary amount columns int the matrix: " << endl;

	cin >> column;



	int string1;

	cout << "Please, enter the first changeable line: " << endl;

	cin >> string1;



	int string2;

	cout << "Please, enter the second changeable line: " << endl;

	cin >> string2;


	int* pline = &line;
	
	int* pcolumn = &column;

	int* pstroka1 = &string1;

	int* pstroka2 = &string2;



	swap_pointer(pline, pcolumn, pstroka1, pstroka2);

	swap_link(line, column, string1, string2);




	return 0;

}


void change_pointer(int* pointer1, int* pointer2) {

	if (*pointer1 > *pointer2) {
		*pointer1 = *pointer1 % *pointer2;
		cout << *pointer1 << endl;
	}
	else if (*pointer2 > *pointer1) {
		*pointer2 = *pointer2 % *pointer1;
		cout << *pointer2 << endl;
	}
	else {
		cout << "The values of the two variables are equal" << endl;
	}
}

void change_link(int& link1, int& link2) {
	if (link1 > link2) {
		link1 = link1 % link2;
		cout << link1 << endl;
	}
	else if (link2 > link1) {
		link2 = link2 % link1;
		cout << link2 << endl;
	}
	else {
		cout << "The values of the two variables are equal" << endl;
	}
}





void change_back_pointer(float* pointer) {

	cout << 1 / *pointer << endl;
}


void change_back_link(float& link) {
	cout << 1 / link << endl;
}






void reduce_pointer(int* pointer1, int* pointer2) {

	*pointer1 = *pointer1 - *pointer2;

	cout << *pointer1 << endl;

}


void reduce_link(int& link1, int& link2) {

	link1 = link1 - link2;

	cout << link1 << endl;
}




void swap_pointer(int* pointer_for_line, int* pointer_for_column, int* pointer_for_string1, int* pointer_for_string2) {

	*pointer_for_string1 = *pointer_for_string1 - 1;

	*pointer_for_string2 = *pointer_for_string2 - 1;


	int** matrix = new int* [*pointer_for_line];
	for (int i = 0; i < *pointer_for_line; i++) {
		matrix[i] = new int[*pointer_for_column];
	}


	cout << "Please, fill matrix with values: " << endl;


	for (int i = 0; i < *pointer_for_line; i++) {
		for (int j = 0; j < *pointer_for_column; j++) {
			cin >> matrix[i][j];
		}
	}

	int memory;

	for (int j = 0; j < *pointer_for_column; j++) {

		memory = matrix[*pointer_for_string1][j];

		matrix[*pointer_for_string1][j] = matrix[*pointer_for_string2][j];

		matrix[*pointer_for_string2][j] = memory;
	}


	cout << endl;


	for (int i = 0; i < *pointer_for_line; i++) {
		for (int j = 0; j < *pointer_for_column; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}


	for (int i = 0; i < *pointer_for_line; i++) {
		delete[] matrix[i];
	}


	delete[] matrix;


}


void swap_link(int& link_for_line, int& link_for_column, int& link_for_string1, int& link_for_string2) {


	link_for_string1 = link_for_string1 - 1;

	link_for_string2 = link_for_string2 - 1;



	int** matrix = new int* [link_for_line];
	for (int i = 0; i < link_for_line; i++) {
		matrix[i] = new int[link_for_column];
	}


	cout << "Please, fill matrix with values: " << endl;


	for (int i = 0; i < link_for_line; i++) {
		for (int j = 0; j < link_for_column; j++) {
			cin >> matrix[i][j];
		}
	}

	int memory;

	for (int j = 0; j < link_for_column; j++) {

		memory = matrix[link_for_string1][j];

		matrix[link_for_string1][j] = matrix[link_for_string2][j];

		matrix[link_for_string2][j] = memory;
	}


	cout << endl;


	for (int i = 0; i < link_for_line; i++) {
		for (int j = 0; j < link_for_column; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}


	for (int i = 0; i < link_for_line; i++) {
		delete[] matrix[i];
	}


	delete[] matrix;


}
