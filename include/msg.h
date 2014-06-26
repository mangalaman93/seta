/*
 *  msg.h
 *  seta
 *
 *  Created by Fabio Pricoco on 11/10/2013.
 *  Updated by Aman Mangal on 26/6/2014
 *  Copyright 2013 Erlang Solutions Ltd. All rights reserved.
 *
 */

#include <string.h>
#include <stdarg.h>

typedef char *msg_t;

msg_t msg_new();
msg_t msg_new_from_str(char *);
msg_t msg_new_from_int(int);
void msg_destroy(msg_t);
void msg_cat(msg_t *, const char *, ...);
void msg_ncat(msg_t *, char *, int);
