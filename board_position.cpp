// Created by @yaishenka on 04.12.2023.
#include "board_position.hpp"

std::ostream& operator<<(std::ostream& os, const BoardPosition& position) {
  os << static_cast<char>('a' + position.column) << position.row + 1;
  return os;
}
