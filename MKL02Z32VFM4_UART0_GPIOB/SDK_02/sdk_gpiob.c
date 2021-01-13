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
#include "sdk_uart0.h"
#include "fsl_gpio.h"

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

/*******************************************************************************
 * Private Source Code                                                         *
 *******************************************************************************/


/*******************************************************************************
 * Public Source Code                                                          *
 *******************************************************************************/
 
/*@brief Asignación de Pin Led para funciones posteriores
 * */
/*@brief  Inicializar el pin LED condiconado a caracter ingresado por teclado:
 * board_led_gpio_pin = 6U  !< Set pin RED 		(R)
 *						7U  !< Set pin GREEN	(G)
 *						10U !< Set pin BLUE		(B)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
uint8_t GPIOB_SetPortState(uint8_t *new_byte) {
	uint8_t i = 0U;
	for (i = 0U; i <= 6U; i++){
		if (*new_byte == new_byte_caracter[i]){
			if (new_byte_caracter[i] == 'R'||new_byte_caracter[i] == 'r'){
				board_led_gpio_pin = 6U;
			}
			if (new_byte_caracter[i] == 'G'||new_byte_caracter[i] == 'g'){
				board_led_gpio_pin = 7U;
			}
			if (new_byte_caracter[i] == 'B'||new_byte_caracter[i] == 'b'){
				board_led_gpio_pin = 10U;
			}
		}
	}
	return (board_led_gpio_pin);
}

/*@brief Define la estructura inicial de dirección del pin LED
 * gpio_pin_direction_t pinDirection (gpio_pin_direction_t pinDirection)
 *
 *		kGPIO_DigitalInput = 	0U,  !< Set current pin as digital input
 *   	kGPIO_DigitalOutput = 	1U,  !< Set current pin as digital output
 *
 * uint8_t outputLogic; !< Set a default output logic, which has no use in input
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void GPIOB_SetUp(){
	gpio_pin_config_t led_config;

	GPIO_PinInit(GPIOB, board_led_gpio_pin, &led_config);
	led_config.pinDirection = kGPIO_DigitalOutput;
	led_config.outputLogic  = 0U;
}

/*@brief  Control de Estado del pin LED condicionado a caracter ingresado por teclado
 *
 * 		board_led_gpio_pin =
 *
 * 				6U  !< (R) Clear pin LED_RED (ON) 	(r) Set pin LED_RED (OFF)
 *				7U  !< (G) Clear pin LED_GREEN (ON)	(g)	Set pin LED_GREEN (OFF)
 *				10U !< (B) Clear pin LED_BLUE (ON)	(b) Set pin LED_BLUE (OFF)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
status_t GPIOB_SetOrClearLed(uint8_t *new_byte){
	if (*new_byte == 'R' || *new_byte == 'G' || *new_byte == 'B'){
		GPIO_PortClear(GPIOB, 1U << board_led_gpio_pin);
	}
	if (*new_byte == 'r' || *new_byte == 'g' || *new_byte == 'b'){
		GPIO_PortSet(GPIOB, 1U << board_led_gpio_pin);
	}else{
		GPIO_PortSet(GPIOB, 1U << 1U);
	}
	return 0;
}
