# Threadx mutex basic example

Basic demonstration of mutex example. 
Mutex is used to block access to GPIO. 
`my_thread` `13`priority and `my_thread2` `15`priority are using GPIO and both are protecting it with mutex. 
`my_thread3` is `14` pririty thread which is blocking `my_thread2`
The `my_thread3` can simply block `my_thread2` with mutex locked here is possible to demonstra priority inherience where `my_thread2` get priority `13` to unlock mutex. 

[Example link](https://github.com/RRISTM/stm32_threadx/tree/master/examples/threadx_mutex_basic)