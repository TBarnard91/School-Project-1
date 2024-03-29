//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** A class of nodes for a link-based binary tree.
 Listing 16-2.
 @file BinaryNode.h */
 
#ifndef BINARY_NODE_
#define BINARY_NODE_
#include <memory>
using namespace std;

template<class ItemType>
class BinaryNode
{   
private:
   ItemType              item;           // Data portion
   shared_ptr<BinaryNode<ItemType>> leftChildPtr;   // Pointer to left child
   shared_ptr<BinaryNode<ItemType>> rightChildPtr;  // Pointer to right child

public:
   BinaryNode();
   BinaryNode(const ItemType& anItem);
   BinaryNode(const ItemType& anItem,
              shared_ptr<BinaryNode<ItemType>> leftPtr,
              shared_ptr<BinaryNode<ItemType>> rightPtr);

   void setItem(const ItemType& anItem);
   ItemType getItem() const;
   
   bool isLeaf() const;

   shared_ptr<BinaryNode<ItemType>> getLeftChildPtr() const;
   shared_ptr<BinaryNode<ItemType>> getRightChildPtr() const;
   
   void setLeftChildPtr(shared_ptr<BinaryNode<ItemType>> leftPtr);
   void setRightChildPtr(shared_ptr<BinaryNode<ItemType>> rightPtr);
}; // end BinaryNode

#include "BinaryNode.cpp"

#endif 