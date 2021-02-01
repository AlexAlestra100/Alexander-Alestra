/*
Alexander Alestra
CISP 400 - TTH 10:30 am
Project 6/7
November 12, 2019  Due December 12th!
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#ifndef RUBBER_ARRAY_H_ABA
#define RUBBER_ARRAY_H_ABA

using namespace std;
template <class T>

class RubberArray
{
    T* _array;
    unsigned _alloc;
    unsigned _items;
    int _Vindex;

public:

    RubberArray (int Vi = 0);

    RubberArray (const T* a, unsigned s, int Vindex = 0);

    RubberArray (const RubberArray&);

    ~RubberArray ();

    RubberArray<T>& operator= (const RubberArray<T>&);

    template <class OS>
    friend ostream& operator<< (ostream&, const RubberArray<OS>&);

    template <class OS>
    friend ostream& operator<< (ostream&, const RubberArray<OS>*);

    T& operator[] (int Vindex);

    const T& operator[] (int Vindex) const;

    RubberArray operator() (int Vfirst, int Vlast) const;

    void operator+= (const T&);

    void operator+= (const RubberArray&);

    unsigned Lenth () const {return _items;}

    void Insert (int Vindex, const T&);

    void Insert (const T&);

    void Delete ();

    void Delete (int Vindex);

    void Delete (int Vfirst, int Vlast);

    void write (ofstream&) const;

    void read (ifstream&);
};

template <class T>
RubberArray<T>::RubberArray (int Vi)
{
    _array = NULL;
    _alloc = 0;
    _items = 0;
    _Vindex = Vi;
}

template <class T>
RubberArray<T>::RubberArray (const T* a, unsigned s, int Vi)
{
    _array = NULL;
    _alloc = 0;
    _items = 0;
    _Vindex = Vi;

    for (unsigned i = 0; i < s; ++i)
        operator+=(a[i]);
}

template <class T>
RubberArray<T>::RubberArray (const RubberArray& ra)
{
    _array = NULL;
    _alloc = 0;
    _items = 0;
    _Vindex = ra._Vindex;

    for (unsigned i = 0; i < ra._items; ++i)
        operator+= (ra._array[i]);
}

template <class T>
RubberArray<T>::~RubberArray ()
{
    if (_alloc != 0);
        delete [] _array;
}

template <class T>
RubberArray<T>& RubberArray<T>::operator= (const RubberArray<T>& ra)
{
    if (this == &ra) return *this;

    if (_alloc != 0)
        delete [] _array;

    _array = NULL;
    _alloc = 0;
    _items = 0;
    _Vindex = ra._Vindex;

    for (unsigned i = 0; i < ra._items; ++i)
        operator+= (ra._array[i]);

    return *this;
}

template <class OS>
ostream& operator<< (ostream& os, const RubberArray<OS>& ra)
{
    if (ra._items == 0)
        os << "empty";
    else
    {
        os << ra._array[0];
        for (unsigned i = 1; i < ra._items; ++i)
            os << "," << ra._array[i];
    }
    return os;
}

template <class OS>
ostream& operator<< (ostream& os, const RubberArray<OS>* ra)
{
    if ((*ra)._items == 0)
        os << "empty";
    else
    {
        os << (*ra)._array[0];
        for (unsigned i = 1; i < (*ra)._items; ++i)
            os << "," << (*ra)._array[i];
    }
    return os;
}

template <class T>
T& RubberArray<T>::operator[] (int Vi)
{
    int Aindex =Vi - _Vindex;
    if (Aindex < 0 || Aindex >= int (_items))
    {
        cout << "error\n";
        exit(200);
    }
    return _array[Aindex];
}

template <class T>
const T& RubberArray<T>::operator[] (int Vi) const
{
    int Aindex =Vi - _Vindex;
    if (Aindex < 0 || Aindex >= int (_items))
    {
        cout << "error\n";
        exit(200);
    }
    return _array[Aindex];
}

template <class T>
RubberArray<T> RubberArray<T>::operator() (int Vfirst, int Vlast) const
{
    int Afirst = Vfirst - _Vindex;
    int Alast = Vlast - _Vindex;

    if (Afirst < 0 || Afirst >= Alast || Alast > _items)
    {
        cout << "Error\n";
        exit(300);
    }

    RubberArray ret(_Vindex);
    for (unsigned i = Afirst; i < Alast; ++i)
        ret += _array[i];

    return ret;
}

template <class T>
void RubberArray<T>::operator+= (const T& t)
{
    if (_items >= _alloc)
    {
        if (_alloc == 0)
        {
            _alloc = 2;
            _array = new T[_alloc];
        }
        else
        {
            _alloc *= 2;
            T* temp = new T[_alloc];
            for (unsigned i = 0; i < _items; ++i)
                temp[i] = _array[i];
            delete [] _array;
            _array = temp;
        }
    }
    _array[_items++] = t;
}

/*template <class OS>
void RubberArray<T>::operator+= (const RubberArray& ra)
{
    //use the other += and run a loop, only works if you add to itself.
}*/

template <class T>
void RubberArray<T>::Insert (int Vi, const T& t)
{
    int Aindex = Vi - _Vindex;
    if (Aindex < 0 || Aindex >= int(_items))
    {
        throw double (5.5);
    }

    RubberArray<T> temp(_Vindex);
    for (unsigned i = 0; i < _items; ++i)
    {
        if (i == Aindex)
            temp += t;
            temp += _array[i];
    }
    *this = temp;
}

template <class T>
void RubberArray<T>::Insert (const T&)
{
    //insert at index 0
}

template <class T>
void RubberArray<T>::Delete ()
{
    Delete(_Vindex);
}

template <class T>
void RubberArray<T>::Delete (int Vi)
{
    int Aindex = Vi - _Vindex;
    if (Aindex < 0 || Aindex >= int(_items))
    {
        throw double (5.6);
    }

    RubberArray<T> temp(_Vindex);
    for (unsigned i = 0; i < _items; ++i)
    {
        if (i != Aindex)
            temp += _array[i];
    }
    *this = temp;
}

template <class T>
void RubberArray<T>::Delete (int Vfirst, int Vlast)
{

}

template <class T>
void RubberArray<T>::write (ofstream& outf) const
{
    if (outf)
    {
        outf.write(reinterpret_cast<const char*>(&_items), sizeof(_items));
        outf.write(reinterpret_cast<const char*>(&_Vindex), sizeof(_Vindex));
        outf.write(reinterpret_cast<const char*>(_array), _items * sizeof(T));
    }
    else
        cout << "File open error\n";
}

template <class T>
void RubberArray<T>::read (ifstream& inf)
{
    if (inf)
    {
        inf.read(reinterpret_cast<char*>(&_items), sizeof(_items));
        inf.read(reinterpret_cast<char*>(&_Vindex), sizeof(_Vindex));
        T* temp = new T[_items];
        inf.read(reinterpret_cast<char*>(temp), _items * sizeof(T));
        *this = RubberArray<T>(temp, _items, _Vindex);
        delete[] temp;
    }
    else
        cout << "File open error\n";
}

#endif
