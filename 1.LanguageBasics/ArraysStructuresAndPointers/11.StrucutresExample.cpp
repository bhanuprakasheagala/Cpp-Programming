/*
The objects mine and yours are also variables with a type (of type movies_t). For example, both have been passed
to function printmovie just as if they were simple variables. Therefore, one of the features of data structures is
the ability to refer to both their members individually or to the entire structure as a whole.
In both cases using the same identifier: the name of the structure
*/
#include <iostream>
#include <string>
//#include <sstream>
using namespace std;

struct movies_t {
  string title;
  int year;
} mine, yours;

void printmovie (movies_t movie);

int main ()
{
  //string mystr;

  mine.title = "2001 A Space Odyssey";
  mine.year = 1968;

  cout << "Enter title: ";
  getline (cin,yours.title);
  cout << "Enter year: ";
//   getline (cin,mystr);
//   stringstream(mystr) >> yours.year;
  cin >> yours.year;

  cout << "My favorite movie is:\n ";
  printmovie (mine);
  cout << "And yours is:\n ";
  printmovie (yours);
  return 0;
}

void printmovie (const movies_t movie)
{
  cout << movie.title;
  cout << " (" << movie.year << ")\n";
}