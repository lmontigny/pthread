// Source: https://docs.oracle.com/cd/E19455-01/806-5257/sync-12/index.html

#include <pthread.h>

pthread_mutex_t count_mutex;
long long count;

void
increment_count()
{
	    pthread_mutex_lock(&count_mutex);
    count = count + 1;
	    pthread_mutex_unlock(&count_mutex);
}

long long
get_count()
{
    long long c;
    
    pthread_mutex_lock(&count_mutex);
	    c = count;
    pthread_mutex_unlock(&count_mutex);
	    return (c);
}
