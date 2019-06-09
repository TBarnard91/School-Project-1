/**
 * @file Film.cpp
 * @author Tyler Barnard
 * @date  November 3, 2018
 * Implementation of the Film class
 * Node type to be stored in the ADT binary search tree. It includes
 * the title (the key), rank, studio, total gross, total theaters, opening gross, opening theaters, and opening date.
 */
#include "Film.h"
#include <iostream>
#include <iomanip>


using namespace std;

/**
    * Default constructor
    */
   Film::Film()
   {
   
   }//end default constructor

   /**
    * Overloaded constructor
    * @param newRank - newtitle - film's title; value for search key
    * @param newTitle - value for film's rank
    * @param newStudio - film's studio name
    * @param newTotalGross - value for film's total gross profit
    * @param newTotalTheater - value for film's total theater
    * @param newOpenGross - value for film's opening gross profit
    * @param newOpenTheater - value for film's opening theater
    * @param newOpenDate - date of film's release
    */
   Film::Film( const string& newTitle,  const int& newRank,
            const string& newStudio, const double& newTotalGross,
            const int& newTotalTheater, const double& newOpenGross,
            const int& newOpenTheater, const string& newOpenDate)
   {
      title = newTitle;
      rank = newRank;
      studio = newStudio;
      totalGross = newTotalGross;
      totalTheater = newTotalTheater;
      openGross = newOpenGross;
      openTheater = newOpenTheater;
      openDate = newOpenDate;
   }//end overloaded constructor
   
   /**
    * Copy Constructor
    *@param copyFilm - Film object to be copied
    */
   Film::Film(const Film& copyFilm)
   {
      rank = copyFilm.rank;
      title = copyFilm.title;
      studio = copyFilm.studio;
      totalGross = copyFilm.totalGross;
      totalTheater = copyFilm.totalTheater;
      openGross = copyFilm.openGross;
      openTheater = copyFilm.openTheater;
      openDate = copyFilm.openDate;
   }
   
   /**
    * Accessor for the title.
    * @return title of this film, the key
    */
   string Film::getTitle(void)
   {
      return title;
   }//end getTitle
   
   /**
    * Mutator for the title.
    * @param newTitle - title of this film
    */
   void Film::setTitle(string& newTitle)
   {
      title =  newTitle;
   }//end setTitle
   
   /**
    * Accessor for the rank of the film
    * @return rank of this film
    */
   int Film::getRank(void)
   {
      return rank;
   }//end getRank
   
   /**
    * Mutator for the rank.
    * @param newRank - rank of this film
    */
   void Film::setRank(int& newRank)
   {
      rank = newRank;
   }//end setRank
   
   /**
    * Accessor for the studio name.
    * @return name of the studio that produced this film
    */
   string Film::getStudio(void)
   {
      return studio;
   }//end getStudio
   
   /**
    * Mutator for the studio name.
    * @param newStudio - name of the studio that produced this film
    */
   void Film::setStudio(string& newStudio)
   {
      studio = newStudio;
   }//end setStudio

   /**
    * Accessor for the total gross.
    * @return total gross of this film
    */
   double Film::getTotalGross(void)
   {
      return totalGross;
   }//end getTotalGross
   
   /**
    * Mutator for the total gross.
    * @param newTotalGross - total gross of this film
    */
   void Film::setTotalGross(double& newTotalGross)
   {
      totalGross = newTotalGross;
   }//end setTotalGross
   
   /**
    * Accessor for the total theaters.
    * @return total number of theaters
    */
   int Film::getTotalTheater(void)
   {
      return totalTheater;
   }//end getTotalGross
   
   /**
    * Mutator for the total theaters.
    * @param newTotalTheater - total number of theaters
    */
   void Film::setTotalTheater(int& newTotalTheater)
   {
      totalTheater = newTotalTheater;
   }//end setTotalGross
   
   /**
    * Accessor for the opening gross.
    * @return opening gross of this film
    */
   double Film::getOpenGross(void)
   {
      return openGross;
   }//end getOpenGross
   
   /**
    * Mutator for the opening gross.
    * @param newOpenGross - opening gross of this film
    */
   void Film::setOpenGross(double& newOpenGross)
   {
      openGross = newOpenGross;
   }//end setOpenGross
   
   /**
    * Accessor for the opening theater.
    * @return name of the opening theater
    */
   int Film::getOpenTheater(void)
   {
      return openTheater;
   }//end getOpenTheater
   
   /**
    * Mutator for the opening theater.
    * @param newOpenTheater = name of the opening theater
    */
   void Film::setOpenTheater(int& newOpenTheater)
   {
      openTheater = newOpenTheater;
   }//end setOpenTheater
   
   /**
    * Accessor for the opening date.
    * @return opening date of this film
    */
   string Film::getOpenDate(void)
   {
      return openDate;
   }//end getOpenDate
   
   /**
    * Mutator for the opening date.
    * @param openDate - opening date of this film
    */
   void Film::setOpenDate(string& newOpenDate)
   {
      openDate = newOpenDate;
   }//end setOpenDate
   
   /**
    * Displays all the data stored for a student.
    */
   void Film::printFilm(void)
   {
      cout << left;
      cout << fixed << setprecision(2) << setw(5) << rank << setw(42) << title << setw(7) << studio << setw(14) << totalGross << setw(8);
      cout << totalTheater << setw(15) << openGross << setw(8) <<  openTheater <<  setw(8) << openDate << endl;
   }//end printFilm

   /**
    * Defines the > operator for a Film object. 
    * @param right - right hand Film object for comparison 
    *                to the this Film object using >
    */
   bool Film::operator> (const Film &right)
   {
      return (title > right.title);
   }//end operator>

   /**
    * Defines the < operator for a Film object. 
    * @param right - right hand Film object for comparison 
    *                to the this Film object using <
    */
   bool Film::operator< (const Film &right)
   {
      return (title > right.title);
   }//end operator<

   /**
    * Defines the == operator for a Film object. 
    * @param right - right hand Film object for comparison 
    *                to the this Film object using ==
    */
   bool Film::operator== (const Film &right)    // Still won't find a match if first letter of title is lowercase. Ex. Minions, MINIONS, MiNiOnS all match Minions, but mINIONS or minions will come up false.
   {                                            // Identical function in standalone program works perfectly. If the first letter is lowercase, then the function appears to skipped completely for some reason.
      string title1 = title;
      string title2 = right.title;
      
      char ch1 = ' ';
      char ch2 = ' ';
      bool check = true;
      
      //check each character from title1 against a character in title2
      for (int i = 0; i < title2.size(); i++)
      {  //verify that check has not been declared false and the characters are alphanumeric
         if (check && isalpha(title1[i]) && isalpha(title2[i]))
         {
            //set each character to lowercase
            ch1 = tolower(title1[i]);
            ch2 = tolower(title2[i]);
 
            //if the characters are not even, set check to false
            if (!(ch1 == ch2))
               {
                  check = false;
               }//end if
         }
      }//end for

      return (check);
   }//end operator==