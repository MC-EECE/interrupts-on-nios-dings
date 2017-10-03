/*
 * HexDisplay.c
 *
 *  Created on: Apr 21, 2015
 *      Author: brent.horine
 */
#include "alt_types.h"
#include "io.h"
#include "system.h"
#include "seven_seg_hex.h"
#include "seven_seg_bcd.h"

 extern volatile alt_u8 leading_zeros;
 extern volatile alt_u8 display_as_bcd;

void toggleBCDHEX(){
	display_as_bcd = !display_as_bcd;
}
void HexDisplay(alt_u32 * base, alt_u16 num) {
	leading_zeros = 0;
	if (display_as_bcd){
		seven_seg_bcd(base,num,leading_zeros);
	} else {
		seven_seg_hex(base, num, 0);// leading_zeros);
	}
}
