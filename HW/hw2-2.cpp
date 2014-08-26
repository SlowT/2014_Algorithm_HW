#include <stdio.h>
#include <stdlib.h>
#include <vector>

// memoization
struct Matrix
{
	int row;
	int col;
};

int GetMinMatrixMul( const std::vector<Matrix>& matrixList );
int GetMinMatrixMul_Aux( const std::vector<Matrix>& matrixList, int first, int last, std::vector<int>& resTable );

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

	std::vector<int> resTable( (matrixList.size() + 1)*matrixList.size()*0.5, INT_MAX );

	return GetMinMatrixMul_Aux( matrixList, 0, matrixList.size() - 1, resTable );
}

int GetMinMatrixMul_Aux( const std::vector<Matrix>& matrixList, int first, int last, std::vector<int>& resTable )
{
	if( last - first < 1 )
		return 0;

	int curResNum = first*matrixList.size() + last - first*(first+1)*0.5;

	for( int i = first; i < last; ++i ){
		resTable[curResNum] = __min( resTable[curResNum],
			matrixList[first].row * matrixList[i].col * matrixList[last].col +
			GetMinMatrixMul_Aux( matrixList, first, i, resTable ) +
			GetMinMatrixMul_Aux( matrixList, i + 1, last, resTable )
			);
	}

	return 	resTable[curResNum];
}