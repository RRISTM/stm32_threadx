# ThreadX timer basic example

Example is showing how to create and use SW timer. 

Tmer is activated in `my_thread` by `tx_timer_activate`. And when expires it will call `my_timer_expire` function where is led toggle. 

[Example link](https://github.com/RRISTM/stm32_threadx/tree/master/examples/threadx_timer_basic)