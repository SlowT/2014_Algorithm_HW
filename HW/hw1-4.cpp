#include <stdio.h>
#include <stdlib.h>
#include <vector>

// recursion (check all cutting)
int GetMaxPrice( int len, const std::vector<int>& priceTable );

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

	if( len == 1 )
		return priceTable[0];

	int maxPrice = 0;
	if( priceTable.size() >= len )
		maxPrice = priceTable[len - 1];

	for( int i = 1; i < len; ++i ){
		maxPrice = __max( maxPrice, GetMaxPrice( i, priceTable ) + GetMaxPrice( len - i, priceTable ) );
	}

	return maxPrice;
}