# ThreadX memory byte pool example

Example is showin how to use byte pools and demonstrate possible issues. 

Forst example is creating byte pool. Byte pool is 400B.

```c
  ret_val=tx_byte_pool_create(&pool_ptr,'our_byte_pool',out_byte_array,OUT_BYTE_ARRAY_LENGTH);
```

Then we alocate from this pool memory of 128B and 128B

```c
  ret_val=tx_byte_allocate(&pool_ptr,(VOID **)&allocated_space_pointer,128,TX_NO_WAIT );
  ret_val=tx_byte_allocate(&pool_ptr,(VOID **)&allocated_space_pointer_2,128,TX_NO_WAIT );
```

Then we will retun `allocated_space_pointer` back

```c
ret_val=tx_byte_release(allocated_space_pointer);
```

But because we returned first seqment the byte pool is not able to defregment free space so we have available 128B + 144B(400B-128B-128B). So we will not be able allocate 200B

```c
ret_val=tx_byte_allocate(&pool_ptr,(VOID **)&allocated_space_pointer_3,200,TX_NO_WAIT ); //this will fail
```

Here you must guarantee the byte pool have enaugh space. Or not use memory release and instead use block pool. 


[Example link](https://github.com/RRISTM/stm32_threadx/tree/master/examples/threadx_memory_byte_pool)