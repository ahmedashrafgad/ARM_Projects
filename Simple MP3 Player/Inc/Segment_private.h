/*
 * Segment_private.h
 *
 *  Created on: Feb 5, 2021
 *      Author: Ahmed Ashraf
 */
//#ifndef SEGMENT_PRIVATE_H_
#define SEGMENT_PRIVATE_H_


#if   defined(SEGMENT_CATHODE)
u8 SegmentUnit[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
u8 SegmentTenth[]={0b0000111111,0b0000000110,0b0001011011,0b0001001111,0b0001100110,0b0001101101,0b0001111101,0b0000000111,0b0001111111,0b0001101111};



#elif defined(SEGMENT_ANODE)
u8 Segment[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};


#endif /* SEGMENT_PRIVATE_H_ */
