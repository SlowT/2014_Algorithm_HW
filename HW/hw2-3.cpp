#include <stdio.h>
#include <stdlib.h>
#include <vector>

// bottom-up
struct Matrix
{
	int row;
	int col;
};

int GetMinMatrixMul( const std::vector<Matrix>& matrixList );

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

	std::vector<int> resTable( (matrixList.size() + 1)*matrixList.size()/2, INT_MAX );

	unsigned int first, last, curResNum;
	for( first = 0, last = 0; first < matrixList.size(); ++first, ++last ){
		curResNum = first*matrixList.size() + last - first*(first + 1)/2;
		resTable[curResNum] = 0;
	}

	for( unsigned int i = 1; i < matrixList.size(); ++i ){
		for( first = 0; first < matrixList.size() - i; ++first ){
			last = first + i;
			curResNum = first*matrixList.size() + last - first*(first + 1)/2;

			for( unsigned int j = first; j < last; ++j ){
				resTable[curResNum] = __min( resTable[curResNum],
					matrixList[first].row * matrixList[j].col * matrixList[last].col +
					resTable[curResNum - last + j] +
					resTable[(j + 1)*matrixList.size() + last - (j + 1)*(j + 2)/2]
					);
			}
		}
	}

	return resTable[matrixList.size()-1];
}