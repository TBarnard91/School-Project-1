/**
 * @file FilmDatabase.h
 * @author Tyler Barnard
 * @date  November 3, 2018
 * @class FilmDatabase
 * This class creates a database using a BinarySearchTree to store
 * items of the Film class type. It accepts data from a file to create
 * Film objects and adds them to the BST. It also includes methods to
 * search the database for Film objects, and print out sorted lists.
 */
#ifndef FILMDATABASE_H
#include "BinarySearchTree.h"
#include "Film.h"
using namespace std;

class FilmDatabase
{
   
private:
   
public:
   /**
    * binary search tree to store Film data
    */
   static BinarySearchTree<Film> filmDatabaseBST;
   
   static int rankCount;          //count for sorting by rank
   static string findStudio;      //store the studio to search for
   static string findKeywords;    //store the keyword to search for
   static string findMonth;       //store the month to search for
   static bool searchResult;      //check for if a search result could be found


   /**
    * Creates a database consisting of Film objects.
    */
   void createDatabase (void);
   
   /**
    * Saves the database to an output file organized by title.
    */
   void titleReport (void);

   /**
    * Saves the database to an output file organized by rank.
    */
   void rankReport (void);
   
   /**
    * Searches the database for a specific title and displays the results.
    @param anItem - Film item to check title against
    */
   void titleSearch(Film& anItem);
 
   /**
    * Searches the database for a specific keyword and displays the results.
    @param kw - keyword to search using
    */
   void keywordSearch(string& kw);
   
   /**
    * Searches the database for all films prduced by a specific studio and displays the results.
    @param s studio to search for
    */
   void studioSearch(string& s);
   
   /**
    * Searches the database for all films realeased in a specific month and displays the results.
    @param m title of the film
    */
   void monthSearch(string& m);
   
   //temp for test
   //void displayData (void);
   
};

#define FILMDATABASE_H
#endif
