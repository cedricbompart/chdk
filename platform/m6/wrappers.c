#include "../generic/wrappers.c"

long lens_get_focus_pos() {
	return _GetFocusLensSubjectDistance();
}

long lens_get_focus_pos_from_lens() {
	return _GetFocusLensSubjectDistanceFromLens();
}

long lens_get_target_distance() {
	return _GetCurrentTargetDistance();
}

int _EngDrvRead(int gpio_reg) {
	extern int _EngDrvRead_FW(int*);
	return _EngDrvRead_FW(&gpio_reg);
}

// DoMFLock: use _MFOn/_MFOff or _PT_MFOn/_PT_MFOff or _SS_MFOn/_SS_MFOff if defined in stubs_entry.S 
int DoMFLock(void) {
	if (!camera_info.state.mode_play) {
		_PT_MFOn();
		return (1);
	}
	return (0);
}

int UnlockMF(void) {
	if (!camera_info.state.mode_play) {
		_PT_MFOff();
		return (1);
	}
	return (0);
}
