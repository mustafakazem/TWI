/*
 * TWI_private.h
 *
 * Created: 3/9/2023 4:39:26 PM
 *  Author: sata
 */ 


#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

#define TWCR    (*(volatile u8*)(0x56))

#define  TWIE	0

#define  TWEN	2
#define  TWWC	3
#define  TWSTO	4
#define  TWSTA	5
#define  TWEA	6
#define  TWINT	7


#define TWSR	(*(volatile u8*)(0x21))


#define  TWPS0	0
#define  TWPS1	1

#define  TWS3	3
#define  TWS4	4
#define  TWS5	5
#define  TWS6	6
#define  TWS7	7


#define TWBR	(*(volatile u8*)(0x20))

#define TWBR0     0
#define TWBR1     1
#define TWBR2     2
#define TWBR3     3
#define TWBR4     4
#define TWBR5     5
#define TWBR6     6
#define TWBR7     7

#define TWDR	(*(volatile u8*)(0x23))

#define  TWDR0	0
#define  TWDR1	1

#define  TWDR2	2
#define  TWDR3	3
#define  TWDR4	4
#define  TWDR5	5
#define  TWDR6	6
#define  TWDR7	7


#define TWAR	(*(volatile u8*)(0x22))

#define TWGCE	0
#define TWA0	1	
#define TWA1	2
#define TWA2	3
#define TWA3	4
#define TWA4	5
#define TWA5	6
#define TWA6	7

#endif /* TWI_PRIVATE_H_ */