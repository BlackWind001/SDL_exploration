if test -f ".temp/main.exe"; then
  rm .temp/main.exe
fi

gcc -I "SDL2/x86_64-w64-mingw32/include/" -L "SDL2/x86_64-w64-mingw32/bin/" -L "SDL2/x86_64-w64-mingw32/lib"\
 -o .temp/main.exe 01-animation/*.c -lSDL2 -lSDL2main

.temp/main.exe