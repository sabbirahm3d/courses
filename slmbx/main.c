//#include "util.h"
//#include "rand.h"
#include "msgsl.h"

#include <stdio.h>


int main() {

    msg_sl *msg_sl_obj = malloc(sizeof(msg_sl));
    init_msg_sl(msg_sl_obj);

    for (int i = 0; i < 5; i++) {

        msg_q *msg_q_obj = malloc(sizeof(msg_q));
        init_msg_q(msg_q_obj);
        insert_msg_sl(msg_sl_obj, i + 1, msg_q_obj);

        char *test_buf = malloc(sizeof(char));
        sprintf(test_buf, "%d", i + 10);
        enqueue_msg_q(msg_q_obj, test_buf);
        enqueue_msg_q(msg_q_obj, "test");
        char *test_buf1 = malloc(sizeof(char));
        sprintf(test_buf1, "%d", i * 20);
        enqueue_msg_q(msg_q_obj, test_buf1);

    }


    dump_msg_sl(msg_sl_obj);

    destroy_msg_sl(msg_sl_obj);

    return 0;

}
