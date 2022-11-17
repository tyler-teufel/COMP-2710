/* FILE NAME: project2_Teufel_tdt0025.cpp
 * AUTHOR: Tyler Teufel
 * 
 * g++ to compile code.
 * Used the hint sheet provided by instructor.
 */

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>

using namespace std;

/*
 * Input: A_alive indicates Aaron is alive true for alive, false for dead
 *        B_alive indicates Bob is alive
 *        C_alive indicates Charlie is alive
 * Return: true if at least two are alive otherwise return false
 */
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);


/*
 * Call by reference
 * Strategy 1: Everyone shoots to kill the highest accuracy player alive
 * Input: B_alive indicates Bob is alive or dead
 *        C_alive indicates Aaron is alive or dead
 * Return: Change B_alive into false if Bob is killed
 *         Change C_alive into false if Charlie is killed
 */
void Aaron_shoots1(bool& B_alive, bool& C_alive);


/*
 * Call by reference
 * Input: A_alive indicates Aaron is alive or dead
 *        C_alive indicates Charlie is alive or dead
 * Return: Change A_alive into false if Aaron is killed
 *         Change C_alive into false if Charlie is killed
 */
void Bob_shoots(bool& A_alive, bool& C_alive);


/*
 * Call by reference
 * Input: A_alive indicates Aaron is alive or dead
 *        B_alive indicates Bob is alive or dead
 * Return: Change A_alive into false if Aaron is killed
 *         Change B_alive into false if Bob is killed
 */
void Charlie_shoots(bool& A_alive, bool& B_alive);


/*
 * Call by reference
 * Strategy 2: Aaron intentionally misses if both are alive
 * Input: B_alive indicates Bob is alive or dead
 *        C_alive indicates Aaron is alive or dead
 * Return: Change B_alive into false if Bob is killed
 *         Change C_alive into false if Charlie is killed
 */
void Aaron_shoots2(bool& B_alive, bool& C_alive);


//Simple method to implement pause function in linux
void Press_any_key(void);


//TEST PROTOTYPES
void test_at_least_two_alive(void);
void test_Aaron_shoots1(void);
void test_Bob_shoots(void);
void test_Charlie_shoots(void);
void test_Aaron_shoots2(void);


//VARIABLES
const int TOTAL_RUNS = 10000;
const int AARON_PROB = 33;
const int BOB_PROB = 50;
const int CHARLIE_PROB = 100;

bool aaronAlive;
bool bobAlive;
bool charlieAlive;
bool aaronFirstShot = true;

bool aimAtAaron = false;
bool aimAtBob = false;
bool aimAtCharlie = false;


int bobWins;
int aaronWins2;
int aaronWins1;
int charlieWins;


int main() {
   //Initializes Random number generator's seed and calls test functions
   cout << "*** Welcome to Tyler's Duel Simulator ***\n";
   
   srand(time(0));
   test_at_least_two_alive();
   Press_any_key();
   
   test_Aaron_shoots1();
   Press_any_key();
   
   test_Bob_shoots();
   Press_any_key();
   
   test_Charlie_shoots();
   Press_any_key();
   
   test_Aaron_shoots2();
   Press_any_key();
   
   //Starts strategy 1 and runs 10,000 times
   cout << "Ready to test strategy 1 (run 10000 times):\n";
   Press_any_key();
   for (int i = 0; i < TOTAL_RUNS; i++ ) {
      aaronAlive = true;
      bobAlive = true;
      charlieAlive = true;
      while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
         if (aaronAlive) {
            Aaron_shoots1(bobAlive, charlieAlive);
            aimAtAaron = false;
            aimAtBob = false;
            aimAtCharlie = false;
         }
         if (bobAlive) {
            Bob_shoots(aaronAlive, charlieAlive);
            aimAtAaron = false;
            aimAtBob = false;
            aimAtCharlie = false;
         }
         if (charlieAlive) {
            Charlie_shoots(aaronAlive, bobAlive);
            aimAtAaron = false;
            aimAtBob = false;
            aimAtCharlie = false;
         }
      }
   
      if (aaronAlive) 
         aaronWins1++;
   
      if (bobAlive) 
         bobWins++;
   
      if (charlieAlive) 
         charlieWins++;
   }
   
   cout << "Aaron won " << aaronWins1 << "/10000 duels or " << static_cast<double>(aaronWins1) /
      TOTAL_RUNS * 100 << "%\n"
      << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS
      * 100 << "%\n"
      << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) /
      TOTAL_RUNS * 100 << "%\n"
      << endl;
   
   //Reinitializes variables and starts strategy 2 to run 10,000 times
   aaronAlive = true;
   bobAlive = true;
   charlieAlive = true;
   

   bobWins = 0;
   aaronWins2 = 0;
   charlieWins = 0;
   
   cout << "Ready to test strategy 2 (run 10000 times):\n";
   Press_any_key();
   
   for (int i = 0; i < TOTAL_RUNS; i++) {
      aaronAlive = true;
      bobAlive = true;
      charlieAlive = true;
      
      while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
         
         if (aaronAlive) {
            Aaron_shoots2(bobAlive, charlieAlive);
            aimAtAaron = false;
            aimAtBob = false;
            aimAtCharlie = false;
         }
         if (bobAlive) {
            Bob_shoots(aaronAlive, charlieAlive);
            aimAtAaron = false;
            aimAtBob = false;
            aimAtCharlie = false;
         }
         if (charlieAlive) {
            Charlie_shoots(aaronAlive, bobAlive); 
            aimAtAaron = false;
            aimAtBob = false;
            aimAtCharlie = false;
         }
      }
      if (aaronAlive)
         aaronWins2++;
         
      if (bobAlive)
         bobWins++;
         
      if (charlieAlive)
         charlieWins++;
      aaronFirstShot = true;
   }
   cout << "Aaron won " << aaronWins2 << "/10000 duels or " << static_cast<double>(aaronWins2) /
         TOTAL_RUNS * 100 << "%\n"
      << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS
         * 100 << "%\n"
      << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) /
         TOTAL_RUNS * 100 << "%\n"
      << endl;
   if (aaronWins1 > aaronWins2) {
      cout << "Strategy 1 is better than strategy 2.\n";
   }
   else {
      cout << "Strategy 2 is better than strategy 1.\n";
   }
   return 0;
}


//Implementation of functions. Look above for documentation of them.
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
   int liveCount = 0;
   if (A_alive) 
      liveCount++;
   
   if (B_alive) 
      liveCount++;
      
   if (C_alive)
      liveCount++;
      
   if (liveCount >= 2) 
      return true;
   
   else 
      return false;
   
}

void test_at_least_two_alive(void) {
   cout << "Unit Testing 1: Function - at_least_two_alive()\n";
   cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, true));
   cout << "\tCase passed ...\n";
   cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(false, true, true));
   cout << "\tCase passed ...\n";
   cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
   assert(true == at_least_two_alive(true, false, true));
   cout << "\tCase passed ...\n";
   cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
   assert(true == at_least_two_alive(true, true, false));
   cout << "\tCase passed ...\n";
   cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
   assert(true == !at_least_two_alive(false, false, true));
   cout << "\tCase passed ...\n";
   cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
   assert(true == !at_least_two_alive(false, true, false));
   cout << "\tCase passed ...\n";
   cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
   assert(true == !at_least_two_alive(true, false, false));
   cout << "\tCase passed ...\n";
   cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
   assert(true == !at_least_two_alive(false, false, false));
   cout << "\tCase passed ...\n";
   //Press_any_key();
   
}

void Aaron_shoots1(bool& B_alive, bool& C_alive) {
   assert(true == (B_alive || C_alive));
   //bool aimAtAaron = false;
   //bool aimAtBob = false;
   //bool aimAtCharlie = false;
   
   int shootResult = rand() % 100;
   if (C_alive) {
      aimAtCharlie = true;
      if (shootResult <= AARON_PROB)
         charlieAlive = false;
   }
   else {
      aimAtBob = true;
      if (shootResult <= AARON_PROB)
         bobAlive = false;
   }
   
}

void test_Aaron_shoots1(void) {
   cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
   
   bool bob_a = true;
   bool charlie_a = true;
   cout << "\tCase 1: Bob alive, Charlie alive\n"
      << "\t\tAaron is shooting at Charlie\n";
   Aaron_shoots1(bob_a, charlie_a);
   assert(true == (aimAtCharlie));
   
   bob_a = false;
   charlie_a = true;
   cout << "\tCase 2: Bob dead, Charlie alive\n"
      << "\t\tAaron is shooting at Charlie\n";
   Aaron_shoots1(bob_a, charlie_a);
   assert(true == (aimAtCharlie));
   
   bob_a = true;
   charlie_a = false;
   cout << "\tCase 3: Bob alive, Charlie dead\n"
      << "\t\tAaron is shooting at Bob\n";
   Aaron_shoots1(bob_a, charlie_a);
   assert(true == (aimAtBob));
   //Press_any_key();
}

void Bob_shoots(bool& A_alive, bool& C_alive) {
   assert(true == (A_alive || C_alive));
   
   //bool aimAtAaron = false;
   //bool aimAtBob = false;
   //bool aimAtCharlie = false;
   
   int shootResult = rand() % 100;
   if (C_alive) {
      aimAtCharlie = true;
      if (shootResult <= BOB_PROB)
         charlieAlive = false;
   }
   else {
      aimAtAaron = true;
      if (shootResult <= BOB_PROB)
         aaronAlive = false;
   }
}

void test_Bob_shoots(void) {
   cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
   
   bool aaron_a = true;
   bool charlie_a = true;
   cout << "\tCase 1: Aaron alive, Charlie alive\n"
      << "\t\tBob is shooting at Charlie\n";
   Bob_shoots(aaron_a, charlie_a);
   assert(true == (aimAtCharlie));
   
   aaron_a = false;
   charlie_a = true;
   cout << "\tCase 2: Aaron dead, Charlie alive\n"
      << "\t\tBob is shooting at Charlie\n";
   Bob_shoots(aaron_a, charlie_a);
   assert(true == (aimAtCharlie));
   
   aaron_a = true;
   charlie_a = false;
   cout << "\tCase 3: Aaron alive, Charlie dead\n"
      << "\t\tBob is shooting at Aaron\n";
   Bob_shoots(aaron_a, charlie_a);
   assert(true == (aimAtAaron));
   //Press_any_key();
}

void Charlie_shoots(bool& A_alive, bool& B_alive) {
   assert(true == (A_alive || B_alive));
   
   //bool aimAtAaron = false;
   //bool aimAtBob = false;
  // bool aimAtCharlie = false;

   if (B_alive) {
      aimAtBob = true;
      bobAlive = false;
   }
   else {
      aimAtAaron = true;
      aaronAlive = false;
   }
}

void test_Charlie_shoots(void) {
   
   cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
   
   aimAtAaron = false;
   aimAtBob = false;
   aimAtCharlie = false;
   bool aaron_a = true;
   bool bob_a = true;
   cout << "\tCase 1: Aaron alive, Bob alive\n"
      << "\t\tCharlie is shooting at Bob\n";
   Charlie_shoots(aaron_a, bob_a);
   assert(true == (aimAtBob));
   
   aimAtAaron = false;
   aimAtBob = false;
   aimAtCharlie = false;
   aaron_a = false;
   bob_a = true;
   cout << "\tCase 2: Aaron dead, Bob alive\n"
      << "\t\tCharlie is shooting at Bob\n";
   Charlie_shoots(aaron_a, bob_a);
   assert(true == (aimAtBob));
   
   aimAtAaron = false;
   aimAtBob = false;
   aimAtCharlie = false;
   aaron_a = true;
   bob_a = false;
   cout << "\tCase 3: Aaron alive, bob dead\n"
      << "\t\tCharlie is shooting at Aaron\n";
   Charlie_shoots(aaron_a, bob_a);
   assert(true == (aimAtAaron));
   //Press_any_key();
}

void Aaron_shoots2(bool& B_alive, bool& C_alive) {
   assert(true == (B_alive || C_alive));
   //bool aimAtAaron = false;
   //bool aimAtBob = false;
   //bool aimAtCharlie = false;
   
   if (aaronFirstShot == false) {
      /* bobAlive = true;
      charlieAlive = true;
      aaronFirstShot = false;
      */
      int shootResult = rand() % 100;
      if (C_alive) {
         aimAtCharlie = true;
         if (shootResult <= AARON_PROB)
            charlieAlive = false;
      }
      else {
         aimAtBob = true;
         if (shootResult <= AARON_PROB)
            bobAlive = false;
      }
      
   }
   else {
      bobAlive = true;
      charlieAlive = true;
      aaronFirstShot = false;
      /*
      int shootResult = rand() % 100;
      if (C_alive) {
         aimAtCharlie = true;
         if (shootResult <= AARON_PROB)
            charlieAlive = false;
      }
      else {
         aimAtBob = true;
         if (shootResult <= AARON_PROB)
            bobAlive = false;
      }
      */
   
   
   }
}

void test_Aaron_shoots2(void) {
   
   cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
   
   aimAtAaron = false;
   aimAtBob = false;
   aimAtCharlie = false;
   bool bob_a = true;
   bool charlie_a = true;
   cout << "\tCase 1: Bob alive, Charlie alive\n"
      << "\t\tAaron intentionally misses his first shot\n"
      << "\t\tBoth Bob and Charlie are alive.\n";
   Aaron_shoots2(bob_a, charlie_a);
   assert(true == !(aimAtCharlie && aimAtBob));
   
   
   aimAtAaron = false;
   aimAtBob = false;
   aimAtCharlie = false;
   bob_a = false;
   charlie_a = true;
   cout << "\tCase 2: Bob dead, Charlie alive\n"
      << "\t\tAaron is shooting at Charlie\n";
   Aaron_shoots2(bob_a, charlie_a);
   assert(true == (aimAtCharlie));
   
   aimAtAaron = false;
   aimAtBob = false;
   aimAtCharlie = false;
   bob_a = true;
   charlie_a = false;
   cout << "\tCase 3: Bob alive, Charlie dead\n"
      << "\t\tAaron is shooting at Bob\n";
   Aaron_shoots2(bob_a, charlie_a);
   assert(true == (aimAtBob));
   //Press_any_key();
   
}

void Press_any_key(void) {
   cout << "Press any key to continue...\n";
   cin.get();
}