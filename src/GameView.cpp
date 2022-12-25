#include "../headers/GameView.h"

GameView::GameView(std::shared_ptr<GameModel> model) : model_(std::move(model)) {
}

void GameView::ShowStartMessage() const {
  std::cout << "\nВы просыпаетесь в замке.\n\n";
}

void GameView::ShowCellMessage() const {
  std::shared_ptr<MapCell> map_cell = model_->GetCurrentCell();
  std::cout << map_cell->messages_[map_cell->state_];
}

void GameView::ShowUnreachableCellMessage(const std::string& cell_name) const {
  std::cout << "В этом направлении Вы пройти не сможете.\nВпереди " << cell_name << ".\n\n";
}

void GameView::ShowMoveMessage(int side_code) const {
  std::cout << "Вы двигаетесь на ";
  switch (side_code) {
    case 0:
      std::cout << "СЕВЕР";
      break;
    case 1:
      std::cout << "ЮГ";
      break;
    case 2:
      std::cout << "ВОСТОК";
      break;
    case 3:
      std::cout << "ЗАПАД";
      break;
    default:
      break;
  }
  std::cout << ".\n\n";
}

void GameView::ShowHelpMessage() const {
  std::cout << "ВАМ ДОСТУПНЫ СЛЕДУЮЩИЕ КОМАНДЫ:\n\n"
               "-- N -- сделать шаг на север,\n"
               "-- W -- сделать шаг на запад,\n"
               "-- S -- сделать шаг на юг,\n"
               "-- E -- сделать шаг на восток,\n"
               "-- D -- копать в данной точке,\n"
               "-- H -- вывести список доступных команд,\n"
               "-- J -- вывести историю посещения сюжетных точек,\n"
               "-- I -- вывести информацию об собранных предметах,\n"
               "-- С -- вывести Ваши координаты,\n"
               "-- X -- выйти из игры.\n\n";
}

void GameView::ShowJournalMessage() const {
  std::cout << "Команда JOURNAL НЕ РЕАЛИЗОВАНА.\n\n";
}

void GameView::ShowInventoryMessage() const {
  Player player = model_->player_;
  std::cout << "ВЫ СОБРАЛИ СЛЕДУЮЩИЕ ПРЕДМЕТЫ:\n\n";
  std::cout << "Красная роза: " << (player.red_rose_ ? "ДА" : "НЕТ") << "\n";
  std::cout << "Синяя роза: " << (player.blue_rose_ ? "ДА" : "НЕТ") << "\n";
  std::cout << "Зелёная роза: " << (player.green_rose_ ? "ДА" : "НЕТ") << "\n";
  std::cout << "Лекарство: " << (player.medicine_ ? "ДА" : "НЕТ") << "\n\n";
}

void GameView::ShowCoordinatesMessage() const {
  int coord_x = model_->player_.column_;
  int coord_y = 11 - model_->player_.row_;
  std::cout << "ТЕКУЩИЕ КООРДИНАТЫ: " << coord_x << ", " << coord_y << ".\n\n";
}

void GameView::ShowDigMessage() const {
  std::cout << "ВЫ КОПАЕТЕ.\n\nВы ничего не откопали.\n\n";
}

void GameView::ShowWinMessage() const {
  std::cout << "Вы нашли лекарство для принцессы и прошли игру!\nПоздравляем!\n\n";
}

void GameView::ShowExitMessage() const {
  std::cout << "ВЫ ВЫШЛИ ИЗ ИГРЫ.\n\n";
}
