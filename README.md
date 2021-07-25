# cub3D

This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever.

The raycasting algorithm is taken from:
* [Ray-Casting Tutorial](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)

Minilibx library:
* [Minilibx documentation](https://harm-smits.github.io/42docs/libs/minilibx)
### compilation

```
make        - for building the project
make clean  - delete object files
make fclean - delete all
make re     - delete all and rebuilding it
make test   - delete object files
make screen - create a screenshot
```

### launching a project
a card with the .cub extension is submitted to the entrance.

```
./cub3D maps/cub2.cub
```
### this is a simple valid map

```
R 1411 1733                   - Screen resolution:  identifier: R (resolution in range [1,∞])
F 140, 0, 90                  - Floor color:        identifier: F (R,G,B colors in range [0,255])
C 150, 151, 3                 - Ceiling color:      identifier: C (R,G,B colors in range [0,255])

NO ./textures/WALL_NORD.xpm   - North texture:      identifier: NO (path to the north texure in .xpm format)
SO ./textures/WALL_SOUTH.xpm  - South texture:      identifier: SO (path to the south texure in .xpm format)
WE ./textures/WALL_WEST.xpm   - West texture:       identifier: WE (path to the west texure in .xpm format)
EA ./textures/WALL_EAST.xpm   - East texture:       identifier: ES (path to the east texure in .xpm format)
S ./textures/SPRITE.xpm       - Sprite texture:     identifier: S (path to the sprite texure in .xpm format)

111111                        - The map must be composed of only 7 possible characters: 0 for an empty space, 
100101                          1 for a wall, and N,S,E or W for the player’s start position and spawning orientation
101001
1100N1
111111
```
