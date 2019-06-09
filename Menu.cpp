/*
 * @file Menu.cpp
 * @author Tyler Barnard
 * @date November 3, 2018
 * The Menu class displays several user menus, and calls
 * appropriate methods from the FilmDatabase based upon
 * user input.
 */
#include "FilmDatabase.h"
#include "Menu.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

   Menu::Menu()
   {
   
   }//end default constructor
   
   // Method to display the Main Menu options
   void Menu::displayMenu(FilmDatabase& aDatabase)
   {
      char entry; // variable to hold user selection
      
      while ((entry != 'x') && (entry != 'X'))
      {
         cout << "      MAIN MENU" << endl;
         cout << "D - Describe the Program" << endl;
         cout << "R -  Reports" << endl;
         cout << "S - Search the Database" << endl;
         cout << "X - Exit the Program" << endl << endl;
         cout << "Enter Selection ->" << endl;
      
         
         cin >> entry;  //get user entry
         
         //check if user entry was valid and call appropriate menu
         switch (entry)
         {
            case 'D':
            case 'd':
               describeProgram();
               break;
            case 'R':
            case 'r':
               reportsMenu(aDatabase);
               break;
            case 'S':
            case 's':
               searchMenu(aDatabase);
               break;
            case 'X':
            case 'x':
               ;
               break;
            default:
               cout << "Invalid option. Please select a valid option." << endl;
         }//end switch
      }//end while
   }//end displayMenu
   
   // Displays a description of the program
   void Menu::describeProgram()
   {
      cout << endl << "This program creates a database containing the 100 highest grossing films of 2015." << endl;
      cout << "The rank, title, studio, total gross, total theaters, opening gross, opening theaters, and opening date are available for each film." << endl;
      cout << "You may search the database for specific films or all films matching specific criteria." << endl;
      cout << "You may also create a report that includes all the information stored in the database, organized by either rank or title." << endl << endl << endl;
   
   }//end describeProgram
   
   /*
      Displays the Reports Menu options, and allows the user to 
      display a list based on film rank or title.
   */
   void Menu::reportsMenu(FilmDatabase& aDatabase)
   {
      char entry; //variable to hold user selection
      
      while ((entry != 'x') && (entry != 'X'))
      {
         cout << "      REPORTS MENU" << endl;
         cout << "T - Order by Film Title report" << endl;
         cout << "R - Order by Rank report" << endl;
         cout << "X - Return to Main Menu" << endl;
      
         
         cin >> entry;  //get user selection
         
         //check user entry and call appropriate method
         switch (entry)
         {
            case 'T':
            case 't':
               aDatabase.titleReport();
               break;
            case 'R':
            case 'r':
               aDatabase.rankReport();
               break;
            case 'x':
            case 'X':
               cout << endl << "Returning to main menu" << endl;
            default:
            cout << "Invalid option. Please select a valid option." << endl;
         }//end switch   
      }//end while
   }//end reportsMenu
   
   /*
      Displays the Serch Menu, and allow the user to search the database for 
      a speicific film based on title, keyoword(s), studio, or month of release.
   */
   void Menu::searchMenu(FilmDatabase& aDatabase)
   {
      char entry; // variable to hold user selection
      
      while ((entry != 'x') && (entry != 'X'))
      {
         cout << endl << "    Search Menu" << endl;
         cout << "T - Search by Title" << endl;
         cout << "K - Search by Keyword(s)" << endl;
         cout << "M - Search by Month of Release" << endl;
         cout << "S - Search by Studio" << endl;
         cout << "X - Return to Main Menu" << endl;
         
         
         cin >> entry;  //get user selection
         cin.ignore();  
         
         switch (entry)
         {
            case 'T':
            case 't':
            {
               Film searchFilm;  //object to use for search
               string findTitle; //title to search database for
               
               cout << "Please enter the title you want to search for." << endl;
               
               getline (cin, findTitle);  //retrieve the full title to search for
               
               findTitle[0] = toupper(findTitle[0]);  //if first letter is lowercase, the overloaded == operator function is skipped for some reason that I haven't figured out.
               
               searchFilm.setTitle(findTitle);     //set Film title to search input
               aDatabase.titleSearch(searchFilm);  
            }
               break;
            case 'K':
            case 'k':
            {  string findKeywords;
            
               cout << "Please enter the keyword you want to search for." << endl;
               cout << "If you wish to search for multiple keywords, seperate each with a comma (,)." << endl;
               cout << "Example Entry: word1,word2,word3" << endl;
               
               getline (cin, findKeywords);
               
               //make stringstream, tokenize and call function below for each
               istringstream iss1 (findKeywords); //stringstream to parse input
                  
               string token;  //variable to hold one word
                 
               getline(iss1, token, ',');  //get first value using , as delimiter
               while (iss1)   //loop through each token and search for them
               {  
                  aDatabase.keywordSearch(token);  //search for matches
                  getline(iss1, token, ','); //move to next line
               }
               
            }
               break;
            case 'S':
            case 's':
               {
                  string findStudio;
            
                  cout << "Please enter the studio you want to search for." << endl;
                  
                  getline (cin, findStudio); //retrieve input from user, and set string to search term
                  
                  aDatabase.studioSearch(findStudio);
               
               }
               break;
            case 'M':
            case 'm':
               {
                  string findMonth = "0";
                  bool check;
                  
                  cout << endl << "Please enter the release month (1-12) you want to search for." << endl;
                  getline (cin, findMonth);  //retrieve user input and set string to search term
                  
                  //verify that month is 1 or 2 characters long
                  check = ((findMonth.size() < 3 ) && (findMonth.size() > 0));
                  while (!check)
                  {
                     cout << endl << "Invalid format. Please enter month, (1-12)." << endl;
                     getline (cin, findMonth);  //retrieve user input and set string to search term
                     check = ((findMonth.size() < 3 ) && (findMonth.size() > 0));
                  }
                     aDatabase.monthSearch(findMonth);   //call function to search for matching Film objects
               }
               break;
            case 'x':
            case 'X':
               cout << endl << "Returning to main menu" << endl << endl;
               break;
            default:
               cout << "Invalid option. Please select a valid option." << endl;
         }//end switch   
      }//end while
   }//end searchMenu