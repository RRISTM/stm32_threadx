# ThreadX queue basic example

Demonstrate usage to message queue. In tihs case between threads. 
We have one thread `my_thread` controlling GPIO. And two other threads `my_thread2` and `my_thread3` which are sending messages which GPIO to toggle. 

For sending is use 

```c
tx_queue_send(&queue_ptr,&message,TX_NO_WAIT);
```
For reception 

```c
ret_val=tx_queue_receive(&queue_ptr,&message,TX_WAIT_FOREVER);
```

[Example link](https://github.com/RRISTM/stm32_threadx/tree/master/examples/threadx_queue_basic)