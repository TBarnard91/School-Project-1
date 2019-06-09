 /*
 * @file Project1.cpp
 * @author Tyler Barnard
 * @date November 3, 2018
 * This program uses a BinarySearchTree to store
 * items of the Film class type. It reads data from a file
 * and creates Film objects which are stored in the BST.
 * Users may search the tree for Films using several criteria
 * or display all items in the tree, sorted by title or rank.
 */
#include "FilmDatabase.h"
#include "Menu.h"
#include <cstdlib>
#include <iostream>
using namespace std;

   BinarySearchTree<Film> FilmDatabase::filmDatabaseBST;
   
   int FilmDatabase::rankCount;
   string FilmDatabase::findStudio;
   string FilmDatabase::findKeywords;
   string FilmDatabase::findMonth;
   bool FilmDatabase::searchResult;

    

int main (void)
{  
   
   BinarySearchTree<Film> filmDatabaseBST = FilmDatabase::filmDatabaseBST;
   
   int rankCount = FilmDatabase::rankCount;
   string findStudio = FilmDatabase::findStudio;
   string findKeywords = FilmDatabase::findKeywords;
   string findMonth = FilmDatabase::findMonth;
   bool searchResult = FilmDatabase::searchResult;
   
   //create the database
   FilmDatabase filmDB;
   filmDB.createDatabase();
   
   //create the main menu
   Menu mainMenu;
   //display the main menu
   mainMenu.displayMenu(filmDB);
   
    return EXIT_SUCCESS;
}

   