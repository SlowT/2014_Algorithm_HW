#include <stdio.h>
#include <stdlib.h>
#include <string>

int GetLCS( const std::string& str1, const std::string& str2 );
int GetLCS_Aux( const std::string& str1, int len1, const std::string& str2, int len2 );

void main( void )
{
	std::string str1 = "abcdcab";
	std::string str2 = "baedcca";

	printf_s( "Max Length : %d\n", GetLCS( str1, str2 ) );

	getchar();
}

int GetLCS( const std::string& str1, const std::string& str2 )
{
	return GetLCS_Aux( str1, str1.length(), str2, str2.length() );
}

int GetLCS_Aux( const std::string& str1, int len1, const std::string& str2, int len2 )
{
	if( len1 == 0 || len2 == 0 )
		return 0;
	if( str1.at( len1 - 1 ) == str2.at( len2 - 1 ) ){
		return GetLCS_Aux( str1, len1 - 1, str2, len2 - 1 ) + 1;
	}
	else{
		return __max( 
			GetLCS_Aux( str1, len1 - 1, str2, len2 ), 
			GetLCS_Aux( str1, len1, str2, len2 - 1 ) );
	}
}