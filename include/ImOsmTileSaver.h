#pragma once
#include "ImOsmITileSaver.h"
#include "ImOsmTileSourceFs.h"
#include <ghc/filesystem.hpp>

namespace ImOsm {
class ITile;

class TileSaver : public ITileSaver {
public:
  TileSaver();
  virtual ~TileSaver();

  virtual bool
  saveMulti(const std::vector<std::shared_ptr<ITile>> &tiles) const override;
  virtual bool save(std::shared_ptr<ITile> tile) const override;

protected:
  virtual ghc::filesystem::path dirPath(std::shared_ptr<ITile>) const = 0;
  virtual std::string fileName(std::shared_ptr<ITile> tile) const;
};

// -----------------------------------------------------------------------------

class TileSaverDir : public TileSaver {
public:
  TileSaverDir();
  TileSaverDir(const ghc::filesystem::path &basePath);
  virtual ~TileSaverDir();

protected:
  virtual ghc::filesystem::path
  dirPath(std::shared_ptr<ITile> tile) const override;

private:
  ghc::filesystem::path _basePath{TileSourceFs::BasePathDefault()};
};

// -----------------------------------------------------------------------------

class TileSaverSubDir : public TileSaver {
public:
  TileSaverSubDir();
  TileSaverSubDir(const ghc::filesystem::path &basePath);
  virtual ~TileSaverSubDir();

protected:
  virtual ghc::filesystem::path
  dirPath(std::shared_ptr<ITile> tile) const override;

private:
  ghc::filesystem::path _basePath{TileSourceFs::BasePathDefault()};
};

} // namespace ImOsm
