// Minh Nguyen
// assignment4.cpp
// cpsc2430

#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;

vector<string> split(string str, char del){
  vector<string> result;
  string temp = "";
  for(int i = 0; i < (int)str.size(); i++){
    if(str[i] != del){
      temp += str[i];
    }else{
      result.push_back(temp);
      temp = "";
    }
  }
  result.push_back(temp);
  return result;
}

class DataEntry
{
private:
  string date;
  string country;
  int c_cases;
  int c_deaths;
public:
  DataEntry(string date, string country, int cases, int deaths){
    this->date = date;
    this->country = country;
    this->c_cases = cases;
    this->c_deaths = deaths;
  }
  string getDate(){
    return this->date;
  }
  string getCountry(){
    return this->country;
  }
  int getCases(){
    return this->c_cases;
  }
  int getDeaths(){
    return this->c_deaths;
  }
  void calculate(DataEntry& obj, DataEntry& v){
    v.c_deaths += obj.getDeaths();
    v.c_cases += obj.getCases();
  }
  void updateDate(DataEntry& obj, DataEntry& v){
    v.date = obj.getDate();
  }
};

class seperateChaining
{
private:
  int tableSize;
  vector<vector<DataEntry>>v;
public:
  seperateChaining(int m){
    v = vector<vector<DataEntry>>(m);
    this->tableSize = m;
  }

  int hashCountry(string name, DataEntry object){
    int sum = 0;
    //int size = (object.getCountry()).length();
    int size = name.length();
    char *arr = new char[size + 1];
    strcpy(arr, name.c_str());
    for (int i = 0; i < size; i++){
      sum += ((int(arr[i]))*(i+1));
    }
    delete [] arr;
    return sum % 17;
  }
  
  void getHelper(string country){
    for(unsigned int i = 0; i < v.size(); i++) {
      for (unsigned int j = 0; j < v[i].size(); j++){
        if(country == v[i][j].getCountry()){
          cout << "Country: " << v[i][j].getCountry() << endl;
          cout << "Date: " << v[i][j].getDate() << endl;
          cout << "Cases: " << v[i][j].getCases() << endl;
          cout << "Deaths: " << v[i][j].getDeaths() << endl;
        }
      }
    }
  }
  
  bool add(DataEntry object){
    //DataEntry object = new DataEntry;
    //if(v[hashCountry(object.getCountry(), object)])
    //return false;
    int result = 0;
    int i = hashCountry(object.getCountry(), object);
    for(unsigned int j = 0; j< v[i].size(); j++){
      if(v[i][j].getCountry() == object.getCountry()){
        string d1 = object.getDate();
        string d2 = v[i][j].getDate();
        vector<string> d1v = split(d1,'/');
        vector<string> d2v = split(d2,'/');
        if(d1v[2]> d2v[2]){
          result = 1;
        }else if(d1v[2]< d2v[2]){
          result = 0;
        }else if(d1v[2] == d2v[2]){
          // compare month
          if(d1v[0]> d2v[0]){
            result = 1;
          }else if(d1v[0]< d2v[0]){
            result = 0;
          }else if(d1v[0] == d2v[0]){
            // compare day
            if(d1v[1]> d2v[1]){
              result = 1;
            }else if(d1v[1]< d2v[1]){
              result = 0;
            }else if(d1v[1] == d2v[1]){
              result = 3;
            }
          }
        }
        if(result == 0){
          object.calculate(object, v[i][j]);
          return true;
        }else if(result == 1){
          object.calculate(object, v[i][j]);
          object.updateDate(object, v[i][j]);
          return true;
        }
      }
    }
    v[hashCountry(object.getCountry(), object)].push_back(object);
    return true;
  }
  
  void removeHelper(string country){
    for(unsigned int i = 0; i < v.size(); i++) {
      for (unsigned int j = 0; j < v[i].size(); j++){
        if(country == v[i][j].getCountry()){
          remove(v[i][j]);
        }
      }
    }
  }
  
  void remove(DataEntry &object){
    int i = hashCountry(object.getCountry(), object);
    for(unsigned int j = 0; j< v[i].size(); j++){
      if(v[i][j].getCountry() == object.getCountry()){
        v[i].erase(v[i].begin() + j);
        cout << object.getCountry() << " is deleted!" << endl;
        return;
      }
    }
    cout << "Country: " << object.getCountry()
         << " is not in hash table!" << endl;
  }
  
  void display(){
    cout << "Hash Table" << endl;
    for(unsigned int i = 0; i < v.size(); i++) {
      cout << i;
      for (unsigned int j = 0; j < v[i].size(); j++)
        cout << " -> " << v[i][j].getCountry();
      cout << endl;
    }
  }
};

const char YES = 'y';
const char NO = 'n';
const int QUIT = 0;
const int CREATE = 1;
const int ADD = 2;
const int GET = 3;
const int REMOVE = 4;
const int DISPLAY = 5;

int main(){
  seperateChaining h(17);
  int menuChoice = -1;
  char ans = 'y';
  int check = 0;
  
  string date, country;
  int cases, deaths;

  while (menuChoice != QUIT){
    menuChoice = -1;
    // menu prompt
    while (menuChoice < QUIT || menuChoice > DISPLAY){
      cout << endl;
      cout << "Menu" << endl;
      cout << QUIT << ". Quit." << endl;
      cout << CREATE << ". Create the initial hash table." << endl;
      cout << ADD << ". Add a new data entry." << endl;
      cout << GET << ". Get a data entry." << endl;
      cout << REMOVE << ". Remove a data entry." << endl;
      cout << DISPLAY << ". Display the hash table." << endl;
      cout << "Choose the number that corresponds with your choice. Choice? ";
      cin >> menuChoice;
      cin.get();
      cout << endl;
    }

    if (menuChoice == QUIT){
      return 0;
    }

    if (menuChoice == CREATE){
      if(check == 0){
        ifstream file("WHO-COVID-Data.txt");
        if(file.is_open()){
          string line;
          while(getline(file, line)){
            vector<string> result = split(line, ',');
            DataEntry oneEntry = DataEntry(result[0], result[1],
                                           std::stoi(result[2]),
                                           std::stoi(result[3]));
            h.add(oneEntry);
          }
        }
        check += 1;
      }else if(check > 0){
        cout << "ERROR!" << endl;
      }
      menuChoice = -1;
    }

    if(menuChoice == ADD){
      while (ans == YES){
        cout << "Enter a date by month/day/year in the form MM/DD/YYYY:" << endl;
        cin >> date;
        cout << "Enter a name for a country:" << endl;
        cin >> country;
        cout << "How many cases were found on this date?:" << endl;
        cin >> cases;
        cout << "How many deaths were found on this date?:" << endl;
        cin >> deaths;
        
        DataEntry addEntry = DataEntry(date, country, cases, deaths);
        h.add(addEntry);
        cout << "again? (y/n) ";
        cin >> ans;
        if (ans == NO)
          menuChoice = -1;
      }
      ans = 'y';
    }

    if(menuChoice == GET){
      while (ans == YES){
        cout << "What country do you want data from?" << endl;
        cin >> country;
        
        h.getHelper(country);
        
        cout << "again? (y/n) ";
        cin >> ans;
        if (ans == NO)
          menuChoice = -1;
      }
      ans = 'y';
    }
    
    if(menuChoice == REMOVE){
      while (ans == YES){
        cout << "What country do you want to delete?" << endl;
        cin >> country;
        
        h.removeHelper(country);
        
        cout << "again? (y/n) ";
        cin >> ans;
        if (ans == NO)
          menuChoice = -1;
      }
      ans = 'y';
    }

    if(menuChoice == DISPLAY){
      h.display();
      menuChoice = -1;
    }
  }
  return 0;
}
