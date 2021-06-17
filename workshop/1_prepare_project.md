----!
Presentation
----!

# Start led blink from scratch

- This short hands-on will show you how to start a project from scratch
- The point is to a get first running led blink in few clicks
- We will then use this base to go further with ThreadX

![Create MX project](./img/12.svg)

# Launch STM32CubeIDE

![CubeMX icon](./img/01.png)

# Select a workspace, click on Launch

![Select a workspace](./img/02.png)

# Start a new project

- Or use File>New>STM32Project (IDE)

![New project](./img/03.png)

# Board selector

- Click on board selector

![Board](./img/04.png)

# Look for Nucleo H723

1. Type H723 in the search box
2. Then click on Nucleo H723

![Nucleo board](./img/05.png)

# Select proposed board

1. Select proposed board
2. Click Next

![Nucleo board selection](./img/06.png)

# Project name

1. Type the project name
2. Next
3. Check FW version
4. Finish

![project name check](./img/07.png)

# Finish the project setup

1. In pop-up asking of peripherals initialization
2. Click Yes

![periphery init](./img/08.png)

3. Then second popup to ask to open device configuration perspective.
4. Click Yes

![device perspective](./img/09.png)

# What you get after few clicks

![generation result](./img/10.png)

# Edit main.c to add your code

1. Look for main.c and double click

![main.c](./img/11.png)

2. Answer yes to the open perspective
3. Then go down to the main() function and find the while(1) loop line 129

```c
/* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }

```

# Adding LED toggling using code completion

1. Just before comment /_ USER CODE END WHILE _/ type:
2. HAL_GPIO_T and the CTRL-Space bar you should get:

![gpio toggle pin](./img/12.png)

3. First argument LED_GREEN_GPIO_Port (type LED CTRL+Space)
4. Second argument LED_GREEN_Pin
5. Add the final ‘;’

![gpio toggle pin selection](./img/13.png)

Or copy here:

```c
 HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
```

# HAL GPIO Toggle

- Each time HAL_GPIO_TogglePin is called

  - LED will turn on/off

- Without delay impossible to see in run
  - Only in debug stepping

![gpio toggle pin hal](./img/13.svg)

# Adding the delay between each LED toggle

1. Starting from

![adding delay](./img/14.png)

2. Type HAL_Delay
3. Choose a delay in ms : 500

![hal delay](./img/15.png)

```c
HAL_Delay(500);
```

4. Add final semicolon `;`
5. Now compile the project using the hammer

![compile](./img/16.png)

# Compilation result

![compile result](./img/17.png)

# Connect the board to the computer

- Time to transfer firmware to the board
- First connect the Nucleo board to the computer

![connect board](./img/18.png)

# Download firmware and Run on target

- First click on the project name
- Then menu Run/Run As/STM32 …
- In Edit Configuration window click OK

![run debug](./img/19.png)

# LED is Blinking

![run code](./img/20.png)
