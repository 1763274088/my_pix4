
#include "stm32f4xx_hal_conf.h"
#include "led.h"


// 开启系统时钟配置
/// System Clock Configuration
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    //启动电源管理时钟
  /* Enable Power Control clock */
  __PWR_CLK_ENABLE();

    // 调整电源工作模式  设置为默认模式 11
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);


  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;    // 外部晶振
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;  // 晶振开
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON; // PLL 开
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;  // PLL外部晶振输入
  RCC_OscInitStruct.PLL.PLLM = 24;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
     clocks dividers */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 |
                                RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);
}



int main(void)
{

    HAL_Init();
    SystemClock_Config();
    LED_Init(LED_AMBER);
	while(1)
	{
        LED_Toggle(LED_AMBER);
        HAL_Delay(500);
    }

}
