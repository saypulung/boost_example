/*
An example to create new JSON Object
{
  "name": "Paijo",
  "age": 30,
  "weight": 170.5,
  "is_active": true
}
*/

// Load C++ standard library
#include <iostream>
#include <string>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using boost::property_tree::ptree;
using std::string;
using std::cin;
using std::cout;
using std::stringstream;

int main()
{
  int age;
  float weight;
  string name;
  bool is_active;

  cout<<"Type your name: ";
  getline(cin, name);

  cout<<"Type your weight: ";
  cin>>weight;

  cout<<"How old your age?: ";
  cin>>age;

  cout<<"Are you active in organization?: ";
  try {
    cin>>is_active;
  } catch(...) {
    is_active = false;
  }
  
  ptree json_obj;
  json_obj.put("name", name);
  json_obj.put("age", age);
  json_obj.put("weight", weight);
  json_obj.put("is_active", is_active);

  stringstream ss;
  boost::property_tree::write_json(ss, json_obj);
  cout<<"Generated JSON Object: \n";
  cout<<ss.str();

  return 0;
}

