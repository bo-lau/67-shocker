## 6‑7 Shocker

Webcam detects the “6‑7” gesture and tells an Arduino Uno to close a relay wired in series with a TENS channel, so that channel is enabled for a few seconds when the gesture happens. Use at your own risk; never bypass TENS safety features or medical guidance. 

---

## Hardware

- Arduino Uno R3  
- 5 V relay module (using **IN1** / channel 1)  
- USB cable to your computer  
- TENS unit with channel **A** lead  
- Channel A lead modified so:
  - One conductor is routed through **COM1 → NO1** on relay channel 1  
  - The other conductor remains continuous end‑to‑end (joined outside the relay)

---

## Disclaimer

This project is provided **for educational purposes only**. It involves electrical stimulation hardware and Arduino‑controlled relays.

- You are solely responsible for how you build and use this project.  
- There is **no warranty** and **no guarantee of safety or fitness for any purpose**.  
- By using this code or wiring, you agree that the author of this repo are **not liable** for any injury, damage, or consequences that may result.

If you are unsure about safety, **do not build or use this project**. 

---

## Arduino

1. Open the repo’s `.ino` file in **Arduino IDE**.  
2. Select **`Tools → Board → Arduino Uno`**.  
3. Select the correct **`Tools → Port`** (the Uno’s port).  
4. Click **Upload**.  
5. Close the Serial Monitor if it’s open.

The sketch listens on `Serial` for a single character:

- `p` → close the relay on IN1 (D7) for a fixed pulse duration  
- `1` → keep relay ON  
- `0` → keep relay OFF  

---

## Web App

1. Open the `6-7-detector.html` file **locally in Chrome or Edge** (browsers that support the Web Serial API). 
2. Click **“Connect Arduino”** and select the Uno’s serial port when prompted.  
3. Power on the TENS, select channel **A**, set intensity low, pads connected as desired.  
4. When the 6‑7 gesture is detected by the webcam, the page sends `p` over Web Serial; the Uno closes the relay and that TENS channel is active for the pulse duration defined in the sketch.

---

## Safety

- Start with **non‑human loads** (pads on a damp sponge, resistor load, etc.), then cautiously move to body tests at **minimum intensity only** if you choose to.  
- Avoid chest, head, or any path that could cross the heart; never use on anyone with implants or relevant medical conditions. 
- If anything feels unsafe or abnormal, stop immediately and disconnect power.
