#pragma once
#include "ImOsmTileDummy.h"
#include <stdint.h>
#include <vector>

namespace ImOsm {
class Tile : public TileDummy {
public:
  Tile(int z, int x, int y, const std::vector<unsigned char> &rawBlob,
       bool preload = true);
  virtual ~Tile() override;

  virtual const char *rawBlob() const override;
  virtual size_t rawBlobSize() const override;
  virtual void rgbaLoad() const override { stbLoad(); }
  virtual const char *rgbaBlob() const override;
  virtual size_t rgbaBlobSize() const override;
  virtual ImTextureID texture() const override;

private:
  using GLuint = unsigned int;

  GLuint glID() const;
  void stbLoad() const;
  void glLoad() const;

private:
  std::vector<unsigned char> _rawBlob;
  mutable int _pxW{}, _pxH{};
  mutable int _channels{};
  mutable std::vector<unsigned char> _rgbaBlob;
  mutable GLuint _id{0};
};
} // namespace ImOsm
