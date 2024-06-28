
#include "../include/FileSystem.hpp"
#include "../include/Sort.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  std::string src;
  std::string dest;

  std::cout << "Enter the path to the desired directory: " << std::endl
            << "  -> ";
  std::cin >> src;

  std::cout << std::endl << "Searching files..." << std::endl;
  auto files = qs::FileSystem::readFiles(src, true, false);
  std::cout << "\033[1;32mFound a total of " << files.size() << " files.\033[0m"
            << std::endl
            << std::endl
            << "Sorting files..." << std::endl;
  auto sortResult = qs::Sort::sort(files);
  std::cout << "\033[1;32mSorted the files into " << sortResult.size()
            << " categories.\033[0m" << std::endl;

  std::cout << std::endl
            << "Enter the path where the files should be moved: " << std::endl
            << "  -> ";
  std::cin >> dest;

  qs::FileSystem::moveFiles(sortResult, dest);

  std::cout << std::endl
            << "\033[1;32mFile moved succesfully.\033[0m" << std::endl;

  return 0;
}
