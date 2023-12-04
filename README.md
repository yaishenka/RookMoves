# RookMoves

## Сборка

    mkdir -p build && cd build
    cmake ..
    make

или

    ./build.sh
    cd build

## Запуск

./RookMoves {OPTIONS}

    This program generates random rooks moves.

OPTIONS:

      -h, --help                        Display this help menu
      -c[moves_count]                   Count of moves to make for each rook
      -r[rooks_count]                   Count of rooks
      --step-wait=[step_timeout]        Milliseconds to wait before next step
      --failed-wait=[step_timeout]      Milliseconds to wait if step failed

## Используемые библиотеки

Я использовал third_party либу ради аргументов командной строки. Все остальное чистый stl

## Запуск с санитайзерами

    ./RookMovesWithSanitizers

В бинаре с санитайзерами нет аргументов, потому что third_party либа не собирается под санитайзерами %)
