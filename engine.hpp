// Created by @yaishenka on 04.12.2023.
#pragma once
#include <chrono>

#include "chess_board.hpp"
#include "consts.hpp"
#include "rook.hpp"
#include "utils.hpp"

class Engine {
 public:
  Engine(size_t rooks_count, size_t rook_moves_count,
         const std::chrono::milliseconds& wait_timeout,
         const std::chrono::milliseconds& step_timeout);

  void ProcessGame();

 private:
  void SetupGame();
  void ControlRook(std::shared_ptr<Rook> rook);
  size_t rooks_count_;
  size_t rook_moves_count_;
  std::chrono::milliseconds wait_timeout_;
  std::chrono::milliseconds step_timeout_;
  std::shared_ptr<ChessBoard> board_;
  std::vector<std::shared_ptr<Rook>> rooks_;
};