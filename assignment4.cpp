// Kevin Bui
// assignment4.cpp
// 4/25/22
// Purpose: to implement a hash table with separate chaining to create 
// Covid Data Tracker
// Input: number for menu options, string for country name, ints for data
// Processing: hash tables, linked lists, recursion
// Output: values in the hash table corresponding to user searches

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class cvsdata{
  string date;
  string country;
  int cases;
  int deaths;
public:
  cvsdata(string date, string country, int cases, int deaths){
    this->date = date;
    this->country = country;
    this->cases = cases;
    this->deaths = deaths;
  }
  string getName(){
      return country;
  }
};

class CovidDB{
    private:
        int tableSize;
        vector<vector<cvsdata>> v;
    public:
        // constructor
        CovidDB(int m){
          v = vector<vector<cvsdata>>(m);
          this->tableSize = m;
        }
        //hash function
        int getIndex(string country){
            int sum = 0;
            int i = 1;
            for(char c:country){
            sum += i * int(c);
            i++;
        }
        sum %= tableSize;
        return sum;
        }

        //add a key to hash table
        void add(cvsdata &entry){
            string word = entry.getName();
             int i = getIndex(word);
                for(long unsigned int j = 0; j < v[i].size(); j++){
                // if found
                if(v[i][j].getName() == word){
                  return;
                }else{
            v[getIndex(word)].push_back(entry);
                }
        }
        }
        //delete a key from hash table
        // void deleteKey(int key){
        //     // get index first
        //     int i = getIndex(key);
        //     // traverse ith list(vector) to search 
        //     for(int j = 0; j< v[i].size(); j++){
        //         // if found, delete
        //         if(v[i][j] == key){
        //             v[i].erase(v[i].begin() + j);
        //             cout << key << " key: " << key << " is deleted!" << endl;
        //             return;
        //         }
        //     }
        //     cout << "No key: " << key << " in hash table!";
        // }
    
        //Display the contents
        void display(){
            cout << "Hash Table" << endl;
            for(long unsigned int i = 0; i < v.size(); i++) {
                cout << i;
                for (long unsigned int j = 0; j < v[i].size(); j++){
                  cvsdata temp = v[i][j];
                    cout << " -> " << temp.getName();
                cout << endl;
            }
        }
        }
};

vector<string> split(string str, char del){
    vector<string> result;
    // declaring temp string to store the curr "word" upto del
    string temp = "";
    for(int i=0; i<(int)str.size(); i++){
        // If current char is not ',', then append it to the "word", otherwise you 
//have completed the word, and start the next word
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
  vector<cvsdata> recordList;
  // open the file
  ifstream file("WHO-COVID-Data.csv");
  if(file.is_open()){
    cout << "Open File Success" << endl;
    string line;
    while(getline(file, line)){
      
      // split the content in each line
      vector<string> result = split(line, ',');
      // wrap up all the data in the string to a cvsdata type and push it to the 
// vector
      cvsdata oneEntry = cvsdata(result[0], result[1], std::stoi(result[2]), 
    std::stoi(result[3]));
      recordList.push_back(oneEntry);
    }
    cout << "There are " << recordList.size() << " records in total." << endl;
    
  }else{
    cout << "Open file failed" << endl;
  }

   CovidDB table(17);
      for (long unsigned int x = 0; x < recordList.size(); x++){
        table.add(recordList[x]);
      }


   table.display();

    // int choice = 1;

    // while (choice != 0) {
    //     cout << "Covid Tracker\nPlease choose the operation you want:" << endl;
    //     cout << "1. Create the initial hash table" << endl
    //     << "2. Add a new data entry" << endl
    //     << "3. Get a data entry" << endl
    //     << "4. Remove a data entry" << endl
    //     << "5. Display hash table" << endl
    //     << "0. Quit the system" << endl << endl;

    //     cin >> choice;

    //     switch(choice){
    //         case 1:

    //             break;
    //         case 2:

    //             break;
    //         case 3:

    //             break;
    //         case 4:

    //             break;
    //         case 5:

    //             break;
    //         case 0:
    //             break;    
    //         default:
    //             cout <<"\nInvalid input, please try again\n\n";
    //     }
    // }
  return 0;
}