# 🕹️ Arduino Nano + Python vJoy Gamepad

This project turns an **Arduino Nano** into a working USB **virtual gamepad** using **Python** and **vJoy** on Windows.

It supports:
- 1 analog joystick (X/Y axes)
- 4 buttons (A, B, X, Y)

All signals are read by the Arduino and sent over USB serial to a Python script, which maps them to a **vJoy virtual joystick** recognized by games.

---

## 📂 Project Structure

nano-vjoy-gamepad/
├── arduino/
│ └── nano_gamepad.ino # Arduino sketch
├── python/
│ └── vjoy_controller.py # Python script for vJoy
├── hardware/
│ └── wiring-diagram.png # Optional wiring diagram
├── README.md

---

## 🔌 Hardware Setup

| Component  | Arduino Pin |
|------------|-------------|
| Joystick X | A0          |
| Joystick Y | A1          |
| Button A   | D2          |
| Button B   | D3          |
| Button X   | D4          |
| Button Y   | D5          |
| VCC        | 5V          |
| GND        | GND         |

> *(You can add `wiring-diagram.png` to the `hardware/` folder)*

---

## ⚙️ Requirements

### ✅ Hardware
- Arduino Nano (or compatible)
- 1 analog joystick
- 4 push buttons
- USB cable

### ✅ Software
- [vJoy driver](https://github.com/jshafer817/vJoy) (install & configure)
- Python 3.9+ (with `pyserial` and `pyvjoy`)

### ✅ Python Libraries
Install them with pip:

pip install pyserial pyvjoy
🚀 How to Run
1. Upload Arduino Sketch
Flash the nano_gamepad.ino to your Nano using the Arduino IDE.

2. Connect Arduino
Plug the Nano into your PC (COM3, COM4, etc.)

3. Run Python Script
Edit the serial port in python/vjoy_controller.py if needed, then run:
python python/vjoy_controller.py

5. Test
Go to https://gamepad-tester.com and move the joystick / press buttons.

🧠 How It Works
The Arduino reads analog and digital inputs

It sends mapped data (0–32767 for axes, 0/1 for buttons) via Serial

Python reads the data, parses it, and updates vJoy

🔧 Troubleshooting
If Python can't open COM port: check Device Manager → Ports → Arduino COM#

If pyvjoy fails: ensure vJoy is installed and Device 1 is configured

To change joystick axes or buttons: modify Arduino code and Python indices

📜 License
MIT License — feel free to modify, use, and share.

✍️ Author
Made by Dreameus — 2025
