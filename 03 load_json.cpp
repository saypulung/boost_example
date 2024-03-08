/*
An example to extract json object in a file
*/

#include <iostream>

#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/json_parser.hpp"
#include "boost/foreach.hpp"
using namespace std;

using boost::property_tree::ptree;
using namespace boost::property_tree::json_parser;

int main()
{
  ptree orders;
  read_json("orders.json", orders);
  boost::optional<ptree&> x = orders.get_child_optional("orders");
  if (x) {
    ptree filteredData;

    // looping use foreach
    BOOST_FOREACH(ptree::value_type & vt, x.get())
    {
      // assign json object content into ptree
      ptree data = vt.second;

      int userId;
      // getting value from key json object
      boost::optional<int> userIdFromJson = data.get_optional<int>("user_id");
      if (userIdFromJson) {
        // assign data from json to a variable
        userId = userIdFromJson.get();
        cout<<"User Id = "<<userId<<endl;
      }

      // getting value from children of key json object
      boost::optional<int> barangCode = data.get_optional<int>("barang.code");
      if (barangCode && barangCode.get() == 3000) {
        cout<<"Data includes `barang.code` == 3000\n";
        filteredData.push_back(std::make_pair("", data));
      }
    }
    ptree arrayBarang;
    arrayBarang.push_back(std::make_pair("order_filtered", filteredData));
    stringstream ss;
    write_json(ss, arrayBarang);
    cout<<"JSON Orders filtered : "<<endl<<ss.str()<<endl;
  }

  return 0;
}