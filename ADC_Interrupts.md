
This document describes how to enable ADC interrupts on the ATmega328 microcontroller and how to write interrupt service routines (ISRs) to handle conversion completion events efficiently.

---

## **ADCSRA – ADC Control and Status Register A**

The **ADCSRA** register manages the overall operation of the ADC, including enabling the ADC, starting conversions, controlling the ADC clock, and enabling interrupts.

| Bit  | Name         | Description                                              |
|------|--------------|----------------------------------------------------------|
| 7    | **ADEN**     | ADC Enable (Enables the ADC)                             |
| 6    | **ADSC**     | ADC Start Conversion (Starts a conversion)               |
| 5    | **ADATE**    | ADC Auto Trigger Enable (Enable automatic trigger)       |
| 4    | **ADIF**     | ADC Interrupt Flag (Set when conversion is complete)     |
| 3    | **ADIE**     | ADC Interrupt Enable (Enable conversion interrupt)       |
| 2-0  | **ADPS2..0** | ADC Prescaler Select Bits (Select ADC clock prescaler)   |

---

## **Enable ADC Interrupts**

To use ADC interrupts, you must:

1. Enable the ADC (`ADEN`)
2. Enable the ADC interrupt (`ADIE`)
3. Start the conversion (`ADSC`)
4. Enable global interrupts (`SREG_I`)

### **Example: Enable ADC Interrupts**

```c
// Enable ADC module
bitSet(ADCSRA, ADEN);

// Enable ADC interrupt
bitSet(ADCSRA, ADIE);

// Start first conversion
bitSet(ADCSRA, ADSC);

// Enable global interrupts
globalInt_Enable;
```

---

## **Interrupt Flag – ADIF**

- Set when an ADC conversion completes
- Cleared automatically when ISR is executed
- Can also be cleared manually:

```c
intFlag_clear(ADCSRA, ADIF); // Clear ADC interrupt flag
```

---

## **Writing the ADC ISR**

The ISR is triggered when a conversion completes. You can read the result and process it immediately.

### **Example: ADC ISR (10-bit result)**

```c
ISR(ADC_vect) 
{
    uint8_t low  = ADCL;
    uint8_t high = ADCH;
    uint16_t result = Combine_8to16(high, low);

    // Process result (e.g., store, filter, transmit)
}
```

### **Example: ADC ISR (8-bit result, left-adjusted)**

```c
ISR(ADC_vect) 
{
    uint8_t result = ADCH; // ADLAR must be set
    // Process result
}
```

---

## **Best Practices**

| Tip                                  | Benefit                                      |
|--------------------------------------|----------------------------------------------|
| Use ISR for non-blocking ADC reads   | Improves responsiveness and efficiency       |
| Avoid polling `ADIF` when `ADIE` is set | Prevents redundant checks                   |
| Keep ISR short and fast              | Avoids interrupt latency issues              |
| Use buffering if multiple samples needed | Ensures data integrity                      |

---

## **Complete Initialization Example**

```c
void adc_InterruptInit(void) 
{
    bitSet(ADCSRA, ADEN);   // Enable ADC
    bitSet(ADCSRA, ADIE);   // Enable ADC interrupt
    bitSet(ADCSRA, ADSC);   // Start first conversion
    globalInt_Enable;       // Enable global interrupts
}
```

---

## **Summary of ADC Interrupt Flow**

1. Configure ADC and enable interrupt
2. Start conversion with `ADSC`
3. Wait for ISR to be triggered
4. Read result inside `ISR(ADC_vect)`
5. Optionally start next conversion manually or via auto trigger

> [!CAUTION]
> Avoid long operations inside the ISR. If processing is heavy, set a flag and handle it in the main loop.



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
