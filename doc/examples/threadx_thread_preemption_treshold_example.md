# ThreadX thread preemption treshold example

This example is showing how to enable preemption treshold in CubeMX 

Demonstrate preemption treahold between two threads. 

```c
  ret_val = tx_thread_create(&thread_ptr, "my_thread",
      my_thread_entry, 0x1234,
	  thread_stack, THRAD_STACK_SIZE,
      14, 14, 1,
      TX_AUTO_START);
  //preemption threshold
  ret_val = tx_thread_create(&thread_ptr2, "my_thread2",
      my_thread_entry2, 0x1234,
	  thread_stack2, THRAD_STACK_SIZE,
      15, 14, 1,
      TX_AUTO_START);
```

And thier functions

```c
VOID my_thread_entry (ULONG initial_input)
{
	while(1){
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
		HAL_Delay(250);
		tx_thread_sleep(20);
	}
}

VOID my_thread_entry2 (ULONG initial_input)
{
	while(1){
		HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_1);
		HAL_Delay(500);
		tx_thread_sleep(20);
	}
}
```

They use `HAL_Delay` which forse thread to run for this time.
With preemption treshold you can see that each thread run for `HAL_Delay`

But if you remove preemption threshold 

```c
//preemption threshold
//  ret_val = tx_thread_create(&thread_ptr2, "my_thread2",
//    my_thread_entry2, 0x1234,
//	  thread_stack2, THRAD_STACK_SIZE,
//    15, 14, 1,
//    TX_AUTO_START);
  //without preemption threshold
  ret_val = tx_thread_create(&thread_ptr2, "my_thread2",
      my_thread_entry2, 0x1234,
	  thread_stack2, THRAD_STACK_SIZE,
      15, 15, 1,
      TX_AUTO_START);
```

Then `my_thread2` will run only when my_thread is in sleep. 

[Example link](https://github.com/RRISTM/stm32_threadx/tree/master/examples/threadx_thread_preemption_treshold)