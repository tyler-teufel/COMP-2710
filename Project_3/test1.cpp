//Sample code for Project 3
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
const int MAX_SIZE = 100;

//Input: (1) Array storing data retrieved from the file (i.e., instream)
//       (2) input file stream object
//Output: Size of array. Note: you need to use this parameter to control the array size.
int readfile(vector<int> input, ifstream& inStreamFirst);
int main( )
{
   ifstream inStream1;
   /*
   int iArray1[MAX_SIZE];
   int iArray1_size;
   int iArray2[MAX_SIZE];
   int iArray2_size;
   */
   int num;
   vector<int> v;
   //string fileName;
   string fileName = "input1-1.txt";
   inStream1.open(fileName);
   if (inStream1.fail())
   {
      cout << "File cannot open\n";
      return 0;
   }
   
   while (!inStream1.fail() && !inStream1.eof()) 
   {
      inStream1 >> num;
      v.push_back(num);
      
   }
   inStream1.close();
   
   for (unsigned int i = 0; i < v.size() - 1; i++) {
      cout << v[i] << endl;
      
   }
}

/*
int readfile(vector<int> input, ifstream& inStream){
   int index;
   inStream >> input;
   while (! inStream.eof()) {
      cout << input.pushBack( << endl;
      index++;
      inStream >> inputArray[index];
   }
   return index;
}
*/