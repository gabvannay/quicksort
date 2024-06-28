
#include "../include/FileSystem.hpp"

#include <filesystem>
#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace qs {
std::vector<std::filesystem::path>
FileSystem::readFiles(std::string path, bool recurse, bool allowHidden) {
  std::filesystem::path directory = path;
  std::vector<std::filesystem::path> files;

  try {
    for (const auto &entry : std::filesystem::directory_iterator(directory)) {
      const std::filesystem::path path = entry.path();

      if (!allowHidden && path.filename().string()[0] == '.') {
        continue;
      }

      if (entry.is_directory()) {
        if (recurse) {
          auto dirFiles = readFiles(path.string(), true, allowHidden);
          files.insert(files.end(), dirFiles.begin(), dirFiles.end());
        }
        continue;
      }

      files.push_back(path);
    }
  } catch (const std::filesystem::filesystem_error &error) {
    std::cerr << "\033[1;31mUnexpected error: " << std::endl
              << error.what() << "\033[0m" << std::endl;
  }

  return files;
}
void FileSystem::moveFiles(
    std::map<std::string, std::vector<std::filesystem::path>> files,
    std::string dest) {

  const std::filesystem::path dir = dest;
  std::filesystem::path wd; // Working Directory
  std::filesystem::path to;

  try {
    std::filesystem::create_directory(dir);
  } catch (const std::filesystem::filesystem_error &error) {
    std::cerr << "\033[1;31mUnexpected error: " << std::endl
              << error.what() << "\033[0m" << std::endl;
  }
  for (const auto &pair : files) {
    wd = dir;
    wd.append(pair.first);

    std::filesystem::create_directory(wd);

    for (const auto &file : pair.second) {
      to = wd;
      to.append(file.filename().string());

      std::filesystem::rename(file, to);
    }
  }
}
}; // namespace qs
