#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

#include "avr/interrupt.h"
#include "AVR_UART_REG.h"
#include "UART_interface.h"
#include "SPI_interface.h"



int main()
{

	uint8_t recive;
	uint8_t send;

	  MCAL_SPI_SlaveInit();

	  MCAL_DIO_u8SetPinDir(PORTC,PIN2,DIO_OUTPUT);



	 while(1)
	 {
		 MCAL_SPI_Slave_DataBusyWait(send,&recive);

		 if(recive=='1')
		 {
			 MCAL_DIO_u8SetPinValue(PORTB,PIN0,DIO_HIGH);
		 }
	     else if (recive=='0')
	 {
		 MCAL_DIO_u8SetPinValue(PORTB,PIN0,DIO_LOW);

	 }
	 }
}
