# ThreadX semaphore basic example

Semaphore is here used to synchronize between two threads. Where `my_thread2` is waiting until semaphore is available. 
And `my_thread` is giving the sempahore. 

Also in this example is possible use counting semaphore limit by  `tx_semaphore_ceiling_put` instead of `tx_semaphore_put`.

[Example link](https://github.com/RRISTM/stm32_threadx/tree/master/examples/threadx_semaphore_basic)