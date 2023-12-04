// Created by @yaishenka on 04.12.2023.

#include "chess_board.hpp"

#include <iostream>

void ChessBoard::AddPiece(const std::shared_ptr<Rook>& rook,
                          const BoardPosition& position) {
  rooks_to_positions_.insert({rook, position});
}

bool ChessBoard::IsOccupied(const BoardPosition& desired_position) {
  return std::any_of(
      rooks_to_positions_.begin(), rooks_to_positions_.end(),
      [&desired_position = desired_position](const auto& rooks_to_position) {
        return rooks_to_position.second == desired_position;
      });
}

bool ChessBoard::Move(const std::shared_ptr<Rook>& rook,
                      const BoardPosition& position) {

  {
    std::unique_lock<std::mutex> lock(board_mutex_);

    if (rooks_to_positions_[rook] == position) {
      return false;
    }

    if (!IsMoveAvailable(rook, position)) {
      return false;
    }

    std::cout << rooks_to_positions_[rook] << position << std::endl;
    rooks_to_positions_[rook] = position;
    PrintToStdout();
  }

  rook->SetPosition(position);
  rook->Move();
  return true;
}

void ChessBoard::PrintToStdout() const {
  std::vector<std::vector<char>> string_board(
      kBoardSize, std::vector<char>(kBoardSize, '*'));

  for (const auto& pair : rooks_to_positions_) {
    string_board[pair.second.row][pair.second.column] ='R';
  }

  std::cout << "  A B C D E F G H" << std::endl;
  size_t current_row_number = 8;
  for (auto it = string_board.rbegin(); it != string_board.rend(); ++it) {
    std::cout << std::to_string(current_row_number) << " ";
    for (auto& str : *it) {
      std::cout << str << " ";
    }
    std::cout << std::endl;
    current_row_number -= 1;
  }
}

bool ChessBoard::IsMoveAvailable(const std::shared_ptr<Rook>& rook,
                                 const BoardPosition& position) const {
  size_t BoardPosition::*still_coordinate;
  size_t BoardPosition::*movable_coordinate;

  if (rook->GetPosition().column == position.column) {
    still_coordinate = &BoardPosition::column;
    movable_coordinate = &BoardPosition::row;
  } else {
    still_coordinate = &BoardPosition::row;
    movable_coordinate = &BoardPosition::column;
  }

  size_t begin = std::min(rook->GetPosition().*movable_coordinate,
                          position.*movable_coordinate);
  size_t end = std::max(rook->GetPosition().*movable_coordinate,
                        position.*movable_coordinate);

  for (const auto& pair : rooks_to_positions_) {
    if (pair.first == rook) {
      continue;
    }

    if (pair.second.*still_coordinate ==
            rook->GetPosition().*still_coordinate &&
        pair.second.*movable_coordinate >= begin &&
        pair.second.*movable_coordinate <= end) {
      return false;
    }
  }

  return true;
}
