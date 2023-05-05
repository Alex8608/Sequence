#pragma once

namespace SEQUENCE
{
	const float EPSILON = 0.00001f;

	enum SequenceType
	{
		ARITHMETIC,
		GEOMETRIC,
	};

	class Sequence;
	using SequencePtr = Sequence*;

	class Sequence
	{
		SequenceType type;
		float first_n;
		float d_q;
		Sequence(SequenceType type, float first_n, float d_q);
	public:
		
		SequenceType get_type() const;
		float get_first_n() const;
		float get_d_q() const;
		static SequencePtr create_ARITHMETIC(float first_n, float d_q);
		static SequencePtr create_GEOMETRIC(float first_n, float d_q);
		float progression_n(int n) const;
		float sum_of_first_n_progression(int n) const;
		SequencePtr clone() const;
		void print() const;
		Sequence& operator=(const Sequence& copy);
	};

	bool operator==(const Sequence& lhs, const Sequence& rhs);
	bool operator!=(const Sequence& lhs, const Sequence& rhs);

	class SequenceList
	{
		SequencePtr* _sequences;
		size_t _size;
	public:
		SequenceList();
		SequenceList(const SequenceList& list);
		int size() const;
		void swap(SequenceList& list) noexcept;
		SequenceList& operator=(const SequenceList& list);
		SequencePtr operator[](int index) const;
		//Sequence& operator[](int index);
		void add(SequencePtr item);
		void insert_index(SequencePtr item, int index);
		void del_index(int index);
		~SequenceList();
	};

	int search(const SequenceList& list, const int n);
}