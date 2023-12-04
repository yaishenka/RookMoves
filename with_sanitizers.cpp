#include <iostream>

#include "engine.hpp"

int main() {
  Engine engine(kDefaultRooksCount, kDefaultMovesCount,
                std::chrono::milliseconds(kFailedStepTimeout),
                std::chrono::milliseconds(kStepTimeout));
  engine.ProcessGame();
}
