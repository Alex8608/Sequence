#pragma once
#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
namespace SEQUENCE
{
	const float EPSILON = 0.00001f;

	enum SequenceType
	{
		ARITHMETIC,
		GEOMETRIC,
	};

	class Sequence;
	using SequencePtr = std::shared_ptr<Sequence>;

	class Sequence
	{
	public:
		virtual float progression_n(int n) const = 0;
		virtual float sum_of_first_n_progression(int n) const = 0;
		virtual SequencePtr clone() const = 0;
		virtual bool equals(SequencePtr other) const = 0;
		virtual ~Sequence() = default;
		virtual void print(std::ostream& stream) const = 0;
	protected:
		Sequence() = default;
		Sequence(const Sequence&) = default;
		Sequence& operator=(const Sequence&) = default;
	};
	//bool operator==(const Sequence& lhs, const Sequence& rhs);
	//bool operator!=(const Sequence& lhs, const Sequence& rhs);

	class AriSequence : public Sequence {
		float first_n;
		float d_q;
	public:
		AriSequence(float first_n, float d_q);
		float get_first_n() const;
		float get_d_q() const;
		float progression_n(int n) const override;
		float sum_of_first_n_progression(int n) const override;
		SequencePtr clone() const override;
		bool equals(SequencePtr other) const override;
		void print(std::ostream& stream) const override;
	};

	class GeoSequence : public Sequence {
		float first_n;
		float d_q;
	public:
		GeoSequence(float first_n, float d_q);
		float get_first_n() const;
		float get_d_q() const;
		float progression_n(int n) const override;
		float sum_of_first_n_progression(int n) const override;
		SequencePtr clone() const override;
		bool equals(SequencePtr other) const override;
		void print(std::ostream& stream) const override;
	};

	class SequenceList
	{
		std::vector<SequencePtr> _sequences;
	public:
		SequenceList() = default;
		SequenceList(const SequenceList& list);
		int size() const;
		void swap(SequenceList& list) noexcept;
		SequenceList& operator=(const SequenceList& list);
		SequencePtr operator[](int index) const;
		//Sequence& operator[](int index);
		void add(SequencePtr item);
		void insert_index(SequencePtr item, int index);
		void del_index(int index);
	};

	int search(const SequenceList& list, const int n);
}