#include "rtthread.h"
#include "main.h"
#include "stdio.h"
 
struct rt_thread led1_thread;
rt_uint8_t rt_led1_thread_stack[128];
void led1_task_entry(void *parameter);
 
//初始化线程函数
void MX_RT_Thread_Init(void)
{
	//初始化LED1线程
	rt_thread_init(&led1_thread,"led1",led1_task_entry,RT_NULL,&rt_led1_thread_stack[0],sizeof(rt_led1_thread_stack),3,20);
	//开启线程调度
	rt_thread_startup(&led1_thread);
}
 
//主任务
void MX_RT_Thread_Process(void)
{
	printf("Hello RT_Thread!!!");
	rt_thread_delay(2000);
}
 
//LED1任务
void led1_task_entry(void *parameter)
{
	while(1)
	{
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3, GPIO_PIN_RESET);
		rt_thread_delay(500);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3, GPIO_PIN_SET);
		rt_thread_delay(500);
	}
}
