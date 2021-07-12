#include <iostream>
#include <string>
#include "include/ise102.h"
using namespace std;
using namespace fmt;
using namespace scn;

int main() {
  string title = "GIVE US YOUR DEETS";
  int year = 2021;
  int age = 0;
  string firstName = "";
  string lastName = "";

  // Print a string of dashes and go to a new line at the end with "\n"
  print("--------------------------------------------\n");
  // Print the title, using two variables. {0} is replaced
  // with the first one, "title". {1} is replaced with the second, "year".
  print("Welcome to {0} {1} \n\n", title, year);
  
  // Like with cout, we'd be asking for input before using cin.
  // Input uses the {0} substitute thing we saw with print, to say
  // take one thing from the input. It stores it in age.
  print("Alright, what's yer age: ");
  input("{0}", age);
  // input("{0} {1}", age, nickname); could have stored two variables if
  // we'd asked for them.
  
  // Prompt combines the two steps (print, input).
  // Use it to get first and last names as two variables.
  prompt("Type yer first name AND last name (with a space): ",
         "{0} {1}", firstName, lastName);
  
  // Using the variables out of order.
  print("So yer name's {0} {1}? And you're only {2}, {0}? \n",
        firstName, lastName, age);
        
  string device = "iPad Pro 2017";
  string performanceAnswer;
  print ("Mate, how's the performance in Chrome on {}?\n", device);
  prompt("Answer: ", "{}", performanceAnswer);
  print("\n");
}

  // You can apply the same thing to any string, vector or other
  // range of values like so: scan(someString, "{0} {1}", name, age);