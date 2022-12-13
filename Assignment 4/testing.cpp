#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> split(string str, char del){
  vector<string> result;
  // declaring temp string to store the curr "word" upto del
  string temp = "";
  for(int i=0; i<(int)str.size(); i++){
    // If current char is not ',', then append it to the "word", otherwise you  have completed the word, and start the next word
    if(str[i] != del){
      temp += str[i];
    }else{
      result.push_back(temp);
      temp = "";
    }
  }
  // push the last substring after the last ',' to the result
  result.push_back(temp);
  return result;
}

int main()
{
  string d1 = "11-22-2021";
  string d2 = "12-11-2021";
  vector<string> d1v = split(d1,'-');
  vector<string> d2v = split(d2,'-');
  // compare year first. Year is stored at d1v/d2v[2]
  if(d1v[2]> d2v[2]){
    cout << "d1v is later than d2v" << endl;
  }else if(d1v[2]< d2v[2]){
    cout << "d1v is earlier than d2v" << endl;
  }else if(d1v[2] == d2v[2]){
    // compare month - same logic as comparing year
    cout << " same year. compare month now " << endl;
    if(d1v[0]> d2v[0]){
      cout << "d1v is later than d2v" << endl;
    }else if(d1v[0]< d2v[0]){
      cout << "d1v is earlier than d2v" << endl;
    }else if(d1v[0] == d2v[0]){
      // compare month - same logic as comparing year
      cout << " same month. compare day now " << endl;
      if(d1v[1]> d2v[1]){
        cout << "d1v is later than d2v" << endl;
      }else if(d1v[1]< d2v[1]){
        cout << "d1v is earlier than d2v" << endl;
      }else if(d1v[1] == d2v[1]){
        // compare month - same logic as comparing year
        cout << " same day. this means they are the same date." << endl;
      }
    }
  }
  return 0;
}
