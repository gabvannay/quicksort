
#ifndef FILE_SYSTEM_
#define FILE_SYSTEM_

#include <filesystem>
#include <string>
#include <vector>

namespace qs {
class FileSystem {
private:
  /**
   * A vector of filesystem's paths
   */
  std::vector<std::filesystem::path> files;

public:
  std::vector<std::filesystem::path> getFiles();
  void readFiles(std::string path, bool recurse, bool allowHidden);
  void moveFiles();
};
} // namespace qs

#endif // !FILE_SYSTEM
