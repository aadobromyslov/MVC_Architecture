#pragma once
#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include "MapData.h"

#include <memory>
#include <vector>
#include <string>

struct Player {
  Player() = default;
  int row_ = 8;
  int column_ = 3;
  bool red_rose_ = false;
  bool green_rose_ = false;
  bool blue_rose_ = false;
  bool medicine_ = false;
};

class MapCell {
 public:
  explicit MapCell(std::vector<std::string> messages = messages::blank, bool reachable = true, int state = 0)
          : messages_(std::move(messages)), reachable_(reachable), state_(state) {
  }
  std::vector<std::string> messages_;
  bool reachable_;
  int state_;
};

class GameModel {
 public:
  GameModel();
  std::shared_ptr<MapCell> map_[12][10];
  Player player_;
  bool is_proceeding_ = true;
  bool IsProceeding() const;
  std::shared_ptr<MapCell> GetCurrentCell() const;
};

#endif