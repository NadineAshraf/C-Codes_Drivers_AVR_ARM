/*************************************************************/
/*************************************************************/
/**************   Author : Nadine Ashraf Adeeb   *************/ 
/**************            Layer:MCAL            *************/ 
/**************             SWC: EXTI            *************/ 
/**************            Version:v1.0          *************/ 
/**************    Date: 11 September,2022       *************/
/*************************************************************/
/*************************************************************/
#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*Options:
            ENABLE
            DISABLE
*/
#define         EXTI_INT0_ENABLE        ENABLE
#define         EXTI_INT1_ENABLE        ENABLE
#define         EXTI_INT2_ENABLE        ENABLE

/* Options:
            FALLING_EDGE
            RISING_EDGE
            ON_CHANGE
            LOW_LEVEL
*/
#define         EXTI_INT0_SENSE_CTRL    FALLING_EDGE
#define         EXTI_INT1_SENSE_CTRL    FALLING_EDGE
#define         EXTI_INT2_SENSE_CTRL    FALLING_EDGE

#endif