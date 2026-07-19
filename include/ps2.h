#ifndef PS2_H
#define PS2_H

#define PS2_DATA   0x60
#define PS2_STATUS 0x64
#define PS2_CMD    0x64

#define PS2_CMD_ENABLE_AUX    0xa8
#define PS2_CMD_READ_CONFIG   0x20
#define PS2_CMD_WRITE_CONFIG  0x60
#define PS2_CMD_WRITE_MOUSE   0xd4

#define MOUSE_CMD_SET_DEFAULTS 0xf6
#define MOUSE_CMD_ENABLE       0xf4

#endif
