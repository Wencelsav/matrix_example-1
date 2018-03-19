#include "matrix.hpp"

matrix_t<T>::matrix_t() : elements_{ nullptr }, rows_{ 0 }, collumns_{ 0 }
{
}

matrix_t<T>::matrix_t( matrix_t const & other )
{
	    elements_= new T *[other.rows()];
	    for (std::size_t i = 0; i < other.rows(); ++i) {
			elements_[i] = new T[other.collumns()];
			for (std::size_t j = 0; j < other.collumns(); ++j) {
				elements_[i][j] = other.elements_[i][j];
			}
	    }
		
	    rows_ = other.rows();
            collumns_=other.collumns();
}

matrix_t & matrix_t<T>::operator =( matrix_t const & other )
{   
	if (this!=&other){
           if(elements_!=nullptr){
	           for (std::size_t i = 0; i < rows_; ++i) {
		      delete[] elements_[i];
	           }
               delete[] elements_;
            }
            elements_ = new T *[other.rows()];
	    for (std::size_t i = 0; i < other.rows(); ++i) {
			elements_[i] = new T[other.collumns()];
			for (std::size_t j = 0; j < other.collumns(); ++j) {
				elements_[i][j] = other.elements_[i][j];
			}
	    }
	    rows_ = other.rows();
            collumns_ = other.collumns();
        }
	return *this;
}

matrix_t<T>::~matrix_t()
{
	if(elements_!=nullptr){
          for (std::size_t i = 0; i < rows_; ++i) {
              delete[] elements_[i];
           }
           delete[] elements_;
        }
}

std::size_t matrix_t<T>::rows() const
{
    return rows_;
}

std::size_t matrix_t<T>::collumns() const
{
    return collumns_;
}

matrix_t matrix_t<T>::operator +( matrix_t const & other ) const
{
        assert(collumns_ == other.collumns() && rows_ == other.rows());
	matrix_t result;
	

	result.elements_= new T*[rows_];
	for (std::size_t i = 0; i < rows_; ++i) {
		result.elements_[i] = new T[collumns_];
	   	for (std::size_t j = 0; j < collumns_; ++j) {
			result.elements_[i][j] = elements_[i][j]+other.elements_[i][j];
	    }
	}
	
        result.rows_=rows_;
        result.collumns_=collumns_;
	return result;
}

matrix_t matrix_t<T>::operator -( matrix_t const & other ) const
{
        assert(collumns_ == other.collumns() && rows_ == other.rows());
        matrix_t result;
	result.elements_= new T*[rows_];
	for (std::size_t i = 0; i < rows_; ++i) {
		result.elements_[i] = new T[collumns_];
	   	for (std::size_t j = 0; j < collumns_; ++j) {
			result.elements_[i][j] = elements_[i][j]-other.elements_[i][j];
	    }
	}
        result.rows_=rows_;
        result.collumns_=collumns_;
	return result;
}

matrix_t matrix_t<T>::operator *( matrix_t const & other ) const
{
        assert(collumns_ == other.rows());
        matrix_t result;
	result.elements_=new T*[rows_];
        for (std::size_t i = 0; i < rows_; i++) {
        result.elements_[i]=new T[other.collumns()];
		for (std::size_t j = 0; j < other.collumns(); j++) {
			float y = 0;
			for (std::size_t z = 0; z < collumns_; z++) {
				y += elements_[i][z] * other.elements_[z][j];
			}
			result.elements_[i][j] = y;
		}
        }  
    
        result.rows_=rows_;
        result.collumns_=other.collumns_;
	return result;
}

matrix_t & matrix_t<T>::operator -=( matrix_t const & other )
{  
    assert(collumns_ == other.collumns() && rows_ == other.rows());
	for (std::size_t i = 0; i < rows_; ++i) {	
	   	for (std::size_t j = 0; j < collumns_; ++j) {
			elements_[i][j] = elements_[i][j]-other.elements_[i][j];
	    }
	}
	return *this;
}

matrix_t & matrix_t<T>::operator +=( matrix_t const & other )
{
	 assert(collumns_ == other.collumns() && rows_ == other.rows());

	

	
	for (std::size_t i = 0; i < rows_; ++i) {	
	   	for (std::size_t j = 0; j < collumns_; ++j) {
			elements_[i][j] = elements_[i][j]+other.elements_[i][j];
	    }
	}
	
        
	return *this;
}

matrix_t & matrix_t<T>::operator *=( matrix_t const & other )
{
	*this=*this * other;
	return *this;
}

std::istream & matrix_t<T>::read( std::istream & stream )
{
    std::size_t rows;
    std::size_t collumns;
    char symbol;
    
    bool success = true;
    if( stream >> rows && stream >> symbol && symbol == ',' && stream >> collumns ) {
        float ** elements = new float *[ rows ];
        for( std::size_t i = 0; success && i < rows; ++i ) {
            elements[ i ] = new T[ collumns ];
            for( std::size_t j = 0; j < collumns; ++j ) {
                if( !( stream >> elements[ i ][ j ] ) ) {
                    success = false;
                    break;
                }
            }
        }
        
        if( success ) {
            for( std::size_t i = 0; i < rows_; ++i ) {
                delete [] elements_[ i ];
            }
            delete [] elements_;
            
            rows_ = rows;
            collumns_ = collumns;
            elements_ = elements;
        }
        else {
            for( std::size_t i = 0; i < rows; ++i ) {
                delete [] elements[ i ];
            }
            delete [] elements;
        }
    }
    else {
        success = false;
    }
    
    if( !success ) {
        stream.setstate( std::ios_base::failbit );
    }
    
	return stream;
}

std::ostream & matrix_t:<T>:write( std::ostream & stream ) const
{
    stream << rows_ << ", " << collumns_;
    for( std::size_t i = 0; i < rows_; ++i ) {
        stream << '\n';
        for( std::size_t j = 0; j < collumns_; ++j ) {
            stream << elements_[ i ][ j ];
            if( j != rows_ - 1 ) {
                stream << ' ';
            }
        }
    }
    
	return stream;
}
