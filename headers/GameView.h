#pragma once
#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <iostream>
#include <memory>

#include "GameModel.h"

class GameView {
 public:
  std::shared_ptr<GameModel> model_;
  explicit GameView(std::shared_ptr<GameModel>);
  void ShowStartMessage() const;
  void ShowCellMessage() const;
  void ShowUnreachableCellMessage(const std::string&) const;
  void ShowMoveMessage(int) const;
  void ShowHelpMessage() const;
  void ShowJournalMessage() const;
  void ShowInventoryMessage() const;
  void ShowCoordinatesMessage() const;
  void ShowDigMessage() const;
  void ShowWinMessage() const;
  void ShowExitMessage() const;
};


#endif