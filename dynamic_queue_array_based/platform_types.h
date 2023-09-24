//
// Created by Blu-ray on 8/20/2023.
//

#ifndef QUEUE_ARRAY_BASED_PLATFORM_TYPES_H
#define QUEUE_ARRAY_BASED_PLATFORM_TYPES_H

#define CPU_TYPE_8 8
#define CPU_TYPE_16 16
#define CPU_TYPE_32 32
#define CPU_TYPE_64 64
/**********************************************************************************/
#define CPU_TYPE (CPU_TYPE_64)
/**********************************************************************************/
#if (CPU_TYPE == CPU_TYPE_64)
typedef unsigned char boolean;
typedef unsigned char u8int;
typedef unsigned short u16int;
typedef unsigned int u32int;
typedef unsigned long long int u64int;
typedef signed char s8int;
typedef signed short s16int;
typedef signed int s32int;
typedef signed long long int s64int;
typedef float float32;
typedef double float64;
typedef long double float128;

#elif (CPU_TYPE == CPU_TYPE_32)
typedef unsigned char boolean;
typedef unsigned char u8int;
typedef unsigned short u16int;
typedef unsigned int u32int;
typedef unsigned long long int u64int;
typedef signed char s8int;
typedef signed short s16int;
typedef signed int s32int;
typedef signed long long int s64int;
typedef float float32;
typedef double float64;
typedef long double float128;

#elif (CPU_TYPE == CPU_TYPE_16)
typedef unsigned char boolean;
typedef unsigned char u8int;
typedef unsigned int u16int;
typedef unsigned long u32int;
typedef unsigned long long int u64int;
typedef signed char s8int;
typedef signed int s16int;
typedef signed long s32int;
typedef signed long long int s64int;
typedef float float32;
typedef double float64;
typedef long double float128;

#elif (CPU_TYPE == CPU_TYPE_8)
typedef unsigned char boolean;
typedef unsigned char u8int;
typedef unsigned int u16int;
typedef unsigned long u32int;
typedef unsigned long long int u64int;
typedef signed char s8int;
typedef signed int s16int;
typedef signed long s32int;
typedef signed long long int s64int;
typedef float float32;
typedef double float64;
typedef long double float128;

#endif
#endif //QUEUE_ARRAY_BASED_PLATFORM_TYPES_H
