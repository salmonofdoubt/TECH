// Filter and function pointers
//

#include <stdlib.h>
#include <string.h>

#include "filter.h"

void filter(void *base, size_t msize, size_t nmemb,
			void **out_data, size_t *out_nmemb, predicate_t p){

	size_t i;

	*out_data = (void *) malloc(msize*nmemb);
	*out_nmemb = 0;

	for(i=0; i<nmemb; i++){
		if (p(base+i*msize)){
			memcpy(*out_data + *out_nmemb*msize, 
					base+i*msize,			
					msize);
			*out_nmemb = *out_nmemb + 1;
		}

	}
}
