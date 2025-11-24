# **Text Twist by C.Code**
<div align="center">

![GitHub top language](https://img.shields.io/github/languages/top/mhnriz/Game-Project-Text-Twist?style=for-the-badge&color=66C842)
![GitHub last commit](https://img.shields.io/github/last-commit/mhnriz/Game-Project-Text-Twist?style=for-the-badge&color=5FCB41)
![GitHub repo size](https://img.shields.io/github/repo-size/mhnriz/Game-Project-Text-Twist?style=for-the-badge&color=038800)

<br>

![Platform](https://img.shields.io/badge/platform-Ubuntu-66C842?style=for-the-badge)
![Audio](https://img.shields.io/badge/Audio-PulseAudio-5FCB41?style=for-the-badge)
![Graphics](https://img.shields.io/badge/Graphics-X11%20Custom%20GFX%20Library-038800?style=for-the-badge)

</div>

---

## 📖 **Overview**

**Text Twist by C.Code** is a Linux-based word puzzle game inspired by the classic **Text Twist**, written entirely in **C**, using a custom pixel graphics engine and sound system.

The game features animated sprites, sound effects, a complete word validation system, and an interactive GUI built using X11.

---

## 🎮 **Gameplay Features**

- 🧩 Randomized letter sets from `GameSets.txt`
- 📚 Dynamic wordlist loading for each game mode
- 🎼 Background music (PulseAudio)
- 🔊 SFX: tap, correct, wrong, bingo
- 🌥️ Animated menu with clouds + sprites
- 🧠 Word validation with duplicate prevention
- ✨ Bingo bonus animation for longest word

---

## 📁 **Project Structure**

```
project/
│
├── data/
│   ├── GameSets.txt
│   ├── wordlist_Game1.txt
│   ├── wordlist_Game2.txt
│   ├── wordlist_Game3.txt
│   ├── bgm.wav
│   ├── tap.wav
│   ├── correct.wav
│   ├── wrong.wav
│   └── bingo.wav
│
├── gfx.c
├── gfx.h
├── gfx_element.c
├── gfx_element.h
├── main.c
└── README.md
```

---

## 🧰 **Dependencies**

Install the required system libraries:

```bash
sudo apt install libx11-dev libpulse-dev build-essential
```

---

## 🛠️ **Build Instructions**

Compile using:

```bash
gcc main.c gfx_element.c gfx.c -o texttwist \
-lX11 -lm -lpulse-simple -lpulse -pthread
```

Run the game:

```bash
./texttwist
```

---

## 🕹️ **How to Play**

### Main Menu
- **PLAY** – Start game  
- **HELP** – View instructions  
- **EXIT** – Quit  

### In Game
| Action | Method |
|--------|--------|
| Select letter | Click letter tile |
| Submit guess | Enter |
| Delete | Delete button |
| Twist letters | Twist button |
| End round | END? |

### Scoring
- Valid word → `2 × length`
- Longest word → **BINGO bonus**

---

## 📦 Data Files

### `GameSets.txt`  
List of base letter combinations.

### Wordlists  
- `wordlist_Game1.txt`  
- `wordlist_Game2.txt`  
- `wordlist_Game3.txt`  

Loaded depending on selected set.

---

## 🎨 Graphics & Animation

Includes:  
- Peashooter  
- Repeater  
- Ice Shooter  
- Zombie (2 frames)  
- Clouds  
- House & grass tiles  

All rendered with **custom pixel drawing functions** in `gfx.c`.

---

## 🔊 Audio System

Built using **PulseAudio Simple API** with separate threads for SFX and BGM.

---


