// Created by @yaishenka on 04.12.2023.
#include "utils.hpp"

#include <random>

#include "board_position.hpp"
#include "consts.hpp"

bool GetRandomBool() {
  std::random_device rd;
  std::mt19937 mt(rd());
  auto gen = std::bind(std::uniform_int_distribution<>(0, 1), mt);
  return static_cast<bool>(gen());
}

size_t GetRandomCoordinate() {
  std::random_device rd;
  std::mt19937 mt(rd());
  auto gen = std::bind(std::uniform_int_distribution<>(0, kBoardSize - 1), mt);

  return gen();
}

BoardPosition GenerateRandomBoardPosition() {
  return BoardPosition(GetRandomCoordinate(), GetRandomCoordinate());
}
