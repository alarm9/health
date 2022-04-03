

//绘制UI界面
void tft_draw_frame()
{
	Gui_box(0, 1, 127, 128,RED)
	Gui_DrawLine(0, 30,128, 30,RED)
	Gui_DrawLine(0, 50,128, 50,RED)
	Gui_DrawLine(0, 70,128, 70,RED)
	Gui_DrawLine(60, 50,60, 70,RED)
	
}














//测试显示血液信息
void tft_test_display(void)
{
	uint8_t str[50];

	if (g_blooddata.display == 1)
	{
		g_blooddata.display = 0;
		
		//显示血氧信息
		sprintf((char *)str,"heart = %3d",g_blooddata.heart);
		Gui_DrawFont_GBK16(8,8,0x00FF,BLACK,str);
		
		//显示心率信息
		sprintf((char *)str,"SpO2 = %3.1f",g_blooddata.SpO2);
		Gui_DrawFont_GBK16(8,26,0x00FF,BLACK,str);
		
		//显示状态信息
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

//绘制边框
void tft_draw_frame(uint16_t color)
{
	gui_draw_square(0,1,127,127,color);
	gui_draw_square(0,1,127,18,color);
	gui_draw_square(0,1,100,18,color);
	gui_draw_square(0,57,127,127,color);
}

//状态信息显示
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

//绘制波形线段
void tft_draw_wave_line(uint8_t p,uint8_t n,uint16_t h0,uint16_t h1,uint16_t color)
{
	uint16_t x = 4;										// x 起始坐标
	uint16_t y = (p == 0) ? 122 : 89; // y 起始坐标
	
	//擦除线
	if((n + 1) < 82)
	{
		Gui_DrawLine((x + n + 2),y - 28,(x + n + 2),y + 1,GRAY2);
		Gui_DrawLine((x + n + 1),y - 28,(x + n + 1),y + 1,BLACK);
	}
	//绘制线
	Gui_DrawLine((x + n),(y - h0),(x + n + 1),(y - h1),color);
	
}

//绘制波形图表
void tft_draw_wave(void)
{
	static uint16_t hist_n  = 0;	//同步历史序号
	
	static uint16_t hbhist_h  = 0;//血红蛋白历史数值
	static uint16_t hbohist_h = 0;//氧合血红蛋白历史数值

	//绘制线
	tft_draw_wave_line(1, hist_n, hbhist_h , g_BloodWave.Hp, 0x8FF0);
	tft_draw_wave_line(0, hist_n, hbohist_h, g_BloodWave.HpO2, 0xFC1F);
	
	//移动下标
	hist_n = (hist_n < 81) ? (hist_n + 1) : 0;
	
	//保存历史
	hbhist_h = g_BloodWave.Hp;
	hbohist_h = g_BloodWave.HpO2;
}

//心率血氧数据刷新
void tft_draw_hrsp(void)
{
	uint8_t str[50];

	//心率信息显示
	sprintf((char *)str,"%3d  ",g_blooddata.heart);
	Gui_DrawFont_GBK16(40,20,0xffe0,GRAY3,str);
	//血氧饱和度显示
	g_blooddata.SpO2 = (g_blooddata.SpO2 > 99.99) ? 99.99:g_blooddata.SpO2;
	sprintf((char *)str," %2.2f%%  ",g_blooddata.SpO2);
	Gui_DrawFont_GBK16(40,38,0x07ff,GRAY3,str);
}


//显示窗口绘制
void tft_draw_windows(void)
{
	Lcd_Clear(GRAY3);
	
	//绘制窗口边线
	tft_draw_frame(GRAY1);

	
	//绘制区块 h31 w84
	gui_draw_Block(3,60,87,91,GRAY2,BLACK);
	gui_draw_Block(3,93,87,124,GRAY2,BLACK);
	
	gui_draw_Block(89,60,125,91,GRAY2,BLACK);
	gui_draw_Block(89,93,125,124,GRAY2,BLACK);
	
	//绘制字符串
	Gui_DrawFont_GBK16(3,20,0xffe0,GRAY3,"HR  :");
	Gui_DrawFont_GBK16(3,38,0x07ff,GRAY3,"SpO2:");
	
	Gui_DrawFont_GBK16(91,67,0x8FF0,BLACK," Hb");
	Gui_DrawFont_GBK16(91,100,0xFC1F,BLACK,"HbO2");
	
	Gui_DrawFont_GBK16(102,2,GREEN,BLACK,"FFT");
	
	Gui_DrawFont_GBK16(3,2,0x001F,GRAY3,"Normal    ");
}

//tft显示刷新
void tft_display_update(void)
{
	//图表更新
	if(g_blooddata.update >= 8)
	{
		//清除图标更新标志位
		g_blooddata.update = 0;
		//血液波形数据更新
		blood_wave_update();
		//绘制波形
		tft_draw_wave();
	}
	
	//转换后的数据更新
	if(g_blooddata.display >= 1)
	{
		//清除更新标志位
		g_blooddata.display = 0;
		//显示血液状态信息
		tft_draw_State(g_blooddata.state);
		//心率血氧数据刷新
		tft_draw_hrsp();
	}
}