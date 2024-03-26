#include <iostream>
#include <string>

#include <boost/filesystem.hpp>

using namespace boost::filesystem;

int main()
{
  path p{"orders.json"};
  std::cout << p.stem() << '\n';
  std::cout << p.extension() << '\n';

  std::cout<< "Current path : "<<current_path()<<'\n';
  std::cout << "Get file separator \n";
  std::cout << path::preferred_separator << "\n";
  std::string separator(1, path::preferred_separator);
  std::cout << "Separator as STRING "<<separator<<"\n";

  std::cout << "Check file \"order.json\" exists \n";
  if (exists("orders.json") && is_regular_file("orders.json")) {
    std::cout << "Ada filenya \n";
  } else {
    std::cout << "Gak ada filenya \n";
  }

  std::cout << "Check file \"photo.jpg\" exists \n";
  if (exists("photo.jpg")) {
    std::cout << "Ada filenya \n";
  } else {
    std::cout << "Gak ada filenya \n";
  }

  std::cout << "Check directory \"screenshots\" exists \n";
  if (exists("screenshots") && is_directory("screenshots")) {
    std::cout << "Ada dir nya \n";
  } else {
    std::cout << "Gak ada dir nya \n";
  }

}