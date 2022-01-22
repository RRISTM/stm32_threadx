# ThreadX basic

ThreadX is added by CubeMX to project on place.

The main access point to Thread is include for `tx_api.h`

```c
#include "tx_api.h"
```

ThreadX is added by CubeMX to Middleware section

![ThreadX Middleware](./img/2021_04_20_000009.png)

CubeMX generated files are in AZURE_RTOS and Core/Src

![ThreadX Middleware](./img/2021_04_20_000010.png)

Main file for user to handle is app_threadx.c where it's needed to create ThreadX items like tasks, queues, memory pools, ...

## Program start flow

ThreadX is called from main.c over `MX_AZURE_RTOS_Init` function. Inside is a call to `tx_kernel_enter` which will initialize ThreadX and start it.
Before ThreadX is started. The `tx_application_define` is called where used can allocate his memory, create tasks and other items from ThreadX. After this function ends ThreadX is started.

![ThreadX init flow](./img/03.svg)
