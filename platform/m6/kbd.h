#ifndef M6_KBD_H
#define M6_KBD_H

extern void _GetKbdState(long*);
extern void _post_msg_3_to_physw_releasesw(void);

typedef struct {
	long bit;           // bitmask in physw_status
	unsigned chdkstate; // nonzero if pressed
	unsigned presse;    // press levent
	unsigned unpresse;  // unpress levent
} ssymkeys;

#endif
