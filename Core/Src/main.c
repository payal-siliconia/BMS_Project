/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_device.h"
#include "usbd_cdc_if.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c2;

/* USER CODE BEGIN PV */
#define  BQ76907_I2C_ADDR   (0x08 << 1)
#define  STACK_VOLTAGE      0x26
#define Read_cell1_voltage  0x14
#define Read_cell2_voltage  0x16
#define Read_cell3_voltage  0x18
#define Read_cell4_voltage  0x1A
#define Read_cell5_voltage  0x1C
#define Read_cell6_voltage  0x1E


extern uint8_t VbaCmdBuffer[64];  // Buffer for incoming "S3000"
extern uint8_t VbaDataReady;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

uint16_t BQ76907_ReadCell1Voltage(void)
{
    uint8_t rx_data[2];
    uint16_t cell1_voltage;

    // Read 2 bytes starting from register 0x14
    if (HAL_I2C_Mem_Read(&hi2c2,BQ76907_I2C_ADDR, 0x14, I2C_MEMADD_SIZE_8BIT,rx_data, 2,  HAL_MAX_DELAY) != HAL_OK)
    {
        return 0xFFFF;  // error
    }

    // Combine little-endian bytes
    cell1_voltage = (rx_data[1] << 8) | rx_data[0];
    return cell1_voltage;  // in Volts

}

uint16_t BQ76907_ReadCell2Voltage(void)
{
    uint8_t rx_data[2];
    uint16_t cell2_voltage;

    // Read 2 bytes starting from register 0x14
    if (HAL_I2C_Mem_Read(&hi2c2,BQ76907_I2C_ADDR, 0x16, I2C_MEMADD_SIZE_8BIT,rx_data, 2,  HAL_MAX_DELAY) != HAL_OK)
    {
        return 0xFFFF;  // error
    }

    // Combine little-endian bytes
    cell2_voltage = (rx_data[1] << 8) | rx_data[0];
    return cell2_voltage;  // in Volts

}

uint16_t BQ76907_ReadCell3Voltage(void)
{
    uint8_t rx_data[2];
    uint16_t cell3_voltage;

    // Read 2 bytes starting from register 0x14
    if (HAL_I2C_Mem_Read(&hi2c2,BQ76907_I2C_ADDR, 0x18, I2C_MEMADD_SIZE_8BIT,rx_data, 2,  HAL_MAX_DELAY) != HAL_OK)
    {
        return 0xFFFF;  // error
    }

    // Combine little-endian bytes
    cell3_voltage = (rx_data[1] << 8) | rx_data[0];
    return cell3_voltage;  // in Volts

}



uint16_t BQ76907_ReadCell4Voltage(void)
{
    uint8_t rx_data[2];
    uint16_t cell4_voltage;

    // Read 2 bytes starting from register 0x14
    if (HAL_I2C_Mem_Read(&hi2c2,BQ76907_I2C_ADDR, 0x1A, I2C_MEMADD_SIZE_8BIT,rx_data, 2,  HAL_MAX_DELAY) != HAL_OK)
    {
        return 0xFFFF;  // error
    }

    // Combine little-endian bytes
    cell4_voltage = (rx_data[1] << 8) | rx_data[0];
    return cell4_voltage;  // in Volts

}


uint16_t BQ76907_ReadCell5Voltage(void)
{
    uint8_t rx_data[2];
    uint16_t cell5_voltage;

    // Read 2 bytes starting from register 0x14
    if (HAL_I2C_Mem_Read(&hi2c2,BQ76907_I2C_ADDR, 0x1C, I2C_MEMADD_SIZE_8BIT,rx_data, 2,  HAL_MAX_DELAY) != HAL_OK)
    {
        return 0xFFFF;  // error
    }

    // Combine little-endian bytes
    cell5_voltage = (rx_data[1] << 8) | rx_data[0];
    return cell5_voltage;  // in Volts

}


uint16_t BQ76907_ReadCell6Voltage(void)
{
    uint8_t rx_data[2];
    uint16_t cell6_voltage;

    // Read 2 bytes starting from register 0x14
    if (HAL_I2C_Mem_Read(&hi2c2,BQ76907_I2C_ADDR, 0x1E, I2C_MEMADD_SIZE_8BIT,rx_data, 2,  HAL_MAX_DELAY) != HAL_OK)
    {
        return 0xFFFF;  // error
    }

    // Combine little-endian bytes
    cell6_voltage = (rx_data[1] << 8) | rx_data[0];
    return cell6_voltage;  // in Volts

}












/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C2_Init();
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 2 */

  HAL_Delay(100);
  uint8_t data[2];
  uint16_t raw_stack_voltage;
  float stack_voltage_v;
  char msg[64];


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  if(HAL_I2C_Mem_Read(&hi2c2, BQ76907_I2C_ADDR ,STACK_VOLTAGE,I2C_MEMADD_SIZE_8BIT, data, 2, 100)==HAL_OK)
	  {

	  	 	  // Combine bytes (Little Endian)
	  	 	  raw_stack_voltage = (uint16_t)(data[1] << 8) | data[0];

	  	 	  // Convert to Volts (1 LSB = 10mV)
	  	 	  stack_voltage_v = raw_stack_voltage * 0.001f;

	  	 	  // Format and send to PuTTY
	  	 	 int len = sprintf(msg, "Stack Voltage: %.2f V\r\n", stack_voltage_v);
	  	 	 CDC_Transmit_FS((uint8_t*)msg, len);
	  }
	  else
	  {
		  char error_msg[]= "I2C Read Failed!\r\n";
		  CDC_Transmit_FS((uint8_t*)error_msg,strlen(error_msg));

	  }

	  HAL_Delay(1000);



	  uint16_t cell1_mv = BQ76907_ReadCell1Voltage();
	  //float cell1_v = cell1_mv / 1000.0f;

	  char usb_buf[64];
	  sprintf(usb_buf, "Cell 1 Voltage = %u.%03u V\r\n", cell1_mv/1000,cell1_mv % 1000);
	  CDC_Transmit_FS((uint8_t*)usb_buf, strlen(usb_buf));


      uint16_t cell2_mv =  BQ76907_ReadCell2Voltage();
      //char usb_buf[64];
      sprintf(usb_buf, "Cell 2 Voltage = %u.%03u V\r\n", cell2_mv/1000,cell2_mv % 1000);
      CDC_Transmit_FS((uint8_t*)usb_buf, strlen(usb_buf));


      uint16_t cell3_mv =  BQ76907_ReadCell3Voltage();
      sprintf(usb_buf, "Cell 3 Voltage = %u.%03u V\r\n", cell3_mv/1000,cell3_mv % 1000);
      CDC_Transmit_FS((uint8_t*)usb_buf, strlen(usb_buf));

      uint16_t cell4_mv =  BQ76907_ReadCell4Voltage();
      sprintf(usb_buf, "Cell 4 Voltage = %u.%03u V\r\n", cell4_mv/1000,cell4_mv % 1000);
      CDC_Transmit_FS((uint8_t*)usb_buf, strlen(usb_buf));

      uint16_t cell5_mv =  BQ76907_ReadCell5Voltage();
      sprintf(usb_buf, "Cell 5 Voltage = %u.%03u V\r\n", cell5_mv/1000,cell5_mv % 1000);
      CDC_Transmit_FS((uint8_t*)usb_buf, strlen(usb_buf));

      uint16_t cell6_mv =  BQ76907_ReadCell6Voltage();
      sprintf(usb_buf, "Cell 6 Voltage = %u.%03u V\r\n", cell6_mv/1000,cell6_mv % 1000);
      CDC_Transmit_FS((uint8_t*)usb_buf, strlen(usb_buf));






  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.ClockSpeed = 100000;
  hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
