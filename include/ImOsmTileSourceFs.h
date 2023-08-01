#pragma once
#include "ImOsmTileSourceAsync.h"
#include <ghc/filesystem.hpp>

namespace ImOsm {
class TileSourceFs : public TileSourceAsync {
public:
  TileSourceFs(int requestLimit, bool preload,
               const ghc::filesystem::path &basePath);
  virtual ~TileSourceFs() = default;

  static std::string FileName(int z, int x, int y);
  static ghc::filesystem::path BasePathDefault();

protected:
  virtual bool receiveTile(int z, int x, int y, TileData &tileData) override;
  inline ghc::filesystem::path basePath() const { return _basePath; }

  virtual ghc::filesystem::path dirPath(int z, int x, int y) const = 0;

private:
  ghc::filesystem::path _basePath{BasePathDefault()};
};

// -----------------------------------------------------------------------------

class TileSourceFsDir : public TileSourceFs {
public:
  TileSourceFsDir(int requestLimit, bool preload,
                  const ghc::filesystem::path &basePath);
  virtual ~TileSourceFsDir() = default;

  static ghc::filesystem::path DirPath(ghc::filesystem::path basePath,
                                       [[maybe_unused]] int z,
                                       [[maybe_unused]] int x,
                                       [[maybe_unused]] int y) {
    return basePath;
  }

protected:
  virtual ghc::filesystem::path dirPath(int z, int x, int y) const override;
};

// -----------------------------------------------------------------------------

class TileSourceFsSubDir : public TileSourceFs {
public:
  TileSourceFsSubDir(int requestLimit, bool preload,
                     const ghc::filesystem::path &basePath);
  virtual ~TileSourceFsSubDir() = default;

  static ghc::filesystem::path DirPath(ghc::filesystem::path basePath, int z,
                                       [[maybe_unused]] int x,
                                       [[maybe_unused]] int y);

protected:
  virtual ghc::filesystem::path dirPath(int z, int x, int y) const override;
};

} // namespace ImOsm
