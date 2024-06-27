
#include "../include/FileSystem.hpp"

#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

namespace qs {
std::vector<std::filesystem::path> files;

std::vector<std::filesystem::path> FileSystem::getFiles() { return files; }

void FileSystem::readFiles(std::string path, bool recurse, bool allowHidden) {
  std::filesystem::path dir = path;

  try {
    for (const auto &entry : std::filesystem::directory_iterator(dir)) {
      const std::filesystem::path path = entry.path();

      if (!allowHidden && path.filename().string()[0] == '.') {
        continue;
      }

      if (entry.is_directory()) {
        if (recurse) {
          readFiles(path.string(), true, allowHidden);
        } else {
          continue;
        }
      }

      files.push_back(path);
    }
  } catch (const std::filesystem::filesystem_error &error) {
    std::cerr << "Unexpected error: " << std::endl << error.what() << std::endl;
  }
}
void FileSystem::moveFiles() {}
}; // namespace qs
