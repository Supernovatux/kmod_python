/* 

 * hello-2.c - Demonstrating the module_init() and module_exit() macros. 

 * This is preferred over using init_module() and cleanup_module(). 

 */ 

#include <linux/init.h> /* Needed for the macros */ 
#include <linux/random.h>
#include <linux/ktime.h>
#include <linux/kernel.h> /* Needed for pr_info() */ 

#include <linux/module.h> /* Needed by all modules */ 
#define ARR_LEN_MY_MOD 1024
MODULE_LICENSE("GPL"); 

MODULE_AUTHOR("supernovatux"); 

MODULE_DESCRIPTION("learning");  

static int __init hello(void) 
{ 
	ktime_t start_time, stop_time, elapsed_time;
	start_time = ktime_get();
	unsigned int A[ARR_LEN_MY_MOD][ARR_LEN_MY_MOD],B[ARR_LEN_MY_MOD][ARR_LEN_MY_MOD],C[ARR_LEN_MY_MOD][ARR_LEN_MY_MOD];
	get_random_bytes(A,4*ARR_LEN_MY_MOD*ARR_LEN_MY_MOD);
	get_random_bytes(B,4*ARR_LEN_MY_MOD*ARR_LEN_MY_MOD);
	for(int i=0;i<ARR_LEN_MY_MOD;i++){
		for(int j=0;j<ARR_LEN_MY_MOD;j++){
			C[i][j]=0;
			for(int k=0;k<ARR_LEN_MY_MOD;k++){
				C[i][j]+=A[i][k]*B[k][j];
			}
		}
	}
	stop_time = ktime_get();
	elapsed_time= ktime_sub(stop_time, start_time);
	pr_info("elapsedTime : %lld\n",  ktime_to_ns(elapsed_time));
    return 0; 
} 

 

static void __exit hello_exit(void) 

{ 

    pr_info("Goodbye, world 2\n"); 

} 

 

module_init(hello); 

module_exit(hello_exit); 

 

MODULE_LICENSE("GPL");
