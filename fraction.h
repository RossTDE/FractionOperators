#pragma once
using namespace std; 

class fraction {
	int num, denum;
public:
	fraction(int a, int b) : num(a), denum(b) { //конструктор при создании: первое - числитель, второе - знаменатель
		if (denum == 0) {
			throw "Astanavis";
		}
		this->reduction();
	}

	void set_value(int a, int b) {
		num = a;
		denum = b;
	}

	void get_value();
	void reduction();
	fraction sum(fraction);
	fraction differ(fraction);
	fraction prod(fraction);
	fraction quot(fraction);

	fraction operator + (const fraction& fr);
    fraction operator - (const fraction& fr);
	fraction operator * (const fraction& fr);
	fraction operator / (const fraction& fr);
	bool operator > (const fraction& fr) const;
	bool operator < (const fraction& fr) const;
	bool operator == (const fraction& fr) const;
	fraction operator ++();
	fraction operator --();

	friend ostream& operator << (ostream& stream, const fraction& fr) {
		stream << fr.num << "/" << fr.denum;
		return stream;
	}

	friend istream& operator >> (istream& stream, fraction& fr) {
		stream >> fr.num;
		stream >> fr.denum;
		fr.reduction();
		return stream;
	}
};


// - - - - - - - - - –ј«ƒ≈Ћ»“≈Ћ№ - - - - - - - - - -


void fraction::get_value() {
	cout << num << "/" << denum << endl;
}

void fraction::reduction() { //сокращение дроби
	for (int i = 9; i > 1; i--) {
		if (this->num % i == 0 && this->denum % i == 0) {
			this->num = this->num / i;
			this->denum = this->denum / i;
		}
	}
	if (this->num < 0 && this->denum < 0) {
		this->num *= -1;
		this->denum *= -1;
	}
}

fraction fraction::sum(fraction n) { //сумма
	int nn, dn;
	if (denum == n.denum) { //если один знаменатель
		nn = num + n.num;
		dn = denum;
	}
	else { //если разные(приведение к общему)
		nn = n.denum * denum;
		dn = n.num * denum + num * n.denum;
	}
	return fraction(nn, dn);
}

fraction fraction::differ(fraction n) {
	int nn, dn;
	if (denum == n.denum) { //если один знаменатель
		nn = num - n.num;
		dn = denum;
	}
	else { //если разные(приведение к общему)
		dn = n.denum * denum;
		nn = n.num * denum - num * n.denum;
	}
	return fraction(nn, dn);
}

fraction fraction::prod(fraction n) {
	int nn, dn;
	nn = num * n.num; //умножение числителей
	dn = denum * n.denum; //умножение знаменателей

	return fraction(nn, dn);
}

fraction fraction::quot(fraction n)
{
	int nn, dn;
	nn = num * n.denum; //умножение числител€ на заменатель
	dn = denum * n.num; //умножение знаменател€ на числитель

	return fraction(nn, dn);
}

fraction fraction::operator + (const fraction& fr)
{
	fraction a = this->sum(fr);
	return fraction(a);
}

fraction fraction::operator - (const fraction& fr)
{
	fraction a = this->differ(fr);
	return fraction(a);
}

fraction fraction::operator * (const fraction& fr)
{
	fraction a = this->prod(fr);
	return fraction(a);
}

fraction fraction::operator / (const fraction& fr) 
{
	fraction a = this->quot(fr);
	return fraction(a);
}

bool fraction::operator > (const fraction& fr) const
{ 
	bool a = false;
	if (fr.denum*this->num > this->denum*fr.num) {
		a = true;
	}
	return a;
}

bool fraction::operator < (const fraction& fr) const
{
	bool a = false;
	if (fr.denum * this->num < this->denum * fr.num) {
		a = true;
	}
	return a;
}

bool fraction::operator == (const fraction& fr) const
{
	bool a = false;
	if (fr.denum * this->num == this->denum * fr.num) {
		a = true;
	}
	return a;
}

fraction fraction::operator ++() {
	fraction one(1, 1);
	one = this->sum(one);

	return one;
}

fraction fraction::operator --() {
	fraction one(1, 1);
	one = this->sum(one);

	return one;
}

