/**
 * @file Film.h 
 * @author Tyler Barnard
 * @date  November 3, 2018
 * @class Film
 * Node type to be stored in the ADT binary search tree. It includes
 * the title (the key), rank, studio, total gross, total theaters, opening gross, opening theaters, and opening date. 
 */
#ifndef FILM_H

#include <string>
#include <fstream>
using namespace std;

class Film
{
private:
   string title; // Film title, the key
   int rank;
   string studio;
   double totalGross;
   int totalTheater;
   double openGross;
   int openTheater;
   string openDate;

   // Static class members
	/*    A static variable is shared among all instances of a class
	      and may be accessed without an instance of the class.
			Static class members MUST be defined and intialized 
			in the implementation file.
	*/

	// Output file to store the data for a film 
	 static ofstream outFile;
	 
public:
   /**
    * Default constructor
    */
   Film();

   /**
    * Overloaded constructor
    * @param newTitle - value for film's rank
    * @param newRank  - film's title; value for search key
    * @param newStudio - film's studio name
    * @param newTotalGross - value for film's total gross profit
    * @param newTotalTheater - value for film's total theater
    * @param newOpenGross - value for film's opening gross profit
    * @param newOpenTheater - value for film's opening theater
    * @param newOpenDate - date of film's release
    */
   Film( const string& newTitle, const int& newRank,
            const string& newStudio, const double& newTotalGross,
            const int& newTotalTheater, const double& newOpenGross,
            const int& openTheater, const string& newOpenDate);
   
   /**
    * Copy Constructor
    *@param copyFilm - Film object to be copied
    */
   Film( const Film &copyFilm);
   
   /**
    * Accessor for the title.
    * @return title of this film, the key
    */
   string getTitle(void);
   
   /**
    * Mutator for the title.
    * @param newTitle - title of this film, the key
    */
   void setTitle(string& newRank);
   
   /**
    * Accessor for the rank of the film
    * @return rank of this film
    */
   int getRank(void);
   
   /**
    * Mutator for the rank of the film
    * @param newRank - rank of this film
    */
   void setRank(int& newRank);
   
   /**
    * Accessor for the studio name.
    * @return name of the studio that produced this film
    */
   string getStudio(void);
   
   /**
    * Mutator for the studio name.
    * @param newStudio - name of the studio that produced this film
    */
   void setStudio(string& newStudio);
   
   /**
    * Accessor for the total gross.
    * @return total gross of this film
    */
   double getTotalGross(void);
   
   /**
    * Mutator for the total gross.
    * @parm newTotalGross - total gross of this film
    */
   void setTotalGross(double& newTotalGross);
   
   /**
    * Accessor for the total theaters.
    * @return total number of theaters
    */
   int getTotalTheater(void);
   
   /**
    * Mutator for the total theaters.
    * @param newTotalTheater - total number of theaters
    */
   void setTotalTheater(int& newTotalTheater);
   
   /**
    * Accessor for the opening gross.
    * @return opening gross of this film
    */
   double getOpenGross(void);
   
   /**
    * Mutator for the opening gross.
    * @param newOpenGross - opening gross of this film
    */
   void setOpenGross(double& newOpenGross);
   
   /**
    * Accessor for the opening theater.
    * @return name of the opening theater
    */
   int getOpenTheater(void);
   
   /**
    * Mutator for the opening theater.
    * @param newOpenTheater - name of the opening theater
    */
   void setOpenTheater(int& newOpenTheater);
   
   /**
    * Accessor for the opening date.
    * @return opening date of this film
    */
   string getOpenDate(void);
   
   /**
    * Mutator for the opening date.
    * @param newOpenDate - opening date of this film
    */
   void setOpenDate(string& newOpenDate);
   
   /**
    * Displays all the data stored for the film.
    */
   void printFilm(void);

   /**
    * Defines the > operator for a Film object. 
    * @param right - right hand Film object for comparison 
    *                to the this Film object using >
    */
   bool operator> (const Film &right);

   /**
    * Defines the < operator for a Film object. 
    * @param right - right hand Film object for comparison 
    *                to the this Film object using <
    */
   bool operator< (const Film &right);

   /**
    * Defines the == operator for a Film object. 
    * @param right - right hand Film object for comparison 
    *                to the this Film object using ==
    */
   bool operator== (const Film &right);
  
}; // end Student
#define Film_H
#endif
