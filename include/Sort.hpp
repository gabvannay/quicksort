
#ifndef SORT_
#define SORT_

#include <filesystem>
#include <map>
#include <string>
#include <vector>

namespace qs {
class Sort {
private:
public:
  static std::map<std::string, std::vector<std::filesystem::path>>
  sort(std::vector<std::filesystem::path> files);
};
} // namespace qs

#endif // !SORT_
