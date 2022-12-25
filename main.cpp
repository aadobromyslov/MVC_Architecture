#include "main.h"

int main() {
  auto model = std::make_shared<GameModel>();
  auto view = std::make_shared<GameView>(model);
  auto controller = std::make_shared<GameController>(model, view);
  controller->RunTheGame();
  return 0;
}