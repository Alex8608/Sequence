#include <sequence/sequence.h>
#include <cmath>
#include <stdexcept>
using namespace SEQUENCE;
using namespace std;
Sequence::Sequence() : type(ARITHMETIC), first_n(0), d_q(0) {}
Sequence::Sequence(SequenceType type, float first_n, float d_q) :type(type), first_n(first_n), d_q(d_q) {}
SequenceType Sequence::get_type() const{
	return type;
}
float Sequence::get_first_n() const {
	return first_n;
}
float Sequence::get_d_q() const {
	return d_q;
}
Sequence Sequence::create_ARITHMETIC(float first_n, float d_q)
{
	return Sequence(ARITHMETIC, first_n, d_q);
}
Sequence Sequence::create_GEOMETRIC(float first_n, float d_q)
{
	return Sequence(GEOMETRIC, first_n, d_q);
}
float Sequence::progression_n(int n) const
{
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
	switch (type)
	{
	case ARITHMETIC:
		return  (2 * first_n + d_q * (n - 1)) * n / 2;
	case GEOMETRIC:
		return first_n * (pow(d_q, n) - 1) / (d_q - 1);
	}
}
void Sequence::print() const
{
	switch (type)
	{
	case ARITHMETIC:
		printf("ARITHMETIC %f %f\n", first_n, d_q);
		break;
	case GEOMETRIC:
		printf("GEOMETRIC %f %f\n", first_n, d_q);
		break;
	}
}