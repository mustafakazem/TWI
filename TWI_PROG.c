/*
 * TWI_PROG.c
 *
 * Created: 3/9/2023 4:39:45 PM
 *  Author: sata
 */ 
#include "TWI_private.h"
#include "TWI_config.h"
#include "TWI_init.h"
#include "std_types.h"
#include "math.h"
#include "bit_math.h"

void I2C_MasterInit(u8 addr){
	TWBR=10;
	#if pre_scaler==Pre_scaler_1
	CLEAR_BIT(TWSR,TWPS0);
	CLEAR_BIT(TWSR,TWPS1);
	
	#elif pre_scaler==Pre_scaler_4
	SET_BIT(TWSR,TWPS0);
	CLEAR_BIT(TWSR,TWPS1);
	
	#elif pre_scaler==Pre_scaler_16
	CLEAR_BIT(TWSR,TWPS0);
	SET_BIT(TWSR,TWPS1);
	#elif pre_scaler==Pre_scaler_64
	SET_BIT(TWSR,TWPS0);
	SET_BIT(TWSR,TWPS1);	
	#endif
	TWAR=(addr<<1);
}


void I2C_SlaveInit(u8 addr){
	TWBR=10;
	#if pre_scaler==Pre_scaler_1
	CLEAR_BIT(TWSR,TWPS0);
	CLEAR_BIT(TWSR,TWPS1);
	
	#elif pre_scaler==Pre_scaler_4
	SET_BIT(TWSR,TWPS0);
	CLEAR_BIT(TWSR,TWPS1);
	
	#elif pre_scaler==Pre_scaler_16
	CLEAR_BIT(TWSR,TWPS0);
	SET_BIT(TWSR,TWPS1);
	#elif pre_scaler==Pre_scaler_64
	SET_BIT(TWSR,TWPS0);
	SET_BIT(TWSR,TWPS1);
	#endif
	TWCR=(1<<TWEN)|(1<<TWEA)|(1<<TWINT);
	TWAR=(addr<<1);
}


boolean I2C_StartCondition(void){
	boolean condition=FALSE;
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	 while(!(TWCR&(1<<TWINT)));
	if(TWSR==0x08){
	condition=TRUE;
	}
	else{
	condition= FALSE;
	}
	return condition;
}


boolean I2C_RepeatedStartCondition(void){
	boolean condition=FALSE;
	 TWCR=(1<<TWSTA)|(1<<TWEN)|(1<<TWINT);
	 	while(!(TWCR&(1<<TWINT)));
	  if(TWSR==0x10){
		  condition=TRUE;
	  }
	  else{
		  condition= FALSE;
	  }
	  return condition;
}

void I2C_StopCondition(void){
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);	
	 while(TWCR&(1<<TWSTO));
}

boolean I2C_WriteByte(u8 data){
	TWDR=data;
	boolean condition=FALSE;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(!(TWCR&(1<<TWINT)));
	u8 status=I2C_ReadStatus();
	if(status==0x28){
		condition=TRUE;
	}
	else{
		condition=FALSE;
	}
	return condition;
}

boolean I2C_Send_SlaveAddressWriteOperation(u8 addr){
	boolean condition =FALSE;
	
	u8 status=I2C_ReadStatus();
	if(status==0x08){
		TWDR=(addr<<1);
		CLEAR_BIT(TWDR,0);
		CLEAR_BIT(TWCR,TWSTA);
		SET_BIT( TWCR,TWINT);
		while(!(TWCR & (1<<TWINT)));
		u8 curr_status=I2C_ReadStatus();
		if(curr_status==0x18){
			condition=TRUE;
		}
		else{
			condition=FALSE;
		}
	}	
	return condition;
}

boolean I2C_Send_SlaveAddressReadOperation(u8 addr){
	boolean condition =TRUE;
	TWDR=(addr<<1);
	SET_BIT(TWDR,0);
	CLEAR_BIT(TWCR,TWSTA);
	SET_BIT(TWCR,TWINT);
	while (!(TWCR &  (1<<TWINT)));
	
if (I2C_ReadStatus()!=0x40)
{
	condition= FALSE;
}
return condition;
}

u8 I2C_ReadByte(void){
	TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA); 
	while(!(TWCR&(1<<TWINT)));	
	return TWDR;
}

u8 I2C_ReadStatus(void){
	return TWSR&0xF8;
}