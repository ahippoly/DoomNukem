# DoomNukem
A reproduction of the legendary game "DooM" using raycasting (the original technique used to make the game)

![GameImage](https://i.imgur.com/gFTZF6D.png)

# Installation
First, you need to build the libraries required for the project to work with this command :
```
make install_libs
```

Then just compile the project with
```
make
```

# Usage
## Game

To launch the game :
```
./doom-nukem "map_file"
```
if no map is provided, the game will launch on the default editor map (maps/editor_map_0)

The map made for the game is called "PrisonBreak", you are Balkany and you need to escape the prison, good luck !
```
./doom-nukem maps/PrisonBreak
```

## Editor

You can edit / create a map with :
```
./editor "map_file"
```
if no map is provided, the editor will create a new map and output it on "maps/editor_map_0"

# Controls
## Game

### Mouse

```Move``` Rotate camera

```LeftClick``` Attack with the current weapon

```RightClick``` Aim if possible with the current weapon

### Keybinds

```ZQSD``` Move the player

```1 - 6``` Change Weapon

```Space``` Jump

```LeftCtrl``` Crouch

```LeftAlt``` Use Jetpack if in inventory

# In-Game Image
## Game
![GameImg2](https://i.imgur.com/39BD3eM.png)
![GameImg3](https://i.imgur.com/nl6Avag.png)
## Editor
![EditorImg1](https://i.imgur.com/PhnRpeq.png)
![EditorImg2](https://i.imgur.com/iV6OLib.png)
