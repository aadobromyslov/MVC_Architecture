#pragma once
#ifndef MAPDATA_H
#define MAPDATA_H

#include <string>
#include <vector>

namespace coordinates {

struct Coordinates {
  int row;
  int column;
};

static Coordinates castle = {8, 3};
static Coordinates witch = {8, 4};

} // namespace coordinates


namespace messages {

static std::vector<std::string> water = {"ВОДА"};
static std::vector<std::string> mountain = {"ГОРЫ"};
static std::vector<std::string> forest = {"НЕПРОХОДИМАЯ ЧАЩА"};

static std::vector<std::string> blank = {"На этой клетке ничего приметного Вы не видите.\n\n"};
static std::vector<std::string> castle = {"ЗАМОК: Нужно найти лекарство для принцессы.\n"
                                          "Оно у колдуньи, которая живёт к востоку отсюда.\n\n"
                                          "Введя 'H', Вы можете посмотреть список доступных команд.\n\n",
                                          "ЗАМОК: Ты ещё не принёс лекарство для принцессы? Принеси :)\n\n",
                                          "ЗАМОК: Ты принёс ЛЕКАРСТВО! Спасибо, ты молодец.\n\n"};
static std::vector<std::string> witch = {"ВЕДЬМА: Тебе нужно лекарство для принцессы? Держи :)\n"
                                         "Вы получили ЛЕКАРСТВО. Нужно отнести его в ЗАМОК.\n\n",
                                         "ВЕДЬМА: Ну как, ты отнёс уже ЛЕКАРСТВО в ЗАМОК?\n\n"};

} // namespace messages


namespace visits {

static bool took_medicine_from_the_witch = false;

} //namespace visits

#endif