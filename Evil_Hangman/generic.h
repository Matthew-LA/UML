#ifndef GENERIC_H
#define GENERIC_H

#include "status.h"

typedef void* ITEM;
typedef void* GENERIC_VECTOR;

GENERIC_VECTOR generic_vector_init_default(void (*fpAssignment)(ITEM* pLeft, IT\
EM right), void (*fpDestroy)(ITEM* phItem));

int generic_vector_get_size(GENERIC_VECTOR hVector);
int generic_vector_get_capacity(GENERIC_VECTOR hVector);

Status generic_vector_push_back(GENERIC_VECTOR hVector, ITEM item);
Status generic_vector_pop_back(GENERIC_VECTOR hVector);

ITEM* generic_vector_at(GENERIC_VECTOR hVector, int index);

void generic_vector_destroy(GENERIC_VECTOR* phVector);

#endif



























-UU-:----F1  generic.h      All L1     (C/l Abbrev) ----------------------------
Beginning of buffer
