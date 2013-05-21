#ifndef __SSTABLE_HASHTABLE_H_
#define __SSTABLE_HASHTABLE_H_

#include "buffer.h"
#include "common.h"
#include <stdio.h>

typedef struct hashtable
{
	int id;
	int bucket_szie;
	data_t** buckets;
	int key_num;

	data_t* bigest_key;		//the biggest data
	data_t* smallest_key;	//the smallest data

	int max;				//limit data max number

	char filename[128];		//file name
	FILE *file;				//file handle
	buffer_t* buf;			//buffer use to serialize
}hashtable_t;

void* hashtable_new(int id);
void hashtable_open(hashtable_t* htable);
void hashtable_free(hashtable_t* htable);
void hashtable_build(hashtable_t* htable);
void hashtable_flush(hashtable_t* htable);
int hashtable_put(hashtable_t* htable,data_t* data);
data_t* hashtable_get(hashtable_t* htable,const char* key);
int hashtable_del(hashtable_t* htable,const char* key);

int hashtable_compactput(hashtable_t* htable,data_t* data);
void hashtable_relasedata(hashtable_t* htable);
void hashtable_writehead(hashtable_t* htable);
void hashtable_writedata(hashtable_t* htable);

#endif