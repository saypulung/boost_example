/*
An example to create new JSON Array and BOOST_FOREACH
{
  "ids": [1, 2, 3, 4, 5]
}
*/

// Load C++ standard library
#include <iostream>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using boost::property_tree::ptree;
using std::cin;
using std::cout;
using std::stringstream;

int main()
{
  int idsCount;
  cout<<"How many IDs you want create?: ";
  cin>>idsCount;

  int ids[idsCount];

  for (int i = 0; i < idsCount; i++)
  {
    cout<<"Type value of array at "<<i<<" : ";
    cin>>ids[i];
  }

  ptree json_obj, content, content_array;
  
  for(int id: ids)
  {
    content.put("", id);
    content_array.push_back(std::make_pair("", content));
  }
  json_obj.push_back(std::make_pair("ids", content_array));

  stringstream ss;
  boost::property_tree::write_json(ss, json_obj);
  cout<<"====================================\n";
  cout<<"Generated JSON Object: \n";
  cout<<ss.str();

  return 0;
}

