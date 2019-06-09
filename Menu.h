/**
 * @file Menu.h 
 * @author Tyler Barnard
 * @date  November 3, 2018
 * @class Menu
 * The Menu class displays several user menus, and calls
 * appropriate methods from the FilmDatabase based upon
 * user input.
 */
#ifndef MENU_H

#include "FilmDatabase.h"
#include <string>
#include <fstream>
using namespace std;

class Menu
{
private:
  	 
public:
   /**
    * Default constructor
    */
   Menu();
   
   /**
   *Displays the Main Menu and allows the user to choose what they want to do
   */
   void describeProgram(void);
   
   /**
   *Displays the Main Menu and allows the user to choose what they want to do
   */
   void displayMenu(FilmDatabase& aDatabase);
   
   /**
   *Displays the Reports Menu and allows the user to produce a report
   */
   void reportsMenu(FilmDatabase& aDatabase);
   
   /**
   *Displays the Main Menu and allows the user to search the database
   */
   void searchMenu(FilmDatabase& aDatabase);
     
}; // end Menu
#define MENU_H
#endif
