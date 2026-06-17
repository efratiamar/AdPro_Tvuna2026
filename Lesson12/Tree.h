#pragma once
#include <iostream>
using namespace std;

template <class T>
class Tree
{
protected:
	class Node
	{
	public:
		T value;
		Node* left;
		Node* right;
		Node* father;
	public:
		Node(T val, Node* f = nullptr, Node* l = nullptr, Node* r = nullptr) 
			: value(val), father(f), left(l), right(r){};
	};

	Node* root;

private:
	void preOrder(Node* current);
	void inOrder(Node* current);
	void postOrder(Node* current);
	void clear(Node* current);

public:
	Tree() : root(nullptr) {};
	~Tree() { clear(); };

	void preOrder() { preOrder(root); };
	void inOrder() { inOrder(root); };
	void postOrder() { postOrder(root); };

	bool isEmpty() { return root == nullptr; };
	void clear() { clear(root); };

	virtual void process(T& val) { cout << val << " "; };

	virtual void add(T val) = 0; //new Node() ...
	virtual void remove(T val) = 0;
	virtual bool search(const T& val) const = 0;

};

template <class T>
void Tree<T>::preOrder(Node* current)
{
	if (current)
	{
		//cout << current->value << " ";
		process(current->value);
		preOrder(current->left);
		preOrder(current->right);
	}
	//else
		//return

}

template <class T>
void Tree<T>::inOrder(Node* current)
{
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}

template <class T>
void Tree<T>::postOrder(Node* current)
{
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}
}

template <class T>
void Tree<T>::clear(Node* current)
{
	if (current)
	{
		clear(current->left);
		clear(current->right);
		delete current;
	}
}
