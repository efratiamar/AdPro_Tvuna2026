#pragma once
#include "Tree.h"

template <class T>
class SearchTree : public Tree<T>
{
private:
	void add(class Tree<T>::Node* current, T val);

	bool search(class Tree<T>::Node* current, const T& val) const;

	class Tree<T>::Node* searchNode(class Tree<T>::Node* current, const T& val) const
	{
		if (!current)
			return nullptr;
		if (current->value == val)
			return current;

		if (current->value < val) //go right
			return search(current->right, val);
		else //go left
			return search(current->left, val);
	}

	class Tree<T>::Node* findSuccessor(class Tree<T>::Node* current, const T& val) const
	{
		//first go right
		//go left till the end

	}




public:
	void add(T val);
	void remove(T val);
	bool search(const T& val) const;
};


template <class T>
void SearchTree<T>::add(T val)
{
	if (!this->root)
		this->root = new class Tree<T>::Node(val);
	else
		add(this->root, val);
}

template <class T>
void SearchTree<T>::add(class Tree<T>::Node* current, T val)
{
	if (current->value < val) //go right
	{
		if (!current->right)
			current->right = new class Tree<T>::Node(val, current);
		else
			add(current->right, val);
	}
	else //go left
	{
		if (!current->left)
			current->left = new class Tree<T>::Node(val, current);
		else
			add(current->left, val);
	}
}

template <class T>
bool  SearchTree<T>::search(const T& val) const
{
	return search(this->root, val);
}

template <class T>
bool  SearchTree<T>::search(class Tree<T>::Node* current, const T& val) const
{
	if (!current)
		return false;
	if (current->value == val)
		return true;

	if (current->value < val) //go right
		return search(current->right, val);
	else //go left
		return search(current->left, val);
}

