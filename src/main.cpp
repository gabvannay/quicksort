
#include "../include/FileSystem.hpp"
#include "../include/Sort.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  std::string testPath = "/home/gabr/Documents/BulbPopCopy/";

  auto files = qs::FileSystem::readFiles(testPath, true, false);
  auto sort = qs::Sort::sort(files);

  // for (const auto &pair : sort) {
  //   std::cout << pair.first << ':' << std::endl;
  //
  //   for (const auto element : pair.second) {
  //     std::cout << "  -> " << element.string() << std::endl;
  //   }
  // }

  qs::FileSystem::moveFiles(sort, "/home/gabr/Documents/sort/");

  return 0;
}
