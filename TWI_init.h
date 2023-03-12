/*
 * TWI_init.h
 *
 * Created: 3/9/2023 4:41:25 PM
 *  Author: sata
 */ 



#ifndef TWI_INIT_H_
#define TWI_INIT_H_
//#define BITRATE(TWSR)	((F_CPU/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1)))))
#include "std_types.h"


#define Pre_scaler_1		0

#define Pre_scaler_4		1

#define Pre_scaler_16		2

#define Pre_scaler_64		3




void I2C_MasterInit(u8 addr);
void I2C_SlaveInit(u8 addr);
boolean I2C_StartCondition(void);			//done
boolean I2C_RepeatedStartCondition(void);	//done
void I2C_StopCondition(void);				//done
boolean I2C_WriteByte(u8 data);				//done
boolean I2C_Send_SlaveAddressWriteOperation(u8 addr); //done
boolean I2C_Send_SlaveAddressReadOperation(u8 addr); 
u8 I2C_ReadByte(void);								 //done
u8 I2C_ReadStatus(void);							 //done

#endif /* TWI_INIT_H_ */