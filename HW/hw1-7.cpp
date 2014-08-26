#include <stdio.h>
#include <stdlib.h>
#include <vector>

// bottom-up
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

	std::vector<int> resTable( len, -1 );

	for( int i = 1; i <= len; ++i ){
		if( i <= priceTable.size() )
			resTable[i - 1] = priceTable[i - 1];

		for( int j = 1; j < i; ++j ){
			resTable[i - 1] = __max( resTable[i - 1], resTable[j - 1] + resTable[i - j - 1] );
		}
	}

	return resTable[len - 1];
}