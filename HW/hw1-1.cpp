#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int GetNumOfNodes( Node* node );

int main( void )
{
	srand( time( NULL ) );
	Node *root = new Node();
	root->data = rand() % 100;
	for( int i = 0; i < 20; ++i ){
		Node *tNode = new Node();
		tNode->data = rand() % 100;
		InsertNode( root, tNode );
	}

	printf_s( "NumOfNodes : %d\n", GetNumOfNodes( root ) );

	ClearTree( root );

	getchar();
	return 0;
}

int GetNumOfNodes( Node* node )
{
	if( nullptr == node )
		return 0;

	return 
		1 + 
		GetNumOfNodes( node->left ) + 
		GetNumOfNodes( node->right );
}