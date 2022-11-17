
/* FILE NAME: project3_Teufel_tdt0025.cpp
 * AUTHOR: Tyler Teufel
 * 
 * g++ to compile code.
 * Used the hint sheet provided by instructor.
 */
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

vector<int> numbers1;
vector<int> numbers2;
/* check_file
 * 
 * Checks to see if the file opened correctly.
 *
 * @param string is the file name.
 * @return false if it fails, else true.
 *
 */
bool check_file(string);


/* to_string2
 *
 * For the tedious formatting required for the sorted values in the UI.
 *
 */
void to_string2(vector<int> v);

/* read_file
 *
 * Takes in a file and reads the values into a vector.
 *
 * @param string takes in a file name.
 * 
 */
vector<int> read_file(string);


/* write_file
 *
 * Creates a new file with the intended data from the vector.
 *
 * @param string enterss a file name.
 * @param vector<int> takes in the data.
 *
 */
void write_file(string, vector<int>);


/* merge
 *
 * returns a vector of merged & sorted data.
 *
 * @param vector<int> takes in the first file's data.
 * @param vector<int> takes in the second file's data.
 */
vector<int> merge(vector<int>, vector<int>);



/*
 * Display the values of a given vector.
 * 
 * Param: file Name of file to display. (string)
 * Param: v Vector containing values to display. (vector<int>)
 */
void to_string(vector<int> v);



/*
* Merge the numbers in two specified files and write all the numbers
* to a specified third file sorted in ascending order.
*
* Return: 1 Program completed successfully. (int)
*/
int main() {
  
   /* declare your variables */
   
   string file1;
   string file2;  
   string file3;
   ifstream stream;
   vector<int> numbers3;
   
   /* Get name of file one. */
   do {
      
      /* user friendly interfaces */
      cout << "*** Welcome to Tyler's sorting program ***\n";
      cout << "Enter the first input file name: ";
      cin >> file1;
   
   } while (cin.fail() || !check_file(file1));
   
   /* Get and display numbers from file one. */
   numbers1 = read_file(file1);
   cout << "\nThe list of " << numbers1.size() << " numbers in file " << file1 << " is:\n";
   to_string(numbers1);
   
   /* Get name of file two. */
   do {
   /* user friendly interfaces */
      cout << "\nEnter the second input file name: ";
      cin >> file2;
   
   } while (cin.fail() || !check_file(file2));
   /* Get and display numbers from file two. */
   numbers2 = read_file(file2);
   cout << "\nThe list of " << numbers2.size() << " numbers in file " << file2 << " is:\n";
   to_string(numbers2);
   
   /* Combine vectors and display the sorted result. */
   numbers3 = merge(numbers1, numbers2);
   cout << "\nThe sorted list of " << numbers3.size() << " numbers is: ";
   to_string2(numbers3);
   /* Get name of output file. */
   do {
   /* user friendly interfaces */
      cout << "\nEnter the name of the output file: ";
      cin >> file3;
      
   } while (cin.fail());
   /* Write combined vector to output file. */
   write_file(file3, numbers3);
   cout << "*** Please check the new file - " << file3 << " ***\n*** Goodbye. ***\n";
   return 1;
}

bool check_file(string file) {
   
   /* Input file stream. (ifstream) */
   ifstream stream;
   
   /* Check whether file exists. */
   stream.open((char*)file.c_str());
   if (stream.fail()) {
      return false;
   }
   stream.close();
   return true;
}

vector<int> read_file(string file) {
   /* Input file stream. (ifstream) */
   ifstream stream;
   /* Vector containing numbers from file. (vector<int>) */
   vector<int> v;
   /* Integer read from file. (int) */
   int i;
   /* Add each number in the file to a vector. */
   stream.open((char*)file.c_str());
   
   stream >> i;
   while (stream.good()) {
      v.push_back(i);
      //cout << i << endl;
      stream >> i;
   }
   stream.close();
   return v;
}
void write_file(string file, vector<int> v) {
/* Output file stream. (ofstream) */
   ofstream newFile;
   newFile.open((char*)file.c_str());
   
   for (unsigned int i = 0; i < v.size(); i++)
   {
      newFile << v[i] << endl;
   }
   newFile.close();
}
vector<int> merge(vector<int> v1, vector<int> v2) {
   vector<int> v3;
   unsigned int index1 = 0;
   unsigned int index2 = 0;
   /* Compare both vectors. */
   while (index1 < v1.size() && index2 < v2.size()) {
      if (v1[index1] > v2[index2]) {
         v3.push_back(v2[index2]);
         index2++;
      } 
      else {
         v3.push_back(v1[index1]);
         index1++;
      }
   }
   /* Add any remaining numbers from vector one. */
   if (v1.size() > index1) {
      while (index1 < v1.size()) {
         v3.push_back(v1[index1]);
         index1++;
      }
   }
   /* Add any remaining numbers from vector two. */
   if (v2.size() > index2) {
      while (index2 < v2.size()) {
         v3.push_back(v2[index2]);
         index2++;
      }
   }
   return v3;
}

void to_string(vector<int> v) {
  
   for (unsigned int i = 0; i < v.size(); i++)
   {
      cout << v[i] << endl;
   }
   
   
   
}


void to_string2(vector<int> v) {
  
   for (unsigned int i = 0; i < v.size(); i++)
   {
      cout << v[i] << " ";
   }
}
