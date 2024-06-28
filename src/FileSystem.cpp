
#include "../include/FileSystem.hpp"

#include <filesystem>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

namespace qs {
using std::filesystem::path;

std::vector<path> FileSystem::readFiles(path dir, bool recurse,
                                        bool allowHidden) {
  if (!std::filesystem::exists(dir)) {
    throw std::invalid_argument("The provided directory does not exist.");
  }
  std::vector<path> files;

  try {
    for (const auto &entry : std::filesystem::directory_iterator(dir)) {
      const path path = entry.path();

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
void FileSystem::moveFiles(std::map<std::string, std::vector<path>> files,
                           path dest) {

  if (!std::filesystem::exists(dest)) {
    throw std::invalid_argument("The provided destination does not exists.");
  }

  path wd; // Working Directory
  path to;

  try {
    std::filesystem::create_directory(dest);
  } catch (const std::filesystem::filesystem_error &error) {
    std::cerr << "\033[1;31mUnexpected error: " << std::endl
              << error.what() << "\033[0m" << std::endl;
    return;
  }

  for (const auto &pair : files) {
    wd = dest;
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
