
#include "../include/FileSystem.hpp"
#include "../include/Sort.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  std::string testPath = "/home/gabr/Documents/BulbPop/";
  qs::FileSystem *fs = new qs::FileSystem();
  fs->readFiles(testPath, true, false);
  auto files = fs->getFiles();
  auto sort = qs::Sort::sort(files);
  int i = 1;

  for (const auto &pair : sort) {
    std::cout << pair.first << ':' << std::endl;

    for (const auto element : pair.second) {
      std::cout << "  -> " << element.string() << std::endl;
    }
  }

  // for (const auto &file : files) {
  //   std::cout << i << ". " << file.string() << std::endl;
  //   i++;
  // }

  return 0;
}
