/*! @file : sdk_gpiob.c
 * @author  Alvaro Luis Garcia Romero (Quote)
 * @version 1.0.0
 * @date    12/01/2021
 * @brief   Driver para 
 * @details
 *
*/
/*******************************************************************************
 * Includes                                                                    *
 *******************************************************************************/
#include "sdk_gpiob.h"
#include "fsl_gpio.h"
#include "fsl_port.h"

/*******************************************************************************
 * Definitions                                                                 *
 *******************************************************************************/

/*******************************************************************************
 * Private Prototypes                                                          *
 *******************************************************************************/

/*******************************************************************************
 * External vars                                                               *
 *******************************************************************************/

/*******************************************************************************
 * Private vars                                                                *
 *******************************************************************************/
volatile uint8_t new_byte_caracter[] = {'R','r','G','g','B','b'};
volatile uint8_t board_led_gpio_pin;
volatile uint8_t status_gpiob;

/*******************************************************************************
 * Private Source Code                                                         *
 *******************************************************************************/


/*******************************************************************************
 * Public Source Code                                                          *
 *******************************************************************************/
 
/*@brief Asignación de Pin Led para funciones posteriores
 *
 *@brief  Inicializar el pin LED condiconado a caracter ingresado por teclado:
 *
 * board_led_gpio_pin 	= 	6U  		!< Set pin RED 			(R or r)
 *						=	7U  		!< Set pin GREEN		(G or g)
 *						=	10U 		!< Set pin BLUE			(B or b)
 *
 * status_gpiob		 	= 	1U (ON)		!< Set 	 init Port Pin	(R or G or B)
 *						=	0U (OFF) 	!< Clear init Port Pin	(r or g or b)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
uint8_t GPIOB_SetPortState(uint8_t *new_byte, uint8_t *board_led_gpio_map) {
	uint8_t i = 0;
	uint8_t assing_nbc;
	uint8_t assing_blgm[] = {
			(uint8_t*)board_led_gpio_map[0],
			(uint8_t*)board_led_gpio_map[1],
			(uint8_t*)board_led_gpio_map[2]
	};
	for (i = 0; i <= 6; i++){
		if (*new_byte == new_byte_caracter[i]){
			assing_nbc = new_byte_caracter[i];
			if (assing_nbc == 'R'||assing_nbc == 'r'){
				board_led_gpio_pin = assing_blgm[0];
				if (assing_nbc == 'R')	status_gpiob = 1;
				if (assing_nbc == 'r')	status_gpiob = 0;
			}
			if (assing_nbc == 'G'||assing_nbc == 'g'){
				board_led_gpio_pin = assing_blgm[1];
				if (assing_nbc == 'G')	status_gpiob = 1;
				if (assing_nbc == 'g')	status_gpiob = 0;
			}
			if (assing_nbc == 'B'||assing_nbc == 'b'){
				board_led_gpio_pin = assing_blgm[2];
				if (assing_nbc == 'B')	status_gpiob = 1;
				if (assing_nbc == 'b')	status_gpiob = 0;
			}
		}
	}
	return (board_led_gpio_pin);
}

/*@brief Inicializa el Port B y Define la Estructura Inicial de Dirección para pin LED
 *
 *@brief Pin mux selection
 *
 *	_port_mux corresponding
 *
 *		kPORT_PinDisabledOrAnalog = 0U, !< Corresponding pin is disabled, but is used as an analog pin.
 * 	--> kPORT_MuxAsGpio = 1U,           !< Corresponding pin is configured as GPIO.
 *    	kPORT_MuxAlt2 = 2U,             !< Chip-specific
 *    	kPORT_MuxAlt3 = 3U,             !< Chip-specific
 *    	kPORT_MuxAlt4 = 4U,             !< Chip-specific
 *    	kPORT_MuxAlt5 = 5U,             !< Chip-specific
 *    	kPORT_MuxAlt6 = 6U,             !< Chip-specific
 *    	kPORT_MuxAlt7 = 7U,             !< Chip-specific
 *    	kPORT_MuxAlt8 = 8U,             !< Chip-specific
 *    	kPORT_MuxAlt9 = 9U,             !< Chip-specific
 *    	kPORT_MuxAlt10 = 10U,           !< Chip-specific
 *    	kPORT_MuxAlt11 = 11U,           !< Chip-specific
 *    	kPORT_MuxAlt12 = 12U,           !< Chip-specific
 *    	kPORT_MuxAlt13 = 13U,           !< Chip-specific
 *    	kPORT_MuxAlt14 = 14U,           !< Chip-specific
 *    	kPORT_MuxAlt15 = 15U,           !< Chip-specific
 *
 *@brief Pin direction
 *
 *	_gpio_pin_direction_t pinDirection (gpio_pin_direction_t pinDirection)
 *
 *	--> kGPIO_DigitalInput = 	0U,  !< Set current pin as digital input
 *  	kGPIO_DigitalOutput = 	1U,  !< Set current pin as digital output
 *
 * uint8_t outputLogic; !< Set a default output logic, which has no use in input
 *
 *	-->	default 0U
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void GPIOB_SetUp(){
	gpio_pin_config_t led_config;

	if (status_gpiob == 1){
		/* Init PORT B in Mux as GPIO*/
		PORT_SetPinMux(PORTB, board_led_gpio_pin, kPORT_MuxAsGpio);

		/* Init GPIO Pin in RGB Led*/
		GPIO_PinInit(GPIOB, board_led_gpio_pin, &led_config);
		led_config.pinDirection = kGPIO_DigitalOutput;
		led_config.outputLogic  = 0U;
	}
}

/*@brief  Control de Estado del pin LED condicionado a caracter ingresado por teclado
 *
 * 	board_led_gpio_pin	6U	,	status_gpiob	1U	->	(R) Clear pin LED_RED 	(ON)
 * 	board_led_gpio_pin	6U	,	status_gpiob	0U	->	(r) Set pin LED_RED 	(OFF)
 *
 * 	board_led_gpio_pin	6U	,	status_gpiob	1U	->	(G) Clear pin LED_GREEN	(ON)
 * 	board_led_gpio_pin	6U	,	status_gpiob	0U	->	(g) Set pin LED_GREEN 	(OFF)
 *
 * 	board_led_gpio_pin	6U	,	status_gpiob	1U	->	(B) Clear pin LED_BLUE 	(ON)
 * 	board_led_gpio_pin	6U	,	status_gpiob	0U	->	(b) Set pin LED_BLUE 	(OFF)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
status_t GPIOB_SetOrClearLed(uint8_t *new_byte){
	if (status_gpiob == 1)		GPIO_PortClear(GPIOB, 1U << board_led_gpio_pin);
	if (status_gpiob == 0)		GPIO_PortSet(GPIOB, 1U << board_led_gpio_pin);
	return 0;
}
