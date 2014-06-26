/*
 *  graph_dot.h
 *  seta
 *
 *  Created by Fabio Pricoco on 22/10/2013.
 *  Copyright 2013 Erlang Solution Ltd. All rights reserved.
 *
 */

#include <stdio.h>
#include "logger.h"
#include "closure.h"
#include "seta_internal.h"

void graph_start(char *);
void graph_finish();
void graph_set_color(int, int);
void graph_spawn_next(int, int);
void graph_spawns(int, spawn_list_t *);
void graph_send_argument(closure_t *, seta_context_t *);
void graph_enable(int, char *);
void graph_color_S1_element(void *, int);
