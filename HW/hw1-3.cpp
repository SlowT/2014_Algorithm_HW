#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <time.h>

int FibByRecursion( int n );
int FibByTopDown( int n );
int FibByBottomUp( int n );

int main( void )
{
	srand( time( (unsigned int)NULL ) );
	int n = rand() % 20;

	printf_s( "FibByRecursion\t%d : %d\n", n, FibByRecursion( n ) );
	printf_s( "FibByTopDown\t%d : %d\n", n, FibByTopDown( n ) );
	printf_s( "FibByBottomUp\t%d : %d\n", n, FibByBottomUp( n ) );
	
	getchar();
	return 0;
}

int FibByRecursion( int n )
{
	if( n < 0 )
		return 0;

	if( n < 2 )
		return n;

	return FibByRecursion( n - 1 ) + FibByRecursion( n - 2 );
}

int FibByTopDown( int n, std::vector<int>& res )
{
	if( n < 0 )
		return 0;

	if( res[n] != -1 )
		return res[n];

	if( n < 2 )
		res[n] = n;
	else
		res[n] = FibByTopDown( n - 1, res ) + FibByTopDown( n - 2, res );

	return res[n];
}
int FibByTopDown( int n )
{
	std::vector<int> res;
	res.assign( n+1, -1 );
	return FibByTopDown( n, res );
}

int FibByBottomUp( int n )
{
	if( n < 2 )
		return n;

	int n_2 = 0, n_1 = 1, res = n;
	for( int i = 2; i <= n; ++i ){
		res = n_2 + n_1;
		n_2 = n_1;
		n_1 = res;
	}

	return res;
}
