#include <iostream>
#include <queue>

using namespace std;

class Node
{
public :
	int value;
	Node* left; //allocate size = 8 byte
	Node* right;
};

class BinarySearchTree
{
public :
	Node* root;
	
	BinarySearchTree()
	{
		root = NULL; //to set to 0
	}
	
	void Insert(int value)
	{
		Insert(root, value);
	}
	
	void Insert(Node* &node, int value)
	{
		//! if the node is NULL, create a new node
		if(node == NULL)
		{
			node = new Node();
			node->value = value;
			node->left = NULL;
			node->right = NULL;
			
			cout << "Node address : " << &node << endl;
			cout << "Node value : " << node->value << endl;
		}
		else if(value < node->value)
		{
			cout << value << " Left " << &(node->left) << endl;
			Insert(node->left, value);//! recursive function -- a function that call itself
		}
		else
		{
			cout << value << " Right " << &(node->right) << endl;
			Insert(node->right, value);
		}
	}
	
	void DisplayBFSLevelOrder(Node* node)
	{
		queue<Node*> b;
		
		if(node)
		{
			b.push(node);
		}
		while(!b.empty())
		{
			Node* node = b.front();
			
			cout << node->value << endl;
			
			if(node->left)
			{
				b.push(node->left);
			}
			
			if(node->right)
			{
				b.push(node->right);
			}
			b.pop();
		}
		
		//! 1. Always try to go left first
		//! 2. If there are no more left, then display current node
		//! 3. Then try to go right first
		//! 4. If has not been displayed yet, then display current node
	}
	void DisplayDFSPreOrder(Node* node)
	{
		bool isDisplayed = false;
		
		cout << node->value << endl;
		
		if(node->left != NULL)
		{
			DisplayDFSPreOrder(node->left);
		}
		
		if(node->right != NULL)
		{
			DisplayDFSPreOrder(node->right);
		}
		
		
	}
	void DisplayDFSInOrder(Node* node)
	{
		bool isDisplayed = false;
		
		if(node->left != NULL)
		{
			DisplayDFSInOrder(node->left);
		}
		cout << node->value << endl;
		if(node->right != NULL)
		{
			DisplayDFSInOrder(node->right);
		}
		
	}
	void DisplayDFSPostOrder(Node* node)
	{
		bool isDisplayed = false;
		
		if(node->left != NULL)
		{
			DisplayDFSPostOrder(node->left);
		}
		
		if(node->right != NULL)
		{
			DisplayDFSPostOrder(node->right);
		}
		
		cout << node->value << endl;
	}
};

int main()
{
	BinarySearchTree* tree = new BinarySearchTree();
	
	tree->Insert(43);
	tree->Insert(17);
	tree->Insert(52);
	tree->Insert(8);
	tree->Insert(12);
	tree->Insert(29);
	tree->Insert(65);
	tree->Insert(93);
	tree->Insert(58);
	tree->Insert(77);
	tree->Insert(2);
	tree->Insert(84);
	
	cout << endl;
	cout << "==============================" << endl;
	cout << "  *Display BFS Level Order*   " << endl;
	cout << "==============================" << endl;
	tree->DisplayBFSLevelOrder(tree->root);
	
	cout << endl;
	cout << "==============================" << endl;
	cout << "  *Display DFS Pre Order*     " << endl;
	cout << "==============================" << endl;
	tree->DisplayDFSPreOrder(tree->root);
	
	cout << endl;
	cout << "==============================" << endl;
	cout << "  *Display DFS In Order*      " << endl;
	cout << "==============================" << endl;
	tree->DisplayDFSInOrder(tree->root);
	
	cout << endl;
	cout << "==============================" << endl;
	cout << "  *Display DFS Post Order*    " << endl;
	cout << "==============================" << endl;
	tree->DisplayDFSPostOrder(tree->root);
	
	return 0;
}

//! Name : Muhamad Luqman bin Shamsuddin
//! Student ID : 0114642
