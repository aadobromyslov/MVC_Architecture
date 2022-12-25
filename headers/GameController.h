#pragma once
#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <iostream>
#include <memory>
#include <vector>

#include "GameModel.h"
#include "GameView.h"
#include "GameCommands.h"

class GameController {
 public:
  std::shared_ptr<GameModel> model_;
  std::shared_ptr<GameView> view_;
  GameController(std::shared_ptr<GameModel>, std::shared_ptr<GameView>);
  void RunTheGame();
  void BeginTheGame() const;
};

#endif