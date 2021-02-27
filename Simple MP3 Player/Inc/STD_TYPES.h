 /*
 * StdTypes.h
 *
 * Created: 12/1/2020 11:21:41 AM
 *  Author: Ahmed Ashraf
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char      		   u8;  //1 bytes
typedef signed   char         	   s8;  //1 bytes
typedef unsigned short int	  	   u16; //2 bytes
typedef signed   short int   	   s16; //2 bytes
typedef unsigned long  int   	   u32; //4 bytes
typedef signed   long  int  	   s32; //4 bytes
typedef unsigned long  long  	   u64; //8 bytes
typedef signed   long  long   	   s64; //8 bytes

#define NULLPTR ((void*)0)

#ifndef NULL
#define NULL  (void *)0
#endif

#endif /* STD_TYPES_H_ */
