#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include <boost/filesystem.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp>

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

  std::string dirName = current_path().string();
  dirName += separator + "nganu";

  std::cout<<"Check or create directory 'nganu'\n";
  if (!exists(dirName)) {
    create_directory(dirName);
  }
  std::string file1Name(dirName + separator + "test.txt");
  ofstream file1(file1Name);
  file1 << "this the example of content";
  file1.close();

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

  std::cout<<"Delete a file \n";
  boost::this_thread::sleep(boost::posix_time::milliseconds(5000));
  if (exists(file1Name) && is_regular_file(file1Name))
  {
    remove(file1Name);
  }

  std::cout<<"Delete directory nganu \n";
  boost::this_thread::sleep(boost::posix_time::milliseconds(5000));
  if (exists(dirName) && is_directory(dirName)) {
    remove(dirName);
  }

}