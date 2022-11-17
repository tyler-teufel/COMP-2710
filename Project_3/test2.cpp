/* FILE NAME: TestingSegments.cpp
* AUTHOR: Tyler Teufel
* 
* g++ to compile code.
* Used the hint sheet provided by instructor.
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
#include <vector>
using namespace std;
vector<int> read_file(string file);
int main()
{
   vector<int> vals;
   
   ifstream inStream;
   int data;
   string filename;
   cout << "*** Welcome to Tyler's sorting program ***\n";
   cout << "Enter the first input file name:";
   cin >> filename;
   cout << "entered filename is:" << filename << endl;
   vals = read_file(filename);
   
   // Pass the file name as an array of chars to open()
   // inStream.open(filename);
   /*
   inStream.open((char*)filename.c_str());
   if (inStream.fail()) {
      cout << "Input file opening failed." << endl;
      exit(1);
   }
   inStream >> data;
   while (!inStream.eof()) {
      cout << data << endl;
      inStream >> data;
   }
   inStream.close();
   return 0;
   */
   
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
      stream >> i;
   }
   stream.close();
   return v;
}