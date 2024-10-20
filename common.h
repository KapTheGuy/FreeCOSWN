#ifndef COMMON_H
#define COMMON_H

// Some nice typedefs, to standardise sizes across platforms.
// These typedefs are written for 32-bit X86.
typedef unsigned int   u32int;
typedef          int   s32int;
typedef unsigned short u16int;
typedef          short s16int;
typedef unsigned char  u8int;
typedef          char  s8int;

typedef u32int uint32;
typedef u16int uint16;
typedef u8int uint8;

typedef uint32 uint32_t;
typedef uint16 uint16_t;
typedef uint8 uint8_t;

typedef uint8_t bool;

typedef int int32_t;
typedef unsigned long long uint64_t;
typedef long long int64_t;

#define true 1
#define false 0

#define NULL        ((void*)0)

void outb(u16int port, u8int value);
u8int inb(u16int port);
u16int inw(u16int port);

#define PANIC(msg) panic(msg, __FILE__, __LINE__);
#define ASSERT(b) ((b) ? (void)0 : panic_assert(__FILE__, __LINE__, #b))

extern void panic(const char *message, const char *file, u32int line);
extern void panic_assert(const char *file, u32int line, const char *desc);

void printf(const char* fmt, ...);

#endif // COMMON_H
