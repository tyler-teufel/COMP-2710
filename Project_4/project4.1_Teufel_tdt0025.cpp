
/*
 * Tyler Teufel 
 * Project4 
 *
 * Utilized the provided hint sheet, and my textbook, "Absolute C++".
 */
//Libary imports.
#include <iostream>
#include <string>
using namespace std;
//Structure for creating a linked list that holds a trivia question,answer and point amount.

struct trivia_node {
   string question;
   string answer;
   int points;
   trivia_node *next;
};


//creates a pointer to triva_node.
typedef trivia_node* ptr_node;
//ptr_node node_list = new triva_node;
int num_of_questions = 3;

//Prototypes
void init_question_list(ptr_node&);
void add_question(ptr_node&);
int ask_question(ptr_node, int);
void Unit_Test();




//creates two versions.
//#define UNIT_TESTING
#define triva_quiz


int main() {
   //Unit_test();
   ptr_node node_list = new trivia_node;
   //string question;
   //string answer;
   //int points;
   //Creates a new trivia game /
   //Sets up three original questions/
   //Sets up loop for user to input his or her own questions.
   //Quiz questions are stored in linked list.
   #ifdef triva_quiz
   
   string answer;
   init_question_list(node_list);
   cout << "*** Welcome to Tyler's trivia quiz game ***\n";
      
   do {
      add_question(node_list);
      cout << "Continue? (Y/N): ";
      cin >> answer;
      num_of_questions++;
         
   } while (answer.compare("Y") == 0);
   if (answer.compare("Y") != 0) {
      cout << "\n";
   }
   
   //This is start of Trivia quiz game.
   ask_question(node_list, num_of_questions);
   
   cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***" << endl;
   return 0;


   #endif
   //Method for testing
   #ifdef UNIT_TESTING
   cout << "***This is a debugging version ***\n";
   Unit_Test();
   return 0;
   #endif
}
   

//initializes the quiz to have these three questions inputted into the linked list.
void init_question_list(ptr_node& q_list) {
   
   ptr_node cur_ptr = new trivia_node;
   q_list = cur_ptr;
   
   cur_ptr->question = "How long was the shortest war on record? (Hint: how many minutes)";
   cur_ptr->answer = "38";
   cur_ptr->points = 100;
   
   
   cur_ptr->next = new trivia_node;
   cur_ptr = cur_ptr->next;
   cur_ptr->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
   cur_ptr->answer = "Bank of Italy";
   cur_ptr->points = 50;
   
   cur_ptr->next = new trivia_node;
   cur_ptr = cur_ptr->next;
   cur_ptr->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)?";
   cur_ptr->answer = "Wii Sports";
   cur_ptr->points = 20;
   
   
}


//gives user the option to add a question to the linked list.
//question is added to the front of the linked list.
void add_question(ptr_node& q_list) {
   
   ptr_node new_ptr = new trivia_node;
   
   //gets data from user.
   cout << "Enter a new question: ";
   getline(cin >> ws, new_ptr->question);
   
   cout << "Enter an answer: ";
   getline(cin >> ws, new_ptr->answer);
   
   cout << "Enter award points: ";
   cin >> new_ptr->points;
   new_ptr->next = q_list;
   q_list = new_ptr;
   
   

  
}


//Checks for null value
//Ask the user trivia questions and starts the game
int ask_question(ptr_node q_list, int num_ask) {
   string user_answer;
   ptr_node cur_ptr = new trivia_node;
   cur_ptr = q_list;
   int total_points = 0;
   if (q_list == NULL) {
      return 1;
   }
   if(num_ask < 1) {
      cout << "Warning - the number of trivia to be asked must equal to or be larger than 1.";
   }  
   else if(num_of_questions < num_ask) {
      cout << "Warning - There is only " << num_of_questions << " trivia in the list.";
      return 1;
   }
   else {
      for(int x = 0; x < num_ask; x++) {
         cout << "Question: " << cur_ptr->question << endl;
         cout << "Answer: ";
         getline(cin >> ws, user_answer);
         if (user_answer.compare(cur_ptr->answer) == 0) {//correct_answer) {
            cout << "Your answer is correct. You receive " << cur_ptr->points << " points." << endl;
            total_points += cur_ptr->points;
            cout << "Your total points: " << total_points << endl << "\n";
         }
         else {
            cout << "your answer is wrong. The correct answer is: " << cur_ptr->answer << endl;
            cout << "Your total points: " << total_points << endl << "\n";
         }
         cur_ptr = cur_ptr->next;
      }
      
         
      
   }
   
   return 0;
}

//Test cases to check whether the methods work.
void Unit_Test() {
   ptr_node node_list = new trivia_node;
   init_question_list(node_list);
   cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
   ask_question(node_list, 0);
   cout << "\nCase 1 Passed\n\n";
   
   cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer. " << endl;
   ask_question(node_list, 1);
   cout << "\nCase 2.1 Passed\n\n";
   
   cout << "Unit Test Case 2.2: Ask 1 question in the linked list. the tester enters a correct answer. " << endl;
   ask_question(node_list, 1);
   cout << "\nCase 2.2 Passed\n\n";
  
   cout << "Unit Test Case 3: Ask all of the questions of the last trivia in the linked list. " << endl;
   ask_question(node_list, 3);
   cout << "\nCase 3 Passed\n\n";
   
   cout << "Unit Test Case 4: Ask 5 questions in the linked list. " << endl;
   ask_question(node_list, 5);
   cout << "\nCase 4 Passed\n\n";
   
   cout << "*** End of the Debugging Version ***";
}


