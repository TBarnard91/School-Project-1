//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file NotFoundException.cpp */
#include "NotFoundException.h"  
using namespace std;

NotFoundException::NotFoundException(const string& message)
         : logic_error("Precondition Violated Exception: " + message)
{
}  // end constructor

// End of implementation file.

