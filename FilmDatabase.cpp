/**
 * @file FilmDatabase.cpp
 * @author Tyler Barnard
 * @date  November 3, 2018
 * Implementation of the FilmDatabase class
 * This class creates a database using a BinarySearchTree to store
 * items of the Film class type. It accepts data from a file to create
 * Film objects and adds them to the BST. It also includes methods to
 * search the database for Film objects, print out sorted lists, and 
 * save and ouput the database to a file.
 */
#include "FilmDatabase.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

   //declare namespace for non-member functions and initialze non-member functions
   namespace testNS
   {
   
       /**
      * Display the contents of a Film object
     */
     void display(Film& anItem)
     {
        anItem.printFilm();
     }
     
     /**
     * Sort and display Film objects by ascending Rank
     */
     void rankSort(Film& anItem)
     {
         bool check;
         int rank1;
         rank1 = anItem.getRank();
         check = (rank1 == FilmDatabase::rankCount);
         
         if (check)
         {
            anItem.printFilm();
         }
     }
     
      /**
      * Compares the title from a Film object with the keyword given
      @param anItem - Film item to compare studios
      */
      void keywordTest(Film& anItem) 
      {  
         string kw;  //temporary string to hold title from Film object
         kw = anItem.getTitle(); //
         
         if (kw.find(FilmDatabase::findKeywords) != string::npos)   //if search term is a substring of the title, and the end of the string has not been reached
         {
            Film tempFilm = FilmDatabase::filmDatabaseBST.getEntry(anItem);  //then copy Film and display Film data
            display(tempFilm);
            FilmDatabase::searchResult = true; //set check to true to indicate a result was found
         }
      
      }//end keywordTest
   
       /**
      * Compares the studio from a Film object with the keyword given
      @param anItem - Film item to compare studios
      */
      void studioTest(Film& anItem)
      {  
         string s;   //temporary variable to hold studio from Film
         s = anItem.getStudio(); //
         if (s == FilmDatabase::findStudio)  //if the search term and the Films studio match 
         {
            Film tempFilm = FilmDatabase::filmDatabaseBST.getEntry(anItem);  //copy Film object and display the data
            display(tempFilm);
            FilmDatabase::searchResult = true; //set check to true to indicate a result was found
         }
      }//end studioTest
      
      /**
       * Compares the release month from a Film object with the keyword given
       @param anItem - Film item to compare months
       */
      void monthTest(Film& anItem)
      {  
         string m;   //string to hold the Film's month
         m = anItem.getOpenDate();
         
         if (FilmDatabase::findMonth.length() == 1)  //check if 1 character (month 1-9)
         {
            if (m[0] == FilmDatabase::findMonth[0])  //if first character match
            {
               Film tempFilm = FilmDatabase::filmDatabaseBST.getEntry(anItem);  
               display(tempFilm);
               FilmDatabase::searchResult = true; //set to true because a result was found
            }
         }
         else if (FilmDatabase::findMonth.length() == 2)   //check if 2 character (month 10-12)
         {
            if ((m[0] == FilmDatabase::findMonth[0]) && (m[1] == FilmDatabase::findMonth[1])) //if first and second character match
            {
               Film tempFilm = FilmDatabase::filmDatabaseBST.getEntry(anItem);  //copy Film object to pass to display() and print Film information
               display(tempFilm);
               FilmDatabase::searchResult = true; //set to true because a result was found
            }
   
         }
      }//end monthTest
      
     
      
   }//end namespace

   

/**
    * Creates a database consisting of Film objects.
    */
   void FilmDatabase::createDatabase (void)
   {  
      //variables to hold the values from file, that will be used to create a Film object
      string tempTitle;
      int tempRank;
      string tempStudio;
      double tempTotalGross;
      int tempTotalTheaters;
      double tempOpeningGross;
      int tempOpeningTheaters;
      string tempOpeningDate;
   
      string line;   //variable to hold one line from file
   
      //name of input file
   const string INPUT_FILE = "Films2015.csv";
   
   //open the input file
   ifstream inFile(INPUT_FILE);
   
   //prime read of the file
   getline(inFile, line);
   
   if(!inFile)
   {
      cout << "Error opening file for input: " << INPUT_FILE << endl;
   }
   
   while (inFile)
   {
      istringstream iss1 (line); //stringstream to parse input
      string token;               //variable to hold one word
      int count = 1; //count to determine current data for each line
      
      while(getline(iss1, token, ','))
      {
        
         //assign token to approriate variable
         switch (count)
         {
            case 1:  //rank int
               tempRank = stoi(token);
               break;
            case 2:  //title string
               tempTitle = token;
               break;
            case 3:  //studio string
               tempStudio = token;
               break;
            case 4:  //totalGross double
               tempTotalGross = stod(token);
               break;
            case 5:  //totalTheaters int
               tempTotalTheaters = stoi(token);
               break;
            case 6:  //openingGross double
               tempOpeningGross = stod(token);
               break;
            case 7:  //openingTheaters int
               tempOpeningTheaters = stoi(token);
               break;
            case 8:  //openingDate string
               tempOpeningDate = token;
               break;
         }//end switch
         
         count++;
      }//end inner while
      
      Film newFilm(tempTitle, tempRank, tempStudio, tempTotalGross, tempTotalTheaters, 
                      tempOpeningGross, tempOpeningTheaters, tempOpeningDate);
                      
      filmDatabaseBST.add(newFilm);
     
      iss1 >> token;
      getline(inFile, line);    // read next line from file*/
   }//end outer while
    
   //close the file
   inFile.close(); 
     
   }//end createDatabase
   
   /**
    * Saves the database to an output file organized by title.
    */
   void FilmDatabase::titleReport (void)
   { 
      cout << left;
      cout << "Report By Title-Inorder:" << endl;
      cout << setw(5) << "Rank" << setw(42) << "Title" << setw(7) << "Studio" << setw(14) << "Total Gross" << setw(8);
      cout << "Tot.Th." << setw(15) << "Open Gross" << setw(8) << "Open Th." << setw(8) << "Date" << endl;
      cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
      
      filmDatabaseBST.inorderTraverse(testNS::display);
      cout << endl << endl;
      
   }//end titleReport

   /**
    * Saves the database to an output file organized by rank.
    */
   void FilmDatabase::rankReport (void)
   {
      cout << left;
      cout << "Report By Rank:" << endl;
      cout << setw(5) << "Rank" << setw(42) << "Title" << setw(7) << "Studio" << setw(14) << "Total Gross" << setw(8);
      cout << "Tot.Th." << setw(15) << "Open Gross" << setw(8) << "Open Th." << setw(8) << "Date" << endl;
      cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
      
      rankCount = 1;
      
      for (int i = 0; i < 100; i++)
      {
         filmDatabaseBST.inorderTraverse(testNS::rankSort);
         rankCount++;
      }
      cout << endl << endl;
   
   }//end rankReport
   
   /**
    * Check if title is in a Film, and display the results.
    @param anItem - Film item to check title against
    */
   void FilmDatabase::titleSearch(Film& anItem)
   {
      
      
      bool found;    //check to verify is a match was found
      found = filmDatabaseBST.contains(anItem); //find out if item is in the BST
      Film tempFilm = filmDatabaseBST.getEntry(anItem);  //create copy of Film from BST
      found = (anItem == tempFilm); //compare to ensure an exact match of titles
      
      if (found)  //if found, retrieve item to copy and display data
      {  
         testNS::display(tempFilm);
      }
      else  //if not, declare no result was found
      {
         cout << "No match for "<< anItem.getTitle() << " was found." << endl;
      }
   }//end titleSearch
  
   /**
    * Searches the database for a specific keyword and displays the results.
    @param kw keyword to search using
    */
   void FilmDatabase::keywordSearch(string& kw)
   {  
      searchResult = false;   //ensure check it set to false
      findKeywords = kw;      //set class variable to search term
      
      
      filmDatabaseBST.inorderTraverse(testNS::keywordTest);  //traverse the tree, calling keywordTest for each 
      
      if (searchResult) //if true, display that results were found, else display no results found.
      {
         cout << "All matches for keyword " << findKeywords << " have been found." << endl << endl;
      }
      else
      {
         cout << "No matches for keyword " << findKeywords << " were found." << endl << endl;
      }
      searchResult = false;   //reset check
      
   }//end keywordSearch
   
   
   
   /**
    * Searches the database for all films prduced by a specific studio and displays the results.
    @param s studio to search for
    */
   void FilmDatabase::studioSearch(string& s)
   {
      
      searchResult = false;   //ensure check is set to false
      findStudio = s;   //set class variable to search value
      
      
      filmDatabaseBST.inorderTraverse(testNS::studioTest);   //traverse the tree, calling studioTest for each
      
      if (searchResult) //if true, display that results were found, else display no results found.
      {
         cout << "All matches for " << findStudio << " have been found." << endl << endl;
      }
      else
      {
         cout << "No matches for " << findStudio << " were found." << endl << endl;
      }
      searchResult = false;   //reset check to false 
   }//end studioSearch
   
  
   
   /**
    * Searches the database for all films realeased in a specific month and displays the results.
    @param m title of the film
    */
   void FilmDatabase::monthSearch(string& m)
   {  
      searchResult = false;   //ensure check is set to false
      findMonth = m;    //set class variable to search value
      
      
      filmDatabaseBST.inorderTraverse(testNS::monthTest); //traverse the tree, calling monthTest at each node
      
      if (searchResult) //if true, display that results were found, else display no results found.
      {
         cout << "All matches for " << findMonth << " have been found." << endl << endl;
      }
      else
      {
         cout << "No matches for " << findMonth << " were found." << endl << endl;
      }
      searchResult = false;   //reset to false
      
   }//end monthSearch
   
   /*
   //temp for test
   void FilmDatabase::displayData (void)
   {
      cout << endl << endl << "Inorder traversal" << endl;
      filmDatabaseBST.inorderTraverse(display);
      cout << endl << endl << "Preorder traversal" << endl;
      filmDatabaseBST.preorderTraverse(display);
      cout << endl << endl << "Postorder traversal" << endl;
      filmDatabaseBST.postorderTraverse(display);
      cout << endl << endl;
   }
   */
   
   