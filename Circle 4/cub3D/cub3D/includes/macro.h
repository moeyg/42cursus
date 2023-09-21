#ifndef MACRO_H
# define MACRO_H

/* Code color information */
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RESET "\033[0m"

# define TRUE 1
# define FALSE 0
# define INIT -1
# define ERROR -1
# define FAIL 1

/* Extension */
# define MAP_EXTENSION ".cub"
# define XPM_EXTENSION ".xpm"

/* Map information */
# define MAP_COMPONENT "01NSEW "
# define UNMOVABLE "1 "
# define MOVABLE "0NSEW"

/* Map background */
# define FLOOR "F "
# define CEILING "C "

/* Map direction */
# define NORTH "NO "
# define SOUTH "SO "
# define WEST "WE "
# define EAST "EA "

# define NO 1
# define SO 2
# define WE 3
# define EA 4
# define F 5
# define C 6
# define MAP 7

/* Game specifications */
# define SCREEN_WIDTH 1200
# define SCREEN_HEIGHT 680
# define FPS 0.1
# define ROTATION_ANGLE M_PI_4

/* Key event */
# define KEY_PRESS 2
# define KEY_EXIT 17
# define KEY_ESC 53

/* Arrow key */
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

/* Arrow key */
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2

#endif
