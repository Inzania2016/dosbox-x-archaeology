/*
 *  Copyright (C) 2002-2021  The DOSBox Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

void DEBUG_SetupConsole(void);
void DEBUG_DrawScreen(void);
bool DEBUG_Breakpoint(void);
bool DEBUG_IntBreakpoint(uint8_t intNum);
void DEBUG_Enable(bool pressed);
void DEBUG_CheckExecuteBreakpoint(uint16_t seg, uint32_t off);
bool DEBUG_ExitLoop(void);
void DEBUG_RefreshPage(char scroll);
Bitu DEBUG_EnableDebugger(void);

extern Bitu cycle_count;
extern Bitu debugCallback;

#if C_DEBUG
bool DEBUG_TraceIsActive(void);
void DEBUG_TraceGuestAction(const char* action_label, const char* guest_key_name);
void DEBUG_TraceCodeHitCheck(void);
void DEBUG_TraceFileOpen(const char* name, const char* fullname, uint8_t flags, uint16_t entry, uint16_t handle, uint8_t drive, bool fcb);
void DEBUG_TraceFileRead(uint16_t handle, const char* name, uint16_t requested, uint16_t actual, bool ret, bool fcb);
void DEBUG_TraceFileSeek(uint16_t handle, const char* name, uint32_t pos, uint32_t type, bool ret, bool fcb);
void DEBUG_TraceFileClose(uint16_t handle, const char* name, uint8_t refs, bool ret, bool fcb);
#else
static inline bool DEBUG_TraceIsActive(void) {
	return false;
}
static inline void DEBUG_TraceGuestAction(const char* /*action_label*/, const char* /*guest_key_name*/) {
}
static inline void DEBUG_TraceCodeHitCheck(void) {
}
static inline void DEBUG_TraceFileOpen(const char* /*name*/, const char* /*fullname*/, uint8_t /*flags*/, uint16_t /*entry*/, uint16_t /*handle*/, uint8_t /*drive*/, bool /*fcb*/) {
}
static inline void DEBUG_TraceFileRead(uint16_t /*handle*/, const char* /*name*/, uint16_t /*requested*/, uint16_t /*actual*/, bool /*ret*/, bool /*fcb*/) {
}
static inline void DEBUG_TraceFileSeek(uint16_t /*handle*/, const char* /*name*/, uint32_t /*pos*/, uint32_t /*type*/, bool /*ret*/, bool /*fcb*/) {
}
static inline void DEBUG_TraceFileClose(uint16_t /*handle*/, const char* /*name*/, uint8_t /*refs*/, bool /*ret*/, bool /*fcb*/) {
}
#endif

#ifdef C_HEAVY_DEBUG
bool DEBUG_HeavyIsBreakpoint(void);
void DEBUG_HeavyWriteLogInstruction(void);
#endif
