#pragma once
namespace SEQUENCE
{
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
		Sequence(SequenceType type, float first_n, float d_q);
	public:
		Sequence();
		SequenceType get_type() const;
		float get_first_n() const;
		float get_d_q() const;
		static Sequence create_ARITHMETIC(float first_n, float d_q);
		static Sequence	create_GEOMETRIC(float first_n, float d_q);
		float progression_n(int n) const;
		float sum_of_first_n_progression(int n) const;
		void print() const;
	};
	class SequenceList
	{
		static const int CAPACITY = 10;
		Sequence _data[CAPACITY];
		int _size;
	public:
		SequenceList();
		int size() const;
		Sequence operator[](int index) const;
		Sequence& operator[](int index);
		void add(Sequence item);
		void add_index(Sequence item, int index);
		void del_index(int index);
		void clear();
		int search(int n) const;
	};
}