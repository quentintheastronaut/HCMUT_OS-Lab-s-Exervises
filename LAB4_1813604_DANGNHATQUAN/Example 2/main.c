#include <sys/types.h>
#include <unistd.h>

void *simple_malloc(size_t size){
    void *p;
    p = sbrk(0);
    if(sbrk(size) == (void*)-1)
        return NULL;
    return p;
}

int main(){
    size_t size = 1000;
    simple_malloc(size);
    return 0;
}
