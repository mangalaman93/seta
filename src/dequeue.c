/*
 *  dequeue.c
 *  stealing-work scheduler
 *
 *  Created by Fabio Pricoco on 09/09/2013.
 *  Updated by Aman Mangal on 27/6/2014
 *  Copyright 2013 Erlang Solutions Ltd. All rights reserved.
 *
 */

#include "dequeue.h"

dequeue_t * dequeue_create() {
	dequeue_t * l = (dequeue_t *)malloc(sizeof(dequeue_t));
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
	return l;
}

dequeue_t * dequeue_copy(void *fun, dequeue_t *d) {
	dequeue_t *copy = dequeue_create();

	void * (*callback)(void *) = fun;
    element_t *ele = d->head;

    while(ele != NULL) {
		dequeue_add_tail(copy, callback(ele->val));
        ele = ele->next;
    }
	return copy;
}

void dequeue_destroy(dequeue_t *l) {
	element_t *ele = l->head;
	element_t *aux = NULL;
    while(ele != NULL) {
		aux = ele;
        ele = ele->next;
		free(aux);
    }
	free(l);
}

void dequeue_foreach(void *fun, dequeue_t *d)
{
	void (*callback)(void *, int) = fun;
    element_t *ele = d->head;

	int i = 0;
    while(ele != NULL) {
		callback(ele->val, i++);
        ele = ele->next;
    }
}

void dequeue_fold(void *fun, void *acc, dequeue_t *d) {
	void (*callback)(void *, void *, int) = fun;
	element_t *ele = d->head;
	int i = 0;
    while(ele != NULL) {
		callback(ele->val, acc, i++);
        ele = ele->next;
    }
}

bool dequeue_is_not_empty(dequeue_t *d) {
	return d->head != NULL;
}
int dequeue_add_head(dequeue_t *l, void *val) {
	element_t *element = (element_t *)malloc(sizeof(element_t));
	element->val = val;
	element->next = l->head;
	l->head = element;
	if (l->tail == NULL) {
		l->tail = element;
	}
	l->size++;
	return 0;
}

int dequeue_add_tail(dequeue_t *l, void *val) {
	element_t *element = (element_t *)malloc(sizeof(element_t));
	element->val = val;
	element->next = NULL;
	if (l->head == NULL) {
		l->head = element;
		l->tail = element;
	}
	else {
		l->tail->next = element;
		l->tail = element;
	}
	l->size++;
	return 0;
}

void * dequeue_extract_head(dequeue_t *l) {
	void *res;
	element_t *aux;

	if (l->head == NULL) {
		return NULL;
	}
	else {
		res = l->head->val;
		if (l->head == l->tail) {
			free(l->head);
			l->head = NULL;
			l->tail = NULL;
			l->size = 0;
		}
		else {
			aux = l->head;
			l->head = l->head->next;
			free(aux);
			l->size--;
		}
		return res;
	}
}

void * dequeue_extract_tail(dequeue_t *l) {
	element_t *prev = l->head;
	element_t *aux = l->head;
	void *res;

	if (l->head == NULL) {
		return NULL;
	}
	else {
		res = l->tail->val;
		if (l->head == l->tail) {
			free(l->head);
			l->head = NULL;
			l->tail = NULL;
			l->size = 0;
		}
		else {
			aux = aux->next;
			while (aux->next != NULL) {
				prev = aux;
				aux = aux->next;
			}
			prev->next = NULL;
			free(aux);
			l->tail = prev;
			l->size--;
		}
		return res;
	}
}

int dequeue_remove_element_by_value(dequeue_t *l, void *e) {
	element_t *prev = l->head;
	element_t *aux = l->head;

	if (l->head == NULL) {
		return -1;
	}
	else {
		if (l->head == l->tail && l->head->val == e) {
			free(l->head);
			l->head = NULL;
			l->tail = NULL;
			l->size = 0;
			return 0;
		}
		else {
			if (l->head->val == e) {
				l->head = l->head->next;
				free(aux);
				l->size--;
				return 0;
			}

			aux = aux->next;
			while (aux !=NULL && aux->val != e) {
				prev = aux;
				aux = aux->next;
			}
			if(aux == NULL)
				return -1;
			else if (aux->val == e) {
				if (l->tail == aux) {
					l->tail = prev;
				}
				prev->next = aux->next;
				free(aux);
				l->size--;
				return 0;
			}
			else {
				return -1;
			}
		}
	}
	return -1;
}

void * dequeue_get_element(dequeue_t l, int n) {
	if (n < 0 || n > l.size || l.head == NULL) {
		return NULL;
	}
	else {
		element_t *aux = l.head;
		for (int i=0; i<n; i++) {
			if (aux->next == NULL) {
				return NULL;
			}
			aux = aux->next;
		}
		return aux->val;
	}
}

int dequeue_set_element(dequeue_t *d, int n, void *new_val) {
	if (d->head == NULL) {
		return -1;
	}
	else {
		element_t *aux = d->head;
		for (int i=0; i<n; i++) {
			if (aux->next == NULL) {
				return -1;
			}
			aux = aux->next;
		}
		aux->val = new_val;
		return 0;
	}
}

void * dequeue_get_last(dequeue_t l) {
	if (l.head == NULL) {
		return NULL;
	}
	else {
		return l.tail->val;
	}
}

int dequeue_size(dequeue_t l) {
	return l.size;
}


void * dequeue_get_first_matching_fun(void *fun, dequeue_t *d) {
	bool (*callback)(void *) = fun;
	element_t *ele = d->head;
	while (ele != NULL) {
		if (callback(ele->val)) {
			return ele->val;
		}
		ele = ele->next;
	}
	return NULL;
}

void * dequeue_get_last_matching_fun(void *fun, dequeue_t *d) {
	bool (*callback)(void *) = fun;
	element_t *ele = d->head;
	void *found = NULL;
	while (ele != NULL) {
		if (callback(ele->val)) {
			found = ele->val;
		}
		ele = ele->next;
	}
	return found;
}


dequeue_iterator_t dequeue_get_iterator(dequeue_t *dequeue) {
	dequeue_iterator_t iterator;
	iterator.cur_element = dequeue->head;
	return iterator;
}

bool dequeue_iterator_has_more(dequeue_iterator_t *iterator) {
	return iterator->cur_element != NULL;
}

void * dequeue_iterator_get_next(dequeue_iterator_t *iterator) {
	element_t *current_element = (element_t *)iterator->cur_element;
	iterator->cur_element = current_element->next;
	return current_element->val;
}
