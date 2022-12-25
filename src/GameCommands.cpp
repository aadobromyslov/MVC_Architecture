#include "../headers/GameCommands.h"

CommandStart::CommandStart(std::shared_ptr<GameModel>  model, std::shared_ptr<GameView>  view)
    : model_(std::move(model)), view_(std::move(view)) {
}

CommandNorth::CommandNorth(std::shared_ptr<GameModel>  model, std::shared_ptr<GameView>  view)
    : model_(std::move(model)), view_(std::move(view)) {
}

CommandSouth::CommandSouth(std::shared_ptr<GameModel>  model, std::shared_ptr<GameView>  view)
    : model_(std::move(model)), view_(std::move(view)) {
}

CommandWest::CommandWest(std::shared_ptr<GameModel>  model, std::shared_ptr<GameView>  view)
    : model_(std::move(model)), view_(std::move(view)) {
}

CommandEast::CommandEast(std::shared_ptr<GameModel>  model, std::shared_ptr<GameView>  view)
    : model_(std::move(model)), view_(std::move(view)) {
}

CommandHelp::CommandHelp(std::shared_ptr<GameModel>  model, std::shared_ptr<GameView>  view)
    : model_(std::move(model)), view_(std::move(view)) {
}

CommandDig::CommandDig(std::shared_ptr<GameModel>  model, std::shared_ptr<GameView>  view)
    : model_(std::move(model)), view_(std::move(view)) {
}

CommandJournal::CommandJournal(std::shared_ptr<GameModel>  model, std::shared_ptr<GameView>  view)
    : model_(std::move(model)), view_(std::move(view)) {
}

CommandInventory::CommandInventory(std::shared_ptr<GameModel>  model, std::shared_ptr<GameView>  view)
    : model_(std::move(model)), view_(std::move(view)) {
}

CommandCoordinates::CommandCoordinates(std::shared_ptr<GameModel>  model, std::shared_ptr<GameView>  view)
    : model_(std::move(model)), view_(std::move(view)) {
}

CommandMove::CommandMove(std::shared_ptr<GameModel>  model, std::shared_ptr<GameView>  view, int row_delta, int column_delta)
    : model_(std::move(model)), view_(std::move(view)), row_delta_(row_delta), column_delta_(column_delta) {
}

CommandAction::CommandAction(std::shared_ptr<GameModel>  model, std::shared_ptr<GameView>  view)
        : model_(std::move(model)), view_(std::move(view)) {
}

CommandActionCastle::CommandActionCastle(std::shared_ptr<GameModel>  model, std::shared_ptr<GameView>  view)
        : model_(std::move(model)), view_(std::move(view)) {
}

CommandActionWitch::CommandActionWitch(std::shared_ptr<GameModel>  model, std::shared_ptr<GameView>  view)
        : model_(std::move(model)), view_(std::move(view)) {
}

CommandActionBlank::CommandActionBlank(std::shared_ptr<GameModel>  model, std::shared_ptr<GameView>  view)
        : model_(std::move(model)), view_(std::move(view)) {
}

CommandExit::CommandExit(std::shared_ptr<GameModel>  model, std::shared_ptr<GameView>  view, bool is_win)
        : model_(std::move(model)), view_(std::move(view)), is_win_(is_win) {
}

void CommandStart::Execute() {
  view_->ShowStartMessage();
  view_->ShowCellMessage();
  ++(model_->GetCurrentCell()->state_);
}

void CommandNorth::Execute() {
  view_->ShowMoveMessage(0);
  auto command = std::make_shared<CommandMove>(model_, view_, -1, 0);
  command->Execute();
}

void CommandSouth::Execute() {
  view_->ShowMoveMessage(1);
  auto command = std::make_shared<CommandMove>(model_, view_, 1, 0);
  command->Execute();
}

void CommandEast::Execute() {
  view_->ShowMoveMessage(2);
  auto command = std::make_shared<CommandMove>(model_, view_, 0, 1);
  command->Execute();
}

void CommandWest::Execute() {
  view_->ShowMoveMessage(3);
  auto command = std::make_shared<CommandMove>(model_, view_, 0, -1);
  command->Execute();
}

void CommandHelp::Execute() {
  view_->ShowHelpMessage();
}

void CommandDig::Execute() {
  view_->ShowDigMessage();
}

void CommandJournal::Execute() {
  view_->ShowJournalMessage();
}

void CommandInventory::Execute() {
  view_->ShowInventoryMessage();
}

void CommandCoordinates::Execute() {
  view_->ShowCoordinatesMessage();
}

void CommandMove::Execute() {
  int current_row = model_->player_.row_;
  int current_column = model_->player_.column_;
  std::shared_ptr<MapCell> supposed_cell = model_->map_[current_row + row_delta_][current_column + column_delta_];
  if (!supposed_cell->reachable_) {
    std::string message = supposed_cell->messages_[supposed_cell->state_];
    return view_->ShowUnreachableCellMessage(message);
  }
  model_->player_.row_ += row_delta_;
  model_->player_.column_ += column_delta_;
  auto command = std::make_shared<CommandAction>(model_, view_);
  command->Execute();
}

void CommandAction::Execute() {
  if (model_->player_.row_ == coordinates::castle.row && model_->player_.column_ == coordinates::castle.column) {
    auto command = std::make_shared<CommandActionCastle>(model_, view_);
    return command->Execute();
  }
  if (model_->player_.row_ == coordinates::witch.row && model_->player_.column_ == coordinates::witch.column) {
    auto command = std::make_shared<CommandActionWitch>(model_, view_);
    return command->Execute();
  }
  auto command = std::make_shared<CommandActionBlank>(model_, view_);
  return command->Execute();
}

void CommandActionCastle::Execute() {
  if (visits::took_medicine_from_the_witch) {
    model_->GetCurrentCell()->state_ = 2;
  }
  view_->ShowCellMessage();
  if (model_->GetCurrentCell()->state_ == 2) {
    auto command = std::make_shared<CommandExit>(model_, view_, true);
    return command->Execute();
  }
}

void CommandActionWitch::Execute() {
  view_->ShowCellMessage();
  if (!visits::took_medicine_from_the_witch) {
    visits::took_medicine_from_the_witch = true;
    model_->player_.medicine_ = true;
    model_->GetCurrentCell()->state_ = 1;
  }
}

void CommandActionBlank::Execute() {
  view_->ShowCellMessage();
}

void CommandExit::Execute() {
  model_->is_proceeding_ = false;
  if (is_win_) {
    view_->ShowWinMessage();
  }
  view_->ShowExitMessage();
}
