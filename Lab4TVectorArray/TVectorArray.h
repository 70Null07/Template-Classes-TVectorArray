#include "Config.h"
#include "BaseException.h"

template <int ArrayLength, typename T>
class TVectorArray
{
public:
	vector <T> SomeVec;
	TVectorArray()
	{
		SomeVec.resize(ArrayLength);
		for (int i = 0; i < ArrayLength; i++)
		{
			SomeVec[i] = GenerateRandomValues();
		}
	}
	TVectorArray(const TVectorArray& obj)
	{
		SomeVec = obj.SomeVec;
	}
	void SetRandomValue(int& i)
	{
		SomeVec[i] = GenerateRandomValues();
	}
	double GenerateRandomValues()
	{
		random_device rd;   // non-deterministic generator
		mt19937 gen(rd());
		uniform_int_distribution<int> dist(0, 100);
		double temp = dist(gen);
		return temp;
	}
	void _sort()
	{
		for (int i = 0; i < SomeVec.size()-1; i++)
		{
			if (SomeVec[i] > SomeVec[i+1])
			{
				swap(SomeVec[i], SomeVec[i+1]);
				i = 0;
			}
		}
	}
	int _count_average() const
	{
		double temp = 0;
		int count = 0;
		for (int i = 0; i < SomeVec.size(); i++)
		{
			temp += SomeVec[i];
		}
		temp = temp / SomeVec.size();
		for (int i = 0; i < SomeVec.size(); i++)
		{
			if (temp < SomeVec[i]) count++;
		}
		return count;
	}
	istream& scan(istream& stream)
	{
		SomeVec.resize(ArrayLength);
		for (int i = 0; i < SomeVec.size(); i++)
		{
		block1:
			try
			{
				double t;
				stream >> t;
				if (t < 0)
					throw BellowZero();
				SomeVec[i] = t;
			}
			catch (BellowZero e)
			{
				cout << "Повторите ввод: " << endl;
				ofstream err_out;
				err_out.open(debug, ios::app);
				err_out << "[" << __DATE__ << " " << __TIME__ << "] " << e.what() << endl;
				err_out.close();
				goto block1;
			}
		}
		return stream;
	}
	ostream& print(ostream& stream)
	{
		stream << SomeVec.size() << endl;
		for (int i = 0; i < SomeVec.size(); i++) {
			stream << SomeVec[i] << endl;
		}
		return stream;
	}
};

class T2DVector 
{
public:
	vector <double> SomeVec;
	T2DVector();
	T2DVector(const T2DVector& obj);

	int LengthVec() const;

	T2DVector& operator = (double num);
	T2DVector& operator = (const T2DVector& obj);

	bool operator > (const T2DVector& obj) const;
	bool operator < (const T2DVector& obj) const
	{
		return !(*this > obj);
	}

	ostream& print(ostream& stream) const;

	friend bool operator > (double& i, T2DVector const& obj);
	friend bool operator < (double& i, T2DVector const& obj);

	friend ostream& operator << (ostream& stream, T2DVector const& obj);
	friend istream& operator >> (istream& stream, T2DVector& obj)
	{
		cout << "Input Bx, By, Ex, Ey: " << endl;
		stream >> obj.SomeVec[0] >> obj.SomeVec[1] >> obj.SomeVec[2] >> obj.SomeVec[3];
		return stream;
	}

	friend double operator += (double& i, T2DVector const& obj);
};

class T3DVector
{
public:
	vector <double> SomeVec;
	T3DVector();
	T3DVector(const T3DVector& obj);

	int LengthVec() const;

	T3DVector& operator = (double num);
	T3DVector& operator = (const T3DVector& obj);

	bool operator > (const T3DVector& obj) const;
	bool operator < (const T3DVector& obj) const;

	ostream& print(ostream& stream) const;

	friend ostream& operator << (ostream& stream, T3DVector const& obj);
	friend istream& operator >> (istream& stream, T3DVector& obj)
	{
		cout << "Input Bx, By, Bz, Ex, Ey, Ez: " << endl;
		stream >> obj.SomeVec[0] >> obj.SomeVec[1] >> obj.SomeVec[2] >> obj.SomeVec[3] >> obj.SomeVec[4] >> obj.SomeVec[5];
		return stream;
	}
	friend double operator += (double& i, T3DVector const& obj);
	friend bool operator > (double& i, T3DVector const& obj);
	friend bool operator < (double& i, T3DVector const& obj);
};
