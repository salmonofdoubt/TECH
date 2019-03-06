/* SRE-U - C02 C Programming
 * Assignment exam
 *
 * Filter function for find
 * */

#ifndef FILTER_H
#define FILTER_H 1

typedef int (*predicate_t)(const void*);

void filter(void *base, size_t msize, size_t nmemb,
			void **out_data, size_t *out_nmemb, predicate_t p);

#endif
