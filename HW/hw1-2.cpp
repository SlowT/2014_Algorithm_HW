#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <queue>

void PrintBFS( Node* src );

int main( void )
{
	srand( time( (unsigned int)NULL ) );
	Node *root = new Node();
	root->data = rand() % 100;
	for( int i = 0; i < 20; ++i ){
		Node *tNode = new Node();
		tNode->data = rand() % 100;
		InsertNode( root, tNode );
	}

	PrintBFS( root );
	printf_s( "\n" );

	ClearTree( root );

	getchar();
	return 0;
}

void PrintBFS( Node* src )
{
	std::queue<Node*> nodeQueue;

	Node* curNode = nullptr;
	nodeQueue.push( src );
	while( !nodeQueue.empty() ){
		curNode = nodeQueue.front();

		printf_s( "[%d] ", curNode->data );

		if( nullptr != curNode->left )
			nodeQueue.push( curNode->left );
		if( nullptr != curNode->right )
			nodeQueue.push( curNode->right );

		nodeQueue.pop();
	}
}