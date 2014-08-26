struct Node{
	int data;
	Node *left;
	Node *right;
};

bool InsertNode(Node* root, Node* src)
{
	if( src->data < root->data ){
		if( nullptr == root->left ){
			root->left = src;
			return 1;
		}
		else{
			InsertNode( root->left, src );
			return 1;
		}
	}
	else if( src->data > root->data ){
		if( nullptr == root->right ){
			root->right = src;
			return 1;
		}
		else{
			InsertNode( root->right, src );
			return 1;
		}
	}
	return 0;
}

bool ClearTree( Node* root )
{
	if( nullptr == root )
		return 0;

	if( root->left )
		ClearTree( root->left );
	if( root->right )
		ClearTree( root->right );
	delete root;

	return 1;
}