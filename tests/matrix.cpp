#include <catch.hpp>
#include <sstream>

#include "matrix.hpp"

TEST_CASE("creating matrix")
{
    matrix_t matrix;
    REQUIRE( matrix.rows() == 0 );
    REQUIRE( matrix.collumns() == 0 );
}

TEST_CASE("reading matrix")
{
    std::string input{
        "3, 3\n"
        "1 1 1\n"
        "2 2 2\n"
        "3 3 3" };
   
    matrix_t matrix;
    std::istringstream istream{ input };
    
    REQUIRE( matrix.read( istream ) );
    REQUIRE( matrix.rows() == 3 );
    REQUIRE( matrix.collumns() == 3 );
    
    std::ostringstream ostream;
    matrix.write( ostream );
    
    REQUIRE( input == ostream.str() );
}
TEST_CASE("operation+")
{
    std::string input{
        "3, 3\n"
        "2 2 2\n"
        "2 2 2\n"
        "2 2 2" };
    std::string input1{
        "3, 3\n"
        "1 1 1\n"
        "1 1 1\n"
        "1 1 1" };
    std::string input2{
         "3, 3\n"
        "3 3 3\n"
        "3 3 3\n"
        "3 3 3" };
    
   
    matrix_t matrix,matrix1;
    std::istringstream istream{ input };
     std::istringstream istream1{ input1 };
    REQUIRE( matrix.read( istream ) );
    REQUIRE( matrix.rows() == 3 );
    REQUIRE( matrix.collumns() == 3 );
    REQUIRE( matrix1.read( istream1 ) );
    REQUIRE( matrix1.rows() == 3 );
    REQUIRE( matrix1.collumns() == 3 );
    matrix+=matrix1;
    std::ostringstream ostream;
    matrix.write( ostream );
    
    REQUIRE( input2 == ostream.str() );
}
TEST_CASE("operation-")
{
    std::string input{
        "3, 3\n"
        "2 2 2\n"
        "2 2 2\n"
        "2 2 2" };
    std::string input1{
        "3, 3\n"
        "1 1 1\n"
        "1 1 1\n"
        "1 1 1" };
    std::string input2{
        "3, 3\n"
        "1 1 1\n"
        "1 1 1\n"
        "1 1 1" };
    
   
    matrix_t matrix,matrix1;
    std::istringstream istream{ input };
    std::istringstream istream1{ input1 };
    REQUIRE( matrix.read( istream ) );
    REQUIRE( matrix.rows() == 3 );
    REQUIRE( matrix.collumns() == 3 );
    REQUIRE( matrix1.read( istream1 ) );
    REQUIRE( matrix1.rows() == 3 );
    REQUIRE( matrix1.collumns() == 3 );
    matrix-=matrix1;
    std::ostringstream ostream;
    matrix.write( ostream );
    
    REQUIRE( input2 == ostream.str() );
}
TEST_CASE("operation*")
{
    std::string input{
        "3, 3\n"
        "2 2 2\n"
        "2 2 2\n"
        "2 2 2" };
    std::string input1{
        "3, 3\n"
        "1 1 1\n"
        "1 1 1\n"
        "1 1 1" };
    std::string input2{
        "3, 3\n"
        "6 6 6\n"
        "6 6 6\n"
        "6 6 6" };
    
   
    matrix_t matrix,matrix1;
    std::istringstream istream{ input };
    std::istringstream istream1{ input1 };
    REQUIRE( matrix.read( istream ) );
    REQUIRE( matrix.rows() == 3 );
    REQUIRE( matrix.collumns() == 3 );
    REQUIRE( matrix1.read( istream1 ) );
    REQUIRE( matrix1.rows() == 3 );
    REQUIRE( matrix1.collumns() == 3 );
    matrix*=matrix1;
    std::ostringstream ostream;
    matrix.write( ostream );
    
    REQUIRE( input2 == ostream.str() );
}
TEST_CASE("operation=")
{
    std::string input{
        "3, 3\n"
        "2 2 2\n"
        "2 2 2\n"
        "2 2 2" };
    std::string input1{
        "3, 2\n"
        "1 1 \n"
        "1 1 \n"
        "1 1 " };
    
   
    matrix_t matrix,matrix1;
    std::istringstream istream{ input };
    std::istringstream istream1{ input1 };
    REQUIRE( matrix.read( istream ) );
    REQUIRE( matrix.rows() == 3 );
    REQUIRE( matrix.collumns() == 3 );
    REQUIRE( matrix1.read( istream1 ) );
    REQUIRE( matrix1.rows() == 3 );
    REQUIRE( matrix1.collumns() == 2 );
    matrix=matrix1;
    std::ostringstream ostream;
    matrix.write( ostream );
    
    REQUIRE( input1 == ostream.str() );
}
