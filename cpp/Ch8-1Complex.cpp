// Name: B10401058 黃詩棋
// Date: April 4, 2017 
// Last Update: April 4, 2017
// Problem statement: Complex
#include<iostream>
#include<cmath>
using namespace std;

class Complex
{
private:
	double realPart, imagPart;
public:
	//initialization
	Complex(double realPartData, double imagPartData) :realPart(realPartData), imagPart(imagPartData) {}
	Complex(double realPartData) :realPart(realPartData) { imagPart = 0; }
	Complex() { realPart = 0, imagPart = 0; }
	double real() const;
	double imag() const;

	friend const double real(const Complex& x);
	friend const double imag(const Complex& x);
	friend const double norm(const Complex& x);
	friend const bool operator ==(const Complex& x, const Complex& y);
	friend const Complex operator +(const Complex& x, const Complex& y);
	friend const Complex operator -(const Complex& x, const Complex& y);
	friend const Complex operator *(const Complex& x, const Complex& y);
	friend const Complex operator /(const Complex& x, const Complex& y);
	friend ostream& operator <<(ostream& outputStream, const Complex& x);
	friend istream& operator >>(istream& inputStream, Complex& x);
};

double Complex::real() const
{
	return realPart;
}

double Complex::imag() const
{
	return imagPart;
}

const double real(const Complex& x)
{
	return x.real();
}

const double imag(const Complex& x)
{
	return x.imag();
}

const double norm(const Complex& x)
{
	//範數(norm) = 平方和開根號
	return sqrt(pow(x.real(), 2) + pow(x.imag(), 2));
}

//判斷兩複數是否相等
const bool operator ==(const Complex& x, const Complex& y)
{
	return((x.real() == y.real()) && (x.imag() == y.imag()));
}

//兩複數相加
const Complex operator +(const Complex& x, const Complex& y)
{
	double newRealPart = x.real() + y.real();
	double newImagPart = x.imag() + y.imag();
	return Complex(newRealPart, newImagPart);
}

//兩複數相減
const Complex operator -(const Complex& x, const Complex& y)
{
	double newRealPart = x.real() - y.real();
	double newImagPart = x.imag() - y.imag();
	return Complex(newRealPart, newImagPart);
}

//兩複數相乘
const Complex operator *(const Complex& x, const Complex& y)
{
	double newRealPart = x.real()*y.real() - x.imag()*y.imag();
	double newImagPart = x.real()*y.imag() + x.imag()*y.real();
	return Complex(newRealPart, newImagPart);
}

//兩複數相除
const Complex operator /(const Complex& x, const Complex& y)
{
	double newRealPart = (x.real()*y.real() + x.imag()*y.imag()) / (pow(y.real(), 2) + pow(y.imag(), 2));
	double newImagPart = (x.imag()*y.real() - x.real()*y.imag()) / (pow(y.real(), 2) + pow(y.imag(), 2));
	return Complex(newRealPart, newImagPart);
}

//輸出複數
ostream& operator <<(ostream& outputStream, const Complex& x)
{
	outputStream << x.real() << " + " << x.imag() << "*i" << endl;
	return outputStream;
}

//輸入複數
istream& operator >>(istream& inputStream, Complex& x)
{
	inputStream >> x.realPart >> x.imagPart;
	return inputStream;
}

int main()
{
	// test constructors
	Complex x, y(3), z(-3.2, 2.1);
	cout << "x =  " << x << "y = " << y << "z = " << z << endl << endl;

	x = Complex(3, -4);

	cout << "testing members and support functions as well as"
		<< " output operator:\n"
		<< "complex number x = " << x << endl
		<< "real part: " << x.real() << endl
		<< "real part from friend real(x): " << real(x) << endl
		<< "imaginary part: " << x.imag() << endl
		<< "imaginary part from friend imag(x) : " << imag(x) << endl
		<< "norm: " << norm(x) << endl << endl;

	cout << "test operator ==:" << endl << endl;
	if (x == y)
		cout << "x = y" << endl << endl;
	else
		cout << "x!=y" << endl << endl;

	cout << "test complex arithmetic and output routines: \n\n";
	y = Complex(1, -1);
	cout << "x =  " << x << "y = " << y << "z = " << z << endl << endl;

	z = x + y;
	cout << "z = x + y = " << z << endl;

	z = x * y;
	cout << "z = x * y = " << z << endl;

	z = x - y;
	cout << "z = x - y = " << z << endl;

	z = x / y;
	cout << "z = x / y = " << z << endl << endl;

	//test of automatic conversion double -> complex by the constructor. 

	double d(2.0);
	cout << "d: " << d << "   x: " << x << endl;
	cout << "x+d: ";
	z = x + d;
	cout << z << endl;
	z = x - d;
	cout << "x-d: ";
	cout << z << endl;
	z = x * d;
	cout << "x*d: ";
	cout << z << endl;
	z = x / d;
	cout << "x/d: ";
	cout << z << endl;
	z = d + x;
	cout << "d+x: ";
	cout << z << endl;
	z = d - x;
	cout << "d-x: ";
	cout << z << endl;
	z = d * x;
	cout << "d*x: ";;
	cout << z << endl;
	z = d / x;
	cout << "d/x: ";;
	cout << z << endl;

	//test whether double/complex and complex/complex give same result:
	Complex two(2, 0);
	cout << "two/x: ";
	cout << two / x << endl;

	cout << "\nGetting data from standard input: \n";
	cin >> x >> y;
	cout << "data read is: x = " << x << " y = " << y << endl << endl;
	return 0;
}