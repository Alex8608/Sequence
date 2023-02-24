#include <sequence/sequence.h>
#include <cmath>
Sequence::Sequence(SequenceType type, float first_n, float d_q)
{
	this->type = type;
	this->first_n = first_n;
	this->d_q = d_q;
}
float Sequence::progression_n(int n)
{
	switch (type)
	{
	case ARITHMETIC:
		return  first_n + d_q * (n - 1);
	case GEOMETRIC:
		return first_n * pow(d_q, n - 1);
	}
}