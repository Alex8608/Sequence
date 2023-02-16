#pragma once

enum SequenceType
{
	ARITHMETIC,
	GEOMETRIC,
};
class Sequence
{
	SequenceType type;
	int first_n;
	int d_q;
	int n;
public:
	Sequence(SequenceType type, int first_n, int d_q);
	int progression_n(int n);
};