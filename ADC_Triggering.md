This document shows how to use free-running and auto-triggered ADC conversions on the ATmega328 microcontroller. It explains how to enable auto triggering, select the trigger source, and configure the ADC for continuous or event-driven sampling.

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

## **ADCSRB – ADC Control and Status Register B**
The **ADCSRB** register controls additional features for the ADC, such as auto-triggering, free-running mode, and other specific features that allow for greater flexibility in ADC operations.

| Bit  | Name         | Description                                             |
|------|--------------|---------------------------------------------------------|
| 7-3  | **Reserved** | Reserved bits (not used)  |
| 2    | **ADTS2**    | ADC Trigger Source Select Bit 2 (Part of Auto-Trigger Source) |
| 1    | **ADTS1**    | ADC Trigger Source Select Bit 1 (Part of Auto-Trigger Source) |
| 0    | **ADTS0**    | ADC Trigger Source Select Bit 0 (Part of Auto-Trigger Source) |
---

- **ADTS2..0 (ADC Trigger Source Select Bits)**:  
  These three bits select the source of the auto-trigger for the ADC conversion. When enabled, ADC conversions can be triggered automatically by various events like a timer overflow or an external interrupt. The possible settings for these bits are:

| **ADTS2** | **ADTS1** | **ADTS0** | **Trigger Source**                                   |
|-----------|-----------|-----------|--------------------------------------------------------|
| 0         | 0         | 0         | Free Running Mode (The ADC starts converting continuously without an external trigger) |
| 0         | 0         | 1         | Analog Comparator (The ADC starts conversion when the analog comparator triggers) |
| 0         | 1         | 0         | External Interrupt Request 0 (Triggered by external interrupt on pin 0) |
| 0         | 1         | 1         | Timer/Counter0 Compare Match A (Triggered by the compare match event of Timer/Counter0) |
| 1         | 0         | 0         | Timer/Counter0 Overflow (Triggered by Timer/Counter0 overflow) |
| 1         | 0         | 1         | Timer/Counter1 Compare Match B (Triggered by the compare match event of Timer/Counter1) |
| 1         | 1         | 0         | Timer/Counter1 Overflow (Triggered by Timer/Counter1 overflow) |
| 1         | 1         | 1         | Timer/Counter1 Capture Event (Triggered by a capture event on Timer/Counter1) |


---

## **Free Running Mode**

In this mode, ADC continuously performs conversions without external events.

### **Configuration:**

```c
bitSet(ADCSRA, ADEN);   // Enable ADC
bitSet(ADCSRA, ADATE);  // Enable auto trigger
bitSet(ADCSRA, ADSC);   // Start first conversion
// ADTS[2:0] = 000 → Free Running
bitClear(ADCSRB, ADTS2); 
bitClear(ADCSRB, ADTS1);
bitClear(ADCSRB, ADTS0);
```

> [!NOTE]
> After the first conversion starts, the next one begins automatically when the previous finishes.

---

## **Auto Trigger with External Event (e.g., Timer0 Compare Match A)**

Use this mode to synchronize ADC sampling with hardware events.


## **ADC Auto Trigger Source Configuration Snippets**

### **Free Running Mode (ADTS[2:0] = 000)**

```c
/* ADTS[2:0] = 000 → Free Running Mode
   The ADC starts converting continuously without an external trigger */
bitClear(ADCSRB, ADTS2);
bitClear(ADCSRB, ADTS1);
bitClear(ADCSRB, ADTS0);
```

---

### **Analog Comparator (ADTS[2:0] = 001)**

```c
/* ADTS[2:0] = 001 → Analog Comparator
   The ADC starts conversion when the analog comparator triggers */
bitClear(ADCSRB, ADTS2);
bitClear(ADCSRB, ADTS1);
bitSet  (ADCSRB, ADTS0);
```

---

### **External Interrupt Request 0 (ADTS[2:0] = 010)**

```c
/* ADTS[2:0] = 010 → External Interrupt Request 0
   Triggered by external interrupt on INT0 pin */
bitClear(ADCSRB, ADTS2);
bitSet  (ADCSRB, ADTS1);
bitClear(ADCSRB, ADTS0);
```

---

### **Timer/Counter0 Compare Match A (ADTS[2:0] = 011)**

```c
/* ADTS[2:0] = 011 → Timer/Counter0 Compare Match A
   Triggered by the compare match event of Timer/Counter0 */
bitClear(ADCSRB, ADTS2);
bitSet  (ADCSRB, ADTS1);
bitSet  (ADCSRB, ADTS0);
```

---

### **Timer/Counter0 Overflow (ADTS[2:0] = 100)**

```c
/* ADTS[2:0] = 100 → Timer/Counter0 Overflow
   Triggered by Timer/Counter0 overflow */
bitSet  (ADCSRB, ADTS2);
bitClear(ADCSRB, ADTS1);
bitClear(ADCSRB, ADTS0);
```

---

### **Timer/Counter1 Compare Match B (ADTS[2:0] = 101)**

```c
/* ADTS[2:0] = 101 → Timer/Counter1 Compare Match B
   Triggered by the compare match event of Timer/Counter1 */
bitSet  (ADCSRB, ADTS2);
bitClear(ADCSRB, ADTS1);
bitSet  (ADCSRB, ADTS0);
```

---

### **Timer/Counter1 Overflow (ADTS[2:0] = 110)**

```c
/* ADTS[2:0] = 110 → Timer/Counter1 Overflow
   Triggered by Timer/Counter1 overflow */
bitSet  (ADCSRB, ADTS2);
bitSet  (ADCSRB, ADTS1);
bitClear(ADCSRB, ADTS0);
```

---

### **Timer/Counter1 Capture Event (ADTS[2:0] = 111)**

```c
/* ADTS[2:0] = 111 → Timer/Counter1 Capture Event
   Triggered by a capture event on Timer/Counter1 */
bitSet  (ADCSRB, ADTS2);
bitSet  (ADCSRB, ADTS1);
bitSet  (ADCSRB, ADTS0);
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
