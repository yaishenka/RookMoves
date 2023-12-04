// Created by @yaishenka on 04.12.2023.
#include <thread>
#include "engine.hpp"

Engine::Engine(size_t rooks_count, size_t rook_moves_count,
               const std::chrono::milliseconds& wait_timeout,
               const std::chrono::milliseconds& step_timeout)
    : rooks_count_(rooks_count),
      rook_moves_count_(rook_moves_count),
      wait_timeout_(wait_timeout),
      step_timeout_(step_timeout) {}

void Engine::ProcessGame() {
  SetupGame();
  std::vector<std::thread> threads;
  threads.reserve(rooks_count_);

  for (auto& rook : rooks_) {
    threads.emplace_back(&Engine::ControlRook, this, rook);
  }

  for (auto& thread : threads) {
    thread.join();
  }
}

void Engine::SetupGame() {
  rooks_.clear();
  rooks_.reserve(rooks_count_);
  board_ = std::make_shared<ChessBoard>();
  for (size_t i = 0; i < rooks_count_; ++i) {
    auto random_position = GenerateRandomBoardPosition();
    while (board_->IsOccupied(random_position)) {
      random_position = GenerateRandomBoardPosition();
    }
    auto rook = std::make_shared<Rook>(random_position, rook_moves_count_);
    board_->AddPiece(rook, random_position);
    rooks_.emplace_back(std::move(rook));
  }

  board_->PrintToStdout();
}

void Engine::ControlRook(std::shared_ptr<Rook> rook) {
  while (rook->GetMovesCount() != 0) {
    auto new_position = rook->GenerateRandomValidPosition();

    bool moved = board_->Move(rook, new_position);
    if (!moved) {
      std::this_thread::sleep_for(wait_timeout_);
      moved = board_->Move(rook, new_position);
    }

    if (moved) {
      std::this_thread::sleep_for(step_timeout_);
    }
  }
}