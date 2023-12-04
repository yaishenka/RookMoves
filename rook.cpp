// Created by @yaishenka on 04.12.2023.
#include "rook.hpp"

Rook::Rook(BoardPosition position, size_t moves_count)
    : position_(std::move(position)), moves_count_(moves_count) {}

void Rook::SetPosition(BoardPosition position) {
  position_ = std::move(position);
}

BoardPosition Rook::GenerateRandomValidPosition() const {
  BoardPosition new_position = GetPosition();
  size_t BoardPosition::*coordinate_to_move;

  bool is_vertical_move = GetRandomBool();
  if (is_vertical_move) {
    coordinate_to_move = &BoardPosition::row;
  } else {
    coordinate_to_move = &BoardPosition::column;
  }

  new_position.*coordinate_to_move = GetRandomCoordinate();
  while (new_position.*coordinate_to_move ==
         GetPosition().*coordinate_to_move) {
    new_position.*coordinate_to_move = GetRandomCoordinate();
  }

  return new_position;
}

void Rook::Move() { moves_count_ -= 1; }
