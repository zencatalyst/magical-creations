
#include "Util.h"
#include <iostream>
#include <vector>
#include <memory>
#include <unordered_set>


class CharMatrix
{
public:
	inline CharMatrix( );
	inline CharMatrix( const unsigned int& Y_DIM, const unsigned int& X_DIM, const char FILL_CHARACTER = ' ' );
	inline ~CharMatrix( ) = default;
	inline CharMatrix( const CharMatrix& ) = delete;
	inline CharMatrix& operator=( const CharMatrix& ) = delete;
	inline CharMatrix( CharMatrix&& rhs ) noexcept;
	inline CharMatrix& operator=( CharMatrix&& rhs ) noexcept;

	inline const unsigned int& getY_DIM( ) const;
	inline const unsigned int& getX_DIM( ) const;
	inline std::vector< std::vector<char> >& getCharacterMatrix( );

	inline static char findCharType( const unsigned int(&coordArr)[4] );
	inline static auto initialize( );
	inline static unsigned int getNumOfInputLines( const unsigned int& Y_DIM, const unsigned int& X_DIM );
	inline static auto getCoords( );
	static void writeToOutput( );

private:
	unsigned int _Y_DIM;
	unsigned int _X_DIM;
	std::vector< std::vector<char> > _characterMatrix;
	inline static const std::unordered_set<char> CHAR_SET { '/', '\\', '|', '-' };
};