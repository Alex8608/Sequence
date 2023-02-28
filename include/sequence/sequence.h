#pragma once

enum SequenceType
{
	ARITHMETIC,
	GEOMETRIC,
};
class Sequence
{
	SequenceType type;
	float first_n;
	float d_q;
public:
	Sequence();
	Sequence(SequenceType type, float first_n, float d_q);
	float progression_n(int n);
	float sum_of_first_n_progression(int n);
	void print();
};