//#include "hwjs.h"
//#include "sys.h"
//#include "time.h"
//#include "usart.h"
//#include "delay.h"
//u32 hw_jsm;	  //����һ��32λ���ݱ��������������
//u8  hw_jsbz;  //����һ��8λ���ݵı���������ָʾ���ձ�־


///*******************************************************************************
//* �� �� ��         : Hwjs_Init
//* ��������		   : ����˿ڳ�ʼ������	  ʱ�Ӷ˿ڼ��ⲿ�жϳ�ʼ�� 
//* ��    ��         : ��
//* ��    ��         : ��
//*******************************************************************************/
//void Hwjs_Init()
//{
//	GPIO_InitTypeDef GPIO_InitStructure;
//	EXTI_InitTypeDef EXTI_InitStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;

//	/* ����GPIOʱ�Ӽ��ܽŸ���ʱ�� */
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);

//	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;//�������
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
//	GPIO_Init(GPIOA,&GPIO_InitStructure);
//	
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource12); //ѡ��GPIO�ܽ������ⲿ�ж���·
//	EXTI_ClearITPendingBit(EXTI_Line12);
//	
//	/* �����ⲿ�жϵ�ģʽ */ 
//	EXTI_InitStructure.EXTI_Line=EXTI_Line12;
//	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
//	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising_Falling;
//	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
//	EXTI_Init(&EXTI_InitStructure); 

//	/* ����NVIC���� */
//	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;   //��ȫ���ж�
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 4; //��ռ���ȼ�Ϊ0
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; 	 //��Ӧ���ȼ�Ϊ1
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;   //ʹ��
//	NVIC_Init(&NVIC_InitStructure);

//}


///*******************************************************************************
//* �� �� ��         : HW_jssj
//* ��������		   : �ߵ�ƽ����ʱ�䣬����¼��ʱ�䱣����t�з��أ�����һ�δ�Լ20us 
//* ��    ��         : ��
//* ��    ��         : t
//*******************************************************************************/
//u8 HW_jssj()
//{
//	u8 t=0;
//	while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_12)==1)//�ߵ�ƽ
//	{
//		t++;
//		delay_us(20);
//		if(t>=250) return t;//��ʱ���
//	}
//	return t;
//}


//void EXTI15_10_IRQHandler(void)	  //����ң���ⲿ�ж�
//{

//	u8 Tim=0,Ok=0,Data,Num=0,nnn;

//   while( EXTI_GetITStatus(EXTI_Line12)==1)
//{		 
//		 
//	   	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_12)==0)
//		{
//			 Tim=HW_jssj();//��ô˴θߵ�ƽʱ��

//			 if(Tim>=250) break;//�������õ��ź�

//			 if(Tim>=200 && Tim<250)
//			 {
//			 	Ok=1;//�յ���ʼ�ź�
//			 }
//			 else if(Tim>=60 && Tim<90)
//			 {
//			 	Data=1;//�յ����� 1
//			 }
//			 else if(Tim>=10 && Tim<50)
//			 {
//			 	Data=0;//�յ����� 0
//			 }

//			 if(Ok==1)
//			 {
//			 	hw_jsm<<=1;
//				hw_jsm+=Data;

//				if(Num>=32)
//				{
//					hw_jsbz=1;
//					nnn=hw_jsbz;
//				  	break;
//				}
//			 }

//			 Num++;
//		}
//   }

//   EXTI_ClearITPendingBit(EXTI_Line12);	
//}


