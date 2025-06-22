# 🕒 Real-Time Clock Display using DS1307, I2C, and LCD with 8051

This project interfaces a **DS1307 RTC module** with an **8051 microcontroller** via the **I2C protocol**, and displays the current time in **HH:MM:SS** format on a **16x2 LCD display**.

---

## 📦 Components Used

- 8051 Microcontroller (AT89C51)
- DS1307 RTC Module
- 16x2 LCD Display (HD44780 compatible)
- Pull-up resistors (typically 4.7kΩ) on SDA and SCL
- Crystal (32.768kHz for RTC, 11.0592MHz for 8051)
- Battery (CR2032 for RTC backup)
- Proteus or hardware setup

---

## 🧠 How It Works

1. **DS1307** keeps real-time time using its internal crystal and battery backup.
2. **8051** communicates with DS1307 over **I2C** using software-bit-banging.
3. **LCD** is used to show the time.
4. Time is read in **BCD format** from DS1307 and converted to ASCII before display.

---

## 📟 LCD Connections

| LCD Pin | Connection     |
|---------|----------------|
| RS      | P1.0           |
| RW      | P1.1           |
| E       | P1.2           |
| D0-D7   | P2.0 - P2.7    |

---

## 🧪 I2C (Bit-Banged) Pin Mapping

| Function | Pin     |
|----------|---------|
| SDA      | P3.1    |
| SCL      | P3.0    |

---

## 📍 DS1307 RTC Address

- **7-bit address**: `0x68`
- **Write address**: `0xD0` (i.e., `0x68 << 1`)
- **Read address**: `0xD1` (i.e., `0x68 << 1 | 1`)

---

## 🔣 BCD to ASCII Conversion

DS1307 returns time in BCD format. To display it:
```c
lcd_data((bcd >> 4) + '0');
lcd_data((bcd & 0x0F) + '0');
