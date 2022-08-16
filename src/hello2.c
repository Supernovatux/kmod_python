#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/ktime.h>
#include <linux/module.h>
#include <linux/random.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("what-the-fuck-are-you-alone?!");
// MODULE_AUTHOR("Supernovatux")
MODULE_DESCRIPTION("learning");

#define MEM 1024
static int __init hello(void) {
    ktime_t start_time, stop_time, elapsed_time;
    int *A, *B, *C;

    /* Don't allocate more on the stack, use kmalloc with GFP_USER */
    A = kmalloc(MEM * MEM * sizeof(int), GFP_USER);
    B = kmalloc(MEM * MEM * sizeof(int), GFP_USER);
    C = kmalloc(MEM * MEM * sizeof(int), GFP_USER);

    get_random_bytes(A, 4 * MEM * MEM);
    get_random_bytes(B, 4 * MEM * MEM);

    start_time = ktime_get();

    int i;
    for (i = 0; i < MEM * MEM; i++) {
        C[i] += A[i] * B[i];
    }

    stop_time = ktime_get();
    elapsed_time = ktime_sub(stop_time, start_time);
    pr_info("elapsedTime : %lld\n", ktime_to_ns(elapsed_time));
    return 0;
}

static void __exit hello_exit(void) { pr_info("Goodbye, world 2\n"); }

module_init(hello);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
