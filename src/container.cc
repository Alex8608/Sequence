#include <cstdio>
#include <stdexcept>
#include <sequence/sequence.h>

using namespace SEQUENCE;
using namespace std;

SequenceList::SequenceList(): _size(0) {}

int SequenceList::size() const {
    return _size;
}

Sequence SequenceList::operator[](int index) const{
    if (index < 0 || _size <= index) {
        throw runtime_error("Index out of range.");
    }
        
    return _data[index];
}
    
Sequence& SequenceList::operator[](int index) {
    if (index < 0 || _size <= index) {
        throw runtime_error("Index out of range.");
    }
        
    return _data[index];
}
    
void SequenceList::add(const Sequence item) {
    if (_size == CAPACITY) {
        throw runtime_error("Full capacity reached.");
    }

    _data[_size] = item;
    ++_size;
}

void SequenceList::add_index(Sequence item, int index) {
    if (_size == CAPACITY) {
        throw runtime_error("Full capacity reached.");
    }
    if (index < 0 || _size <= index) {
        throw runtime_error("Index out of range.");
    }
    int counter = 0;
    while (_size - index - counter > 0)
    {
        _data[_size - counter] = _data[_size - 1 - counter];
        ++counter;
    }
    _data[index] = item;
    ++_size;
}

void SequenceList::del_index(int index) {
    if (_size == 0) {
        throw runtime_error("SequenceList is empty");
    }
    if (index < 0 || _size <= index) {
        throw runtime_error("Index out of range.");
    }
    int counter = 0;
    while (_size - index - 1 - counter > 0)
    {
        _data[index + counter] = _data[index + 1 + counter];
        ++counter;
    }
    --_size;
}

void SequenceList::clear() {
    _size = 0;
}

int SequenceList::search(int n) const{
    if (n < 1) {
        throw runtime_error("n < 1");
    }
    int max_i = -1;
    for (int i = 0; i < _size; i++)
    {
        int max_sum;
        if (max_i != -1) {
            max_sum = _data[max_i].sum_of_first_n_progression(n);
        }
        else max_sum = _data[0].sum_of_first_n_progression(n);
        int current_sum = _data[i].sum_of_first_n_progression(n);
        if (max_sum <= current_sum)
        {
            max_i = i;
        }
    }
    return max_i;
}