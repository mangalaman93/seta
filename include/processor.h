//
//  processor.h
//  seta
//
//  Created by Fabio Pricoco on 19/10/13.
//  Copyright (c) 2013 Erlang Solution Ltd. All rights reserved.
//

#include <pthread.h>
#include "ready_queue.h"
#include "scheduler.h"

typedef struct {
	int id;
	ready_queue_t *rq;
	pthread_t thread;
	pthread_mutex_t rq_mutex;
	// info
	dequeue_t *stalled;
	pthread_mutex_t stalled_mutex;
	int cur_space;
	int total_space;
} processor_t;

processor_t * processor_create(int);
void processor_create_info(processor_t *);
void processor_destroy_info(processor_t *);
void processor_destroy(processor_t *);
void processor_start(processor_t *);
void processor_wait_4_me(processor_t *);
void processor_lock_ready_queue(processor_t *);
void processor_unlock_ready_queue(processor_t *);
void processor_lock_stalled(processor_t *);
void processor_unlock_stalled(processor_t *);
void processor_add_to_stalled(processor_t *, closure_t *);
void processor_remove_from_stalled(processor_t *, closure_t *);
void processor_computate_space(processor_t *);
