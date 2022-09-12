/*************************************************************/
/*************************************************************/
/**************   Author : Nadine Ashraf Adeeb   *************/ 
/**************            Layer:MCAL            *************/ 
/**************             SWC: EXTI            *************/ 
/**************            Version:v1.0          *************/ 
/**************    Date: 11 September,2022       *************/
/*************************************************************/
/*************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_Interface.h"
#include "EXTI_Register.h"
#include "EXTI_Private.h" 
#include "EXTI_Config.h"

/* Global pointer to function to hold INT0 ISR Address*/
void (*EXTIGlobal_pvInt0NotificationFunction)(void) = NULL;
/* Global pointer to function to hold INT1 ISR Address*/
void (*EXTIGlobal_pvInt1NotificationFunction)(void) = NULL;
/* Global pointer to function to hold INT2 ISR Address*/
void (*EXTIGlobal_pvInt2NotificationFunction)(void) = NULL;

     /* Pre-Build / Pre-Compiled */
void EXTI_voidINT0Init(void)
{
	#if  EXTI_INT0_ENABLE == ENABLE
	/* Peripheral Interrupt Enable for INT0 */
	   SET_BIT(GICR, GICR_INT0);
	   /* Check Sense Control for INT0 */
	  #if EXTI_INT0_SENSE_CTRL == LOW_LEVEL  
	      CLR_BIT(MCUCR, MCUCR_ISC01);
	      CLR_BIT(MCUCR, MCUCR_ISC00);
	  #elif EXTI_INT0_SENSE_CTRL == ON_CHANGE  
	      CLR_BIT(MCUCR, MCUCR_ISC01);
	      SET_BIT(MCUCR, MCUCR_ISC00);
	  #elif EXTI_INT0_SENSE_CTRL == FALLING_EDGE 
	      SET_BIT(MCUCR, MCUCR_ISC01);
	      CLR_BIT(MCUCR, MCUCR_ISC00);
	  #elif EXTI_INT0_SENSE_CTRL == RISING_EDGE
	      SET_BIT(MCUCR, MCUCR_ISC01);
	      SET_BIT(MCUCR, MCUCR_ISC00);
	   #else 
		   #error "EXTI_INT0_SENSE_CTRL Error Configuration"
	   #endif
	#elif  EXTI_INT0_ENABLE == DISABLE
	     CLR_BIT(GICR, GICR_INT0);
    #else 
		   #error "EXTI_INT0_ENABLE Error Configuration"
	#endif
	
	
}
void EXTI_voidINT1Init(void)
{
	#if  EXTI_INT1_ENABLE == ENABLE
	/* Peripheral Interrupt Enable for INT0 */
	   SET_BIT(GICR, GICR_INT1);
	  #if EXTI_INT1_SENSE_CTRL == LOW_LEVEL  
	      CLR_BIT(MCUCR, MCUCR_ISC11);
	      CLR_BIT(MCUCR, MCUCR_ISC10);
	  #elif EXTI_INT1_SENSE_CTRL == ON_CHANGE  
	      CLR_BIT(MCUCR, MCUCR_ISC11);
	      SET_BIT(MCUCR, MCUCR_ISC10);
	  #elif EXTI_INT1_SENSE_CTRL == FALLING_EDGE 
	      SET_BIT(MCUCR, MCUCR_ISC11);
	      CLR_BIT(MCUCR, MCUCR_ISC10);
	  #elif EXTI_INT1_SENSE_CTRL == RISING_EDGE
	      SET_BIT(MCUCR, MCUCR_ISC11);
	      SET_BIT(MCUCR, MCUCR_ISC10);
	   #else 
		   #error "EXTI_INT1_SENSE_CTRL Error Configuration"
	   #endif
	#elif  EXTI_INT1_ENABLE == DISABLE
	     CLR_BIT(GICR, GICR_INT1);
    #else 
		   #error "EXTI_INT1_ENABLE Error Configuration"
	#endif
	
	
}

void EXTI_voidINT2Init(void)
{
	#if  EXTI_INT2_ENABLE == ENABLE
	/* Peripheral Interrupt Enable for INT0 */
	   SET_BIT(GICR, GICR_INT2);
	 
	  #if EXTI_INT0_SENSE_CTRL == FALLING_EDGE 
	      CLR_BIT( MCUCSR, MCUCSR_INT2);
	  #elif EXTI_INT0_SENSE_CTRL == RISING_EDGE
	      SET_BIT( MCUCSR, MCUCSR_INT2);
	  #else 
		   #error "EXTI_INT2_SENSE_CTRL Error Configuration"
	  #endif
	#elif  EXTI_INT2_ENABLE == DISABLE
	     CLR_BIT(GICR, GICR_INT2);
    #else 
		   #error "EXTI_INT2_ENABLE Error Configuration"
	#endif
	
}
     /* Post-Build Configurations */
u8 EXTI_u8INT0SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Sense)
	{
		case LOW_LEVEL:
		               CLR_BIT(MCUCR, MCUCR_ISC01);
	                   CLR_BIT(MCUCR, MCUCR_ISC00);
					   break;
		case ON_CHANGE:
		               CLR_BIT(MCUCR, MCUCR_ISC01);
	                   SET_BIT(MCUCR, MCUCR_ISC00);
					   break;
	    case FALLING_EDGE:
		               SET_BIT(MCUCR, MCUCR_ISC01);
	                   CLR_BIT(MCUCR, MCUCR_ISC00);
					   break;
	    case RISING_EDGE:
		               SET_BIT(MCUCR, MCUCR_ISC01);
	                   SET_BIT(MCUCR, MCUCR_ISC00);
					   break;
	    default: Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8INT1SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Sense)
	{
		case LOW_LEVEL:
		               CLR_BIT(MCUCR, MCUCR_ISC11);
	                   CLR_BIT(MCUCR, MCUCR_ISC10);
					   break;
		case ON_CHANGE:
		               CLR_BIT(MCUCR, MCUCR_ISC11);
	                   SET_BIT(MCUCR, MCUCR_ISC10);
					   break;
	    case FALLING_EDGE:
		              SET_BIT(MCUCR, MCUCR_ISC11);
	                  CLR_BIT(MCUCR, MCUCR_ISC10);
					   break;
	    case RISING_EDGE:
		               SET_BIT(MCUCR, MCUCR_ISC11);
	                   SET_BIT(MCUCR, MCUCR_ISC10);
					   break;
	    default: Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8INT2SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Sense)
	{
		
	    case FALLING_EDGE:
		               CLR_BIT( MCUCSR, MCUCSR_INT2);
					   break;
	    case RISING_EDGE:
		               SET_BIT( MCUCSR, MCUCSR_INT2);
					   break;
	    default: Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}
void EXTI_voidINT0State(u8 Copy_u8Int0State)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Int0State)
	{
		case ENABLE:
			      SET_BIT(GICR, GICR_INT0);
		          break;

		case DISABLE:
			      CLR_BIT(GICR, GICR_INT0);
		          break;
		default: Local_u8ErrorState = NOK;
           
	}

}
void EXTI_voidINT1State(u8 Copy_u8Int1State)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Int1State)
	{
		case ENABLE:
			      SET_BIT(GICR, GICR_INT1);
		          break;

		case DISABLE:
			      CLR_BIT(GICR, GICR_INT1);
		          break;
		default: Local_u8ErrorState = NOK;
           
	}

}
void EXTI_voidINT2State(u8 Copy_u8Int2State)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Int2State)
	{
		case ENABLE:
			      SET_BIT(GICR, GICR_INT2);
		          break;

		case DISABLE:
			      CLR_BIT(GICR, GICR_INT2);
		          break;
		default: Local_u8ErrorState = NOK;
           
	}

}
void EXTI_voidINT0SetCallBack(void (*Copy_pv0NotificationFunction)(void))
{
	u8 Local_u8ErrorState = OK;
     if(Copy_pv0NotificationFunction != NULL)
    {
        EXTIGlobal_pvInt0NotificationFunction = Copy_pv0NotificationFunction;
    }
    else
    {
        Local_u8ErrorState = NULL_POINTER;
    }
}

/*ISR For INT0*/
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(EXTIGlobal_pvInt0NotificationFunction != NULL)
	{
       EXTIGlobal_pvInt0NotificationFunction();
	}
	else
	{
		/* Do Nothing*/
	}

}
void EXTI_voidINT1SetCallBack(void (*Copy_pv1NotificationFunction)(void))
{
	u8 Local_u8ErrorState = OK;
     if(Copy_pv1NotificationFunction != NULL)
    {
        EXTIGlobal_pvInt0NotificationFunction = Copy_pv1NotificationFunction;
    }
    else
    {
        Local_u8ErrorState = NULL_POINTER;
    }

}

/*ISR For INT1*/
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if(EXTIGlobal_pvInt1NotificationFunction != NULL)
	{
       EXTIGlobal_pvInt1NotificationFunction();
	}
	else
	{
		/* Do Nothing*/
	}

}
void EXTI_voidINT2SetCallBack(void (*Copy_pv2NotificationFunction)(void))
{
	u8 Local_u8ErrorState = OK;
     if(Copy_pv2NotificationFunction != NULL)
    {
        EXTIGlobal_pvInt2NotificationFunction = Copy_pv2NotificationFunction;
    }
    else
    {
        Local_u8ErrorState = NULL_POINTER;
    }
}

/*ISR For INT2*/
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if(EXTIGlobal_pvInt2NotificationFunction != NULL)
	{
       EXTIGlobal_pvInt2NotificationFunction();
	}
	else
	{
		/* Do Nothing*/
	}

}
