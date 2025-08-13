
This section provides detailed descriptions of the functions used to interact with the ADC peripheral of the ATMEGA328 microcontroller. These functions are part of the custom library for accessing and utilizing the ADC hardware. Each function is explained with its purpose and usage, accompanied by code examples to demonstrate how they can be implemented in your projects.

> [!NOTE]  
> The library and all of its APIs provided below have been developed by myself.  
This library utilizes various macros defined in the `aKaReZa.h` header file, which are designed to simplify bitwise operations and register manipulations.    
Detailed descriptions of these macros can be found at the following link:  
> [https://github.com/aKaReZa75/AVR/blob/main/Macros.md](https://github.com/aKaReZa75/AVR/blob/main/Macros.md)  

| Setting                         | Value                           |
|---------------------------------|---------------------------------|
| **CPU Frequency**               | 16 MHz                          |
| **Prescaler**                   | 128                             |
| **Reference Voltage**           | AVCC                            |
| **Result Alignment**            | Right Alignment                 |
| **Measurement Method**          | Polling                         |

### **Initialization**
```c
void adc_Init(bool _initStatus);
```
* This function configures the ADC to use the default settings for the input channel and reference voltage.
* It also enables the ADC and sets the appropriate prescaler for ADC clock.
* @param `_initStatus`:  
   - If `_initStatus` is set to `Initialize`, the USART module will be configured and enabled.
   - If `_initStatus` is set to `deInitialize`, the USART module will be disabled and deinitialized. 
   
**Example:**
```c
#include "aKaReZa.h"
#include "adc.h"

int main(void) 
{
    adc_Init(Initialize); /**< Initialize ADC with default settings */
    while(1)
    {
        /* Your code here */
    }
}
```

### **Internal Temperature Sensor**
```c
int8_t adc_internalTemp(void);
```
* This function returns the ADC result from the internal temperature sensor.

**Example:**
```c
#include "aKaReZa.h"
#include "adc.h"

int8_t tempValue = 0;

int main(void) 
{
    adc_Init(Initialize); /**< Initialize ADC with default settings */
    tempValue = adc_internalTemp(); /**< Get the temperature value from the internal sensor */
    while(1)
    {
        /* Use the tempValue */
    }
}
```

### **ADC Read**
```c
uint16_t adc_Read(uint8_t _adcChannel);
```
* This function returns the 10-bit result from the specified ADC channel.
- @param `_adcChannel`: Specifies the ADC channel to be read. It is an 8-bit value, where each bit represents an ADC input channel (0-7 for the ATMEGA328).
  
> [!IMPORTANT]
The ATMEGA328's ADC operates **sequentially**, meaning that you cannot read multiple channels **simultaneously**. To read data from multiple ADC channels, you need to read each channel one by one, performing an individual conversion for each channel.   
This process is not parallel, so you'll need to configure the ADC to select the desired channel before each conversion, and wait for the conversion to complete before moving on to the next channel. While this means the readings are not simultaneous, it allows for accurate sampling of each individual channel.


**Example:**
```c
#include "aKaReZa.h"
#include "adc.h"

uint16_t adcResult = 0;

int main(void) 
{
    adc_Init(Initialize); /**< Initialize ADC with default settings */
    adcResult = adc_Read(0); /**< Read the ADC value from channel 0 */
    while(1)
    {
        /* Use the adcResult */
    }
}
```

### Summary
| API Function         | Description                                       |
|----------------------|---------------------------------------------------|
| `adc_Init`           | Initializes the ADC module with default settings. |
| `adc_internalTemp`   | Reads the internal temperature sensor.            |
| `adc_Read`           | Reads the ADC value from a specified channel.     |

## Complete Example

```c
#include "aKaReZa.h"
#include "adc.h"

uint16_t adcResult = 0;

int main(void) 
{
    adc_Init(Initialize); /**< Initialize the ADC with default settings */
    while(1)
    {
        adcResult = adc_Read(0); /**< Read ADC from channel 0 */
        /* Example usage of ADC result */
        if (adcResult > 512)
        {
            bitSet(PORTB, 0); /**< Set PORTB0 if ADC result is greater than 512 */
        }
        else
        {
            bitClear(PORTB, 0); /**< Clear PORTB0 if ADC result is less than 512 */
        }
    }
}
```


# 🌟 Support Me
If you found this repository useful:
- Subscribe to my [YouTube Channel](https://www.youtube.com/@aKaReZa75).
- Share this repository with others.
- Give this repository and my other repositories a star.
- Follow my [GitHub account](https://github.com/aKaReZa75).

# ✉️ Contact Me
Feel free to reach out to me through any of the following platforms:
- 📧 [Email: aKaReZa75@gmail.com](mailto:aKaReZa75@gmail.com)
- 🎥 [YouTube: @aKaReZa75](https://www.youtube.com/@aKaReZa75)
- 💼 [LinkedIn: @akareza75](https://www.linkedin.com/in/akareza75)
