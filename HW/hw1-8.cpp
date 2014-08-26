#include <stdio.h>
#include <stdlib.h>
#include <vector>

// bottom-up, print length of pieces
int GetMaxPrice( int len, const std::vector<int>& priceTable, std::vector<int>& firstCutTable );
void PrintFirstCutTable( const std::vector<int>& firstCutTable );

int main( void )
{
	std::vector<int> priceTable = {
		1, 5, 8, 9, 10, 17, 17, 20, 24, 30
	};

	int len;
	printf_s( "input rod length : " );
	scanf_s( "%d", &len );

	std::vector<int> firstCutTable;
	printf_s( "MaxPrice : %d\n\n", GetMaxPrice( len, priceTable, firstCutTable ) );
	printf_s( "Length of Pieces : " );
	PrintFirstCutTable( firstCutTable );

	getchar();
	getchar();
	return 0;
}

int GetMaxPrice( int len, const std::vector<int>& priceTable, std::vector<int>& firstCutTable )
{
	if( len < 1 || priceTable.empty() )
		return 0;

	if( len == 1 )
		return priceTable[0];

	std::vector<int> resTable( len, -1 );
	firstCutTable.assign( len, 0 );

	int tmp;
	for( int i = 1; i <= len; ++i ){
		if( i <= priceTable.size() ){
			resTable[i - 1] = priceTable[i - 1];
			firstCutTable[i - 1] = i;
		}

		for( int j = 1; j < i; ++j ){
			tmp = resTable[j - 1] + resTable[i - j - 1];

			if( resTable[i - 1] < tmp ){
				resTable[i - 1] = tmp;
				firstCutTable[i - 1] = j;
			}
		}
	}

	return resTable[len - 1];
}

void PrintFirstCutTable( const std::vector<int>& firstCutTable )
{
	int len = firstCutTable.size();
	if( len == 0 )
		return;

	while( len > 0 ){
		printf_s( "%d", firstCutTable[len - 1] );

		len -= firstCutTable[len - 1];
		if( len > 0 )
			printf_s( " / " );
	}
	printf_s( "\n" );
}
