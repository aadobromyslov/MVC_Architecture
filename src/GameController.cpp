#include "../headers/GameController.h"


GameController::GameController(std::shared_ptr<GameModel> model, std::shared_ptr<GameView> view)
    : model_(std::move(model)), view_(std::move(view)) {
}

void GameController::RunTheGame() {
  BeginTheGame();
  std::vector<ICommand*> commands(0);
  while (model_->IsProceeding()) {
    char command_char = 'A';
    std::cin >> command_char;
    switch (toupper(command_char)) {
      case 'N' :
        commands.push_back(new CommandNorth(model_, view_));
        break;
      case 'W' :
        commands.push_back(new CommandWest(model_, view_));
        break;
      case 'S' :
        commands.push_back(new CommandSouth(model_, view_));
        break;
      case 'E' :
        commands.push_back(new CommandEast(model_, view_));
        break;
      case 'H' :
        commands.push_back(new CommandHelp(model_, view_));
        break;
      case 'D' :
        commands.push_back(new CommandDig(model_, view_));
        break;
      case 'J' :
        commands.push_back(new CommandJournal(model_, view_));
        break;
      case 'I' :
        commands.push_back(new CommandInventory(model_, view_));
        break;
      case 'C' :
        commands.push_back(new CommandCoordinates(model_, view_));
        break;
      case 'X' :
        commands.push_back(new CommandExit(model_, view_, false));
        break;
    }
    commands.back()->Execute();
  }
  for (auto command : commands) {
    delete command;
  }
}

void GameController::BeginTheGame() const {
  auto command = std::make_shared<CommandStart>(model_, view_);
  command->Execute();
}
