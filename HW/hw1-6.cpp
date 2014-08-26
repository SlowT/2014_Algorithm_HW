#include <stdio.h>
#include <stdlib.h>
#include <vector>

// memoization
int GetMaxPrice( int len, const std::vector<int>& priceTable );
int GetMaxPrice_Aux( int len, const std::vector<int>& priceTable, std::vector<int>& resTable );

int main( void )
{
	std::vector<int> priceTable = {
		1, 5, 8, 9, 10, 17, 17, 20, 24, 30
	};

	int len;
	printf_s( "input rod length : " );
	scanf_s( "%d", &len );

	printf_s( "MaxPrice : %d\n", GetMaxPrice( len, priceTable ) );

	getchar();
	getchar();
	return 0;
}

int GetMaxPrice( int len, const std::vector<int>& priceTable )
{
	if( len < 1 || priceTable.empty() )
		return 0;

	std::vector<int> resTable( len, -1 );
	resTable[0] = priceTable[0];

	return GetMaxPrice_Aux( len, priceTable, resTable );
}

int GetMaxPrice_Aux( int len, const std::vector<int>& priceTable, std::vector<int>& resTable )
{
	if( resTable[len - 1] > 0 )
		return resTable[len - 1];

	if( len <= priceTable.size() )
		resTable[len - 1] = priceTable[len - 1];

	for( int i = 1; i < len; ++i ){
		resTable[len - 1] = __max( resTable[len - 1], GetMaxPrice_Aux( i, priceTable, resTable ) + GetMaxPrice_Aux( len - i, priceTable, resTable ) );
	}

	return resTable[len - 1];
}
