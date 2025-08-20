# Aluminium C (alc) 🔧

**Мощный и легкий инструмент для автоматизации workflow на языке C.**

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Version: 0.1.0](https://img.shields.io/badge/Version-0.1.0-blue)](https://github.com/your_username/alc)
[![Language: C](https://img.shields.io/badge/Language-C-blue)](https://www.iso.org/standard/74528.html)

`alc` — это утилита командной строки, созданная для разработчиков на C, которая упрощает рутинные задачи: создание структуры проектов, управление файлами и папками, а также выполнение системных команд. Легкий как алюминий и мощный как язык C.

---

## ✨ Возможности

-   **`create`**: Мгненное создание файлов и папок для вашего проекта.
-   **`delete`**: Быстрое и безопасное удаление файлов и папок.
-   **`console`**: Вывод текста в консоль прямо через утилиту.
-   **`callcmd`**: Выполнение любой системной команды прямо из `alc`.
-   **Простота и скорость**: Написано на чистом C, без лишних зависимостей.
-   **Кроссплатформенность** (в разработке): Работает на Windows и готовится к поддержке *nix систем.

---

## 🚀 Быстрый старт

### Сборка из исходников

1.  **Клонируйте репозиторий:**
    ```bash
    git clone https://github.com/your_username/alc.git
    cd alc
    ```

2.  **Скомпилируйте проект:**
    ```bash
    gcc -o alc main.c
    ```

3.  **Добавьте `alc` в PATH (опционально, но рекомендуется):**
    ```bash
    # Переместите исполняемый файл в удобную директорию
    mv alc /usr/local/bin/ # Пример для Linux/macOS
    # Или добавьте текущую директорию в PATH
    ```

---

## 📚 Использование

### Создание объектов
```bash
# Создать папку с именем 'my_project'
alc create folder my_project

# Создать файл 'main.c'
alc create file main.c

### Удаление объектов

# Удалить папку 'temp'
alc delete folder temp

# Удалить файл 'old_file.c'
alc delete file old_file.c

### Взаимодействие с системой

# Вывести сообщение в консоль
alc console "Hello, World!"

# Выполнить любую команду системы
alc callcmd ls -la
alc callcmd echo "Aluminium C is powerful!"

### Структура проекта

alc/
├── LICENSE
├── README.md       # Этот файл
└── main.c          # Исходный код утилиты