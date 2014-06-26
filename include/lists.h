//
//  lists.h
//  seta
//
//  Created by Fabio Pricoco on 19/10/13.
//  Updated by Aman Mangal 26/6/2014
//  Copyright (c) 2013 Erlang Solution Ltd. All rights reserved.
//

#include <string.h>
#include <stdarg.h>
#include "dequeue.h"
#include "msg.h"

typedef struct {
	int id;
	char *label;
} spawn_element_t;

typedef dequeue_t spawn_list_t;
typedef dequeue_t msg_list_t;

spawn_list_t * spawn_list_create();
void spawn_list_append(spawn_list_t *, int, char *);
void spawn_list_destroy(spawn_list_t *);

msg_list_t * msg_list_create();
void msg_list_append(msg_list_t *, char *);
void msg_list_append_reverse(msg_list_t *, char *);
void msg_list_append_int(msg_list_t *, int);
void msg_list_append_int_reverse(msg_list_t *, int);
void msg_list_set(msg_list_t *, int, char *);
void msg_list_str(msg_t *, msg_list_t *);
msg_list_t * msg_list_copy(msg_list_t *);
void msg_list_foreach(void *, msg_list_t *);
void msg_list_destroy(msg_list_t *);
void msg_list_print(msg_list_t *);
