#include <sequence/sequence.h>
#include <cmath>
#include <stdexcept>
#include <iostream>

using namespace SEQUENCE;
using namespace std;

Sequence::Sequence(SequenceType type, float first_n, float d_q) :type(type), first_n(first_n), d_q(d_q) {}

SequenceType Sequence::get_type() const {
	return type;
}

float Sequence::get_first_n() const {
	return first_n;
}

float Sequence::get_d_q() const {
	return d_q;
}

SequencePtr Sequence::create_ARITHMETIC(const float first_n, const float d_q)
{
	return new Sequence(ARITHMETIC, first_n, d_q);
}

SequencePtr Sequence::create_GEOMETRIC(const float first_n, const float d_q)
{
	return new Sequence(GEOMETRIC, first_n, d_q);
}

float Sequence::progression_n(int n) const
{
	if (n < 1) {
		throw runtime_error("n < 1");
	}
	switch (type)
	{
	case ARITHMETIC:
		return  first_n + d_q * (n - 1);
	case GEOMETRIC:
		return first_n * pow(d_q, n - 1);
	}
}

float Sequence::sum_of_first_n_progression(int n) const
{
	if (n < 1) {
		throw runtime_error("n < 1");
	}
	switch (type)
	{
	case ARITHMETIC:
		return  (2 * first_n + d_q * (n - 1)) * n / 2;
	case GEOMETRIC:
		return first_n * (pow(d_q, n) - 1) / (d_q - 1);
	}
}

SequencePtr Sequence::clone() const {
	return new Sequence(type, first_n, d_q);
}

Sequence& Sequence::operator=(const Sequence& copy)
{
	type = copy.get_type();
	first_n = copy.get_first_n();
	d_q = copy.get_d_q();
	return *this;
}

bool SEQUENCE::operator==(const Sequence& lhs, const Sequence& rhs) {
	return
		lhs.get_type() == rhs.get_type() &&
		abs(lhs.get_first_n() - rhs.get_first_n()) < EPSILON &&
		abs(lhs.get_d_q() - rhs.get_d_q()) < EPSILON;
}

bool SEQUENCE::operator!=(const Sequence& lhs, const Sequence& rhs) {
	return !(lhs == rhs);
}

void Sequence::print() const
{
	switch (type)
	{
	case ARITHMETIC:
		cout << "(ARITHMETIC, " << first_n << ", " << d_q << ")" << endl;
		break;
	case GEOMETRIC:
		cout << "(GEOMETRIC, " << first_n << ", " << d_q << ")" << endl;
		break;
	}
}

std::ostream& SEQUENCE::operator<<(std::ostream& out, const Sequence& item)
{
	switch (item.get_type())
	{
	case ARITHMETIC:
		out << "(ARITHMETIC, " << item.get_first_n() << ", " << item.get_d_q() << ")" << endl;
		break;
	case GEOMETRIC:
		out << "(GEOMETRIC, " << item.get_first_n() << ", " << item.get_d_q() << ")" << endl;
		break;
	}
	return out;
}
