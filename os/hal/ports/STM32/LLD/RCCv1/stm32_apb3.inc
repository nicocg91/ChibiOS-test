/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    RCCv1/stm32_apb2.inc
 * @brief   Shared APB3 clock handler.
 *
 * @addtogroup STM32_APB3_HANDLER
 * @{
 */

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#if defined(RCC_CFGR_PPRE3_Pos)
#define STM32_PPRE3_POS         RCC_CFGR_PPRE3_Pos
#elif defined(RCC_CFGR2_PPRE2_Pos)
#define STM32_PPRE3_POS         RCC_CFGR2_PPRE3_Pos
#else
#error "unknown register name"
#endif

/**
 * @name    PPRE3 field bits definitions
 * @{
 */
#define STM32_PPRE3_MASK        (7U << STM32_PPRE3_POS)
#define STM32_PPRE3_FIELD(n)    ((n) << STM32_PPRE3_POS)
#define STM32_PPRE3_DIV1        STM32_PPRE3_FIELD(0U)
#define STM32_PPRE3_DIV2        STM32_PPRE3_FIELD(4U)
#define STM32_PPRE3_DIV4        STM32_PPRE3_FIELD(5U)
#define STM32_PPRE3_DIV8        STM32_PPRE3_FIELD(6U)
#define STM32_PPRE3_DIV16       STM32_PPRE3_FIELD(7U)
/** @} */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/* Registry checks for robustness.*/

/* Checks on configurations.*/
#if !defined(STM32_PPRE3)
#error "STM32_PPRE3 not defined in mcuconf.h"
#endif

/* Input checks.*/
#if !defined(STM32_PCLK3_MAX)
#error "STM32_PCLK3_MAX not defined in hal_lld.h"
#endif

#if !defined(STM32_HCLK)
#error "STM32_HCLK not defined in hal_lld.h"
#endif

/**
 * @brief   APB3 frequency.
 */
#if (STM32_PPRE3 == STM32_PPRE3_DIV1) || defined(__DOXYGEN__)
#define STM32_PCLK3                 (STM32_HCLK / 1U)

#elif STM32_PPRE3 == STM32_PPRE3_DIV2
#define STM32_PCLK3                 (STM32_HCLK / 2U)

#elif STM32_PPRE3 == STM32_PPRE3_DIV4
#define STM32_PCLK3                 (STM32_HCLK / 4U)

#elif STM32_PPRE3 == STM32_PPRE3_DIV8
#define STM32_PCLK3                 (STM32_HCLK / 8U)

#elif STM32_PPRE3 == STM32_PPRE3_DIV16
#define STM32_PCLK3                 (STM32_HCLK / 16U)

#else
#error "invalid STM32_PPRE3 value specified"
#endif

/*
 * APB3 frequency check.
 */
#if STM32_PCLK3 > STM32_PCLK3_MAX
#error "STM32_PCLK3 exceeding maximum frequency (STM32_PCLK3_MAX)"
#endif

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/** @} */
