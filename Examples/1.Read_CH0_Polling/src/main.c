#include "aKaReZa.h"

/** Voltage gain for converting ADC value to voltage.
 *  Calculated as Vref / (2^n), where:
 *  Vref = 5V (reference voltage),
 *  n = 10 (ADC resolution),
 *  So, Volt_Gain = 5V / 1023 = 0.0048876 V per ADC step.
 *  This value is used to convert ADC readings to the corresponding voltage.
 */
#define Volt_Gain  0.0048876

char alcd[17];
uint16_t adc_RawValue = 0;
float Voltage = 0;

int main(void)
{
  alcd_init();
  adc_Init(Initialize);
  while(1)
  {
    adc_RawValue = adc_Read(0);
    sprintf(alcd, "ADC CH0: %4u", adc_RawValue);
    alcd_gotoxy(0, 0);
    alcd_puts(alcd);

    Voltage = adc_RawValue * Volt_Gain;
    sprintf(alcd, "Vol CH0: %1.2f", Voltage);
    alcd_gotoxy(0, 1);
    alcd_puts(alcd);    
    delay_ms(10);
  };
};
