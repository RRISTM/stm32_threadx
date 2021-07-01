# ThreadX memory block pool example

This example is showing how to create a block pool. 

We create one block pool named `block pool`. 
Block pool is created from 400B and one block will be 150B so we have two blocks. 

```c
ret_val=tx_block_pool_create(&pool_ptr,'block pool',150,out_byte_array,OUR_BLOCK_ARRAY_LENGTH);
```

Then we allocate two blocks in from this pool this will take all available blocks

```c
  ret_val=tx_block_allocate(&pool_ptr,(VOID **)&allocated_space_pointer,TX_NO_WAIT);
  ret_val=tx_block_allocate(&pool_ptr,(VOID **)&allocated_space_pointer_2,TX_NO_WAIT);
```

Here we dealocate one pool by 

```c
ret_val=tx_block_release(allocated_space_pointer);
```

So now it is one available block
we can allocate him

```c
ret_val=tx_block_allocate(&pool_ptr,(VOID **)&allocated_space_pointer_3,TX_NO_WAIT);
```

# Test alocation fail

If you will comment

```c
//ret_val=tx_block_release(allocated_space_pointer);
```

Then no additional pool will be possible to allocate and last allocation will return non zero value in `ret_val`


[Example link](https://github.com/RRISTM/stm32_threadx/tree/master/examples/threadx_memory_block_pool)
