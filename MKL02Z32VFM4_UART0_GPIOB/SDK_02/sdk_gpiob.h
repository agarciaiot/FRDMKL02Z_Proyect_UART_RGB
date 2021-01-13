/*! @file : sdk_gpiob.h
 * @author  Alvaro Luis Garcia Romero (Quote)
 * @version 1.0.0
 * @date    12/01/2021
 * @brief   Driver para 
 * @details
 *
 */
#ifndef SDK_GPIOB_H_
#define SDK_GPIOB_H_
/*******************************************************************************
 * Includes                                                                    *
 *******************************************************************************/
#include "fsl_common.h"

/*!
 * @addtogroup SDK_02
 * @{
 */
/*!
 * @addtogroup GPIOB
 * @{
 */
/*******************************************************************************
 * Public Definitions                                                          *
 *******************************************************************************/

/*******************************************************************************
 * External vars                                                               *
 *******************************************************************************/

/*******************************************************************************
 * Public vars                                                                 *
 *******************************************************************************/

/*******************************************************************************
 * Public Prototypes                                                           *
 *******************************************************************************/

/*@brief Asignación de Pin Led para funciones posteriores
 * */
uint8_t GPIOB_SetPortState(uint8_t *new_byte);

/*@brief Define la estructura inicial de dirección del pin LED
 * */
void GPIOB_SetUp(/*uint8_t *ptb_gpio_pin*/);

/*@brief  Control de Estado del pin LED condicionado a caracter ingresado por teclado
 * */
status_t GPIOB_SetOrClearLed(uint8_t *new_byte);


/** @} */ // end of GPIOB group

/** @} */ // end of SDK_02 group

#endif /* SDK_GPIOB_H_ */
