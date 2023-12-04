// Created by @yaishenka on 04.12.2023.
#pragma once
#include <chrono>
#include <memory>

#include "utils.hpp"
#include "board_position.hpp"

class Rook : public std::enable_shared_from_this<Rook> {
 public:
  Rook(BoardPosition position, size_t moves_count);

  const BoardPosition& GetPosition() const { return position_; }
  void SetPosition(BoardPosition position);
  BoardPosition GenerateRandomValidPosition() const;

  size_t GetMovesCount() const {return moves_count_; }
  void Move();
 private:
  BoardPosition position_;
  size_t moves_count_;
};