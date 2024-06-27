
#include "../include/FileSystem.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  std::string testPath = "/home/gabr/Documents/BulbPop/";
  qs::FileSystem *fs = new qs::FileSystem();
  fs->readFiles(testPath, true, false);
  auto files = fs->getFiles();
  int i = 1;

  for (const auto &file : files) {
    std::cout << i << ". " << file.string() << std::endl;
    i++;
  }

  return 0;
}
