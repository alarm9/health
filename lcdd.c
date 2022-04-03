

//����UI����
void tft_draw_frame()
{
	Gui_box(0, 1, 127, 128,RED)
	Gui_DrawLine(0, 30,128, 30,RED)
	Gui_DrawLine(0, 50,128, 50,RED)
	Gui_DrawLine(0, 70,128, 70,RED)
	Gui_DrawLine(60, 50,60, 70,RED)
	
}














//������ʾѪҺ��Ϣ
void tft_test_display(void)
{
	uint8_t str[50];

	if (g_blooddata.display == 1)
	{
		g_blooddata.display = 0;
		
		//��ʾѪ����Ϣ
		sprintf((char *)str,"heart = %3d",g_blooddata.heart);
		Gui_DrawFont_GBK16(8,8,0x00FF,BLACK,str);
		
		//��ʾ������Ϣ
		sprintf((char *)str,"SpO2 = %3.1f",g_blooddata.SpO2);
		Gui_DrawFont_GBK16(8,26,0x00FF,BLACK,str);
		
		//��ʾ״̬��Ϣ
		if(g_blooddata.state)
		{
			sprintf((char *)str,"ERROR     ");
			Gui_DrawFont_GBK16(8,44,0xF000,BLACK,str);
		}
		else
		{
			sprintf((char *)str,"NORMAL    ");
			Gui_DrawFont_GBK16(8,44,0x07E0,BLACK,str);
		}
	}
}

//���Ʊ߿�
void tft_draw_frame(uint16_t color)
{
	gui_draw_square(0,1,127,127,color);
	gui_draw_square(0,1,127,18,color);
	gui_draw_square(0,1,100,18,color);
	gui_draw_square(0,57,127,127,color);
}

//״̬��Ϣ��ʾ
void tft_draw_State(uint8_t st)
{
	switch(st)
	{
		case BLD_NORMAL:
		{
			tft_draw_frame(GRAY1);
			Gui_DrawFont_GBK16(3,2,0x001F,GRAY3,"Normal    ");
			break;
		}
		case BLD_ERROR:
		{
			tft_draw_frame(RED);
			Gui_DrawFont_GBK16(3,2,0xF000,GRAY3,"Caution   ");
			break;
		}
	}
}

//���Ʋ����߶�
void tft_draw_wave_line(uint8_t p,uint8_t n,uint16_t h0,uint16_t h1,uint16_t color)
{
	uint16_t x = 4;										// x ��ʼ����
	uint16_t y = (p == 0) ? 122 : 89; // y ��ʼ����
	
	//������
	if((n + 1) < 82)
	{
		Gui_DrawLine((x + n + 2),y - 28,(x + n + 2),y + 1,GRAY2);
		Gui_DrawLine((x + n + 1),y - 28,(x + n + 1),y + 1,BLACK);
	}
	//������
	Gui_DrawLine((x + n),(y - h0),(x + n + 1),(y - h1),color);
	
}

//���Ʋ���ͼ��
void tft_draw_wave(void)
{
	static uint16_t hist_n  = 0;	//ͬ����ʷ���
	
	static uint16_t hbhist_h  = 0;//Ѫ�쵰����ʷ��ֵ
	static uint16_t hbohist_h = 0;//����Ѫ�쵰����ʷ��ֵ

	//������
	tft_draw_wave_line(1, hist_n, hbhist_h , g_BloodWave.Hp, 0x8FF0);
	tft_draw_wave_line(0, hist_n, hbohist_h, g_BloodWave.HpO2, 0xFC1F);
	
	//�ƶ��±�
	hist_n = (hist_n < 81) ? (hist_n + 1) : 0;
	
	//������ʷ
	hbhist_h = g_BloodWave.Hp;
	hbohist_h = g_BloodWave.HpO2;
}

//����Ѫ������ˢ��
void tft_draw_hrsp(void)
{
	uint8_t str[50];

	//������Ϣ��ʾ
	sprintf((char *)str,"%3d  ",g_blooddata.heart);
	Gui_DrawFont_GBK16(40,20,0xffe0,GRAY3,str);
	//Ѫ�����Ͷ���ʾ
	g_blooddata.SpO2 = (g_blooddata.SpO2 > 99.99) ? 99.99:g_blooddata.SpO2;
	sprintf((char *)str," %2.2f%%  ",g_blooddata.SpO2);
	Gui_DrawFont_GBK16(40,38,0x07ff,GRAY3,str);
}


//��ʾ���ڻ���
void tft_draw_windows(void)
{
	Lcd_Clear(GRAY3);
	
	//���ƴ��ڱ���
	tft_draw_frame(GRAY1);

	
	//�������� h31 w84
	gui_draw_Block(3,60,87,91,GRAY2,BLACK);
	gui_draw_Block(3,93,87,124,GRAY2,BLACK);
	
	gui_draw_Block(89,60,125,91,GRAY2,BLACK);
	gui_draw_Block(89,93,125,124,GRAY2,BLACK);
	
	//�����ַ���
	Gui_DrawFont_GBK16(3,20,0xffe0,GRAY3,"HR  :");
	Gui_DrawFont_GBK16(3,38,0x07ff,GRAY3,"SpO2:");
	
	Gui_DrawFont_GBK16(91,67,0x8FF0,BLACK," Hb");
	Gui_DrawFont_GBK16(91,100,0xFC1F,BLACK,"HbO2");
	
	Gui_DrawFont_GBK16(102,2,GREEN,BLACK,"FFT");
	
	Gui_DrawFont_GBK16(3,2,0x001F,GRAY3,"Normal    ");
}

//tft��ʾˢ��
void tft_display_update(void)
{
	//ͼ�����
	if(g_blooddata.update >= 8)
	{
		//���ͼ����±�־λ
		g_blooddata.update = 0;
		//ѪҺ�������ݸ���
		blood_wave_update();
		//���Ʋ���
		tft_draw_wave();
	}
	
	//ת��������ݸ���
	if(g_blooddata.display >= 1)
	{
		//������±�־λ
		g_blooddata.display = 0;
		//��ʾѪҺ״̬��Ϣ
		tft_draw_State(g_blooddata.state);
		//����Ѫ������ˢ��
		tft_draw_hrsp();
	}
}