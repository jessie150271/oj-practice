//Name: 黃詩棋
//Date: April 16, 2017
//Last Updata: April 16, 2017
//Problem statement: CH10_01_Design Polynomial Class
#include<iostream>
#include<cmath>
using namespace std;

class Polynomial {
public:
	Polynomial(); // creates an empty polynomial
	Polynomial(const Polynomial& poly);
	Polynomial(double coefficient[], int size);
	~Polynomial();
	//Use indexed polynomial as r-value to inspect coefficient
	//and as l-value to assign coefficient
	double& operator[](int degree);
	//This is required if we are to have const correctness
	const double& operator[](int degree)const;
	const Polynomial& operator=(const Polynomial & rhs);
	int mySize();
	//friend functions:
	friend double evaluate(const Polynomial& poly, double arg);
	friend Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);
	friend Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs);
	friend Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs);
private:
	double *coef;
	int size;
};

//Default constructor
Polynomial::Polynomial() {
	coef = new double;
	size = 0;
}

//Copy constructor
Polynomial::Polynomial(const Polynomial& poly) {
	this->size = poly.size;
	this->coef = new double[this->size];
	for (int i = 0; i < this->size; i++)
		this->coef[i] = poly.coef[i];
}

//Parameterized constructor
Polynomial::Polynomial(double coefficient[], int size) {
	this->size = size;
	this->coef = new double[size];
	for (int i = 0; i < size; i++)
		this->coef[i] = coefficient[i];
}

//Destructor
Polynomial::~Polynomial() {
	delete []coef;
}

//return size
int Polynomial::mySize() {
	return this->size;
}

// ↓ Operator member function ↓
double& Polynomial::operator[](int degree){
	return this->coef[degree];
}

const double& Polynomial::operator[](int degree)const {
	return this->coef[degree];
}

const Polynomial& Polynomial::operator=(const Polynomial& rhs) {
	if (this == &rhs)
		return *this;
	else {
		if (this->coef != NULL)
			delete[] this->coef;
		this->size = rhs.size;
		this->coef = new double[this->size];
		for (int i = 0; i < this->size; i++)
			this->coef[i] = rhs.coef[i];
		return *this;
	}
}

// ↓ Friend function ↓
double evaluate(const Polynomial& poly, double arg) {
	double value = 0;
	for (int i = 0; i < poly.size; i++)
		value += poly.coef[i] * pow(arg, i);
	return value;
}

Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs) {
	Polynomial temp;
	temp = (lhs.size >= rhs.size) ? lhs : rhs;//copy size較大的給temp
	for (int i = 0; i < temp.size; i++) {
		temp[i] += (temp.size == lhs.size) ? rhs.coef[i] : lhs.coef[i];
		if (i == lhs.size - 1 || i == rhs.size - 1)//較小的加完了
			break;
	}
	return temp;
}

Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs) {
	double *tempAry;
	int tempSize;
	tempSize = (lhs.size >= rhs.size) ? lhs.size : rhs.size;
	tempAry = new double[tempSize];
	for (int i = 0; i < tempSize; i++) {
		if (i < lhs.size && i < rhs.size)			// lhs和rhs在rank(i)時都有係數
			tempAry[i] = lhs.coef[i] - rhs.coef[i];
		else if (i < lhs.size && i >= lhs.size)		// lhs的rank > rhs的rank
			tempAry[i] = lhs.coef[i];
		else if (i >= lhs.size && i < rhs.size)		// lhs的rank < rhs的rank
			tempAry[i] = -rhs.coef[i];
	}
	int tempSize2 = tempSize;
	for (int i = tempSize - 1; i > 0; i--) {		//若最高項係數為0 不要新增此項
		if (tempAry[i] == 0)
			tempSize2 = i - 1;
		else
			break;
	}
	if (tempSize != tempSize2) {					//判斷高次向是否為0
		double *tempAry2;
		tempAry2 = new double[tempSize2];
		for (int i = 0; i < tempSize2; i++)
			tempAry2[i] = tempAry[i];
		delete[]tempAry;
		tempAry = NULL;
		return Polynomial(tempAry2, tempSize2);
	}
	else
		return Polynomial(tempAry, tempSize);
}

Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs) {
	Polynomial temp;
	temp.size = lhs.size + rhs.size - 1;
	temp.coef = new double[temp.size];			//相乘的項次為兩式最高項次相加
	for (int i = 0; i < temp.size; i++)
		temp.coef[i] = 0;
	for (int i = 0; i < lhs.size; i++)
		for (int j = 0; j < rhs.size; j++)		//兩係數相乘之值在i+j項次
			temp.coef[i + j] += lhs.coef[i] * rhs.coef[j];
	return temp;
}


//input-main1.cpp
int main()
{
	Polynomial empty;
	double one[] = { 1 };
	Polynomial One(one, 1);
	double quad[] = { 3, 2, 1 };
	double cubic[] = { 1, 2, 0, 3 };
	Polynomial q(quad, 3); // q is 3 + 2*x + x*x
	Polynomial c(cubic, 4);// c is 1 + 2*x + 0*x*x + 3*x*x*x
	Polynomial p = q;  // test copy constructor
	Polynomial r;
	r = q;             //test operator=
	r = c;

	cout << "Polynomial q " << endl;
	for (int i = 0; i < 3; i++)
		cout << "term with degree " << i << " has coefficient " << q[i] << endl;
	
	cout << "Polynomial c " << endl;
	for (int i = 0; i < 4; i++)
		cout << "term with degree " << i << " has coefficient " << c[i] << endl;
	
	cout << "value of q(2) is " << evaluate(q, 2) << endl;
	cout << "value of p(2) is " << evaluate(p, 2) << endl;
	cout << "value of r(2) is " << evaluate(r, 2) << endl;
	cout << "value of c(2) is " << evaluate(c, 2) << endl;

	r = q + c;
	cout << "value of (q + c)(2) is " << evaluate(r, 2) << endl;

	r = q - c;
	cout << "value of (q - c)(2) is " << evaluate(r, 2) << endl;

	r = q * c;
	cout << "size of q*c is " << r.mySize() << endl;
	cout << "Polynomial r (= q*c) " << endl;

	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;

	cout << "value of (q * c)(2) is " << evaluate(r, 2) << endl;
	return 0;
}