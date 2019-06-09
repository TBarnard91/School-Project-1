//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file NotFoundException.h */

#ifndef _NOT_FOUND_EXCEPTION
#define _NOT_FOUND_EXCEPTION

#include <stdexcept>
#include <string>
using namespace std;

class NotFoundException : public logic_error
{
public:
   NotFoundException(const string& message = "");
}; // end NotFoundException 
#endif
