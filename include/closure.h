//
//  closure.h
//  seta
//
//  Created by Fabio Pricoco on 19/10/13.
//  Updated by Aman Mangal on 26/6/2013
//  Copyright (c) 2013 Erlang Solution Ltd. All rights reserved.
//

#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include "lists.h"

typedef struct {
	int level;
	int join_counter;
	void *fun;
	void *args;
	bool is_first_thread;
	bool is_last_thread;
	pthread_mutex_t mutex;
	int proc;
	// info
	char *name;
	int args_size;
	msg_list_t *arg_name_list;
	int allocated_ancients;
	msg_list_t *allocated_ancient_list;
	int id;
} closure_t;

closure_t * closure_create();
closure_t * closure_create_info(closure_t *);
closure_t * closure_create_graph(closure_t *, char *);
void closure_destroy_graph(closure_t *);
void closure_destroy_info(closure_t *);
void closure_destroy(closure_t *);
void closure_set_fun(closure_t *, void *);
void closure_set_args(closure_t *, void *);
void closure_lock(closure_t *);
void closure_unlock(closure_t *);
int closure_space(closure_t *);
void closure_space_cb(void *, void *, int);
void closure_str(char **, closure_t *);
