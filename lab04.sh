#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Ошибка: Вы не ввели числа."
    echo "Пример запуска: $0 5 3 8 1"
    exit 1
fi

M=("$@")

echo -n "До: "
echo "${M[@]}"

mapfile -t M < <(printf "%s\n" "${M[@]}" | sort -n)

echo -n "После: "
echo "${M[@]}"
