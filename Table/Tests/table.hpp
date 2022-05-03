#ifndef TABLE_TABLE_HPP
#define TABLE_TABLE_HPP

#include <array>
#include <string>
#include <iostream>
#include <iomanip>

template <typename ELT>
struct Element{
    ELT value;
    //Element<ELT>* ptr;
};

template <typename ELT>
class Table {
private:
    int rows;
    int columns;
    ELT *ptr;

public:
    Table() : rows(0), columns(0){};
    Table(int r, int c);  // default constructor
    Table( const Table<ELT> & ); // copy constructor
    /*~Table();*/

    int numRows(){return rows;};
    int numCols(){return columns;};


    /*void print() const;
    void inputValues();
    const Table<ELT> &operator=(const Table<ELT> & );
    bool operator==( const Table<ELT> & ) const;

    bool operator!=( const Table<ELT> &right ) const{ return !( *this == right ); }

    ELT &operator()( int, int );
    const ELT &operator()( int, int ) const;*/

};

template <typename ELT>
Table<ELT>::Table( int r, int c ){
    rows = r;
    columns = c;
    if(r != 0 && c != 0) {
        int size = rows * columns;
        ptr = new ELT[size];

        assert(ptr != 0);

        for (int i = 0; i < rows * columns; i++)
            ptr[i] = 0; // initialize array
    }
}

template <typename ELT >
Table<ELT>::Table(const Table<ELT> &init ){
    rows = init.rows;
    columns = init.columns;

    ptr = new ELT[ rows * columns ];
    assert( ptr != 0 );

    for ( int i = 0; i < rows * columns; i++ )
        ptr[ i ] = init.ptr[ i ];
}

/*
template <typename ELT>
Table<ELT>::~Table(){
    delete [] ptr;
}

template <typename ELT>
const Table<ELT> &Table<ELT>::operator=( const Table<ELT> &right ){
    if ( &right != this ) {

        if ( rows * columns != right.rows * right.columns ) {
            delete [] ptr;
            rows = right.rows;
            columns = right.columns;
            ptr = new ELT[ rows * columns ];
            assert( ptr != 0 );
        }

        for ( int i = 0; i < rows * columns; i++ )
            ptr[ i ] = right.ptr[ i ];
    }

    return *this;
}


template <typename  ELT>
bool Table<ELT>::operator ==(const Table <ELT> &right) const {
    if ( &right == this )
        return true;
    else
        return false;
}

template <typename ELT>
ELT &Table<ELT>
::operator()( int s1, int s2 )
{
    assert( 0 <= s1 && s1 < rows );
    assert( 0 <= s2 && s2 < columns );

    return ptr[ rows * s1 + s2  ];
}



template <typename ELT>
const ELT &Table<ELT>::operator()( int s1, int s2 ) const{
    assert( 0 <= s1 && s1 < rows );
    assert( 0 <= s2 && s2 < columns );

    return ptr[ columns * s1 + s2  ]; // rvalue
}

template <typename ELT>
void Table<ELT>::inputValues(){
    for ( int i = 0; i < rows * columns; i++ )
        std::cin >> ptr[ i ];
}

template <typename ELT>
void Table <ELT> :: print() const{
    int i = 0;
    for (i ; i < rows * columns; i++ ) {
        std::cout << std::setw( 6 ) << ptr[ i ];

        if ( ( i + 1 ) % columns == 0 )
            std::cout << std::endl;
    }

    if ( i % columns != 0 )
        std::cout << std::endl;
}*/
#endif //TABLE_TABLE_HPP
