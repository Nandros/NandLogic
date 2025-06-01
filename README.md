# NandLogic

## Installation

```bash
cmake -B build -S . -DRMLUI_BACKEND=SDL_SDLrenderer -DCMAKE_BUILD_TYPE=Debug
cmake --build build -j
cd build
make
```

## Notes

Use rectangle for element colision : include RmlUi/Core/Rectangle

## TODO

- [ ] Inputs/Ouputs
- [ ] Consol log for debug
- [ ] Window zoom
- [ ] Configuration
- [ ] Color Themes
- [ ] Text in configurable files (for differents languages)