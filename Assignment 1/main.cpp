// NAME: Minh Nguyen
// DATE: 10/3/2021
// VERSION: 1

#include <iostream>
#include <string>
#include "management.h"

using namespace std;

const int ADD = 1; // const value for menu for user to add animal
const int GET = 2; // const value for menu for user to get animal
const int QUIT = 3; // const value for menu for user to quit
const char YES = 'y'; // const char to continue function
const char NO = 'n'; // const char to stop function
const string CAT = "cat"; // const string for "cat" to compare type
const string DOG = "dog"; // const string for "dog" to compare type

int main()
{
  Queue q; // animal queue
  string name, type; // user input variables
  string tempName, tempType, adopt; // temp values to determine which animal
                                    // to adopt and cout to the screen
  int tempSize; // temp int value to hold the size of the queue
  char ans = 'y'; // user input (y/n) to continue or stop
  int choice = 0; // user input to choose animal preference
  int menuChoice = 0; // user input for menu choice
  bool found = false; // boolean to check if a cat or dog was found

  // while user wants to play
  while (menuChoice != QUIT){
    menuChoice = 0;
    // menu prompt
    while (menuChoice < ADD || menuChoice > QUIT){
      cout << endl;
      cout << "Menu" << endl;
      cout << ADD << ". Add animal" << endl;
      cout << GET << ". Get animal" << endl;
      cout << QUIT << ". Quit" << endl << endl;
      cout << "Choose 1, 2, or 3. Choice? ";
      cin >> menuChoice;
      cin.get();
      cout << endl;
    }
    
    // menu selection 1 for adding animal
    if (menuChoice == ADD){
      while (ans == YES){
        cout << "What animal do you want to add (cat or dog): ";
        cin >> type;
        cout << "What name do you want to give this " << type << ": ";
        cin >> name;
        if (type == "dog" || type == "cat"){
          q.enqueue(type, name);
        }else{
          cout << "error, incorrect variables... try again..." << endl;
          }
        cout << "do you want to add another animal? (y/n) ";
        cin >> ans;
      if (ans == NO)
        menuChoice = 0;
      }
      ans = 'y';
    }
    
    // menu selection 2 for getting animal
    if (menuChoice == GET){
      while (ans == YES){
        cout << "Do you want a 1) cat, 2) dog, 3) no preference, or 4) quit";
        cout << endl << "(input 1, 2, 3, or 4): ";
        cin >> choice;
        if (choice < 0 || choice > 4){
          return 0;
          }
        tempSize = q.size();
        //choice for cat
        if (choice == 1){
          if (tempSize != 0){
            found = false;
            if (q.peekType() == CAT){
              adopt = q.peekName();
              q.dequeue();
              found = true;
            }else{
              tempSize = q.size();
              found = false;
              for (int i = 0; i < tempSize; i++){
                tempType = q.peekType();
                tempName = q.peekName();
                if (tempType == CAT && found != true){
                  adopt = q.peekName();
                  q.dequeue();
                  found = true;
                  tempSize = (tempSize - i);
                  i = 0;
                }else{
                  q.dequeue();
                  q.enqueue(tempType, tempName);
                }
              }
            }
            if (found)
              cout << "You have adopted a cat named " << adopt << endl;
            else
              cout << "There are no cats in the animal shelter." << endl;
              }
          if (tempSize == 0)
          cout << "There are no cats in the animal shelter." << endl;
          //choice for dog
        }else if (choice == 2){
          if (tempSize != 0){
            found = false;
            if (q.peekType() == DOG){
              adopt = q.peekName();
              q.dequeue();
              found = true;
            }else{
              tempSize = q.size();
              found = false;
              for (int i = 0; i < tempSize; i++){
                tempType = q.peekType();
                tempName = q.peekName();
                if (tempType == DOG && found != true){
                  adopt = q.peekName();
                  q.dequeue();
                  found = true;
                  tempSize = (tempSize - i);
                  i = 0;
                }else{
                  q.dequeue();
                  q.enqueue(tempType, tempName);
                }
              }
            }
            if (found)
              cout << "You have adopted a dog named " << adopt << endl;
            else
              cout << "There are no dogs in the animal shelter." << endl;
          }
          if (tempSize == 0)
            cout << "There are no dogs in the animal shelter." << endl;
          // no preference
        }else if (choice == 3){
          if (tempSize != 0){
            tempType = q.peekType();
            tempName = q.peekName();
            q.dequeue();
            cout << "You have adopted a " << tempType << " named ";
            cout << tempName << "." << endl;
          }else{
            cout << "There are no available animals in the shelter." << endl;
          }
          // leave
        }else if (choice == 4){
          cout << "do you want to get another animal? (y/n) ";
          cin >> ans;
          if (ans == NO)
            menuChoice = 0;
        }
      }
    }
    ans = 'y';
    
    // menu selection 3 quit
    if (menuChoice == QUIT){
      cout << "Bye bye!";
    }
    cout << endl;
}
  return 0;
}
