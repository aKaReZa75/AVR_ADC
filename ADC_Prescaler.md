This document explains how to set the ADC clock using prescaler bits in ADCSRA for optimal accuracy on the ATmega328 microcontroller.

---

### **ADC Control and Status Register A (ADCSRA)**

The **ADCSRA** register manages the overall operation of the ADC, including enabling the ADC, starting conversions, controlling the ADC clock, and enabling interrupts.

| Bit  | Name         | Description                                              |
|------|--------------|----------------------------------------------------------|
| 7    | **ADEN**     | ADC Enable (Enables the ADC)                             |
| 6    | **ADSC**     | ADC Start Conversion (Starts a conversion)               |
| 5    | **ADATE**    | ADC Auto Trigger Enable (Enable automatic trigger)       |
| 4    | **ADIF**     | ADC Interrupt Flag (Set when conversion is complete)     |
| 3    | **ADIE**     | ADC Interrupt Enable (Enable conversion interrupt)       |
| 2-0  | **ADPS2..0** | ADC Prescaler Select Bits (Select ADC clock prescaler)   |

- **ADEN (ADC Enable)**:  
  This bit enables the ADC module. When set to **1**, the ADC is powered on and ready for conversions. Setting it to **0** disables the ADC.

- **ADSC (ADC Start Conversion)**:  
  When set to **1**, this bit starts the ADC conversion on the selected channel. The conversion process will begin, and the bit will automatically be cleared once the conversion is completed.

- **ADATE (ADC Auto Trigger Enable)**:  
  Setting this bit to **1** enables automatic triggering of ADC conversions based on specific events, such as timer overflows, external interrupts, etc. If this bit is cleared to **0**, conversions must be started manually by setting the **ADSC** bit.

- **ADIF (ADC Interrupt Flag)**:  
  This bit is set to **1** when the ADC conversion is complete. If interrupts are enabled (by setting **ADIE**), this flag triggers an interrupt. It is cleared by reading the ADC Data Register or by setting it manually.

- **ADIE (ADC Interrupt Enable)**:  
  This bit enables the interrupt for ADC conversion completion. If **ADIE** is set to **1**, the interrupt will trigger when **ADIF** is set. If **ADIE** is cleared, no interrupt will occur.

- **ADPS2..0 (ADC Prescaler Select Bits)**:  
  These three bits control the prescaler for the ADC clock. The ADC requires a clock frequency between 50 kHz and 200 kHz for optimal performance. These bits determine the division factor applied to the system clock to generate the ADC clock. Example settings:
  - **000**: Divide by 2
  - **001**: Divide by 2
  - **010**: Divide by 4
  - **011**: Divide by 8
  - **100**: Divide by 16
  - **101**: Divide by 32
  - **110**: Divide by 64
  - **111**: Divide by 128
---

## **Prescaler Settings**

| ADPS2 | ADPS1 | ADPS0 | Division Factor | ADC Clock (F_CPU = 16 MHz) |
|-------|-------|-------|------------------|-----------------------------|
| 0     | 0     | 0     | 2                | 8 MHz                       |
| 0     | 0     | 1     | 2                | 8 MHz                       |
| 0     | 1     | 0     | 4                | 4 MHz                       |
| 0     | 1     | 1     | 8                | 2 MHz                       |
| 1     | 0     | 0     | 16               | 1 MHz                       |
| 1     | 0     | 1     | 32               | 500 kHz                     |
| 1     | 1     | 0     | 64               | 250 kHz                     |
| 1     | 1     | 1     | 128              | 125 kHz                     |

> [!TIP]
> The recommended ADC clock frequency is between 50 kHz and 200 kHz for maximum resolution and accuracy.

---

## **Prescaler Configuration Code Snippets with Comments**

### **Prescaler = 2 (ADC Clock = 8 MHz)**

```c
// Set ADC prescaler to 2 → ADC clock = F_CPU / 2 = 8 MHz
// Not recommended for high-resolution conversions
bitClear(ADCSRA, ADPS2); // ADPS2 = 0
bitClear(ADCSRA, ADPS1); // ADPS1 = 0
bitSet  (ADCSRA, ADPS0); // ADPS0 = 1
```

---

### **Prescaler = 4 (ADC Clock = 4 MHz)**

```c
// Set ADC prescaler to 4 → ADC clock = F_CPU / 4 = 4 MHz
// Still too fast for accurate readings
bitClear(ADCSRA, ADPS2); // ADPS2 = 0
bitSet  (ADCSRA, ADPS1); // ADPS1 = 1
bitClear(ADCSRA, ADPS0); // ADPS0 = 0
```

---

### **Prescaler = 8 (ADC Clock = 2 MHz)**

```c
// Set ADC prescaler to 8 → ADC clock = F_CPU / 8 = 2 MHz
// May be acceptable for fast but low-precision sampling
bitClear(ADCSRA, ADPS2); // ADPS2 = 0
bitSet  (ADCSRA, ADPS1); // ADPS1 = 1
bitSet  (ADCSRA, ADPS0); // ADPS0 = 1
```

---

### **Prescaler = 16 (ADC Clock = 1 MHz)**

```c
// Set ADC prescaler to 16 → ADC clock = F_CPU / 16 = 1 MHz
// Borderline usable, better to go slower for precision
bitSet  (ADCSRA, ADPS2); // ADPS2 = 1
bitClear(ADCSRA, ADPS1); // ADPS1 = 0
bitClear(ADCSRA, ADPS0); // ADPS0 = 0
```

---

### **Prescaler = 32 (ADC Clock = 500 kHz)**

```c
// Set ADC prescaler to 32 → ADC clock = F_CPU / 32 = 500 kHz
// Acceptable for medium-speed applications
bitSet  (ADCSRA, ADPS2); // ADPS2 = 1
bitClear(ADCSRA, ADPS1); // ADPS1 = 0
bitSet  (ADCSRA, ADPS0); // ADPS0 = 1
```

---

### **Prescaler = 64 (ADC Clock = 250 kHz)**

```c
// Set ADC prescaler to 64 → ADC clock = F_CPU / 64 = 250 kHz
// Recommended for good balance between speed and accuracy
bitSet  (ADCSRA, ADPS2); // ADPS2 = 1
bitSet  (ADCSRA, ADPS1); // ADPS1 = 1
bitClear(ADCSRA, ADPS0); // ADPS0 = 0
```

---

### **Prescaler = 128 (ADC Clock = 125 kHz)**

```c
// Set ADC prescaler to 128 → ADC clock = F_CPU / 128 = 125 kHz
// Best choice for high-resolution and stable conversions
bitSet  (ADCSRA, ADPS2); // ADPS2 = 1
bitSet  (ADCSRA, ADPS1); // ADPS1 = 1
bitSet  (ADCSRA, ADPS0); // ADPS0 = 1
```

---

## **Best Practices**

| Tip                                | Benefit                                      |
|------------------------------------|----------------------------------------------|
| Use prescaler 64 or 128 for 16 MHz | Ensures ADC clock is within optimal range    |
| Avoid high ADC clock (>200 kHz)    | Prevents loss of resolution and accuracy     |
| Set prescaler before enabling ADC  | Ensures stable conversion timing             |


> [!CAUTION]
> Using a prescaler too low may result in unstable or noisy ADC readings.


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
