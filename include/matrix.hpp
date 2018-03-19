#include <iostream>
#include <assert.h>
template <typename T> class matrix_t {
private:
	T ** elements_;
	std::rows_;
	std::size_t collumns_;
public:
	matrix_t<T>();
	matrix_t<T>( matrix_t const & other );
	matrix_t<T> & operator =( matrix_t const & other );
	~matrix_t<T>();

	std::size_t rows() const;
	std::size_t collumns() const;

	matrix_t<T> operator +( matrix_t const & other ) const;
	matrix_t<T>  operator -( matrix_t const & other ) const;
	matrix_t<T> operator *( matrix_t const & other ) const;

	matrix_t<T> & operator -=( matrix_t const & other );
	matrix_t<T> & operator +=( matrix_t const & other );
	matrix_t<T> & operator *=( matrix_t const & other );

	std::istream & read( std::istream & stream );
	std::ostream & write( std::ostream  & stream ) const;
};
