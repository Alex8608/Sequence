#include <sequence/sequence.h>
#include <cmath>
#include <cassert>
#include <stdexcept>

using namespace SEQUENCE;
using namespace std;

AriSequence::AriSequence(float first_n, float d_q) : first_n(first_n), d_q(d_q) {}

float AriSequence::get_first_n() const {
	return first_n;
}

float AriSequence::get_d_q() const {
	return d_q;
}

float AriSequence::progression_n(int n) const
{
	if (n < 1) {
		throw runtime_error("n < 1");
	}
	return  first_n + d_q * (n - 1);
	//return first_n * pow(d_q, n - 1);
}

float AriSequence::sum_of_first_n_progression(int n) const
{
	if (n < 1) {
		throw runtime_error("n < 1");
	}
	return  (2 * first_n + d_q * (n - 1)) * n / 2;
	//return first_n * (pow(d_q, n) - 1) / (d_q - 1);
}

SequencePtr AriSequence::clone() const {
	return make_shared<AriSequence>(first_n, d_q);
}

//Sequence& Sequence::operator=(const Sequence& copy)
//{
//	type = copy.get_type();
//	first_n = copy.get_first_n();
//	d_q = copy.get_d_q();
//	return *this;
//}

//bool SEQUENCE::operator==(const Sequence& lhs, const Sequence& rhs) {
//	return
//		lhs.get_type() == rhs.get_type() &&
//		abs(lhs.get_first_n() - rhs.get_first_n()) < EPSILON &&
//		abs(lhs.get_d_q() - rhs.get_d_q()) < EPSILON;
//}
//
//bool SEQUENCE::operator!=(const Sequence& lhs, const Sequence& rhs) {
//	return !(lhs == rhs);
//}

bool AriSequence::equals(SequencePtr other) const {
	const auto downcasted_other = dynamic_pointer_cast<AriSequence>(other);
	if (downcasted_other == nullptr) {
		return false;
	}

	return (first_n == downcasted_other->first_n) && (d_q == downcasted_other->d_q);
}

void AriSequence::print(ostream& out) const
{
	out << "(ARITHMETIC, " << get_first_n() << ", " << get_d_q() << ")" << endl;
}

//std::ostream& SEQUENCE::operator<<(std::ostream& out, const Sequence& item)
//{
//	switch (item.get_type())
//	{
//	case ARITHMETIC:
//		out << "(ARITHMETIC, " << item.get_first_n() << ", " << item.get_d_q() << ")" << endl;
//		break;
//	case GEOMETRIC:
//		out << "(GEOMETRIC, " << item.get_first_n() << ", " << item.get_d_q() << ")" << endl;
//		break;
//	}
//	return out;
//}

GeoSequence::GeoSequence(float first_n, float d_q) : first_n(first_n), d_q(d_q) {}

float GeoSequence::get_first_n() const {
	return first_n;
}

float GeoSequence::get_d_q() const {
	return d_q;
}

float GeoSequence::progression_n(int n) const
{
	if (n < 1) {
		throw runtime_error("n < 1");
	}
	return first_n * pow(d_q, n - 1);
}

float GeoSequence::sum_of_first_n_progression(int n) const
{
	if (n < 1) {
		throw runtime_error("n < 1");
	}
	return first_n * (pow(d_q, n) - 1) / (d_q - 1);
}

SequencePtr GeoSequence::clone() const {
	return make_shared<GeoSequence>(first_n, d_q);
}

bool GeoSequence::equals(SequencePtr other) const {
	const auto downcasted_other = dynamic_pointer_cast<GeoSequence>(other);
	if (downcasted_other == nullptr) {
		return false;
	}

	return (first_n == downcasted_other->first_n) && (d_q == downcasted_other->d_q);
}

void GeoSequence::print(ostream& out) const
{
	out << "(GEOMETRIC, " << get_first_n() << ", " << get_d_q() << ")" << endl;
}