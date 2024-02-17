# Setup and build

1. Download and unpack the SDL-devel-mingw32 tar file (Refer image below) from [SDL releases](https://github.com/libsdl-org/SDL/releases) into the current directory.

![alt text](assets/SDL2_download_image.png)

2. Rename the SDL folder to SDL2.
3. Open an MSYS2 MinGW64 shell.
4. Run `./build.sh`

# Additional info

1. In `image.c`, there is a call to `printf` in the `animateImage` function which when removed causes
   the animation to be extremely fast. This is weird and needs to be checked. Added the code as part
   of the commit: [dc23a07](https://github.com/BlackWind001/SDL_exploration/commit/dc23a07136b77928e3eaec2ce5b289fdc96feb7e) . Previous implementation commit: [7c76807](https://github.com/BlackWind001/SDL_exploration/commit/7c7680781c70d3969abc53ce6e9c407832464ed9)

# References

1. [LibSDL docs](https://www.libsdl.org/release/SDL-1.2.15/docs/html/index.html)
2. [Dev.to articles](https://dev.to/noah11012/using-sdl2-in-c-and-with-c-too-1l72)
3. [Lazyfoo SDL tutorial](https://lazyfoo.net/tutorials/SDL/)
4. [Studyplan.dev](https://www.studyplan.dev/sdl)
5. [SDL Wiki](https://wiki.libsdl.org/SDL2/FrontPage)
6. [Archived Strivix blog](https://web.archive.org/web/20220615030917/https://www.strivix.com/learn-programming/learn-sdl/sdl-basics#Basic-Graphics)
7. SDL docs generated using Doxygen
