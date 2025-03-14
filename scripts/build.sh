#!/bin/bash

if [ ! -d "build" ]; then
  echo "Створення директорії build..."
  mkdir build || { echo "Не вдалося створити директорію build"; exit 1; }
fi

cd build || { echo "Не вдалося перейти до директорії build"; exit 1; }

echo "Налаштування проекту через CMake..."
cmake -G "Ninja" .. || { echo "Помилка під час налаштування проекту через CMake"; exit 1; }

echo "Збірка проекту за допомогою CMake..."
cmake --build . || { echo "Помилка під час збірки проекту"; exit 1; }

./app || { echo "Помилка під час запуску клієнта"; exit 1; }