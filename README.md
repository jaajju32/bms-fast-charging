# 🔋 Battery Management System – Fast Charging + Safety Monitoring

This project was developed as a **final year engineering project** for a friend, with embedded system logic written and optimized by me. It is a custom **Battery Management System (BMS)** for a **3S 12V 80Wh lithium-ion battery pack**, focused on safe and intelligent **fast charging**, **thermal protection**, and **cell health tracking**.

---

## 🧠 My Contribution

I designed and implemented the **core fast charging logic** and sensor-based safety protocol using an **Arduino Nano**. My optimized power delivery profile ensures safe and efficient battery charging across different charge levels:

| Battery Charge (%) | Charging Power     |
|--------------------|--------------------|
| 0% to 50%          | 200 Watts (Max)    |
| 50% to 80%         | 150 Watts          |
| 80% to 90%         | 100 Watts          |
| 90% to 100%        | ≤ 50 Watts         |

This tiered charging protocol protects the battery from overheating and overvoltage damage, especially in the final 10% where lithium-ion cells are most sensitive.

---

## 🔧 Core Features

| Feature               | Description |
|-----------------------|-------------|
| 🔋 Fast Charging       | Charged a 12V/80Wh battery at 200W with intelligent tiered cutoff logic |
| 🌡️ Thermal Protection  | Used analog temperature sensors to halt charging if temp > 50°C |
| ⚖️ Cell Balancing      | Voltage readings from 3 cells used to detect imbalance |
| 🧠 Degradation Tracking| Estimated degradation from charge cycles and voltage drop over time |
| 📉 Safe Charge Control | MOSFET/Relay switching based on sensor data |

---

## 🔩 Hardware & Tools Used

| Component                  | Purpose |
|---------------------------|---------|
| Arduino Nano              | Core controller running the BMS firmware |
| Current Sensor (ACS712)   | Measures charging current |
| Temperature Sensors (NTC) | Reads battery thermal data |
| Voltage Divider Network   | Measures individual cell voltages |
| MOSFETs / Relays          | Switches high-current paths |
| 3S Li-ion Battery Pack    | 12V / 80Wh test battery |

---

## 💻 Code Features (Arduino C++)

- Real-time voltage & temperature sensing via ADC
- Logic:
  - `if temp > 50°C` → Stop charging
  - `if cell voltage > 4.2V` → Stop charging
  - `if ΔV > 0.1V across cells` → Slow down charging
- Adaptive power levels based on charge percentage

---

## 🧠 Learning Outcomes

- Real-world fast charging control
- Battery safety + embedded power management
- Multi-cell monitoring and logic control
- Lithium-ion battery care principles

---
