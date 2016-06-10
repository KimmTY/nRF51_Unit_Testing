# nRF51_Unit_Testing
- This repository help you getting unit test result with Unity framwork from nRF51-DK board.
- This repository is modified from ble_app_uart_s110_pca10028.
- This repository contains test code which is not related with project working code. Only prove nRF51-DK can print test code result.

# Need
- nRF51-DK
- Serial terminal program, e.g., Teraterm
- arm-none-eabi-gcc 4.9.3


# 1. Download repository and unzip

# 2. Connect nRF51-DK

# 3. Run Teraterm and config UART
- baudrate : 38400
- data : 8 bit
- parity : none
- stopbit : 1 bit
- control-flow : hardware

# 4. Run CMD and Type Commands
```
$ cd nRF51_Unit_Testing-master
$ make all
$ make flash_softdevice
$ make flash nrf51422_xxac_s110
```
# 5. Check test code result from Teraterm

# 6. Result


###UART confg

###Terminal text color config

###Test result attribute

