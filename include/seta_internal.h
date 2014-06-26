/*
 *  seta_internal.h
 *  seta
 *
 *  Created by Fabio Pricoco on 22/10/2013.
 *  Copyright 2013 Erlang Solution Ltd. All rights reserved.
 *
 */

//! Context needed by seta for the data exchange between the scheduler and threads.
typedef struct {
	int level;
	int n_local_proc;
	bool is_last_thread;
	bool spawn_next_done;
	bool free_args_done;
	// info
	char *spawned;
	int args_size;
	void *arg_name_list;
	int allocated_ancients;
	int closure_id;
	void *allocated_ancient_list;
	void *spawn_list;
	void *args;
} seta_context_t;
