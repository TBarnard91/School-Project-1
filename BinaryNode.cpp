//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file BinaryNode.cpp */

#include "BinaryNode.h"
#include <cstddef>
using namespace std;

template<class ItemType>
BinaryNode<ItemType>::BinaryNode()
      : item(nullptr), leftChildPtr(nullptr), rightChildPtr(nullptr)
{ }  // end default constructor

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem)
      : item(anItem), leftChildPtr(nullptr), rightChildPtr(nullptr)
{ }  // end constructor

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem,
                                    shared_ptr<BinaryNode<ItemType>> leftPtr,
                                    shared_ptr<BinaryNode<ItemType>> rightPtr)
      : item(anItem), leftChildPtr(leftPtr), rightChildPtr(rightPtr)
{ }  // end constructor

template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem)
{
   item = anItem;
}  // end setItem

template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const 
{
   return item;
}  // end getItem

template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const
{
   return ((leftChildPtr == nullptr) && (rightChildPtr == nullptr));
}

template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(shared_ptr<BinaryNode<ItemType>> leftPtr)
{
   leftChildPtr = leftPtr;
}  // end setLeftChildPtr

template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(shared_ptr<BinaryNode<ItemType>> rightPtr)
{
   rightChildPtr = rightPtr;
}  // end setRightChildPtr

template<class ItemType>
shared_ptr<BinaryNode<ItemType>> BinaryNode<ItemType>::getLeftChildPtr() const
{
   return leftChildPtr;
}  // end getLeftChildPtr		

template<class ItemType>
shared_ptr<BinaryNode<ItemType>> BinaryNode<ItemType>::getRightChildPtr() const
{
   return rightChildPtr;
}  // end getRightChildPtr		

