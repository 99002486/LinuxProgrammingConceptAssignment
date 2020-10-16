#include<stdio.h>
#include<pthread.h>
void* sum_body(void* sub_array)
{
    int* arraypart = (int*)sub_array;
    int sub_sum=0;
    for(int i=0;i<100;i++)
    {
        sub_sum+=arraypart[i];;
    }
    pthread_exit((void*)sub_sum);

}
int main()
{
    static int array[1000];
    static int sum=0;
    void* sub_sum=NULL;
    for(int i=0;i<1000;i++)
    {
        array[i]=i;
    }
    pthread_t threads[10];
    for(int i=0;i<10;i++)
    {
        int* sub_array=array + (i*100);
        pthread_create(&threads[i],NULL,sum_body,(void*) sub_array);
    }
    for(int i=0;i<10;i++)
    {
        pthread_join(threads[i],&sub_sum);
        sum+=(int)sub_sum;
    }
    printf("total = %d\n",sum);
    return 0;
}