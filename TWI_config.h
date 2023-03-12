/*
 * TWI_config.h
 *
 * Created: 3/9/2023 4:39:01 PM
 *  Author: sata
 */ 


#ifndef TWI_CONFIG_H_
#define TWI_CONFIG_H_

#define F_CPU 16000000UL

#define BITRATE(TWSR)	((F_CPU/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1)))))


#define pre_scaler Pre_scaler_1




#endif /* TWI_CONFIG_H_ */