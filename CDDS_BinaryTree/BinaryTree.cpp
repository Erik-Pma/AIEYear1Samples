/*----------------------------------------
Author: Richard Stern
Description: A simple binary search tree
Date: 17/4/2015
----------------------------------------*/
#include "BinaryTree.h"
#include "TreeNode.h"
#include "raylib.h"
#include <iostream>
#include <cstdlib>
using namespace std;


BinaryTree::BinaryTree()
{
    m_pRoot = nullptr;
}

BinaryTree::~BinaryTree()
{
	while(m_pRoot)
	{
		Remove(m_pRoot->GetData());
	}
}

// Return whether the tree is empty
bool BinaryTree::IsEmpty() const 
{ 
	return (m_pRoot == nullptr);
}

// Insert a new element into the tree.
// Smaller elements are placed to the left, larger onces are placed to the right.
void BinaryTree::Insert(int a_nValue)
{
	
	TreeNode* pCurrent = m_pRoot;
	TreeNode* newNode = new TreeNode(a_nValue);
	TreeNode* pParent = nullptr;
	if (BinaryTree::IsEmpty())
	{	
		
		m_pRoot = newNode;
		cout << "input" << endl;
		
		return;
	}
	while (pCurrent != nullptr) 
	{
		
		if ( a_nValue < pCurrent->GetData())
		{
			cout << "went left" << endl;
			pParent = pCurrent;
			pCurrent = pCurrent->GetLeft();
		}
		else if ( a_nValue > pCurrent->GetData())
		{
			cout << "went right" << endl;
			pParent = pCurrent;
			pCurrent = pCurrent->GetRight();
		}
		else if ( a_nValue == pCurrent ->GetData())
		{
			cout << "dupe break" << endl;
			pParent = pCurrent;
			return;
		}
		
	}
	cout << "out of while" << endl;
	if (pParent->GetData() > a_nValue) 
	{
		cout << pParent->GetData() << newNode->GetData() << endl;
		pParent->SetLeft(newNode);
		cout << pParent->HasLeft() << endl;
		return;
	}
	else
	{
		cout << pParent->GetData() << newNode->GetData() << endl;
		pParent->SetRight(newNode) ;
		cout << pParent->HasRight() << endl;
		return;
	}
	

}

TreeNode* BinaryTree::Find(int a_nValue)
{
	TreeNode* pCurrent = nullptr;
	TreeNode* pParent = nullptr;

	return FindNode(a_nValue, pCurrent, pParent) ? pCurrent: nullptr;
}

bool BinaryTree::FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent)
{


	return false;
}

void BinaryTree::Remove(int a_nValue)
{

}

void BinaryTree::PrintOrdered()
{
	PrintOrderedRecurse(m_pRoot);
	cout << endl;
}

void BinaryTree::PrintOrderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::PrintUnordered()
{
    PrintUnorderedRecurse(m_pRoot);
	cout << endl;
}

void BinaryTree::PrintUnorderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::Draw(TreeNode* selected)
{
	Draw(m_pRoot, 400, 40, 400, selected);
}

void BinaryTree::Draw(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
	
	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->HasLeft())
		{
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			
			Draw(pNode->GetLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		if (pNode->HasRight())
		{
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);

			Draw(pNode->GetRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		pNode->Draw(x, y, (selected == pNode));
	}
}