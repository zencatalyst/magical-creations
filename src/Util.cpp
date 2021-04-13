
#include "Util.h"


inline bool Util::tokenize( std::string& inputStr, const unsigned int& tokenCount, std::vector< std::string >& foundedTokens )
{
	bool isAcceptable = true;

	std::string spaceChar(" ");
	std::string tabChar("	");
	std::string delimiter = tabChar + spaceChar;

	char* ptr2FirstChar = &inputStr[0];
	char* ptr2NextToken = strtok( ptr2FirstChar, delimiter.c_str( ) );

	while ( ptr2NextToken )
	{
		foundedTokens.push_back( ptr2NextToken );
	    ptr2NextToken = strtok( NULL, delimiter.c_str( ) );
	}

	isAcceptable = ( foundedTokens.size( ) != tokenCount ) ? false : true;

	return isAcceptable;
}

bool Util::isUInt( std::string& inputStr, const unsigned int& tokenCount, std::vector<unsigned int>& result_Uints,
				const std::vector<unsigned int>& specificTokensIndices, const int minValue, const int maxValue )
{
	bool isAcceptable = ( minValue < 0 || maxValue < 0 ) ? false : true;

	if ( !isAcceptable ) { return isAcceptable; }

	std::vector< std::string > foundedTokens;
	foundedTokens.reserve( tokenCount );

	isAcceptable = tokenize( inputStr, tokenCount, foundedTokens );

	if ( !isAcceptable )
	{
		return isAcceptable;
	}

	size_t pos = 0;
	unsigned int j = 0;

	for ( unsigned int i = 0; i < foundedTokens.size( ); ++i )
	{
		isAcceptable = true;

		if ( !specificTokensIndices.empty( ) )
		{
			if ( j < specificTokensIndices.size( ) )
			{
				i = specificTokensIndices[j];
			}
			else
			{
				break;
			}
			++j;
		}

		try
		{
			int result_Int = std::stoi( foundedTokens[i], &pos, 10 );

			if ( pos != foundedTokens[i].length( ) )
			{
				isAcceptable = false;
			}
			if ( isAcceptable )
			{
				isAcceptable = ( (result_Int > maxValue || result_Int < minValue) ) ? false : true;
			}
			if ( isAcceptable )
			{
				result_Uints[i] = result_Int;
			}
		}
		catch( const std::invalid_argument& ia )
		{
			isAcceptable = false;
		}
		catch ( const std::out_of_range& oor )
		{
			isAcceptable = false;
		}
		catch ( const std::exception& e )
		{
			isAcceptable = false;
		}
		catch ( ... )
		{
			isAcceptable = false;
		}

		if ( !isAcceptable )
		{
			break;
		}
	}

	return isAcceptable;
}