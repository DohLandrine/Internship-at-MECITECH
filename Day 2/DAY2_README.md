# Day 2 - Sound System Design for Attendance Device

**Date:** Tuesday July 24, 2025

## Tasks Done

- Began working on the sound system of an “attendance taking system”.
- Tasked to use an ESP32 and a passive buzzer to generate audio feedback.
- Defined sound behaviors for various user and system events.
- Mapped each event sound to a corresponding LED color indicator.

## Task Description

Design and implement sound feedback using a passive buzzer on ESP32. Each sound corresponds to a specific system action. Sound behaviors are categorized as:

- **Blocking**: Played once for about 2 seconds.
- **Non-blocking**: Repeated in a pulsing manner (e.g. 500ms ON, 500ms OFF) until the event ends.

### Sound Type Breakdown

| Sound Type         | Behavior     |
|--------------------|--------------|
| Turned On          | Blocking     |
| Remove Finger      | Non-blocking |
| Place Finger       | Non-blocking |
| Accepted           | Blocking     |
| No Match           | Blocking     |
| Low Battery        | Blocking     |
| Alert to Power Off | Blocking     |
| Power Off          | Blocking     |
| Error              | Blocking     |
| Connected          | Blocking     |
| Disconnected       | Blocking     |

## What I Learned

- How to classify and design sound responses based on system interaction types.
- Best practices for giving audio feedback in embedded systems.
- Considerations for user experience in low-cost hardware interfaces.

## Tools/Technologies Used

- ESP32
- Passive Buzzer
- Embedded C / Arduino Framework
- LEDs for visual pairing with sounds
