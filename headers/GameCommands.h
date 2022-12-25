#pragma once
#ifndef GAME_COMMANDS_H
#define GAME_COMMANDS_H

#include <memory>

#include "GameModel.h"
#include "GameView.h"

class ICommand {
 public:
  virtual void Execute() = 0;
  virtual ~ICommand() = default;
};

class CommandStart : public ICommand {
 public:
  std::shared_ptr<GameModel> model_;
  std::shared_ptr<GameView> view_;
  CommandStart(std::shared_ptr<GameModel> , std::shared_ptr<GameView> );
  void Execute() override;
  ~CommandStart() override = default;
};

class CommandNorth : public ICommand {
 public:
  std::shared_ptr<GameModel> model_;
  std::shared_ptr<GameView> view_;
  CommandNorth(std::shared_ptr<GameModel>, std::shared_ptr<GameView>);
  void Execute() override;
  ~CommandNorth() override = default;
};

class CommandSouth : public ICommand {
 public:
  std::shared_ptr<GameModel> model_;
  std::shared_ptr<GameView> view_;
  CommandSouth(std::shared_ptr<GameModel>, std::shared_ptr<GameView>);
  void Execute() override;
  ~CommandSouth() override = default;
};

class CommandWest : public ICommand {
 public:
  std::shared_ptr<GameModel> model_;
  std::shared_ptr<GameView> view_;
  CommandWest(std::shared_ptr<GameModel>, std::shared_ptr<GameView>);
  void Execute() override;
  ~CommandWest() override = default;
};

class CommandEast : public ICommand {
 public:
  std::shared_ptr<GameModel> model_;
  std::shared_ptr<GameView> view_;
  CommandEast(std::shared_ptr<GameModel>, std::shared_ptr<GameView>);
  void Execute() override;
  ~CommandEast() override = default;
};

class CommandHelp : public ICommand {
 public:
  std::shared_ptr<GameModel> model_;
  std::shared_ptr<GameView> view_;
  CommandHelp(std::shared_ptr<GameModel>, std::shared_ptr<GameView>);
  void Execute() override;
  ~CommandHelp() override = default;
};

class CommandDig : public ICommand {
 public:
  std::shared_ptr<GameModel> model_;
  std::shared_ptr<GameView> view_;
  CommandDig(std::shared_ptr<GameModel>, std::shared_ptr<GameView>);
  void Execute() override;
  ~CommandDig() override = default;
};

class CommandJournal : public ICommand {
 public:
  std::shared_ptr<GameModel> model_;
  std::shared_ptr<GameView> view_;
  CommandJournal(std::shared_ptr<GameModel>, std::shared_ptr<GameView>);
  void Execute() override;
  ~CommandJournal() override = default;
};

class CommandInventory : public ICommand {
 public:
  std::shared_ptr<GameModel> model_;
  std::shared_ptr<GameView> view_;
  CommandInventory(std::shared_ptr<GameModel>, std::shared_ptr<GameView>);
  void Execute() override;
  ~CommandInventory() override = default;
};

class CommandCoordinates : public ICommand {
 public:
  std::shared_ptr<GameModel> model_;
  std::shared_ptr<GameView> view_;
  CommandCoordinates(std::shared_ptr<GameModel>, std::shared_ptr<GameView>);
  void Execute() override;
  ~CommandCoordinates() override = default;
};

class CommandMove : public ICommand {
 public:
  std::shared_ptr<GameModel> model_;
  std::shared_ptr<GameView> view_;
  int row_delta_;
  int column_delta_;
  CommandMove(std::shared_ptr<GameModel>, std::shared_ptr<GameView>, int, int);
  void Execute() override;
  ~CommandMove() override = default;
};

class CommandAction : public ICommand {
 public:
  std::shared_ptr<GameModel> model_;
  std::shared_ptr<GameView> view_;
  CommandAction(std::shared_ptr<GameModel>, std::shared_ptr<GameView>);
  void Execute() override;
  ~CommandAction() override = default;
};

class CommandActionCastle : public ICommand {
 public:
  std::shared_ptr<GameModel> model_;
  std::shared_ptr<GameView> view_;
  CommandActionCastle(std::shared_ptr<GameModel>, std::shared_ptr<GameView>);
  void Execute() override;
  ~CommandActionCastle() override = default;
};

class CommandActionWitch : public ICommand {
 public:
  std::shared_ptr<GameModel> model_;
  std::shared_ptr<GameView> view_;
  CommandActionWitch(std::shared_ptr<GameModel>, std::shared_ptr<GameView>);
  void Execute() override;
  ~CommandActionWitch() override = default;
};

class CommandActionBlank : public ICommand {
 public:
  std::shared_ptr<GameModel> model_;
  std::shared_ptr<GameView> view_;
  CommandActionBlank(std::shared_ptr<GameModel>, std::shared_ptr<GameView>);
  void Execute() override;
  ~CommandActionBlank() override = default;
};

class CommandExit : public ICommand {
 public:
  std::shared_ptr<GameModel> model_;
  std::shared_ptr<GameView> view_;
  bool is_win_;
  CommandExit(std::shared_ptr<GameModel>, std::shared_ptr<GameView>, bool);
  void Execute() override;
  ~CommandExit() override = default;
};

#endif