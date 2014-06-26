//
//  ready_queue.h
//  seta
//
//  Created by Fabio Pricoco on 19/10/13.
//  Updated by Aman Mangal on 26/6/2014
//  Copyright (c) 2013 Erlang Solution Ltd. All rights reserved.
//

#include <stdio.h>
#include "graph_dot.h"

typedef dequeue_t ready_queue_t;

ready_queue_t * ready_queue_create();
void ready_queue_destroy(dequeue_t *rq);
closure_t * ready_queue_extract_head_from_deepest_level(ready_queue_t *);
closure_t * ready_queue_extract_tail_from_shallowest_level(ready_queue_t *);
void ready_queue_post_closure_to_level(ready_queue_t *, closure_t *, int);
int ready_queue_space(ready_queue_t *);
