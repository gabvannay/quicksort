
#include "../include/Sort.hpp"
#include <string>

namespace qs {
using std::filesystem::path;

std::map<std::string, std::vector<path>> Sort::sort(std::vector<path> files) {
  std::map<std::string, std::vector<path>> result;
  std::string ext;

  for (path file : files) {
    if (file.extension() == "") {
      ext = ".txt";
    } else {
      ext = file.extension().string();
    }

    // Try to emplace a new element at the key from the file extension
    auto emplace = result.try_emplace(ext, std::vector{file});

    // If it fails, the key already exists so the file should be pushed...
    // ... at the already existing key
    if (!emplace.second) {
      result[ext].push_back(file);
    }
  }

  return result;
}
} // namespace qs
