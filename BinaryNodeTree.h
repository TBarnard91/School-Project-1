//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT binary tree: Link-based implementation.
 Listing 16-3.
 @file BinaryNodeTree.h */
 
#ifndef BINARY_NODE_TREE_
#define BINARY_NODE_TREE_

#include <memory>
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "PrecondViolatedExcep.h"
#include "NotFoundException.h"
using namespace std;

template<class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType>
{
private:
   shared_ptr<BinaryNode<ItemType>> rootPtr;
   
protected:
   //------------------------------------------------------------
   // Protected Utility Methods Section:
   // Recursive helper methods for the public methods.
   //------------------------------------------------------------
   
   int getHeightHelper(shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
   int getNumberOfNodesHelper(shared_ptr<BinaryNode<ItemType>> subTreePtr) const;
   
   // Recursively adds a new node to the tree in a left/right fashion to
   // keep the tree balanced.
   shared_ptr<BinaryNode<ItemType>> balancedAdd(shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                     shared_ptr<BinaryNode<ItemType>> newNodePtr);
   
   // Copies values up the tree to overwrite value in current node until
   // a leaf is reached; the leaf is then removed, since its value is
   // stored in the parent.
   shared_ptr<BinaryNode<ItemType>> moveValuesUpTree(shared_ptr<BinaryNode<ItemType>> subTreePtr);
   
   // Removes the target value from the tree by calling moveValuesUpTree
   // to overwrite value with value from child.
   virtual shared_ptr<BinaryNode<ItemType>>
               removeValue(shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                     const ItemType target, bool& success);
   
   // Recursively searches for target value in the tree by using a
   // preorder traversal.
   shared_ptr<BinaryNode<ItemType>> findNode(shared_ptr<BinaryNode<ItemType>> treePtr,
                                  const ItemType& target,
                                  bool& success) const;
   
   // Copies the tree rooted at treePtr and returns a pointer to
   // the copy.
   shared_ptr<BinaryNode<ItemType>> copyTree(const shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const;
   
   // Recursively deletes all nodes from the tree.
   void destroyTree(shared_ptr<BinaryNode<ItemType>> subTreePtr);
   
   // Recursive traversal helper methods:
   void preorder(void visit(ItemType&), shared_ptr<BinaryNode<ItemType>> treePtr) const;
   void inorder(void visit(ItemType&), shared_ptr<BinaryNode<ItemType>> treePtr) const;
   void postorder(void visit(ItemType&), shared_ptr<BinaryNode<ItemType>> treePtr) const;
   
public:
   //------------------------------------------------------------
   // Constructor and Destructor Section.
   //------------------------------------------------------------
   BinaryNodeTree();
   BinaryNodeTree(const ItemType& rootItem);
   BinaryNodeTree(const ItemType& rootItem,
                   const shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
                   const shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr);
   BinaryNodeTree(const BinaryNodeTree<ItemType>& tree);
   virtual ~BinaryNodeTree();
   
   //------------------------------------------------------------
   // Public BinaryTreeInterface Methods Section.
   //------------------------------------------------------------
   bool isEmpty() const;
   int getHeight() const;
   int getNumberOfNodes() const;
   ItemType getRootData() const throw(PrecondViolatedExcep);
   void setRootData(const ItemType& newData);
   bool add(const ItemType& newData); // Adds a node
   bool remove(const ItemType& data); // Removes a node
   void clear();
   ItemType getEntry(const ItemType& anEntry) const throw(NotFoundException);
   bool contains(const ItemType& anEntry) const;
   
   //------------------------------------------------------------
   // Public Traversals Section.
   //------------------------------------------------------------
   void preorderTraverse(void visit(ItemType&)) const;
   void inorderTraverse(void visit(ItemType&)) const;
   void postorderTraverse(void visit(ItemType&)) const;
   
   //------------------------------------------------------------
   // Overloaded Operator Section.
   //------------------------------------------------------------
   BinaryNodeTree& operator=(const BinaryNodeTree& rightHandSide);
}; // end BinaryNodeTree
#include "BinaryNodeTree.cpp"
#endif
