#include "mbx.h"
#include "msgsl.h"
#include <unistd.h>

#include <stdio.h>

int main() {

    msg_sl *msg_sl_obj = malloc(sizeof(msg_sl));
    init_msg_sl(msg_sl_obj, 16, 2);

    insert_msg_sl(msg_sl_obj, 1, getuid());
    insert_msg_sl(msg_sl_obj, 2, getuid());
    insert_msg_sl(msg_sl_obj, 3, getuid());

    msg_sl_node *found = search_msg_sl(msg_sl_obj, 1);

    if (found != NULL) {

        printf("%d found\n", found->uid);
        enqueue_msg_q(found->msg_queue, "success");

    }

    dump_msg_sl(msg_sl_obj);

    destroy_msg_sl(msg_sl_obj);

//    for (unsigned int i = 0; i < 5; i++) {
//
//        insert_msg_sl(msg_sl_obj, i + 1, getuid(), msg_q_obj);
//
//        char *test_buf = malloc(sizeof(char));
//        sprintf(test_buf, "%d", i + 10);
//        enqueue_msg_q(msg_q_obj, test_buf);
//        enqueue_msg_q(msg_q_obj, "test");
//        char *test_buf1 = malloc(sizeof(char));
//        sprintf(test_buf1, "%d", i * 20);
//        enqueue_msg_q(msg_q_obj, test_buf1);
//
//    }
//



//    printf("init: %ld\n", slmbx_init(16, 2));
//    printf("destroy: %ld\n", slmbx_shutdown());

    return 0;

}
