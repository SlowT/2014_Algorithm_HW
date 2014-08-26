#include <stdio.h>
#include <stdlib.h>
#include <vector>

// recursion
struct Matrix
{
	int row;
	int col;
};

int GetMinMatrixMul( const std::vector<Matrix>& matrixList );
int GetMinMatrixMul_Aux( const std::vector<Matrix>& matrixList, int first, int last );

int main( void )
{
	std::vector<Matrix> list = {
		{ 4, 3 },
		{ 3, 5 },
		{ 5, 10 },
		{ 10, 2 },
		{ 2, 7 }
	};

	printf_s( "%d\n", GetMinMatrixMul( list ) );

	getchar();
	return 0;
}

int GetMinMatrixMul( const std::vector<Matrix>& matrixList )
{
	if( matrixList.empty() )
		return 0;

	return GetMinMatrixMul_Aux( matrixList, 0, matrixList.size() - 1 );
}

int GetMinMatrixMul_Aux( const std::vector<Matrix>& matrixList, int first, int last )
{
	if( last - first < 1 )
		return 0;

	int min = INT_MAX;
	for( int i = first; i < last; ++i ){
		min = __min( min,
			matrixList[first].row * matrixList[i].col * matrixList[last].col +
			GetMinMatrixMul_Aux( matrixList, first, i ) +
			GetMinMatrixMul_Aux( matrixList, i + 1, last )
			);
	}

	return min;
}