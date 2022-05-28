#include <iostream>
using namespace std;

class IGeoFig {
public:
	virtual double square() = 0;

	virtual double perimeter() = 0;
};

class CVector2D {
public:
	double x, y;
};


class IPhysObject {
public:
	virtual double mass() = 0;

	virtual CVector2D position() = 0;

	virtual bool operator == (const IPhysObject& ob) const = 0;

	virtual bool operator < (const IPhysObject& ob) const = 0;

};


class IPrintable {
public:
	virtual void draw() = 0;
};


class IDialogInitiable {
public:
	virtual void initFromDialog() = 0;
};


class BaseCObject {
public:
	virtual const char* classname() = 0;

	virtual unsigned int size() = 0;
};


class Rectangle : public IGeoFig, public IPhysObject, public IPrintable, public IDialogInitiable, public BaseCObject {
private:

	double square;

	double perimeter;


	double weight;


	CVector2D X;


	CVector2D Y;

public:



	void initFromDialog() override {


		cout << "Enter square of Rectangle: " << endl;

		cin >> square;



		cout << "Enter perimeter of Rectangle: " << endl;

		cin >> perimeter;
		

	}


	CVector2D position() override {


		cout << "Enter coordinates of Rectangle: " << endl;

		cin >> X.x;

		cin >> Y.y;


		return X;
	}




	double mass() override {


		cout << "Enter the mass of the Rectangle: " << endl;


		cin >> weight;



		return weight;
	}


	double square() override {

		return square;
	}

	double perimeter() override {

		return perimeter;
	}


	bool operator == (const IPhysObject& ob) const {

		return this->weight == ob.mass;


	}



	bool operator < (const IPhysObject& ob) const {

		return this->weight < ob.;
	}




	void draw() override {


		cout << "Rectangle" << endl;

		cout << "Square of Rectangle: " << square << endl;

		cout << "Perimeter of Rectangle: " << perimeter << endl;

		cout << "Mass of Rectangle: " << weight << endl;

		cout << "Coordinates of Rectangle: " << X.x << " " << Y.y << endl;

	}


};

class Ellipse : public IGeoFig, public IPhysObject, public IPrintable, public IDialogInitiable, public BaseCObject {
public:

	double square1;

	double perimeter1;


	double weight1;


	CVector2D X1;


	CVector2D Y1;

	void initFromDialog() {


		cout << "Enter square of Ellipse: " << endl;

		cin >> square1;


		cout << "Enter perimeter of Ellipse: " << endl;

		cin >> perimeter1;


	}


	double square() override {

		return square1;
	}

	double perimeter() override {

		return perimeter1;
	}


	CVector2D position() override {


		cout << "Enter coordinates of Rectangle: " << endl;

		cin >> X1.x;

		cin >> Y1.y;


		return X1;
	}




	double mass() override {


		cout << "Enter the mass of the Rectangle: " << endl;


		cin >> weight1;



		return weight1;
	}




	bool operator == (const IPhysObject& ob) const {

	}



	bool operator < (const IPhysObject& ob) const {

	}



	void draw() override {

		cout << "Ellipse" << endl;

		cout << "Square of Ellipse: " << square1 << endl;

		cout << "Perimeter of Ellipse: " << perimeter1 << endl;

		cout << "Mass of Ellipse: " << weight1 << endl;

		cout << "Coordinates of Ellipse: " << X1.x << " " << Y1.y << endl;

	}


};




int main() {


	Rectangle rectangle();

	Ellipse ellipse();


	bool result = rectangle == ellipse;

	cout << "==: " << result << endl;


	return 0;
}