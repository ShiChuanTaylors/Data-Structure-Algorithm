/* Data Structure and Algorithm - Tree & AVL
 * Created by Ting Shi Chuan, Software Engineering Student
 * Taylor's University
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTreeNode
{
	double key;
	struct BinaryTreeNode *leftChild;
	struct BinaryTreeNode *rightChild;
	
}BinaryTreeNode;



void bstInsert(BinaryTreeNode* root, double value);
int bstHeight(BinaryTreeNode* node);
void bstPrint(BinaryTreeNode* root);
BinaryTreeNode* bstFind(BinaryTreeNode * root, double x);
int bstIsAVL(BinaryTreeNode* root);
BinaryTreeNode* bstMin(BinaryTreeNode* root);
BinaryTreeNode* bstMax(BinaryTreeNode* root); 

void main()
{
	BinaryTreeNode* node;
	BinaryTreeNode* root = (BinaryTreeNode*) malloc(sizeof(BinaryTreeNode));
	root->key = 5.5;
	root->leftChild = NULL;
	root->rightChild = NULL;
	bstInsert(root, 7.7);
	bstInsert(root, 3.2);
	bstInsert(root, 4.0);
	
	node = bstFind(root, 3.2);
	if(node != NULL)
	       printf("The value %.2f was found.\n", node->key);
	else
	       printf("Value 3.2 was not found.\n");
	       
	/*node = bstMin(root);
	if(node != NULL)
	       printf("The minimum value is %f.\n", node->key);
	node = bstMax(root);
	if(node != NULL)
	       printf("The maximum value is %f.\n", node->key);
	root = bstDelete(root, 3.2);
	node = bstFind(root, 3.2);
	if(node != NULL)
	       printf("The value %f was found.\n", node->key);
	else
	       printf("Value 3.2 was not found.\n";
	// delete the root
	root = bstDelete(root, 7.7);
	printf("Height of binary search tree is %d.\n", bstHeight(root)); bstClear(root);
*/

	bstPrint(root);
	printf("Height of binary tree is %d.\n", bstHeight(root));
}

// inserts a new node in the binary search tree at the correct position
void bstInsert(BinaryTreeNode* root, double value) 
{
	
	if(root->key < value)
	{
		if(root->rightChild == NULL)
		{
			BinaryTreeNode* newNode = (BinaryTreeNode*) malloc(sizeof(BinaryTreeNode));
			newNode->key = value;
			newNode->leftChild = NULL;
			newNode->rightChild = NULL;
			
			root->rightChild = newNode;	
		}
		else
			bstInsert(root->rightChild, value);
	}
	else
	{
		if(root->leftChild == NULL)
		{
			BinaryTreeNode* newNode = (BinaryTreeNode*) malloc(sizeof(BinaryTreeNode));
			newNode->key = value;
			newNode->leftChild = NULL;
			newNode->rightChild = NULL;
			
			root->leftChild = newNode;	
		}
		else
			bstInsert(root->leftChild, value);
	}
		
}


// calculates the height of the tree
int bstHeight(BinaryTreeNode* node)
{
	if(node == NULL)
		return 0;
	else
	{
		int hl = bstHeight(node->leftChild);
		int hr = bstHeight(node->rightChild);
		if(hl > hr)
			return(1 + hl);
		else 
			return(1 + hr);
		
	}
	
	
}

BinaryTreeNode* bstFind(BinaryTreeNode * root, double x)
{
	if(root == NULL)
		return NULL;
	else
	{	
		printf("%.2f\n", root->key);
		if(root->key == x)
			return root;
		else
			if(root->key > x)
				return bstFind(root->leftChild, x);
			else 
				return bstFind(root->rightChild, x);
	}
}

BinaryTreeNode* bstMin(BinaryTreeNode* root) 
{
	if(root->leftChild == NULL)
		return root;
	else
		return bstMin(root->leftChild);	
	
}

BinaryTreeNode* bstMax(BinaryTreeNode* root) 
{
	if(root->rightChild == NULL)
		return root;
	else
		return bstMin(root->rightChild);	
	
}

void bstPrint(BinaryTreeNode *root)
{	
	if(root == NULL)
		return;
	
	printf("%.2f\n", root->key);
	bstPrint(root->leftChild);
	bstPrint(root->rightChild);
	
}

void bstDelete(BinaryTreeNode* root)
{
	
}

boolean bstIsAVL(BinaryTreeNode* root)
{
	if(root == NULL)
		return true;
	else
	{		
		int hl = bstHeight(root->leftChild);
		int hr = bstHeight(root->rightChild);
		if(abs(hl-hr) > 1)
			return false;
		else
			return (bstIsAVL(root->leftChild) && bstIsAVL(root->rightChild));
	}
}


