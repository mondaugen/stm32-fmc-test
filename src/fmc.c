#include "fmc.h"

#define REFRESH_COUNT       ((uint32_t)0x0569)   /* SDRAM refresh counter (90Mhz SD clock) */

static void Delay(__IO uint32_t nCount)
{
  __IO uint32_t index = 0; 
  for(index = (100000 * nCount); index != 0; index--)
  {
  }
}

void FMC_Config(void)
{  
  GPIO_InitTypeDef            GPIO_InitStructure;
  FMC_SDRAMInitTypeDef        FMC_SDRAMInitStructure;
  FMC_SDRAMTimingInitTypeDef  FMC_SDRAMTimingInitStructure;
  FMC_SDRAMCommandTypeDef     FMC_SDRAMCommandStructure;
  
  uint32_t tmpr = 0;
  uint32_t timeout = SDRAM_TIMEOUT;

  /* GPIO configuration ------------------------------------------------------*/ 
  /* Enable GPIOs clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB
                        | RCC_AHB1Periph_GPIOC
                        | RCC_AHB1Periph_GPIOD
                        | RCC_AHB1Periph_GPIOE
                        | RCC_AHB1Periph_GPIOF
                        | RCC_AHB1Periph_GPIOG
                        ,ENABLE);
                         
  /* Common GPIO configuration */
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
  
  /* GPIOD configuration */
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource0, GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource1, GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource8, GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource9, GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource10, GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_FMC);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0  |GPIO_Pin_1  |GPIO_Pin_8 |GPIO_Pin_9 |
                                GPIO_Pin_10 |GPIO_Pin_14 |GPIO_Pin_15;

  GPIO_Init(GPIOD, &GPIO_InitStructure);

  /* GPIOE configuration */
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource0 , GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource1 , GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource7 , GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource8 , GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource9 , GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource10 , GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource11 , GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource12 , GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource13 , GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource14 , GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource15 , GPIO_AF_FMC);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0  | GPIO_Pin_1  | GPIO_Pin_7 | GPIO_Pin_8  |
                                GPIO_Pin_9  | GPIO_Pin_10 | GPIO_Pin_11| GPIO_Pin_12 |
                                GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;

  GPIO_Init(GPIOE, &GPIO_InitStructure);

  /* GPIOF configuration */
  GPIO_PinAFConfig(GPIOF, GPIO_PinSource0 , GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOF, GPIO_PinSource1 , GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOF, GPIO_PinSource2 , GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOF, GPIO_PinSource3 , GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOF, GPIO_PinSource4 , GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOF, GPIO_PinSource5 , GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOF, GPIO_PinSource11 , GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOF, GPIO_PinSource12 , GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOF, GPIO_PinSource13 , GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOF, GPIO_PinSource14 , GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOF, GPIO_PinSource15 , GPIO_AF_FMC);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0  | GPIO_Pin_1  | GPIO_Pin_2  | GPIO_Pin_3  |
                                GPIO_Pin_4  | GPIO_Pin_5  | GPIO_Pin_11 | GPIO_Pin_12 |
                                GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;      

  GPIO_Init(GPIOF, &GPIO_InitStructure);

  /* GPIOG configuration */
  GPIO_PinAFConfig(GPIOG, GPIO_PinSource0 , GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOG, GPIO_PinSource1 , GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOG, GPIO_PinSource8 , GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOG, GPIO_PinSource15 , GPIO_AF_FMC);
  

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 |GPIO_Pin_1 |
                                GPIO_Pin_8 | GPIO_Pin_15;

  GPIO_Init(GPIOG, &GPIO_InitStructure);
   
  /* GPIOH configuration */
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource5 , GPIO_AF_FMC);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource6 , GPIO_AF_FMC);
  

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6;

  GPIO_Init(GPIOB, &GPIO_InitStructure);

  /* GPIOI configuration */
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource0 , GPIO_AF_FMC);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
  
  GPIO_Init(GPIOC, &GPIO_InitStructure);
      
  /* Enable FMC clock */
  RCC_AHB3PeriphClockCmd(RCC_AHB3Periph_FMC, ENABLE);
  
  /* FMC SDRAM device initialization sequence --------------------------------*/ 
  /* Step 1 ----------------------------------------------------*/ 
  /* Timing configuration for 84 Mhz of SD clock frequency (168Mhz/2) */
  /* TMRD: 2 Clock cycles */
  FMC_SDRAMTimingInitStructure.FMC_LoadToActiveDelay    = 2;      
  /* TXSR: min=70ns (6x11.90ns) */
  FMC_SDRAMTimingInitStructure.FMC_ExitSelfRefreshDelay = 7;
  /* TRAS: min=42ns (4x11.90ns) max=120k (ns) */
  FMC_SDRAMTimingInitStructure.FMC_SelfRefreshTime      = 4;
  /* TRC:  min=70 (6x11.90ns) */        
  FMC_SDRAMTimingInitStructure.FMC_RowCycleDelay        = 7;         
  /* TWR:  min=1+ 7ns (1+1x11.90ns) */
  FMC_SDRAMTimingInitStructure.FMC_WriteRecoveryTime    = 2;      
  /* TRP:  20ns => 2x11.90ns */
  FMC_SDRAMTimingInitStructure.FMC_RPDelay              = 2;                
  /* TRCD: 20ns => 2x11.90ns */
  FMC_SDRAMTimingInitStructure.FMC_RCDDelay             = 2;
  
  /* Step 2 ----------------------------------------------------*/
  
  /* FMC SDRAM control configuration */
  FMC_SDRAMInitStructure.FMC_Bank = FMC_Bank2_SDRAM;
  
  /* Row addressing: [7:0] */
  FMC_SDRAMInitStructure.FMC_ColumnBitsNumber   = FMC_ColumnBits_Number_8b;
  /* Column addressing: [10:0] */
  FMC_SDRAMInitStructure.FMC_RowBitsNumber      = FMC_RowBits_Number_12b;
  FMC_SDRAMInitStructure.FMC_SDMemoryDataWidth  = SDRAM_MEMORY_WIDTH;
  FMC_SDRAMInitStructure.FMC_InternalBankNumber = FMC_InternalBank_Number_4;
  /* CL: Cas Latency = 3 clock cycles */
  FMC_SDRAMInitStructure.FMC_CASLatency         = FMC_CAS_Latency_3; 
  FMC_SDRAMInitStructure.FMC_WriteProtection    = FMC_Write_Protection_Disable;
  FMC_SDRAMInitStructure.FMC_SDClockPeriod      = SDCLOCK_PERIOD;  
  FMC_SDRAMInitStructure.FMC_ReadBurst          = FMC_Read_Burst_Disable;
  FMC_SDRAMInitStructure.FMC_ReadPipeDelay      = FMC_ReadPipe_Delay_1;
  FMC_SDRAMInitStructure.FMC_SDRAMTimingStruct  = &FMC_SDRAMTimingInitStructure;
  /* FMC SDRAM bank initialization */
  FMC_SDRAMInit(&FMC_SDRAMInitStructure);
  
/* Step 3 --------------------------------------------------------------------*/
  /* Configure a clock configuration enable command */
  FMC_SDRAMCommandStructure.FMC_CommandMode            = FMC_Command_Mode_CLK_Enabled;
  FMC_SDRAMCommandStructure.FMC_CommandTarget          = FMC_Command_Target_bank2;
  FMC_SDRAMCommandStructure.FMC_AutoRefreshNumber      = 1;
  FMC_SDRAMCommandStructure.FMC_ModeRegisterDefinition = 0;
  /* Wait until the SDRAM controller is ready */ 
  while((FMC_GetFlagStatus(FMC_Bank1_SDRAM, FMC_FLAG_Busy) != RESET) && (timeout > 0))
  {
    timeout--;
  }
  /* Send the command */
  FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStructure);  
  
/* Step 4 --------------------------------------------------------------------*/
  /* Insert 100 ms delay */
  Delay(10);
    
/* Step 5 --------------------------------------------------------------------*/
  /* Configure a PALL (precharge all) command */ 
  FMC_SDRAMCommandStructure.FMC_CommandMode            = FMC_Command_Mode_PALL;
  FMC_SDRAMCommandStructure.FMC_CommandTarget          = FMC_Command_Target_bank2;
  FMC_SDRAMCommandStructure.FMC_AutoRefreshNumber      = 1;
  FMC_SDRAMCommandStructure.FMC_ModeRegisterDefinition = 0;
  
  /* Wait until the SDRAM controller is ready */  
  timeout = SDRAM_TIMEOUT; 
  while((FMC_GetFlagStatus(FMC_Bank1_SDRAM, FMC_FLAG_Busy) != RESET) && (timeout > 0))
  {
    timeout--;
  }
  /* Send the command */
  FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStructure);
  
/* Step 6 --------------------------------------------------------------------*/
  /* Configure a Auto-Refresh command */ 
  FMC_SDRAMCommandStructure.FMC_CommandMode            = FMC_Command_Mode_AutoRefresh;
  FMC_SDRAMCommandStructure.FMC_CommandTarget          = FMC_Command_Target_bank2;
  FMC_SDRAMCommandStructure.FMC_AutoRefreshNumber      = 4;
  FMC_SDRAMCommandStructure.FMC_ModeRegisterDefinition = 0;
  
  /* Wait until the SDRAM controller is ready */ 
  timeout = SDRAM_TIMEOUT; 
  while((FMC_GetFlagStatus(FMC_Bank1_SDRAM, FMC_FLAG_Busy) != RESET) && (timeout > 0))
  {
    timeout--;
  }
  /* Send the command */
  FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStructure);
  
/* Step 7 --------------------------------------------------------------------*/
  /* Program the external memory mode register */
  tmpr = (uint32_t)SDRAM_MODEREG_BURST_LENGTH_2          |
                   SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL   |
                   SDRAM_MODEREG_CAS_LATENCY_3           |
                   SDRAM_MODEREG_OPERATING_MODE_STANDARD |
                   SDRAM_MODEREG_WRITEBURST_MODE_SINGLE;
  
  /* Configure a load Mode register command*/ 
  FMC_SDRAMCommandStructure.FMC_CommandMode            = FMC_Command_Mode_LoadMode;
  FMC_SDRAMCommandStructure.FMC_CommandTarget          = FMC_Command_Target_bank2;
  FMC_SDRAMCommandStructure.FMC_AutoRefreshNumber      = 1;
  FMC_SDRAMCommandStructure.FMC_ModeRegisterDefinition = tmpr;
  
  /* Wait until the SDRAM controller is ready */ 
  timeout = SDRAM_TIMEOUT; 
  while((FMC_GetFlagStatus(FMC_Bank1_SDRAM, FMC_FLAG_Busy) != RESET) && (timeout > 0))
  {
    timeout--;
  }
  /* Send the command */
  FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStructure);
  
/* Step 8 --------------------------------------------------------------------*/

  /* Set the refresh rate counter */
  /* (7.81 us x Freq) - 20 */
  /* Set the device refresh counter */
  FMC_SetRefreshCount(REFRESH_COUNT);
  
  /* Wait until the SDRAM controller is ready */ 
  timeout = SDRAM_TIMEOUT; 
  while((FMC_GetFlagStatus(FMC_Bank1_SDRAM, FMC_FLAG_Busy) != RESET) && (timeout > 0))
  {
    timeout--;
  } 
}
