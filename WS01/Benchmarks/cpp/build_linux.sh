cmake -S ./ -B ./build_linux
cmake --build ./build_linux --config Release
cmake --install ./build_linux --prefix ./
