#include <stdexcept>
#include <sequence/sequence.h>

using namespace SEQUENCE;
using namespace std;

SequenceList::SequenceList(const SequenceList& list) {
    const auto n = list.size();
    _sequences.reserve(n);
    for (int i = 0; i < n; ++i) {
        _sequences.push_back(list[i]->clone());
    }
}

int SequenceList::size() const {
    return static_cast<int>(_sequences.size());
}

void SequenceList::swap(SequenceList& list) noexcept {
    std::swap(this->_sequences, list._sequences);
}

SequenceList& SequenceList::operator=(const SequenceList& list) {
    SequenceList copy(list);
    copy.swap(*this);
    return *this;
}

SequencePtr SequenceList::operator[](const int index) const {
    if (index < 0 || this->size() <= index) {
        throw runtime_error("[SequenceList::operator[]] Index out of range.");
    }

    return _sequences.at(index);
}

void SequenceList::add(SequencePtr item) {
    _sequences.push_back(item);
}

void SequenceList::insert_index(SequencePtr const item, int index) {
    _sequences.insert(_sequences.begin() + index, item);
}

void SequenceList::del_index(int index) {
    _sequences.erase(_sequences.begin()+index);
}

int SEQUENCE::search(const SequenceList& sequences, const int n) {
    if (n < 1) {
        throw runtime_error("n < 1");
    }
    int max_i = -1;
    for (int i = 0; i < sequences.size(); i++)
    {
        int max_sum;
        if (max_i != -1) {
            max_sum = sequences[max_i]->sum_of_first_n_progression(n);
        }
        else max_sum = sequences[0]->sum_of_first_n_progression(n);
        int current_sum = sequences[i]->sum_of_first_n_progression(n);
        if (max_sum <= current_sum)
        {
            max_i = i;
        }
    }
    return max_i;
}