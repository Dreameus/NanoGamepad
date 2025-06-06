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
│ └── wiring-diagram.png
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

```bash
pip install pyserial pyvjoy
🚀 How to Run
1. Upload Arduino Sketch
Flash the nano_gamepad.ino to your Nano using the Arduino IDE.

2. Connect Arduino
Plug the Nano into your PC (COM3, COM4, etc.)

3. Run Python Script
Edit the serial port in python/vjoy_controller.py if needed, then run:

bash
Копировать
Редактировать
python python/vjoy_controller.py
4. Test
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
Made by [Your Name or GitHub username] — 2025

yaml
Копировать
Редактировать

---

Would you like me to bundle this with your code and send you a ZIP to upload to GitHub directly?






Вы сказали:
make fully read me make it very good


ChatGPT сказал:
Absolutely! Here’s a detailed, professional, and polished README.md for your Arduino Nano + Python vJoy Gamepad project — perfect for GitHub to impress at DevHacks or anywhere:

markdown
Копировать
Редактировать
# 🕹️ Arduino Nano + Python vJoy Gamepad

**Transform your Arduino Nano into a fully functional USB virtual gamepad using Python and the vJoy driver on Windows!**

This project reads inputs from a single analog joystick and four buttons connected to an Arduino Nano, sends the data via USB serial, and uses a Python script to map the inputs to a virtual joystick device via vJoy.

---

## 🎮 Features

- **1 analog joystick** (X and Y axes)
- **4 digital buttons** (A, B, X, Y)
- Real-time USB serial communication from Arduino to PC
- Python script translates serial data into vJoy joystick inputs
- Works with any Windows game supporting gamepads
- Easy to extend with more buttons or controls

---

## 📂 Project Structure

nano-vjoy-gamepad/
├── arduino/
│ └── nano_gamepad.ino # Arduino sketch (main firmware)
├── python/
│ └── vjoy_controller.py # Python script for serial → vJoy mapping
├── hardware/
│ └── wiring-diagram.png # Optional wiring diagram image
├── README.md # This documentation file
├── .gitignore # To exclude build and temp files
└── LICENSE # MIT License file (optional)

markdown
Копировать
Редактировать

---

## 🔌 Hardware Components & Wiring

| Component       | Arduino Pin   | Notes                           |
|-----------------|---------------|--------------------------------|
| Analog Joystick | X → A0        | Connect VRx to A0 (analog input) |
| Analog Joystick | Y → A1        | Connect VRy to A1 (analog input) |
| Button A        | D2            | Connect one side to pin, other to GND |
| Button B        | D3            | "                              |
| Button X        | D4            | "                              |
| Button Y        | D5            | "                              |
| Power           | 5V            | For joystick and buttons       |
| Ground          | GND           | Common ground for all           |

> **Button wiring note:** Use the Arduino's internal pull-up resistors. Buttons connect pin to GND so pressed = LOW.

> You can add a wiring diagram image `hardware/wiring-diagram.png` for clarity.

---

## ⚙️ Software Requirements

- **Arduino IDE** — to upload the sketch  
- **vJoy Driver** — to create a virtual joystick device  
  [Download & install vJoy](https://github.com/jshafer817/vJoy)  
  Make sure to configure a device with at least 2 axes (X, Y) and 4 buttons  
- **Python 3.9+**  
- Python packages: `pyserial` and `pyvjoy`

Install Python packages via:

```bash
pip install pyserial pyvjoy
🚀 Getting Started
1. Upload the Arduino Sketch
Open arduino/nano_gamepad.ino in Arduino IDE

Select Arduino Nano board and correct COM port

Upload the sketch

2. Connect Your Hardware
Connect your joystick and buttons to Arduino as per wiring

Plug the Arduino Nano into your PC via USB

3. Configure vJoy
Open the vJoy Configuration application

Make sure at least one device is enabled

Set up 2 axes (X and Y) and 4 buttons

Apply and close

4. Run the Python Script
Open terminal / PowerShell

Navigate to the project folder

Run:

bash
Копировать
Редактировать
python python/vjoy_controller.py
Make sure the COM port in the script matches your Arduino's COM port (COM3, COM4, etc.)

5. Test Your Gamepad
Open Gamepad Tester or any gamepad test software

Move joystick and press buttons to verify input is working

🧠 How It Works
Arduino reads analog joystick (0–1023) and button states

It maps joystick values to vJoy axis range (0–32767)

Button states are inverted (pressed = 1) via internal pull-ups

Data is sent as comma-separated values over Serial USB

Python script reads Serial data, parses it, and updates vJoy device accordingly

🛠️ Customization & Extensions
Add more buttons:
Add digital pins in Arduino and update Python button mapping

Add second joystick or triggers:
Use additional analog inputs (e.g., A2, A3) and extend vJoy axes

Add deadzone or smoothing:
Implement in Arduino or Python for better control feel

Change COM port or baud rate:
Adjust in both Arduino and Python script

🔧 Troubleshooting
Problem	Solution
Python script can't open COM port	Check Device Manager for correct COM port and permissions
No input detected in game/tester	Ensure vJoy device is enabled and configured correctly
Arduino not detected	Check USB cable and drivers
Buttons not responding	Verify wiring and button pull-ups
Python throws errors	Confirm correct Python version and installed packages

📜 License
This project is licensed under the MIT License

👤 Author
Made by Dreameus — 2025

🔗 Useful Links
vJoy Official GitHub

pyvjoy PyPI page

Gamepad Tester

Arduino Nano Documentation

Thank you for checking out this project! Feel free to open issues or submit pull requests.
