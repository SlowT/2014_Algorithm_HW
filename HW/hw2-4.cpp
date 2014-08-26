#include <stdio.h>
#include <stdlib.h>
#include <vector>

// bottom-up, print order
struct Matrix
{
	int row;
	int col;
};

int GetMinMatrixMul( const std::vector<Matrix>& matrixList, std::vector<int>& cutPosList );
void PrintCutPos( const std::vector<int>& cutPosList, unsigned int matNum );
void PrintCutPos_Aux( const std::vector<int>& cutPosList, unsigned int matNum, unsigned int sId, unsigned int eId );

int main( void )
{
	std::vector<Matrix> list = {
			{ 4, 3 },
			{ 3, 5 },
			{ 5, 10 },
			{ 10, 2 },
			{ 2, 7 }
	};

	std::vector<int> cutPosList;
	printf_s( "%d\n", GetMinMatrixMul( list, cutPosList ) );

	PrintCutPos( cutPosList, list.size() );

	getchar();
	return 0;
}

int GetMinMatrixMul( const std::vector<Matrix>& matrixList, std::vector<int>& cutPosList )
{
	if( matrixList.empty() )
		return 0;

	std::vector<int> resTable( (matrixList.size() + 1)*matrixList.size() / 2, INT_MAX );
	cutPosList.assign( resTable.size(), 0 );

	unsigned int sId, eId, curResNum, tmp;
	for( sId = 0, eId = 0; sId < matrixList.size(); ++sId, ++eId ){
		curResNum = sId*matrixList.size() + eId - sId*(sId + 1) / 2;
		resTable[curResNum] = 0;
	}

	for( unsigned int i = 1; i < matrixList.size(); ++i ){
		for( sId = 0; sId < matrixList.size() - i; ++sId ){
			eId = sId + i;
			curResNum = sId*matrixList.size() + eId - sId*(sId + 1) / 2;

			for( unsigned int j = sId; j < eId; ++j ){
				tmp = matrixList[sId].row * matrixList[j].col * matrixList[eId].col +
					resTable[curResNum - eId + j] +
					resTable[(j + 1)*matrixList.size() + eId - (j + 1)*(j + 2) / 2];

				if( resTable[curResNum] > tmp ){
					resTable[curResNum] = tmp;
					cutPosList[curResNum] = j;
				}
			}
		}
	}

	return resTable[matrixList.size() - 1];
}

void PrintCutPos( const std::vector<int>& cutPosList, unsigned int matNum )
{
	if( cutPosList.empty() )
		return;

	PrintCutPos_Aux( cutPosList, matNum, 0, matNum - 1 );
	printf_s( "\n" );
}

void PrintCutPos_Aux( const std::vector<int>& cutPosList, unsigned int matNum, unsigned int sId, unsigned int eId )
{
	if( eId == sId ){
		printf_s( "M%d", sId );
		return;
	}

	unsigned int cutPosNum = sId*matNum + eId - sId*(sId + 1) / 2;
	printf_s( "(" );
	PrintCutPos_Aux( cutPosList, matNum, sId, cutPosList[cutPosNum] );
	PrintCutPos_Aux( cutPosList, matNum, cutPosList[cutPosNum] + 1, eId );
	printf_s( ")" );
}