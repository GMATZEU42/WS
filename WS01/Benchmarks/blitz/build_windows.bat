cmake -S ./ -B ./build_win
cmake --build ./build_win --config Release

copy "%cd%\build_win\Release\matrix_square.exe" "%cd%\matrix_square.exe"