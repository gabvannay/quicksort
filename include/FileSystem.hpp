
#ifndef FILE_SYSTEM_
#define FILE_SYSTEM_

#include <filesystem>
#include <string>
#include <vector>

namespace qs {
using std::filesystem::path;

class FileSystem {
public:
  static std::vector<path> readFiles(std::string path, bool recurse,
                                     bool allowHidden);
  void moveFiles();
};
} // namespace qs

#endif // !FILE_SYSTEM_
