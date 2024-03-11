# Climb-Sense-Hold

Climb-Sense-Hold is a climbing hold that can sense when it is grasped by a climber. Intended for use in climbing gyms, especially on moon boards, it aims to enhance training by dynamically indicating the next hold to grab based on real-time sensing.

<img width="800" alt="Screenshot 2024-03-11 at 2 02 14 PM" src="https://github.com/aapatni/climb-sense-hold/assets/21110240/a64fa727-0268-4b8f-905f-a474b3387772">

Check out a demo [here](https://youtu.be/DqYrknb-pzY)

## Technical Details

- Utilizes capacitive touch sensing facilitated by nickel-based conductive paint applied to the climbing holds.
- Hardware: Includes Arduino Mega 2560, Adafruit MPR121 touch sensor, conductive paint, and standard climbing hold materials.
- Functionality: Holds change color to guide climbers: blue for the next target, red for holds to avoid, and green to confirm a successful grip.

## Prototyping

Flexible Pressure Sensor: First approach; discarded due to inconsistency and installation challenges.
    
<img width="500" alt="Screenshot 2024-03-11 at 1 58 50 PM" src="https://github.com/aapatni/climb-sense-hold/assets/21110240/0edd1856-c859-4458-ae38-35f12571985e">

Atmospheric Pressure Sensor: Second approach; discarded due to sealing issues and extremely fine granularity in pressure changes.
    
<img width="500" alt="Screenshot 2024-03-11 at 1 59 05 PM" src="https://github.com/aapatni/climb-sense-hold/assets/21110240/a0cc6a0f-1b05-4d8e-9c27-f207c4bcb77a">

Capacitive Touch Sensing: Chosen method for its simplicity, minimal hardware requirements, and ease of integration.

<img width="500" alt="Screenshot 2024-03-11 at 1 59 15 PM" src="https://github.com/aapatni/climb-sense-hold/assets/21110240/b7f1b55b-3dae-4579-ae21-6ab5ddb799db">

## Final Design

I built a hang board featuring six sensor-equipped holds, implementing a game to aid in strength training. The system uses LEDs to guide the climber and simple logic to process touch input and control the LEDs.
