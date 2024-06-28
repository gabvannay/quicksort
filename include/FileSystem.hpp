
#ifndef FILE_SYSTEM_
#define FILE_SYSTEM_

#include <filesystem>
#include <map>
#include <string>
#include <vector>

namespace qs {
using std::filesystem::path;

class FileSystem {
public:
  static std::vector<path> readFiles(std::string path, bool recurse,
                                     bool allowHidden);
  static void
  moveFiles(std::map<std::string, std::vector<std::filesystem::path>> files,
            std::string dest);
};
} // namespace qs

#endif // !FILE_SYSTEM_
