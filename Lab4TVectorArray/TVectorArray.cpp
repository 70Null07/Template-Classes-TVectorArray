#include "TVectorArray.h"
#include "Config.h"

T2DVector::T2DVector()
{
	random_device rd;   // non-deterministic generator
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 100);
	SomeVec.resize(4);
	for (int i = 0; i < 4; i++)
	{
		SomeVec[i] = (double)dist(gen);
	}
}

T2DVector::T2DVector(const T2DVector& obj)
{
	SomeVec = obj.SomeVec;
}

int T2DVector::LengthVec() const
{
	return sqrt(pow(SomeVec[0] + SomeVec[2], 2) + pow(SomeVec[1] + SomeVec[3], 2));
}

T2DVector&  T2DVector::operator = (double num)
{
	srand(num);
	for (int i = 0; i < 4; i++) {
		SomeVec[i] = (rand()*1000)/10000.;
	}
	return (*this);
}
T2DVector& T2DVector::operator = (const T2DVector& obj)
{
	for (int i = 0; i < 4; i++)
	{
		SomeVec[i] = obj.SomeVec[i];
	}
	return (*this);
}

bool T2DVector::operator > (const T2DVector& obj) const
{
	if (LengthVec() > obj.LengthVec())
	{
		return true;
	}
	else
	{ 
		return false;
	}
}

ostream& T2DVector::print(ostream& stream) const
{
	stream << "\n B(x): " << SomeVec[0] << " B(y): " << SomeVec[1] << " E(x): " << SomeVec[2] << " E(y): " << SomeVec[3] << endl;
	return stream;
}

bool operator > (double& i, T2DVector const& obj)
{
	if (obj.LengthVec() > i)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator < (double& i, T2DVector const& obj)
{
	return !(i > obj);
}

ostream& operator << (ostream& stream, T2DVector const& obj)
{
	return obj.print(stream);
}

double operator += (double& i, T2DVector const& obj)
{
	i = i + obj.LengthVec();
	return i + obj.LengthVec();
}

T3DVector::T3DVector()
{
	random_device rd;   // non-deterministic generator
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, 100);
	SomeVec.resize(6);
	for (int i = 0; i < 6; i++)
	{
		SomeVec[i] = (double)dist(gen);
	}
}
T3DVector::T3DVector(const T3DVector& obj)
{
	SomeVec = obj.SomeVec;
}
T3DVector& T3DVector::operator = (double num)
{
	srand(num);
	for (int i = 0; i < 6; i++) {
		SomeVec[i] = (rand()*1000)/10000.;
	}
	return (*this);
}

int T3DVector::LengthVec() const
{
	return sqrt(pow(SomeVec[0] + SomeVec[3], 2) + pow(SomeVec[1] + SomeVec[4], 2) + pow(SomeVec[2] + SomeVec[5], 2));
}

T3DVector& T3DVector::operator = (const T3DVector& obj)
{
	for (int i = 0; i < 6; i++)
	{
		SomeVec[i] = obj.SomeVec[i];
	}
	return (*this);
}

bool T3DVector::operator > (const T3DVector& obj) const
{
	if (LengthVec() > obj.LengthVec())
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool T3DVector::operator < (const T3DVector& obj) const
{
	return !(*this > obj);
}

ostream& T3DVector::print(ostream& stream) const
{
	stream << "\n B(x): " << SomeVec[0] << " B(y): " << SomeVec[1] << " B(z): " << SomeVec[2] << " E(x): " << SomeVec[3] << " E(y): " << SomeVec[4] << " E(z): " << SomeVec[5] << endl;
	return stream;
}

ostream& operator << (ostream& stream, T3DVector const& obj)
{
	return obj.print(stream);
}

double operator += (double& i, T3DVector const& obj)
{
	i = i + obj.LengthVec();
	return i + obj.LengthVec();
}

bool operator > (double& i, T3DVector const& obj)
{
	if (obj.LengthVec() > i)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator < (double& i, T3DVector const& obj)
{
	return !(i > obj);
}