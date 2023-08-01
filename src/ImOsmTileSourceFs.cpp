#include "ImOsmTileSourceFs.h"
#include <fstream>
#include <sstream>

namespace ImOsm {
TileSourceFs::TileSourceFs(int requestLimit, bool preload,
                           const ghc::filesystem::path &basePath)
    : TileSourceAsync{requestLimit, preload}, _basePath{basePath} {}

std::string TileSourceFs::FileName(int z, int x, int y) {
  std::ostringstream fname_maker;
  fname_maker << z << '-' << x << '-' << y;
  return fname_maker.str();
}

ghc::filesystem::path TileSourceFs::BasePathDefault() {
  return ghc::filesystem::current_path().append("tiles");
}

bool TileSourceFs::receiveTile(int z, int x, int y, TileData &tileData) {
  auto path{dirPath(z, x, y)};
  std::ifstream reader(path.append(FileName(z, x, y)),
                       std::fstream::in | std::fstream::binary | std::ios::ate);
  auto pos{reader.tellg()};
  if (reader && pos > 0) {
    tileData.blob.resize(pos);
    reader.seekg(0, std::ios::beg);
    reader.read(reinterpret_cast<char *>(&tileData.blob[0]), pos);
    return true;
  }
  return false;
}

// -----------------------------------------------------------------------------

TileSourceFsDir::TileSourceFsDir(int requestLimit, bool preload,
                                 const ghc::filesystem::path &basePath)
    : TileSourceFs{requestLimit, preload, basePath} {}

ghc::filesystem::path TileSourceFsDir::dirPath(int z, int x, int y) const {
  return DirPath(basePath(), z, x, y);
}
// -----------------------------------------------------------------------------

TileSourceFsSubDir::TileSourceFsSubDir(int requestLimit, bool preload,
                                       const ghc::filesystem::path &basePath)
    : TileSourceFs{requestLimit, preload, basePath} {}

ghc::filesystem::path
TileSourceFsSubDir::DirPath(ghc::filesystem::path basePath, int z, int x,
                            int y) {
  return basePath.append(std::to_string(z));
}

ghc::filesystem::path TileSourceFsSubDir::dirPath(int z, int x, int y) const {
  return DirPath(basePath(), z, x, y);
}

} // namespace ImOsm
