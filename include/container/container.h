#pragma once
#include <sequence/sequence.h>
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
    void clear();
    int search(int n);
};