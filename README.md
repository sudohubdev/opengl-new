# Opengl заготовка
приклад застосунку opengl
# Build
## Для macOS 🍎
### Установити brew + xcode
### Потім ввести команди:
```bash
git clone https://github.com/g0vnocoders/opengl-new
brew install glew
brew install glfw
brew install libpng
brew install glm
make macos #попросить пароль для ініціалізації
make
```
## Для Windows:
### Cкачати MSYS2 та VS Code(або іншу IDE)

https://www.msys2.org

https://code.visualstudio.com

### Ввести ці команди (__MSYS2 MinGW64 з синьою іконкою в меню пуск__):
### якщо щось питає [Y/N] то завжди натискуємо y. якщо питає щось вибрати просто ентер
```bash
# open it with C:\msys64\mingw64.exe!!!  not cmd.exe
pacman -S git #install git
pacman -S mingw-w64-x86_64-gcc
pacman -S mingw-w64-x86_64-toolchain #збірка
git clone https://github.com/g0vnocoders/opengl-new
cd opengl-new
#compile libpng
makepkg -sCL
#compile our project
make
```


## Для користувачів Linux:
### Все на ізі, для убунти ставимо пакети і запускаєм make:
```bash
# Ubuntu/Debian
sudo apt-get update
sudo apt-get install cmake pkg-config
sudo apt-get install mesa-utils libglu1-mesa-dev freeglut3-dev mesa-common-dev
sudo apt-get install libglew-dev libglfw3-dev libglm-dev
sudo apt-get install libao-dev libmpg123-dev
sudo apt-get install libpng-dev
git clone https://github.com/g0vnocoders/opengl-new
cd opengl-new
make
```


# Довідничок
## Щоб очистити всі файли щоб зробити новий проект пишемо:
### make newproject

## Щоб зібрати просто пишемо:
### make

## Використовуємо GLEW + GLFW. Цей код працює всюди:
```cpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#if defined(__APPLE__)
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif
```
