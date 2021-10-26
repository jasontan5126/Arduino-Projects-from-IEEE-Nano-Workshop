# Arduino-Projects-from-IEEE-Nano-Workshop

**Project 1 (Potentiometer Blink):**  
 -> Create a blinking LED with its blinking rate controlled by a potentiometer. 
 
 -> Print the value being read from the potentiometer to your Serial monitor
 
**Project 2 (Digital vs. Analog, and PWM):**  
      
      **Part 1 - Sound**
          -> Write a song (minimum 10 notes) using play( ) and play it through your speaker.
          -> Get creative!
          -> Example song here: Despacito
               =>Copy-paste into your code and call Despacito() in loop() to use!
          -> No experience with music? No problem. Here are some songs with labelled notes.
     
       **Part 2 - Interface**
          -> Implement the potentiometer interface.
          -> Depending on where the dial is turned, a different song will play when you press RESET.

          -> Be able to switch between at least 3 songs.
               => This means you will have to add more music!
          -> You will need to use several if statements.
 **Project 3 - (Distance Sensor):** 
  
       **Overview**
          -> Using Arduino, LEDs, IR Emitters, and IR phototransistors, make a Distance Sensor!
               => The closer an object is to the sensor, the brighter the LED should be
               => We can control LED brightness with PWM (Pulse width modulation: 
                  Let you change the duty cycle and gives you an average 
                  voltage between 0 to 5V)
       
 

 
**Project 4 (Serial Communication):**  

        **Overview**
          -> In this project, you will be implementing a 2-Arduino game called Red Light, Green Light. 
             In this game you are a carduino playing against a randomly generated stoplight: 
             You must move at a green light, and stop at a red light; should you run over a 
             red signal, or stay put at a green signal, you lose. If you get it right, you’ll 
             gain a point and move to the next intersection.
             
         Materials Required:
	      
		=> 2 Arduino Nano
		=> 2 Breadboard
		=> 1 Green LED
		=> 1 Red LED
		=> 1 White LED
		=> 2 Push Button
		=> two 10kOhm Resistor
		=> two 100nF Capacitor
	   
	 Checkpoint 1: Getting your MCUs talking to each other	
		Wire up your MCUs so that we can get them talking using the Serial library. 
		To read and write between hardware devices, use the Serial library’s read 
		and write functions. Also, make sure that you are first checking that there 
		is available serial data before reading from Serial. To print text to the
		screen of your computer use the print or println functions as we have done before.
		Remember that data transmitted by one MCU is data received by the other. 
		Connect the Tx of one device to the Rx of the other device and vice versa.
		Make sure you also connect GND pins on both devices to each other so they share
		a common ground. 
		
		NOTE: DO NOT CONNECT THE TX RX PINS WHEN UPLOADING A SKETCH TO YOUR ARDUINO. 
		Disconnect these pins when uploading code and reconnect them after the code 
		is done uploading.

		Checkpoint 1: Write two sketches, one for each Arduino. One sketch(transmitter) 
		should send two different characters continuously in a loop with a small delay 
		between sending each character. The other sketch(receiving) should turn on the
		onboard led (pin 13) when one of the characters is received and turn off the 
		onboard led when the other character is received. Make sure to set the same baud 
		rate for both sketches. Use 2 computers to observe the data going over more easily.

	Checkpoint 2: Wiring Up the Hardware

		Stoplight Arduino: 
		You will need to hook up 2 different output LEDs (choose between red, yellow 
		and/or green)** to your Stoplight Arduino. Remember, LEDs can burn out if more 
		than 20mA of current passes through them, and usually you want to limit current 
		to <=5mA to save energy and to prevent the LED from being too bright. Make sure 
		to include a current-limiting resistor in series with your LEDs. The digital pins 
		output ~5V when you write HIGH.


		Carduino: 
		Your Carduino will have 2 push button inputs, one representing the gas pedal and 
		one representing your brake. If the Green Light is flashed, you’ll press on the 
		gas button. When the Red Light is flashed, you’ll press on the brake. Grab these
		buttons from the OPS parts drawers. Use this pinout to help you in selecting pins 
		for your Arduino

			Button Debouncing
			When you press or release a button, it will “bounce” several times before 
			reaching its final state, which means several button presses will be registered.
			One way to avoid this is to put a capacitor in series with the button, so 
			that the button release will not register until after the capacitor is fully 
			discharged over time. If the capacitor’s value has been appropriately chosen, this
			will be after the button has finished bouncing, such that only one press will be 
			registered. Below is the basic circuit for button debouncing:
			
			

			
			

			Vout is the voltage read by the microcontroller input pin, and Vdd is +5V. Use a 
			10k resistor and a 100nF capacitor for your debouncing circuit, so that you achieve
			an RC time constant of 1ms (time constant = resistance * capacitance).
			NOTE: This debouncing circuit also includes a pull-down resistor, so that Vout is HIGH
			when the button is pressed, and LOW otherwise. Also, the RC constant can be a complicated
			topic, but for now it is sufficient to understand that it is the product of resistance 
			and capacitance, and corresponds to the amount of time the circuit debounces. 
			
		Checkpoint 2-a: Draw the full schematic (on paper). After you get checked off, continue onto...
		
		Checkpoint 2-b: Write a sketch and build the circuit to light up each LED on one Arduino while
		its corresponding button on the other is pressed down. When a button is released, the LED should 
		turn off.

		Checkpoint 3: Red Light, Green Light
		The final objective of this lab is to write a complete implementation of the Red Light Green Light game.
		The expectations for this game are as follows:

		Game Requirements:
		Two differently colored LEDs (Stoplight side; the game controller) One white LED (Carduino side; the player)
		The Stoplights (Game Controller) flashes one of the LEDs; the color chosen should be as random as possible 
		(check the Appendix for help on this); On the Carduino (Player Module), the player should press the button that 
		matches the LED the Controller flashed (i.e. Gas for Green Light, Brake for Red Light) The Stoplight (Game Controller) 
		should wait until a button is pressed on the Carduino (Player Module). The player must press the correct button. 
		If the player presses the correct button, the white LED must blink and a point must be added to the player’s score. 
		A new round must begin. Should the player lose (by pressing the incorrect button), the white LED on the Car (Player Module) 
		should turn on for 5 seconds, then start a new game (remember to reset score). The serial monitor should print the 
		player’s score at the end of every round (intersection). When the play loses, the serial monitor should show this 
		with the reset score after the game starts again.

		Project Completion: Implement the Red Light, Green Light game, adhering to the above requirements.
 
 
