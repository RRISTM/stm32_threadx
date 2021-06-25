# ThreadX thread create example

Example is showing how to create your thread. 
Thread will be named `my_thread`
With stack `thread_stack` of size `THRAD_STACK_SIZE`
Thread have priority 15 and will start automatically. 

```c
  ret_val = tx_thread_create(&thread_ptr, "my_thread",
      my_thread_entry, 0x1234,
	  thread_stack, THRAD_STACK_SIZE,
      15, 15, TX_NO_TIME_SLICE,
      TX_AUTO_START);
```

The thread is running function `my_thread_entry`

```c
VOID my_thread_entry (ULONG initial_input)
{
	while(1){
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
		tx_thread_sleep(50);
	}
}
```

Function only toglle with LED and the go to sleep for `500ms`.

[Example link](https://github.com/RRISTM/stm32_threadx/tree/master/examples/threadx_thread_create)