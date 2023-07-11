#include<fstream>
#include<iostream>
#include<string>
using namespace std;
#include"HugeReal.h"
void HugeReal::assign(const HugeReal& h)
{
	this->size = h.size;
	this->Ds = new int[this->size];
	for (int di = 0; di < h.size; di++)
		this->Ds[di] = h.Ds[di];
	this->isNeg = h.isNeg;
	this->Rsize = h.Rsize;
	this->Rz = new int[this->Rsize];
	for (int di = 0; di < h.Rsize; di++)
		this->Rz[di] = h.Rz[di];
}
HugeReal::HugeReal()
{
	this->size = 0;
	this->Ds = nullptr;
	this->isNeg = false;
	this->Rsize = 0;
	this->Rz = nullptr;
}
HugeReal::HugeReal(int s, int rs)
{
	this->size = s;
	this->Ds = new int [s] {};
	this->Rsize = rs;
	this->Rz = new int [rs] {};
	this->isNeg = false;
}
void HugeReal::insert_at_end(int*& vs, int& size, int t)
{
	int* ha = new int [size + 1] {};
	for (int i = 0; i < size; i++)
		ha[i] = vs[i];
	ha[size] = t;
	delete[]vs;
	vs = ha;
	size++;
}
HugeReal::HugeReal(const HugeReal& h)
{
	assign(h);
}
void HugeReal::load_integer(ifstream& rdr)
{
	char sym;
	bool check = false;
	sym = rdr.peek();
	if (sym == '-')
	{
		this->isNeg = true;
		rdr.ignore();
	}
	else
	{
		this->isNeg = false;
	}
	string aline;
	getline(rdr, aline);
	for (int i = 0; i < aline.size(); i++)
	{
		if (aline[i] == 46)
		{
			this->size = i;
			check = true;
			break;
		}

	}
	if (check == false)
		this->size = aline.size();
	int de = aline.size(), e = this->size;
	this->Rsize = 0;
	this->Ds = new int[this->size];
	for (int di = 0; di < this->size; di++)
		this->Ds[this->size - di - 1] = aline[di] - '0';

	if (check == true)
	{
		this->Rsize = aline.size() - this->size - 1;
		int f = this->Rsize;
		this->Rz = new int[this->Rsize];
		for (int di = 0; di < this->Rsize; di++)
			this->Rz[this->Rsize - di - 1] = aline[this->size + di + 1] - '0';
	}
	this->trim();
}
HugeReal::HugeReal(ifstream& rdr)
{
	this->load_integer(rdr);
}
const HugeReal& HugeReal:: operator=(const HugeReal& h)
{
	if (this == &h)
		return *this;
	delete[] this->Ds;
	this->assign(h);
	return*this;
}
ostream& operator<<(ostream&, const HugeReal& h)
{
	cout << ((h.isNeg) ? "-" : "+");
	for (int i = 0; i < h.size; i++)
	{
		cout << h.Ds[h.size - 1 - i];
	}
	if (h.Rsize > 0)
	{
		cout << '.';
		for (int i = 0; i < h.Rsize; i++)
		{
			cout << h.Rz[h.Rsize - 1 - i];
		}
	}
	return cout;
}
const HugeReal HugeReal::add(const HugeReal& h)const
{
	int o = this->size;
	HugeReal R(this->size + 1, this->Rsize);
	int carry = 0;

	for (int i = 0; i < R.Rsize; i++)
	{
		if (i < h.Rsize)
		{
			R.Rz[i] = (Rz[i] + h.Rz[i] + carry) % 10;
			carry = (Rz[i] + h.Rz[i] + carry) / 10;
		}
		else
		{
			R.Rz[i] = (Rz[i] + carry) % 10;
			carry = (Rz[i] + carry) / 10;
		}

	}

	for (int i = 0; i < R.size; i++)
	{
		if (i < h.size)
		{
			R.Ds[i] = ((*this)[i] + h[i] + carry) % 10;
			carry = ((*this)[i] + h[i] + carry) / 10;
		}
		else if (i < size)
		{
			R.Ds[i] = ((*this)[i] + carry) % 10;
			carry = ((*this)[i] + carry) / 10;
		}
		else
		{
			R.Ds[i] = carry;
			carry = 0;
		}
	}
	R.trim();
	return R;
}
const HugeReal HugeReal::sub(const HugeReal& h)const
{
	HugeReal R(this->size + 1, this->Rsize);
	int carry = 0;
	for (int i = 0; i < R.Rsize; i++)
	{
		if (i < h.Rsize)
		{
			int ans = (this->Rz[i] - h.Rz[i] - carry) % 10;
			carry = (ans < 0) ? 1 : 0;
			ans = (ans < 0) ? ans + 10 : ans;
			R.Rz[i] = ans;
		}
		else if (i < Rsize)
		{
			int ans = (this->Rz[i] - carry) % 10;
			carry = (ans < 0) ? 1 : 0;
			ans = (ans < 0) ? ans + 10 : ans;
			R.Rz[i] = ans;
		}
	}
	for (int i = 0; i < R.size; i++)
	{
		if (i < h.size)
		{
			int ans = ((*this)[i] - h[i] - carry) % 10;
			carry = (ans < 0) ? 1 : 0;
			ans = (ans < 0) ? ans + 10 : ans;
			R.Ds[i] = ans;
		}
		else if (i < size)
		{
			int ans = ((*this)[i] - carry) % 10;
			carry = (ans < 0) ? 1 : 0;
			ans = (ans < 0) ? ans + 10 : ans;
			R.Ds[i] = ans;
		}
		else
			R.Ds[i] = carry, carry = 0;
	}

	R.trim();
	return R;
	/*HugeInteger R(this->size + 1, this->Rsize+1);
	HugeInteger temp(h);
	temp.isNeg = false;
	if (h.isNeg == false)
		temp.isNeg = true;
	R = *this + temp;
	R.trim();
	return R;*/
}
int& HugeReal:: operator[](int i)
{
	return this->Ds[i];
}
int HugeReal::operator[](int i)const
{
	if (i >= this->size)
		return 0;
	return this->Ds[i];
}
bool HugeReal::quantity_wise_lesser(const HugeReal& h)const
{
	if (this->size < h.size)
		return true;
	if (this->size > h.size)
		return false;
	for (int i = this->size - 1; i >= 0; i--)
	{
		if ((*this)[i] < h[i])
			return true;
		if ((*this)[i] > h[i])
			return false;
	}
	if (this->Rsize < h.Rsize)
		return true;
	if (this->Rsize > h.Rsize)
		return false;
	for (int i = this->Rsize - 1; i >= 0; i--)
	{
		if (this->Rz[i] < h.Rz[i])
			return true;
		if (this->Rz[i] > h.Rz[i])
			return false;
	}
	return false;
}
bool HugeReal::quantity_wise_greater(const HugeReal& h)const
{
	return h.quantity_wise_lesser(*this);
}
bool HugeReal::quantity_wise_equal(const HugeReal& h)const
{
	if (this->size != h.size)
		return false;
	for (int i = 0; i < this->size; i++)
		if ((*this)[i] != h[i])
			return false;
	return true;
}
bool HugeReal::quantity_wise_greater_or_equal(const HugeReal& h)const
{
	return ((*this).quantity_wise_equal(h) || (*this).quantity_wise_greater(h));
}
bool HugeReal::quantity_wise_lesser_or_equal(const HugeReal& h)const
{
	return ((*this).quantity_wise_equal(h) || (*this).quantity_wise_lesser(h));
}
bool HugeReal::quantity_wise_not_equal(const HugeReal& h)const
{
	return !(this->quantity_wise_equal(h));
}
const HugeReal HugeReal:: operator+(const HugeReal& h)const
{
	int ii = this->size;
	if (this->isNeg == h.isNeg)
	{
		if (this->quantity_wise_greater(h))
		{
			HugeReal R = add(h);
			R.isNeg = this->isNeg;
			R.trim();
			return R;
		}
		else
		{
			HugeReal R = h.add(*this);
			R.isNeg = h.isNeg;
			R.trim();
			return R;
		}
	}
	else
	{
		if (this->quantity_wise_greater(h))
		{
			HugeReal R = sub(h);
			R.isNeg = this->isNeg;
			R.trim();
			return R;
		}
		else
		{
			HugeReal R = h.sub(*this);
			R.isNeg = h.isNeg;
			R.trim();
			return R;
		}
	}
}
const HugeReal HugeReal::operator-()const
{
	HugeReal r = *this;
	r.isNeg = !(r.isNeg);
	return r;
}
const HugeReal HugeReal:: operator-(const HugeReal& h)const
{
	return (*this) + (-h);
}
bool HugeReal::operator>(const HugeReal& h)const
{
	if (this->isNeg != h.isNeg)
		return this->isNeg == true;
	else if (this->isNeg == true)
		return this->quantity_wise_greater(h);
	else
		return this->quantity_wise_lesser(h);
}
bool HugeReal::operator<(const HugeReal& h)const
{
	return h > (*this);
}
const HugeReal HugeReal::operator++()
{
	*this = *this + one();
	return *this;
}
bool HugeReal::operator==(const HugeReal& h)const
{
	if (this->isNeg != h.isNeg)
		return false;
	if (this->size != h.size)
		return false;
	for (int i = 0; i < this->size; i++)
		if ((*this)[i] != h[i])
			return false;
	return true;
}
bool HugeReal:: operator<=(const HugeReal& h) const
{
	if ((*this == h) || (*this > h))
		return true;
}
bool HugeReal:: operator>=(const HugeReal& h) const
{
	return (((*this) < h) || ((*this) == h));
}
const HugeReal HugeReal ::operator+=(const HugeReal& h)
{
	*this = *this + h;
	return *this;
}
const HugeReal HugeReal ::operator-=(const HugeReal& h)
{
	*this = *this - h;
	return *this;
}
//const HugeReal HugeReal::operator*(const HugeReal& h) const
//{
//	int ds1, ds2;
//	if (this->isNeg == h.isNeg)
//		ds1 = ds2 = 0;
//	else
//		ds1 = ds2 = 1;
//	HugeReal R(this->size + h.size + ds1, this->Rsize + h.Rsize + ds2);
//	for (int i = 0; i < this->size; i++)
//	{
//		int carry = 0;
//		for (int j = 0; j < h.size; j++)
//		{
//			int sum = this->Ds[i] * h.Ds[j] + R.Ds[i + j] + carry;
//			R.Ds[i + j] = sum % 10;
//			carry = sum / 10;
//		}
//		if (carry > 0)
//			R.Ds[i + h.size] += carry;
//	}
//	for (int i = 0; i < this->Rsize; i++)
//	{
//		int carry = 0;
//		for (int j = 0; j < h.Rsize; j++)
//		{
//			int sum = this->Rs[i] * h.Rs[j] + R.Rs[i + j] + carry;
//			R.Rs[i + j] = sum % 10;
//			carry = sum / 10;
//		}
//		if (carry > 0)
//			R.Rs[i + h.Rsize] += carry;
//	}
//	if (this->isNeg != h.isNeg)
//		R.isNeg = true;
//	R.trim();
//	return R;
//}

const HugeReal HugeReal ::operator*(const HugeReal& h)const
{
	HugeReal fake;
	fake.size = this->size + this->Rsize ;
	fake.Ds = new int[fake.size];
	for (int i = 0; i < this->size; i++)
		fake.Ds[i] = this->Ds[i];
	for (int i = 0; i < this->Rsize; i++)
		fake.Ds[this->size + i ] = this->Rz[i];
	HugeReal also;
	also.size = h.size + h.Rsize;
	also.Ds = new int[also.size];
	for (int i = 0; i < h.size; i++)
		also.Ds[i] = h.Ds[i];
	for (int i = 0; i < h.Rsize; i++)
		also.Ds[h.size + i ] = h.Rz[i];
	int deci =this->Rsize+ h.Rsize;

	HugeReal answer, r = fake, t = t.zero(), count = count.one();
	if (this->isNeg == true && h.isNeg == true || this->isNeg == false && h.isNeg == false)
		t.isNeg = false;
	else
		t.isNeg = true;
	for (HugeReal c = also; c < answer.zero(); c = c - count)
	{
		for (count = count.one(), r = fake; count + count <= c; r = r + r)
		{
			count = count + count;
		}
		t = t + r;
	}
	HugeReal nm(t.size - deci, deci);
	for (int i = deci; i < t.size; i++)
		nm.Ds[i - deci] = t.Ds[i];
	for (int i = 0; i < deci; i++)
		nm.Rz[i] = t.Ds[i];
	return nm;
}
const HugeReal HugeReal::operator*=(const HugeReal& h)
{
	*this = *this * h;
	return *this;
}
const HugeReal HugeReal::operator/(HugeReal& H) const {
	HugeReal r = *this, t = t.zero(), count = count.one(), B = H, c = c.zero();
	r.isNeg = false;
	B.isNeg = false;
	if (r > B)
	{
		return c;
	}
	if (H.isNeg == true)
	{
		H.isNeg = false;
		for (; r >= H; c += count, r -= B)
		{
			count = count.one();
			for (B = H; B + B <= r; B += B, count += count);
		}
		H.isNeg = true;
	}
	else
	{
		for (; r >= H; c += count, r -= B)
			for (B = H, count = count.one(); B + B <= r; B += B, count += count);
	}
	c.isNeg = (this->isNeg != H.isNeg);
	return c;
}

//const HugeInteger HugeInteger ::operator/(const HugeInteger& h)const
//{
//	HugeInteger answer, t = t.zero(), count = count.one(), quotient = quotient.zero(), c;
//	if (this->isNeg == true && h.isNeg == true || this->isNeg == false && h.isNeg == false)
//		t.isNeg = false;
//	else
//		t.isNeg = true;
//	if (*this < h)
//		quotient = quotient.one();
//	else
//		return 0;
//
//	for (c = *this; c < answer.zero(); c = c - count)
//	{
//		t = t.zero();
//		for (count = h; count + count <= c; count += count)
//		{
//			++t;
//		}
//		quotient = (quotient * t);
//	}
//
//	return quotient;
//}
void HugeReal::trim()
{
	int i = this->size - 1;
	int count = 0;
	while (Ds[i] == 0)
	{
		if (Ds[i] == 0)
		{
			for (int k = i; k < size; k++)
			{
				Ds[k] = Ds[k + 1];
			}
			count++;
		}
		i--;
	}
	this->size = size - count;
	int* h = new int[size];
	for (int tr = 0; tr < size; tr++)
		h[tr] = Ds[tr];
	this->Ds = new int[size];
	for (int i = 0; i < size; i++)
		Ds[i] = h[i];
	delete[]h;
}
HugeReal::~HugeReal()
{
	delete[]this->Ds;
}
