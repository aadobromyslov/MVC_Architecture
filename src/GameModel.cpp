#include "../headers/GameModel.h"

#include <iostream>

GameModel::GameModel() {
  for (int row = 0; row < 12; ++row) {
    for (int column = 0; column < 10; ++column) {
      map_[row][column] = std::make_shared<MapCell>();
    }
  }
  for (int column = 0; column < 10; ++column) {
    map_[0][column] = std::make_shared<MapCell>(messages::mountain, false);
    map_[11][column] = std::make_shared<MapCell>(messages::water, false);
  }
  for (int row = 1; row < 11; ++row) {
    map_[row][0] = std::make_shared<MapCell>(messages::water, false);
    map_[row][9] = std::make_shared<MapCell>(messages::forest, false);
  }
  map_[coordinates::castle.row][coordinates::castle.column] = std::make_shared<MapCell>(messages::castle);
  map_[coordinates::witch.row][coordinates::witch.column] = std::make_shared<MapCell>(messages::witch);
}

bool GameModel::IsProceeding() const {
  return is_proceeding_;
}

std::shared_ptr<MapCell> GameModel::GetCurrentCell() const {
  return map_[player_.row_][player_.column_];
}
