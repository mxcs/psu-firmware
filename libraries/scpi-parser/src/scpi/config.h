/*-
 * Copyright (c) 2012-2013 Jan Breuer,
 *
 * All Rights Reserved
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file   config.h
 * @date   Wed Mar 20 12:21:26 UTC 2013
 *
 * @brief  SCPI Configuration
 *
 *
 */

#ifndef __SCPI_CONFIG_H_
#define __SCPI_CONFIG_H_

#ifdef	__cplusplus
extern "C" {
#endif

// This is automatically added by the build-arduino-library.py
#define SCPI_USER_CONFIG 1

#ifdef SCPI_USER_CONFIG
#include "scpi_user_config.h"
#endif

/* set the termination character(s)   */
#define LINE_ENDING_CR          "\r"    /*   use a <CR> carriage return as termination charcter */
#define LINE_ENDING_LF          "\n"    /*   use a <LF> line feed as termination charcter */
#define LINE_ENDING_CRLF        "\r\n"  /*   use <CR><LF> carriage return + line feed as termination charcters */

#ifndef SCPI_LINE_ENDING
#define SCPI_LINE_ENDING        LINE_ENDING_CRLF
#endif

/**
 * Detect, if it has limited resources or it is running on a full blown operating system.
 * All values can be overiden by scpi_user_config.h
 */
#define SYSTEM_BARE_METAL 0
#define SYSTEM_FULL_BLOWN 1

/* This should cover all windows compilers (msvc, mingw, cvi) and all Linux/OSX/BSD and other UNIX compatible systems (gcc, clang) */
#if defined(_WIN32) || defined(_WIN64) || defined(__unix) || defined(__unix__) || defined(__APPLE__)
#define SYSTEM_TYPE SYSTEM_FULL_BLOWN
#else
#define SYSTEM_TYPE SYSTEM_BARE_METAL
#endif

/**
 * Enable full error list
 * 0 = Minimal set of errors
 * 1 = Full set of errors
 *
 * For small systems, full set of errors will occupy large ammount of data
 * It is enabled by default on full blown systems and disabled on limited bare metal systems
 */
#ifndef USE_FULL_ERROR_LIST
#define USE_FULL_ERROR_LIST SYSTEM_TYPE
#endif

/**
 * Enable also LIST_OF_USER_ERRORS to be included
 * 0 = Use only library defined errors
 * 1 = Use also LIST_OF_USER_ERRORS
 */
#ifndef USE_USER_ERROR_LIST
#define USE_USER_ERROR_LIST 0
#endif

#ifndef USE_COMMAND_TAGS
#define USE_COMMAND_TAGS 1
#endif

#ifndef USE_64K_PROGMEM_FOR_CMD_LIST
#define USE_64K_PROGMEM_FOR_CMD_LIST 0
#endif

#ifndef USE_FULL_PROGMEM_FOR_CMD_LIST
#define USE_FULL_PROGMEM_FOR_CMD_LIST 0
#endif

#ifndef USE_64K_PROGMEM_FOR_ERROR_MESSAGES
#define USE_64K_PROGMEM_FOR_ERROR_MESSAGES 0
#endif

#ifndef USE_FULL_PROGMEM_FOR_ERROR_MESSAGES
#define USE_FULL_PROGMEM_FOR_ERROR_MESSAGES 0
#endif

#ifndef USE_DEPRECATED_FUNCTIONS
#define USE_DEPRECATED_FUNCTIONS 1
#endif

#ifndef USE_CUSTOM_DTOSTR
#define USE_CUSTOM_DTOSTR 0
#endif

#ifndef USE_UNITS_IMPERIAL
#define USE_UNITS_IMPERIAL 0
#endif

#ifndef USE_UNITS_ANGLE
#define USE_UNITS_ANGLE SYSTEM_TYPE
#endif

#ifndef USE_UNITS_PARTICLES
#define USE_UNITS_PARTICLES SYSTEM_TYPE
#endif

#ifndef USE_UNITS_DISTANCE
#define USE_UNITS_DISTANCE SYSTEM_TYPE
#endif

#ifndef USE_UNITS_MAGNETIC
#define USE_UNITS_MAGNETIC SYSTEM_TYPE
#endif

#ifndef USE_UNITS_LIGHT
#define USE_UNITS_LIGHT SYSTEM_TYPE
#endif

#ifndef USE_UNITS_ENERGY_FORCE_MASS
#define USE_UNITS_ENERGY_FORCE_MASS SYSTEM_TYPE
#endif

#ifndef USE_UNITS_TIME
#define USE_UNITS_TIME SYSTEM_TYPE
#endif

#ifndef USE_UNITS_TEMPERATURE
#define USE_UNITS_TEMPERATURE SYSTEM_TYPE
#endif

#ifndef USE_UNITS_RATIO
#define USE_UNITS_RATIO SYSTEM_TYPE
#endif

#ifndef USE_UNITS_POWER
#define USE_UNITS_POWER 1
#endif

#ifndef USE_UNITS_FREQUENCY
#define USE_UNITS_FREQUENCY 1
#endif

#ifndef USE_UNITS_ELECTRIC
#define USE_UNITS_ELECTRIC 1
#endif

#ifndef USE_UNITS_ELECTRIC_CHARGE_CONDUCTANCE
#define USE_UNITS_ELECTRIC_CHARGE_CONDUCTANCE SYSTEM_TYPE
#endif

/* Compiler specific */
/* RealView/Keil ARM Compiler, e.g. Cortex-M CPUs */
#if defined(__CC_ARM)
#define HAVE_STRNLEN            0
#define HAVE_STRNCASECMP        1
#define HAVE_STRNICMP           0
#endif

/* National Instruments (R) CVI x86/x64 PC platform */
#if defined(_CVI_)
#define HAVE_STRNLEN            0
#define HAVE_STRNCASECMP        0
#define HAVE_STRNICMP           1
#define HAVE_STDBOOL            0
#endif

/* 8bit PIC - PIC16, etc */
#if defined(_MPC_)
#define HAVE_STRNLEN            0
#define HAVE_STRNCASECMP        0
#define HAVE_STRNICMP           1
#endif

/* PIC24 */
#if defined(__C30__)
#define HAVE_STRNLEN            0
#define HAVE_STRNCASECMP        0
#define HAVE_STRNICMP           0
#endif

/* PIC32mx */
#if defined(__C32__)
#define HAVE_STRNLEN            0
#define HAVE_STRNCASECMP        1
#define HAVE_STRNICMP           0
#endif

/* AVR libc */
#if defined(__AVR__)
#include <stdlib.h>
#define HAVE_DTOSTRE            1
#endif

/* ======== test strnlen ======== */
#ifndef HAVE_STRNLEN
#define HAVE_STRNLEN            1
#endif
/* ======== test strncasecmp ======== */
#ifndef HAVE_STRNCASECMP
#define HAVE_STRNCASECMP        1
#endif
/* ======== test strnicmp ======== */
#ifndef HAVE_STRNICMP
#define HAVE_STRNICMP           0
#endif

#ifndef HAVE_STDBOOL
#define HAVE_STDBOOL            1
#endif

/* define local macros depending on existance of strnlen */
#if HAVE_STRNLEN
#define SCPIDEFINE_strnlen(s, l)	strnlen((s), (l))
#else
#define SCPIDEFINE_strnlen(s, l)	BSD_strnlen((s), (l))
#endif

/* define local macros depending on existance of strncasecmp and strnicmp */
#if HAVE_STRNCASECMP
#define SCPIDEFINE_strncasecmp(s1, s2, l) strncasecmp((s1), (s2), (l))
#elif HAVE_STRNICMP
#define SCPIDEFINE_strncasecmp(s1, s2, l) strnicmp((s1), (s2), (l))
#else
#define SCPIDEFINE_strncasecmp(s1, s2, l) OUR_strncasecmp((s1), (s2), (l))
#endif

#if HAVE_DTOSTRE
#define SCPIDEFINE_floatToStr(v, s, l) strlen(dtostre((double)(v), (s), 6, DTOSTR_PLUS_SIGN | DTOSTR_ALWAYS_SIGN | DTOSTR_UPPERCASE))
#elif USE_CUSTOM_DTOSTRE
#define SCPIDEFINE_floatToStr(v, s, l) strlen(SCPI_dtostre((v), (s), (l), 6, 0))
#else
#define SCPIDEFINE_floatToStr(v, s, l) snprintf((s), (l), "%g", (v))
#endif

#if HAVE_DTOSTRE
#define SCPIDEFINE_doubleToStr(v, s, l) strlen(dtostre((v), (s), 15, DTOSTR_PLUS_SIGN | DTOSTR_ALWAYS_SIGN | DTOSTR_UPPERCASE))
#elif USE_CUSTOM_DTOSTRE
#define SCPIDEFINE_doubleToStr(v, s, l) strlen(SCPI_dtostre((v), (s), (l), 15, 0))
#else
#define SCPIDEFINE_doubleToStr(v, s, l) snprintf((s), (l), "%.15lg", (v))
#endif


#ifdef	__cplusplus
}
#endif

#endif
