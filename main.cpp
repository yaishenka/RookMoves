#include <iostream>

#include "engine.hpp"
#include "third_party/args.hpp"

int main(int argc, char** argv) {
  args::ArgumentParser parser("This program generates random rooks moves.");
  args::HelpFlag help(parser, "help", "Display this help menu", {'h', "help"});
  args::ValueFlag<int> moves_count(parser, "moves_count",
                                   "Count of moves to make for each rook",
                                   {'c'}, kDefaultMovesCount);
  args::ValueFlag<int> rooks_count(parser, "rooks_count", "Count of rooks",
                                   {'r'}, kDefaultRooksCount);
  args::ValueFlag<int> step_timeout(parser, "step_timeout",
                                    "Milliseconds to wait before next step",
                                    {"step-wait"}, kStepTimeout);
  args::ValueFlag<int> wait_timeout(parser, "step_timeout",
                                    "Milliseconds to wait if step failed",
                                    {"failed-wait"}, kFailedStepTimeout);

  try {
    parser.ParseCLI(argc, argv);
  } catch (args::Help) {
    std::cout << parser;
    return 0;
  } catch (args::ParseError e) {
    std::cerr << e.what() << std::endl;
    std::cerr << parser;
    return 1;
  } catch (args::ValidationError e) {
    std::cerr << e.what() << std::endl;
    std::cerr << parser;
    return 1;
  }

  Engine engine(args::get(rooks_count), args::get(moves_count),
                std::chrono::milliseconds(args::get(wait_timeout)),
                std::chrono::milliseconds(args::get(step_timeout)));
  engine.ProcessGame();
}
