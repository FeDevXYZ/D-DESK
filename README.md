<h1 align="center">D-DESK</h1>
<p align="center">
  A custom programmable keypad with 9 buttons, 2 potentiometers, and an OLED display, powered by ESP32.
</p>

<h2>Features</h2>
<ul>
  <li>9 configurable buttons in a 3x3 grid with visual feedback (highlight and inversion)</li>
  <li>Two potentiometers with rounded, filling bars showing position in real time</li>
  <li>Clean, intuitive OLED 128x64 interface</li>
  <li>Compatible with ESP32 (ESP32-S3-DevKitC-1 recommended)</li>
  <li>Buttons wired from GPIO2 to GPIO10 with internal pull-ups</li>
  <li>Potentiometers connected to analog inputs A0 and A1</li>
</ul>

<h2>Hardware Required</h2>
<ul>
  <li>ESP32-S3-DevKitC-1 (or similar ESP32 board)</li>
  <li>OLED SSD1306 128x64 (I2C)</li>
  <li>9 push buttons connected from GPIO2–GPIO10 to GND</li>
  <li>2 potentiometers connected to A0 and A1</li>
</ul>

<h2>Pinout</h2>
<table>
  <thead>
    <tr>
      <th>Component</th>
      <th>ESP32 Pin</th>
    </tr>
  </thead>
  <tbody>
    <tr><td>Buttons 1–9</td><td>GPIO 2 to GPIO 10</td></tr>
    <tr><td>Potentiometer X</td><td>A0</td></tr>
    <tr><td>Potentiometer Y</td><td>A1</td></tr>
    <tr><td>OLED SDA</td><td>GPIO 21 (I2C SDA)</td></tr>
    <tr><td>OLED SCL</td><td>GPIO 22 (I2C SCL)</td></tr>
  </tbody>
</table>

<h2>Installation</h2>
<ol>
  <li>Clone this repository</li>
  <li>Open the project in Arduino IDE</li>
  <li>Install required libraries: <b>Adafruit_SSD1306</b> and <b>Adafruit_GFX</b></li>
  <li>Configure pins if needed</li>
  <li>Upload the sketch to your ESP32 board</li>
</ol>

<h2>Usage</h2>
<ul>
  <li>Press buttons to trigger actions (customize in code)</li>
  <li>Potentiometers update bars on the OLED in real time</li>
  <li>OLED shows button states and potentiometer values visually</li>
</ul>

<h2>Languages and Tools</h2>
<p>
  <a href="https://www.arduino.cc/" target="_blank" rel="noreferrer">
    <img src="https://cdn.worldvectorlogo.com/logos/arduino-1.svg" alt="Arduino" width="40" height="40"/>
  </a>
  <a href="https://www.w3schools.com/cpp/" target="_blank" rel="noreferrer">
    <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/cplusplus/cplusplus-original.svg" alt="C++" width="40" height="40"/>
  </a>
</p>

<h2>License</h2>
<p>MIT License</p>
