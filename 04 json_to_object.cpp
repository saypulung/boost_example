/*
An example to parse JSON into an object
*/

#include <iostream>
#include <string>

#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/json_parser.hpp"
#include "boost/foreach.hpp"
using namespace std;

using boost::property_tree::ptree;
using namespace boost::property_tree::json_parser;

class Order
{
  private:
    int productCode;
    int userId;
  
  public:
    void setProductCode(int code);
    void setUserId(int id);
    int getProductCode();
    int getUserId();
    void fromJson(ptree& json);
    Order();
    Order(ptree& json);
    ptree& toJson(ptree& output);
};

void Order::setProductCode(int code)
{
  productCode = code;
}

void Order::setUserId(int id)
{
  userId = id;
}

int Order::getProductCode() { return productCode; }
int Order::getUserId() { return userId; }

void Order::fromJson(ptree& json)
{
  boost::optional<int> opProductCode = json.get_optional<int>("barang.code");
  boost::optional<int> opUserId = json.get_optional<int>("user_id");

  if (opProductCode) {
    productCode = opProductCode.get();
  }

  if (opUserId) {
    userId = opUserId.get();
  }
}
Order::Order(){}
Order::Order(ptree& json){ fromJson(json);}

ptree& Order::toJson(ptree& output)
{
  output.put("barang.code", productCode);
  output.put("user_id", userId);
  return output;
}

int main()
{
  string orderJson = "{\"barang\":{\"code\": 12},\"user_id\": 1}";
  stringstream ss;
  ss<<orderJson;
  ptree jsonLoad;
  boost::property_tree::read_json(ss, jsonLoad);

  Order order;
  //converting json into object
  order.fromJson(jsonLoad);

  cout<<"Getting values of properties: "<<endl;
  cout<<order.getProductCode()<<endl;
  cout<<order.getUserId()<<endl;
  cout<<"=============================="<<endl;

  // try to updating existing data
  order.setProductCode(15);
  order.setUserId(21);

  ptree jsonOut;
  order.toJson(jsonOut);

  stringstream ss2;
  cout<<"Converting object into json"<<endl;
  boost::property_tree::write_json(ss2, jsonOut);
  // see the output of json
  cout<<ss2.str()<<endl;

  return 0;
}