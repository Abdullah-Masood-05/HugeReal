//#include<iostream>
#include<fstream>
#pragma once
class HugeReal


{
	int* Ds;
	int size;
	bool isNeg;
	int* Rz;
	int Rsize;
	void assign(const HugeReal&);
	static void insert_at_end(int*& vs, int& size, int t);
	const HugeReal add(const HugeReal& h)const;
	const HugeReal sub(const HugeReal& h)const;
	bool quantity_wise_lesser(const HugeReal& h)const;
	bool quantity_wise_greater(const HugeReal& h)const;
	bool quantity_wise_equal(const HugeReal& h)const;
	bool quantity_wise_greater_or_equal(const HugeReal& h)const;
	bool quantity_wise_lesser_or_equal(const HugeReal& h)const;
	bool quantity_wise_not_equal(const HugeReal& h)const;
	static HugeReal one()
	{
		HugeReal R(1, 0);
		R.Ds[0] = 1;
		R.Rz[0] = 1;
		return R;
	}
	static HugeReal zero()
	{
		HugeReal R(1, 1);
		R.Ds[0] = 0;
		R.Rz[0] = 0;
		return R;
	}
public:
	HugeReal();
	HugeReal(int s, int);
	HugeReal(const HugeReal&);
	void load_integer(ifstream& rdr);
	HugeReal(ifstream& rdr);
	const HugeReal operator+(const HugeReal&)const;
	const HugeReal operator-()const;
	const HugeReal operator-(const HugeReal& h)const;
	const HugeReal operator*(const HugeReal& h)const;
	const HugeReal operator*=(const HugeReal& h);
	const HugeReal operator/(HugeReal&)const;
	bool operator>(const HugeReal&)const;
	bool operator<(const HugeReal&)const;
	bool operator==(const HugeReal&)const;
	bool operator>=(const HugeReal& h) const;
	bool operator<=(const HugeReal& h) const;
	const HugeReal operator+=(const HugeReal& h);
	const HugeReal operator-=(const HugeReal& h);
	const HugeReal operator++();
	void trim();
	int& operator[](int i);
	int operator[](int i)const;
	const HugeReal& operator=(const HugeReal&);
	friend ostream& operator<<(ostream&, const HugeReal&);
	~HugeReal();
};

