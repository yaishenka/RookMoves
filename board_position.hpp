// Created by @yaishenka on 04.12.2023.
#pragma once
#include <cstddef>
#include <iostream>

struct BoardPosition {
 public:
  BoardPosition() = default;

  BoardPosition(size_t column, size_t row) : column(column), row(row) {}

  BoardPosition(char column, size_t row) : column(column - 'a'), row(row - 1) {}

  bool operator==(const BoardPosition&) const = default;

  size_t column = 0;
  size_t row = 0;
};

std::ostream& operator<<(std::ostream& os, const BoardPosition& position);