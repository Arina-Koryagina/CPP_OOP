#pragma once

#include"List.h"
#include"String.h"

template<class TKey, class TVal>
struct BTreeNode
{
	      TKey key;
	      TVal value;
	BTreeNode* left;
	BTreeNode* right;

	BTreeNode(const TKey& k, const TVal& val) : key(k), value(val), left(nullptr), right(nullptr) {}

	void print()
	{
		if (left != nullptr) left->print();
		cout << value << " ";
		if (right != nullptr) right->print();
	}

	void key_print(String k)
	{
		if (left != nullptr) left->key_print(k);
		cout << k << " " << key << endl;
		cout << value;
		if (right != nullptr) right->key_print(k);
	}

	void formKeysLNR(List<TKey>& list)
	{
		if (left != nullptr) left->formKeys(list);
		list.push_back(key);
		if (right != nullptr) right->formKeys(list);
	}
	void formKeysNLR(List<TKey>& list)
	{
		list.push_back(key);
		if (left != nullptr) left->formKeys(list);
		if (right != nullptr) right->formKeys(list);
	}

	//BTreeNode* copy()
	//{
	//	if (left != nullptr) left->copy();
	//	if (right != nullptr) right->copy();
	//	BTreeNode* newNode(*this);
	//	return newNode;
	//}

	void del()
	{
		if (left != nullptr) left->del();
		if (right != nullptr) right->del();
		delete this;
	}

	TVal* getValue(const TKey& k)
	{
		if (k == key) return &value;
		else if (k < key && left != nullptr) left->getValue(k);
		else if (k > key && right != nullptr) right->getValue(k);
		else return nullptr;
	}
};

template<class TKey, class TVal>
class BTree
{
	BTreeNode<TKey, TVal>* root = nullptr;
	bool isPush = false;

	BTreeNode<TKey, TVal>* push_r(const TKey& key, const TVal& val, BTreeNode<TKey, TVal>*& node);

public:
	~BTree();

	void clear();
	void formKeysLNR(List<TKey>&);
	void formKeysNLR(List<TKey>&);
	void print();
	void key_print(String k);
	bool push(const TKey& key, const TVal& val);
	bool push_r(const TKey& key, const TVal& val);
	TVal* getValue(const TKey& key);
};

template<class TKey, class TVal>
BTreeNode<TKey, TVal>* BTree<TKey, TVal>::push_r(const TKey& key, const TVal& val, BTreeNode<TKey, TVal>*& node)
{
	if (!node)
	{
		node = new BTreeNode<TKey, TVal>(key, val);
		isPush = true;
		return node;
	}
	
	if (key == node->key) isPush = false;
	
	else if (key < node->key)
	{
		node->left = push_r(key, val, node->left);
	}
	else if (key > node->key)
	{
		node->right = push_r(key, val, node->right);
	}
	return node;
}

template<class TKey, class TVal>
BTree<TKey, TVal>::~BTree()
{
	if (root)
		clear();
}

template<class TKey, class TVal>
void BTree<TKey, TVal>::clear()
{
	if (root)
		root->del();
	root = nullptr;
}

template<class TKey, class TVal>
void BTree<TKey, TVal>::formKeysLNR(List<TKey>& list)
{
	if (root)
	{
		root->formKeys(list);
	}
}template<class TKey, class TVal>
void BTree<TKey, TVal>::formKeysNLR(List<TKey>& list)
{
	if (root)
	{
		root->formKeysNLR(list);
	}
}

template<class TKey, class TVal>
void BTree<TKey, TVal>::print()
{
	if (root)
	{
		root->print();
	}
	cout << endl;
}

template<class TKey, class TVal>
void BTree<TKey, TVal>::key_print(String k)
{
	if (root)
	{
		root->key_print(k);
	}
	cout << endl;
}

template<class TKey, class TVal>
bool BTree<TKey, TVal>::push(const TKey& key, const TVal& val)
{
	if (!root)
	{
		root = new BTreeNode<TKey, TVal>(key, val);
		return true;
	}

	BTreeNode<TKey, TVal>* current = root;
	do
	{
		if (key == current->key) return false;

		else if (key < current->key)
		{
			if (current->left != nullptr)
			{
				current = current->left;
			}
			else
			{
				current->left = new BTreeNode<TKey, TVal>(key, val);
				return true;
			}
		}
		else
		{
			if (current->right != nullptr)
			{
				current = current->right;
			}
			else
			{
				current->right = new BTreeNode<TKey, TVal>(key, val);
				return true;
			}
		}
	} while (true);
}

template<class TKey, class TVal>
bool BTree<TKey, TVal>::push_r(const TKey& key, const TVal& val)
{
	push_r(key, val, root);
	return isPush;
}

template<class TKey, class TVal>
TVal* BTree<TKey, TVal>::getValue(const TKey& key)
{
	if (root)
		return root->getValue(key);
	else
		return nullptr;
}
