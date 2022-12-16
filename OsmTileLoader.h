#pragma once
#include "OsmTileTexture.h"
#include <array>
#include <chrono>
#include <curl/curl.h>
#include <future>
#include <list>
#include <map>
#include <memory>

class OsmTileLoader {
public:
  OsmTileLoader();
  ~OsmTileLoader();

  void beginLoad(int z, int xmin, int xmax, int ymin, int ymax);
  ImTextureID tileAt(int z, int x, int y);

  struct RemoteTile {
    std::vector<std::byte> blob;
    CURLcode code{CURLE_OK};
  };

  struct Tile {
    std::array<int, 3> zxy{0, 0, 0};
    std::shared_future<RemoteTile> future;
    std::unique_ptr<OsmTileTexture> texture;

    bool operator==(const Tile &other) { return this->zxy == other.zxy; }
  };

private:
  const int _tileSizePx{256};
  OsmTileTexture _blankTile{_tileSizePx, TextureColor::Slate};
  std::list<Tile> _tiles;
  const int _futureLimit{4}, _textureLimit{4};
  int _futureCounter{}, _textureCounter{};

  RemoteTile onHandleRequest(const std::array<int, 3> &zxy);

  static size_t onPullResponse(void *data, size_t size, size_t nmemb,
                               void *userp);
};