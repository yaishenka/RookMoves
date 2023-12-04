// Created by @yaishenka on 04.12.2023.
#pragma once

#include <algorithm>
#include <chrono>
#include <mutex>
#include <unordered_map>

#include "board_position.hpp"
#include "consts.hpp"
#include "rook.hpp"

class ChessBoard {
 public:
  // Not thread safety
  void AddPiece(const std::shared_ptr<Rook>& rook,
                const BoardPosition& position);

  // Not thread safety
  bool IsOccupied(const BoardPosition& desired_position);

  // Thread safety
  bool Move(const std::shared_ptr<Rook>& rook, const BoardPosition& position);

  // Not thread safety
  void PrintToStdout() const;

 private:
  bool IsMoveAvailable(const std::shared_ptr<Rook>& rook,
                       const BoardPosition& position) const;

  std::unordered_map<std::shared_ptr<Rook>, BoardPosition> rooks_to_positions_;
  std::mutex board_mutex_;
};