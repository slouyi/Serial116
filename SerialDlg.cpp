// SerialDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Serial.h"
#include "SerialDlg.h"
#include ".\serialdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//




// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CSerialDlg 对话框



CSerialDlg::CSerialDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSerialDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSerialDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSerialDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_CHECKCUT, OnBnClickedCheckcut)
	ON_BN_CLICKED(IDC_BUTTONRUN, OnBnClickedButtonrun)
	ON_BN_CLICKED(IDC_BUTTONTEST, OnBnClickedButtontest)
	ON_BN_CLICKED(IDC_BUTTONFULLCUT, OnBnClickedButtonfullcut)
	ON_BN_CLICKED(IDC_BUTTONPARCUT, OnBnClickedButtonparcut)
	ON_BN_CLICKED(IDC_BUTTONCON, OnBnClickedButtoncon)
	ON_BN_CLICKED(IDC_BUTTONFILE, OnBnClickedButtonfile)
	ON_BN_CLICKED(IDC_BUTTONMONEY, OnBnClickedButtonmoney)
	ON_BN_CLICKED(IDC_BUTTONRERUN, OnBnClickedButtonrerun)
	ON_BN_CLICKED(IDC_BUTTONBARCODE, OnBnClickedButtonbarcode)
	ON_BN_CLICKED(IDC_BUTTONDIGFONT, OnBnClickedButtondigfont)
	ON_BN_CLICKED(IDC_BUTTONDOWNLOADBIT, OnBnClickedButtondownloadbit)
	ON_BN_CLICKED(IDC_BUTTONLOGO, OnBnClickedButtonlogo)
	ON_BN_CLICKED(IDC_BUTTONSTATUS, OnBnClickedButtonstatus)
	ON_BN_CLICKED(IDC_BUTTONDRIVER, OnBnClickedButtondriver)
	ON_BN_CLICKED(IDC_BUTTONBITMAP, OnBnClickedButtonbitmap)
	ON_BN_CLICKED(IDC_BUTTONBLACKMARK, OnBnClickedButtonblackmark)
	ON_BN_CLICKED(IDC_BUTTONOTHERCUT, OnBnClickedButtonothercut)
	ON_BN_CLICKED(IDC_BUTTONLEFT, OnBnClickedButtonleft)
	ON_BN_CLICKED(IDC_BUTTONRERVER, OnBnClickedButtonrerver)
END_MESSAGE_MAP()


// CSerialDlg 消息处理程序

BOOL CSerialDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将\“关于...\”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	//选中自动切刀
	((CButton*)GetDlgItem(IDC_CHECKCUT))->SetCheck(TRUE);
	bCHECKCUT=TRUE;

	//设置串口属性
	GetDlgItem(IDC_COMBOPORT)->SetWindowText("lpt1");
	GetDlgItem(IDC_COMBOBARD)->SetWindowText("9600");
	GetDlgItem(IDC_COMBOJY)->SetWindowText("N");
	GetDlgItem(IDC_COMBOLENGTH)->SetWindowText("8");
	GetDlgItem(IDC_COMBOEND)->SetWindowText("1");

	//设置模式
	GetDlgItem(IDC_COMBOMODE)->SetWindowText("ESC/POS模式");

	//设置张数
	GetDlgItem(IDC_EDITNUM)->SetWindowText("10");

	//设置间隔时间
	GetDlgItem(IDC_EDITMINU)->SetWindowText("0");

	//设置连续打印驱动方式
	((CButton*)GetDlgItem(IDC_RADIODIRECT))->SetCheck(TRUE);
	
	//((CButton*)GetDlgItem(IDC_RADIODIRECT))->Get
	return TRUE;  // 除非设置了控件的焦点，否则返回 TRUE
}

void CSerialDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSerialDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
HCURSOR CSerialDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CSerialDlg::OnBnClickedCheckcut()
{
	// TODO: Add your control notification handler code here
	if(!bCHECKCUT)		//如果点击选上
	{
		((CButton*)GetDlgItem(IDC_CHECKCUT))->SetCheck(TRUE);
		bCHECKCUT=TRUE;

		//这里加上相关的激活代码
		//AfxMessageBox("激活啦");
	}
	else
	{
		((CButton*)GetDlgItem(IDC_CHECKCUT))->SetCheck(FALSE);
		bCHECKCUT=FALSE;
		//AfxMessageBox("不激活啦");
	}
}


// 打印串口
void CSerialDlg::OpenCom(void)
{	
	COMMTIMEOUTS cto;
	DWORD dwError;
	char temp[256];
	char jy[10];


	memset(temp,0,256);

	GetDlgItemText(IDC_COMBOPORT,csCom);

	hCom=CreateFile(csCom,GENERIC_READ|GENERIC_WRITE,0,0,OPEN_EXISTING,0,0);
	if(hCom==INVALID_HANDLE_VALUE)
	{
		dwError=GetLastError();
		AfxMessageBox("can't open com,please check!"); 
		return;
	}
	//超时设置	
	/*if(!GetCommTimeouts(hCom,&cto))
	{
	AfxMessageBox("获取超时设置时出错，无法初始化串口!"); 
	return;
	}*/
	GetCommTimeouts(hCom,&cto);

	cto.ReadIntervalTimeout=0;
	cto.ReadTotalTimeoutConstant=20;
	cto.ReadTotalTimeoutMultiplier=20;
	cto.WriteTotalTimeoutConstant=0;
	cto.WriteTotalTimeoutMultiplier=0;
	/*if(!SetCommTimeouts(hCom,&cto))
	{
	AfxMessageBox("设置超时设置时出错，无法初始化串口!"); 
	return;
	}*/

	SetCommTimeouts(hCom,&cto);


	//SetCommMask(hCom,EV_RXCHAR|EV_RXFLAG);

	FillMemory(&dcb,sizeof(dcb),0);
	dcb.DCBlength=sizeof(dcb);


	/*if(!GetCommState(hCom,&dcb))
	{
	AfxMessageBox("无法取得DCB，无法初始化串口!"); 
	return;
	}*/
	GetCommState(hCom,&dcb);


	dcb.fDtrControl=DTR_CONTROL_ENABLE;

	GetDlgItemText(IDC_COMBOJY,jy,5);
	char jy2=jy[0];

	sprintf(temp,"baud=%d parity=%c data=%d stop=%d",GetDlgItemInt(IDC_COMBOBARD,NULL,NULL),jy[0],GetDlgItemInt(IDC_COMBOLENGTH,NULL,NULL),GetDlgItemInt(IDC_COMBOEND,NULL,NULL));

	//
	if(!BuildCommDCB(temp, &dcb))
	{
		AfxMessageBox("无法设置串口属性/build，无法初始化串口!"); 
		return;
	}

	/*DWORD dwtemp=GetDlgItemInt(IDC_COMBOBARD,NULL,NULL);
	switch(dwtemp)
	{
	case 9600:
	dcb.BaudRate=CBR_9600;
	break;

	case 19200:
	dcb.BaudRate=CBR_19200;
	break;

	case 38400:
	dcb.BaudRate=CBR_38400;
	break;

	default:
	dcb.BaudRate=CBR_9600;
	GetDlgItem(IDC_COMBOBARD)->SetWindowText("9600");
	break;
	}        	
	dcb.fBinary=1;
	dcb.Parity=NOPARITY;
	dcb.ByteSize=8;
	dcb.StopBits=1;
	dcb.fDtrControl=DTR_CONTROL_ENABLE;
	dcb.wReserved1=0;*/

	/*if(!SetCommState(hCom,&dcb))
	{
	AfxMessageBox("无法设置串口属性/setcommstate，无法初始化串口!"); 
	return;
	}*/
	SetCommState(hCom,&dcb);


	/*if(!PurgeComm(hCom,PURGE_TXABORT|PURGE_RXABORT|PURGE_TXCLEAR|PURGE_RXCLEAR))
	{
	AfxMessageBox("puregecomm出错，无法初始化串口!"); 
	return;
	}*/
	PurgeComm(hCom,PURGE_TXABORT|PURGE_RXABORT|PURGE_TXCLEAR|PURGE_RXCLEAR);




}

void CSerialDlg::DisabelAll(void)
{
	//设置灰色
	GetDlgItem(IDC_BUTTONRUN)->EnableWindow(FALSE);		     //走纸
	GetDlgItem(IDC_BUTTONTEST)->EnableWindow(FALSE);	     //单张测试
	GetDlgItem(IDC_BUTTONFULLCUT)->EnableWindow(FALSE);	     //全切
	GetDlgItem(IDC_BUTTONPARCUT)->EnableWindow(FALSE);       //半切
	GetDlgItem(IDC_BUTTONCON)->EnableWindow(FALSE);		     //开始连续打印
	GetDlgItem(IDC_BUTTONFILE)->EnableWindow(FALSE);	     //文件打印
	GetDlgItem(IDC_BUTTONRERUN)->EnableWindow(FALSE);        //反向走纸
	GetDlgItem(IDC_BUTTONMONEY)->EnableWindow(FALSE);	     //弹钱箱
	GetDlgItem(IDC_BUTTONBARCODE)->EnableWindow(FALSE);	   	 //条码打印
	GetDlgItem(IDC_BUTTONDIGFONT)->EnableWindow(FALSE);		 //多倍字体
	GetDlgItem(IDC_BUTTONDOWNLOADBIT)->EnableWindow(FALSE);  //下载位图
	GetDlgItem(IDC_BUTTONLOGO)->EnableWindow(FALSE);		 //打印LOGO
	GetDlgItem(IDC_BUTTONSTATUS)->EnableWindow(FALSE);       //打印机状态
	GetDlgItem(IDC_BUTTONDRIVER)->EnableWindow(FALSE);		 //驱动打印
	GetDlgItem(IDC_BUTTONBITMAP)->EnableWindow(FALSE);       //图型打印
	GetDlgItem(IDC_BUTTONBLACKMARK)->EnableWindow(FALSE);     //黑标检测
	GetDlgItem(IDC_BUTTONOTHERCUT)->EnableWindow(FALSE);      //其它切刀
	GetDlgItem(IDC_BUTTONLEFT)->EnableWindow(FALSE);         //字体居中
	GetDlgItem(IDC_BUTTONRERVER)->EnableWindow(FALSE);       //字体旋转


	
	GetDlgItem(IDC_EDITNUM)->EnableWindow(FALSE);//张数
	GetDlgItem(IDC_EDITMINU)->EnableWindow(FALSE);//分钟
	GetDlgItem(IDC_RADIODIRECT)->EnableWindow(FALSE);//直接端口
	GetDlgItem(IDC_RADIODRV)->EnableWindow(FALSE);//驱动打印
	GetDlgItem(IDC_CHECKFONT)->EnableWindow(FALSE);//字体
	GetDlgItem(IDC_CHECKCUT)->EnableWindow(FALSE);//切刀
	GetDlgItem(IDC_CHECKLOGO)->EnableWindow(FALSE);//图片

}

void CSerialDlg::EnableAll(void)
{
	//设置激活
	GetDlgItem(IDC_BUTTONRUN)->EnableWindow(TRUE);		     //走纸
	GetDlgItem(IDC_BUTTONTEST)->EnableWindow(TRUE);	         //单张测试
	GetDlgItem(IDC_BUTTONFULLCUT)->EnableWindow(TRUE);	     //全切
	GetDlgItem(IDC_BUTTONPARCUT)->EnableWindow(TRUE);        //半切
	GetDlgItem(IDC_BUTTONCON)->EnableWindow(TRUE);		     //开始连续打印
	GetDlgItem(IDC_BUTTONFILE)->EnableWindow(TRUE);	         //文件打印
	GetDlgItem(IDC_BUTTONRERUN)->EnableWindow(TRUE);         //反向走纸
	GetDlgItem(IDC_BUTTONMONEY)->EnableWindow(TRUE);	     //弹钱箱
	GetDlgItem(IDC_BUTTONBARCODE)->EnableWindow(TRUE);	   	 //条码打印
	GetDlgItem(IDC_BUTTONDIGFONT)->EnableWindow(TRUE);		 //多倍字体
	GetDlgItem(IDC_BUTTONDOWNLOADBIT)->EnableWindow(TRUE);   //下载位图
	GetDlgItem(IDC_BUTTONLOGO)->EnableWindow(TRUE);		     //打印LOGO
	GetDlgItem(IDC_BUTTONSTATUS)->EnableWindow(TRUE);        //打印机状态
	GetDlgItem(IDC_BUTTONDRIVER)->EnableWindow(TRUE);		 //驱动打印
	GetDlgItem(IDC_BUTTONBITMAP)->EnableWindow(TRUE);       //图型打印
	GetDlgItem(IDC_BUTTONBLACKMARK)->EnableWindow(TRUE);       //黑标检测
	GetDlgItem(IDC_BUTTONOTHERCUT)->EnableWindow(TRUE);      //其它切刀
	GetDlgItem(IDC_BUTTONLEFT)->EnableWindow(TRUE);         //字体居中
	GetDlgItem(IDC_BUTTONRERVER)->EnableWindow(TRUE);       //字体旋转


	GetDlgItem(IDC_EDITNUM)->EnableWindow(TRUE);//张数
	GetDlgItem(IDC_EDITMINU)->EnableWindow(TRUE);//分钟
	GetDlgItem(IDC_RADIODIRECT)->EnableWindow(TRUE);//直接端口
	GetDlgItem(IDC_RADIODRV)->EnableWindow(TRUE);//驱动打印
	GetDlgItem(IDC_CHECKFONT)->EnableWindow(TRUE);//字体
	GetDlgItem(IDC_CHECKCUT)->EnableWindow(TRUE);//切刀
	GetDlgItem(IDC_CHECKLOGO)->EnableWindow(TRUE);//图片

}



//走纸
void CSerialDlg::OnBnClickedButtonrun()
{
	// TODO: Add your control notification handler code here

	//serial
	DWORD serial=((0x5678*0x11)^(0x1234*0x43))&0xffff;


	//
	char run[]="\x0a\x0a\x0a";


	//设置灰色
	DisabelAll();
	

	//打开端口
	OpenCom();

	//走纸三行
	if(!WriteFile(hCom,run,(sizeof(run)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
		
	}
	//关闭端口
	if(hCom!=NULL)
	CloseHandle(hCom);


	//设置激活
	EnableAll();


	
}


void CSerialDlg::OnBnClickedButtontest()
{
	// TODO: Add your control notification handler code here
	//
	char run[]="\x1b\x40《钻石花》这篇故事，是卫斯理为主角故事中的第一篇，写作时，还完全未涉及\"科学幻想\"这个题材。在第一次出版的时候，曾再三考虑要不要列入，结果还是列入了。因为这是卫斯理这个人物的\"首本戏\"，对这个人物的来龙去脉，有相当详细的交待。不久之前，一位读友就问：\"卫斯理的中国武术，主要是哪里学来的？\"就有点自己也记不清楚，还是他有肯定的答案：是杭州疯丐金二的徒弟。这种\"典故\"，就是全出在《钻石花》这个故事中。\n\n\n";
	
	

	//设置灰色
	DisabelAll();



	//打开端口
	OpenCom();

	//打印单张并切纸
	if(!WriteFile(hCom,run,(sizeof(run)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
		
	}
	//关闭端口
	if(hCom!=NULL)
		CloseHandle(hCom);

	//走纸3行
	//OnBnClickedButtonrun();

	//设置激活
	EnableAll();
}

void CSerialDlg::OnBnClickedButtonfullcut()
{
	// TODO: Add your control notification handler code here
	//全切纸	
	char run[]="\x1b\x40\x1b\x69\x1";

	//设置灰色
	DisabelAll();


	//打开端口
	OpenCom();

	//打印单张并切纸
	if(!WriteFile(hCom,run,(sizeof(run)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
		
	}
	//关闭端口
	if(hCom!=NULL)
		CloseHandle(hCom);


	//设置激活
	EnableAll();

}

void CSerialDlg::OnBnClickedButtonparcut()
{
	// TODO: Add your control notification handler code here

	//部分切纸
	char run[]="\x1b\x40\x1b\x6d";


	//设置灰色
	DisabelAll();


	//打开端口
	OpenCom();

	//打印单张并切纸
	if(!WriteFile(hCom,run,(sizeof(run)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
		
	}
	//关闭端口
	if(hCom!=NULL)
		CloseHandle(hCom);


	//设置激活
	EnableAll();
}

void CSerialDlg::OnBnClickedButtoncon()
{
	// TODO: Add your control notification handler code here

	char run[]="《钻石花》这篇故事，是卫斯理为主角故事中的第一篇，写作时，还完全未涉及\"科学幻想\"这个题材。在第一次出版的时候，曾再三考虑要不要列入，结果还是列入了。因为这是卫斯理这个人物的\"首本戏\"，对这个人物的来龙去脉，有相当详细的交待。不久之前，一位读友就问：\"卫斯理的中国武术，主要是哪里学来的？\"就有点自己也记不清楚，还是他有肯定的答案：是杭州疯丐金二的徒弟。这种\"典故\"，就是全出在《钻石花》这个故事中。\n\n";
	
	char temp[100];
	int j=0;

	memset(temp,0,100);

	//全切纸	
	char fullcut[]="\n\n\n\x1b\x69\x1";
	//部分切纸
	char partcut[]="\n\n\n\x1b\x6d";

	//设置灰色
	DisabelAll();
	
	DWORD num=GetDlgItemInt(IDC_EDITNUM);

	//打开端口
	OpenCom();
	if(hCom==NULL)return;

	//AfxMessageBox("开始连续测试，直到打印完毕程序才恢复!");	
	for(DWORD i=0;i<num;i++)
	{
		j=i+1;
		//头
		sprintf(temp,"第%d张开始打印\n\x0\x0",j);
		WriteFile(hCom,temp,(sizeof(temp)-1),&dwBytesWritten,NULL);
		//打印单张
		if(!WriteFile(hCom,run,(sizeof(run)-1),&dwBytesWritten,NULL))
		{
			DWORD dwError=GetLastError();
			AfxMessageBox("数据无法送住端口!"); 			
		}
		if(bCHECKCUT)//切纸
			WriteFile(hCom,partcut,(sizeof(partcut)-1),&dwBytesWritten,NULL);
	}
	//AfxMessageBox("连续测试，打印完毕!");	
	
	//关闭端口
	if(hCom!=NULL)
		CloseHandle(hCom);


	//走纸3行
	OnBnClickedButtonrun();

	//设置激活	
	EnableAll();

}

void CSerialDlg::OnBnClickedButtonfile()
{
	// TODO: Add your control notification handler code here

	CFileDialog dlg(TRUE);
	if (IDOK == dlg.DoModal())
	{
		m_filename = dlg.GetPathName();

		if (m_filename.IsEmpty())
		{
			AfxMessageBox("^_^请选择文件.");
			return;
		}

		//打开文件
//		DWORD  dwPoint;
		DWORD  dwFilelength=0;
		char *chBuff;


		HANDLE	hFile=CreateFile(m_filename,GENERIC_READ,0,NULL,OPEN_EXISTING,0x80,NULL);
		if(hFile==INVALID_HANDLE_VALUE)
		{
			AfxMessageBox("无法打开文件!");
			return;
		}

		////定位文件头
		//dwPoint=SetFilePointer(hFile,0,NULL,FILE_END);
		//if(dwPoint==INVALID_HANDLE_VALUE)
		//{
		//	AfxMessageBox("无法打开文件!");
		//	return;
		//}
		//
		dwFilelength=GetFileSize(hFile,NULL);
		chBuff=new char[dwFilelength];
		ReadFile(hFile,chBuff,dwFilelength,&dwBytesWritten,NULL);

		OpenCom();
		if(hCom==INVALID_HANDLE_VALUE)return;

		//写到打印机中
		if(!WriteFile(hCom,chBuff,dwFilelength,&dwBytesWritten,NULL))
		{
			DWORD dwError=GetLastError();
			AfxMessageBox("数据无法送住端口!"); 
			
		}

		AfxMessageBox("文件发送完毕");

		if(hCom!=NULL)CloseHandle(hCom);
		CloseHandle(hFile);

		//release
		if(chBuff!=NULL)
		delete []chBuff;

	}




}


void CSerialDlg::OnBnClickedButtonmoney()
{
	//弹钱箱
	char plus11[]="\x1b\x40\x1b\x70\x0\x20\x90";
	char plus12[]="\x1b\x40\x1b\x70\x1\x20\x80";

	//设置灰色
	DisabelAll();

	//打开端口
	OpenCom();
    
	//送数据
	if(!WriteFile(hCom,plus11,(sizeof(plus11)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
	}
	if(!WriteFile(hCom,plus12,(sizeof(plus12)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
	}

	//关闭端口
	if(hCom!=NULL)
		CloseHandle(hCom);

	//设置激活
	EnableAll();
}

void CSerialDlg::OnBnClickedButtonrerun()
{
	//反向走纸
	char backrun11[]="\x1b\x40\x1b\x6a\xf0";

	//设置灰色
	DisabelAll();

	//打开端口
	OpenCom();

	//送数据
	if(!WriteFile(hCom,backrun11,(sizeof(backrun11)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
	}	

	//关闭端口
	if(hCom!=NULL)
		CloseHandle(hCom);

	//设置激活
	EnableAll();




}

void CSerialDlg::OnBnClickedButtonbarcode()
{
	//条码打印
	//AfxMessageBox("条码打印功能暂时还没加！");

	char read[]="\n打印机内置条码功能打印条型码：\n";   	
	char code39[]="CODE39条码：\n";
	char read2[]="\x1d\x72\x2\x1d\x68\xa2\x1d\x77\x02";/*人工识别符在下面*/
	char code39b[]="\x1d\x6b\x45\x0c\x31\x32\x33\x34\x35\36\x37\x38\x39\x41\x42\x43";



	//设置灰色
	DisabelAll();

	//打开端口
	OpenCom();

	//送数据
	if(!WriteFile(hCom,read,(sizeof(read)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
	}
	if(!WriteFile(hCom,code39,(sizeof(code39)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
	}
	//送数据
	if(!WriteFile(hCom,read2,(sizeof(read2)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
	}
	if(!WriteFile(hCom,code39b,(sizeof(code39b)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
	}

	//关闭端口
	if(hCom!=NULL)
		CloseHandle(hCom);

	//设置激活
	EnableAll();



}


void CSerialDlg::OnBnClickedButtondigfont()
{

	//多倍字体
	//AfxMessageBox("多倍字体打印功能暂时还没加！");
	char bigfont0[]="\x1d\x21\x00 正常字体打印\n";
	char bigfont1[]="\x1d\x21\x11 壹倍字体打印\n";
	char bigfont2[]="\x1d\x21\x22 贰倍字体打印\n";
	char bigfont3[]="\x1d\x21\x33 叁倍字体打印\n";
	char bigfont4[]="\x1d\x21\x44 肆倍字体打印\n";
	char bigfont5[]="\x1d\x21\x55 伍倍字体打印\n";

	//设置灰色
	DisabelAll();

	//打开端口
	OpenCom();

	//送数据
	if(!WriteFile(hCom,bigfont0,(sizeof(bigfont0)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
	}
	if(!WriteFile(hCom,bigfont1,(sizeof(bigfont1)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
	}
	if(!WriteFile(hCom,bigfont2,(sizeof(bigfont2)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
	}
	if(!WriteFile(hCom,bigfont3,(sizeof(bigfont3)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
	}
	if(!WriteFile(hCom,bigfont4,(sizeof(bigfont4)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
	}
	if(!WriteFile(hCom,bigfont5,(sizeof(bigfont5)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
	}

	//关闭端口
	if(hCom!=NULL)
		CloseHandle(hCom);

	//设置激活
	EnableAll();





}







void CSerialDlg::OnBnClickedButtondownloadbit()
{

	//下载位图
	AfxMessageBox("下载位图功能暂时还没加！");

}

void CSerialDlg::OnBnClickedButtonlogo()
{

	//内置LOGO
	//AfxMessageBox("内置LOGO功能暂时还没加！");


	char logo[]="打印机内置图片开始打印：\n\n\x1d\x2f\x0 \n打印图片结束！\x0a\x0a";

	char logo2[]="所有的内置图片：\n图片1：\n\x1b\x59\x01 \n图片2：\n\x1b\x59\x02 \n图片3：\n\x1b\x59\x03 \n图片4：\n\x1b\x59\x04 \n图片5：\n\x1b\x59\x05 \n图片6：\n\x1b\x59\x06 \n \n \n\x0a\x0a";

	/*LOG指令：
		1BH  ‘Y’  01：中行
		1BH  ‘Y’  02：建行
		1BH  ‘Y’  03：工行
		1BH  ‘Y’  04：农行
		1BH  ‘Y’  05：交行
		1BH  ‘Y’  06：招行*/

	//设置灰色
	DisabelAll();

	//打开端口
	OpenCom();

	//送数据
	if(!WriteFile(hCom,logo,(sizeof(logo)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
	}

	if(!WriteFile(hCom,logo2,(sizeof(logo2)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
	}

	//关闭端口
	if(hCom!=NULL)
		CloseHandle(hCom);

	//设置激活
	EnableAll();


}

void CSerialDlg::OnBnClickedButtonstatus()
{
	//打印机状态
	//AfxMessageBox("打印机状态功能暂时还没加！");


	HMODULE hWinIO=LoadLibrary("WinIo.dll");
	//DWORD 


}

void CSerialDlg::OnBnClickedButtondriver()
{

	//驱动程序打印
	//AfxMessageBox("驱动程序功能暂时还没加！");
	CDC dc;
	CPrintDialog dlg(FALSE);
	//dlg.GetDefault();
	if(dlg.DoModal()==IDOK)
	{
		dc.Attach(dlg.GetPrinterDC());
	}

}

void CSerialDlg::OnBnClickedButtonbitmap()
{

	char Bitmap[]="\n图形打印开始：\x0a\x0a";
	char Bitmap2[]="\n图形打印结束！\x0a\x0a\x0a";
	
	/*AfxMessageBox("图型打印功能暂时还没加！");
	return;*/




	///////////////////////////////////////工商银行/////////////////////////////////////
unsigned char bitmapcode[]=
		{0x1b,0x40,0x1b,0x2a,0x00,0x3f,0x01,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x03,0x07,0x0F,0x0F,0x0E,0x0E,0x0E,
		0x0E,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0E,0x0E,0x0E,0x0E,0x0F,0x07,0x07,
		0x03,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x01,0x01,0x01,0x01,0x01,0x01,0x1F,0x1F,
		0x11,0x01,0x01,0x01,0x01,0x01,0x03,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x1F,0x0F,
		0x08,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x0B,0x0B,0x09,0x08,0x1F,
		0x1F,0x08,0x00,0x00,0x00,0x00,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x03,0x03,
		0x02,0x02,0x02,0x02,0x02,0x06,0x06,0x06,0x02,0x00,0x00,0x00,0x00,0x00,0x04,0x04,
		0x04,0x04,0x04,0x06,0x07,0x05,0x04,0x14,0x1C,0x1C,0x04,0x07,0x07,0x06,0x04,0x04,
		0x0C,0x0C,0x0C,0x04,0x00,0x00,0x00,0x01,0x0F,0x1E,0x1A,0x12,0x02,0x07,0x02,0x1F,
		0x0F,0x09,0x09,0x09,0x09,0x09,0x09,0x0F,0x0F,0x08,0x00,0x00,0x00,0x00,0x01,0x02,
		0x06,0x1D,0x1B,0x11,0x00,0x00,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x0C,0x0C,
		0x05,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

		unsigned char bitmapcode1[]=
		{0x1b,0x2a,0x00,0x3f,0x01,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x3F,0x7F,0xFF,0xF0,0xE0,0xC0,0x80,0xFE,0xFE,0xFE,0xEE,0xEE,
		0xEF,0xEF,0xEF,0xEF,0x00,0xEF,0xEF,0xEF,0xEF,0xEE,0xEE,0xFE,0xFE,0xFE,0xFE,0x80,
		0xE0,0xE0,0xF8,0xFF,0x7F,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x10,0x10,0x10,0x10,0x10,0x10,0xFF,0xFF,
		0x10,0x10,0x10,0x10,0x10,0x10,0xF8,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,
		0x00,0x04,0x24,0x24,0x24,0x24,0xFC,0xFC,0x24,0x34,0x7C,0x7C,0x2C,0x04,0x00,0xFF,
		0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,
		0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0xFF,0x7F,0x48,0x48,0x5F,0xDF,0x69,0x69,0x49,0x49,0xFF,0xFF,0x78,0x50,0x40,0xFF,
		0x7F,0x40,0x00,0x00,0x00,0x20,0x50,0x90,0x90,0xFF,0xFF,0x90,0xB1,0xB2,0x92,0xFF,
		0xFF,0x20,0x30,0x2D,0x26,0x23,0x25,0xF5,0xFC,0x08,0x00,0x00,0x04,0x88,0x10,0x30,
		0x7F,0xFF,0xA0,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xFF,0xFF,0x80,
		0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};


unsigned char bitmapcode2[]=
		{0x1b,0x2a,0x00,0x3f,0x01,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0xF8,0xFC,0xFE,0x3F,0x0F,0x07,0x03,0xFD,0xFF,0xFE,0xEE,0xEE,
		0xEE,0xEE,0xEE,0xEE,0x00,0xEE,0xEE,0xEE,0xEE,0xEE,0xEE,0xFE,0xFE,0xFF,0xFD,0x03,
		0x07,0x0F,0x7F,0xFE,0xFC,0xE8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0xEC,0xCC,
		0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0xCC,0xCC,
		0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,0xCC,
		0xCC,0x0C,0x0C,0x0C,0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,
		0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,
		0xEC,0xEC,0x0C,0x0C,0x8C,0x8C,0x0C,0x0C,0x0C,0x0C,0x8C,0x8C,0x4C,0x4C,0x6C,0xEC,
		0xCC,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x4C,0xEC,0xCC,0x8C,0x0C,0x0C,0x4C,0xEC,
		0xCC,0x8C,0x8C,0x0C,0x0C,0x0C,0x8C,0x8C,0xCC,0xCC,0x4C,0x0C,0x0C,0x0C,0x0C,0x0C,
		0xEC,0xCC,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x8C,0x8C,0xCC,0xEC,0xCC,0xCC,0x0C,
		0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,
		0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,
		0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,
		0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,
		0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,
		0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,
		0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x00,0x00,0x00,0x00};

unsigned char bitmapcode3[]=
		{0x1b,0x2a,0x00,0x3f,0x01,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xC0,0xE0,0xE0,0xF0,0xF0,0xF0,
		0x70,0x70,0x70,0x70,0x70,0x70,0x70,0x70,0x70,0x70,0xF0,0xF0,0xE0,0xE0,0xE0,0xC0,
		0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x00,0x7E,0x30,0x0C,0x7E,0x00,0x00,0x7E,
		0x42,0x42,0x42,0x3C,0x00,0x7C,0x02,0x02,0x7C,0x00,0x76,0x5A,0x6E,0x00,0x00,0x40,
		0x40,0x7E,0x40,0x40,0x00,0x7E,0x50,0x5C,0x72,0x00,0x00,0x7E,0x06,0x3C,0x44,0x3C,
		0x06,0x00,0x00,0x7E,0x02,0x02,0x00,0x00,0x00,0x06,0x3C,0x44,0x3C,0x06,0x00,0x00,
		0x7E,0x30,0x0C,0x7E,0x00,0x7E,0x42,0x42,0x42,0x3C,0x00,0x00,0x3C,0x66,0x42,0x42,
		0x42,0x24,0x3C,0x66,0x42,0x42,0x66,0x3C,0x00,0x00,0x7E,0x78,0x06,0x78,0x7E,0x00,
		0x7E,0x78,0x06,0x78,0x7E,0x00,0x00,0x7E,0x52,0x52,0x52,0x00,0x00,0x7E,0x50,0x5C,
		0x72,0x00,0x7E,0x00,0x3C,0x66,0x42,0x42,0x42,0x24,0x7E,0x00,0x06,0x3C,0x44,0x3C,
		0x06,0x00,0x00,0x7E,0x02,0x02,0x00,0x00,0x00,0x00,0x7E,0x52,0x52,0x52,0x6E,0x3C,
		0x44,0x3C,0x06,0x00,0x00,0x7E,0x30,0x0C,0x7E,0x00,0x00,0x7E,0x18,0x28,0x46,0x00,
		0x00,0x00,0x3C,0x66,0x42,0x42,0x66,0x3C,0x00,0x00,0x7E,0x50,0x50,0x50,0x00,0x00,
		0x3C,0x66,0x42,0x42,0x42,0x24,0x00,0x7E,0x10,0x10,0x7E,0x00,0x7E,0x00,0x00,0x7E,
		0x30,0x0C,0x7E,0x00,0x06,0x3C,0x44,0x3C,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
	///////////////////////////////////////工商银行/////////////////////////////////////



//unsigned char bitmapform[1024];    //用于打印图片
//unsigned char bitmapform1[1024];
//unsigned char bitmapform2[1024];
//unsigned char bitmapform3[1024];
//unsigned char bitmapform4[1024];
//	int i=0;
//
//	memset(bitmapform,0,sizeof(bitmapform));
//	memset(bitmapform1,0,sizeof(bitmapform1));
//	memset(bitmapform2,0,sizeof(bitmapform2));
//	memset(bitmapform3,0,sizeof(bitmapform3));
//	memset(bitmapform4,0,sizeof(bitmapform4));
//
//	//形成图型数据
//	bitmapform[0] = (BYTE)0X1B;
//	bitmapform[1] = (BYTE)0X40;
//	//bitmapform[0] = (BYTE) 0X1C;
//	//bitmapform[1] = (BYTE) 0X26;
//
//	bitmapform[2] = (BYTE)0X1B;
//	bitmapform[3] = (BYTE)0X2A;
//	bitmapform[4] = (BYTE)0X00;//m
//	//	bitmapform[4] = (BYTE) 0X20;
//	//bitmapform[5]= (BYTE)0X0F;
//	bitmapform[5]= (BYTE)0X3F;
//
//	//bitmapform[6] = (BYTE)0X00;//n2
//	bitmapform[6] = (BYTE)0x01;
//	//bitmapform[6] = (BYTE)0X02;
//	//bitmapform[6] = (BYTE)0X03;
//	for (i=7;i<325;i++)
//	{
//		bitmapform[i]= bitmapcode[i-7];
//		//  bitmapform[i]=0XFF;
//	};
//
//
//
//
//
//
//
//	bitmapform1[0] = (BYTE)0X1B;
//	bitmapform1[1] = (BYTE)0X2A;
//	//bitmapform[0] = (BYTE) 0X1C;
//	//bitmapform[1] = (BYTE) 0X26;
//
//	//bitmapform1[2] = (BYTE)0X1B;
//	//bitmapform1[3] = (BYTE)0X2A;
//	bitmapform1[2] = (BYTE)0X00;//m
//	//	bitmapform1[4] = (BYTE) 0X20;
//	//bitmapform1[5]= (BYTE)0X0F;
//	bitmapform1[3]= (BYTE)0X3f;
//	//bitmapform1[6] = (BYTE)0X00;//n2
//	bitmapform1[4] = (BYTE)0x01;
//	
//
//	//bitmapform1[0] = (BYTE)0X1B;
//	//bitmapform1[1] = (BYTE)0X40;
//	////bitmapform[0] = (BYTE) 0X1C;
//	////bitmapform[1] = (BYTE) 0X26;
//
//	//bitmapform1[2] = (BYTE)0X1B;
//	//bitmapform1[3] = (BYTE)0X2A;
//	//bitmapform1[4] = (BYTE)0X00;//m
//	////	bitmapform1[4] = (BYTE) 0X20;
//	////bitmapform1[5]= (BYTE)0X0F;
//	//bitmapform1[5]= (BYTE)0X3F;
//	////bitmapform1[6] = (BYTE)0X00;//n2
//	//bitmapform1[6] = (BYTE)0x01;
//
//	for (i=5;i<323;i++)
//	{
//		bitmapform1[i]= bitmapcode1[i-5];
//		// bitmapform1[i]=0XFF;
//	};
//
//
//
//	//bitmapform2[0] = (BYTE)0X1B;
//	//bitmapform2[1] = (BYTE)0X40;
//	bitmapform2[0] = (BYTE)0X1B;
//	bitmapform2[1] = (BYTE)0X2A;
//	bitmapform2[2] = (BYTE)0X00;//m
//	//	bitmapform2[4] = (BYTE) 0X20;
//	//bitmapform2[5]= (BYTE)0X0F;
//	bitmapform2[3]= (BYTE)0X3f;
//
//	//bitmapform2[6] = (BYTE)0X00;//n2
//	bitmapform2[4] = (BYTE)0x01;
//	//bitmapform2[6] = (BYTE)0X02;
//	//bitmapform2[6] = (BYTE)0X03;
//	for (i=5;i<323;i++)
//	{
//
//		bitmapform2[i]= bitmapcode2[i-5];
//		//bitmapform2[i]=0XFF;
//	};
//
//
//
//
//	//bitmapform3[0] = (BYTE)0X1B;
//	//bitmapform3[1] = (BYTE)0X40;
//	//bitmapform[0] = (BYTE) 0X1C;
//	//bitmapform[1] = (BYTE) 0X26;
//
//	bitmapform3[0] = (BYTE)0X1B;
//	bitmapform3[1] = (BYTE)0X2A;
//	bitmapform3[2] = (BYTE)0X00;//m
//	//	bitmapform3[4] = (BYTE) 0X20;
//	//bitmapform3[5]= (BYTE)0X0F;
//	bitmapform3[3]= (BYTE)0X3f;
//
//	//bitmapform3[6] = (BYTE)0X00;//n2
//	bitmapform3[4] = (BYTE)0x01;
//	//bitmapform3[6] = (BYTE)0X02;
//	//bitmapform3[6] = (BYTE)0X03;
//
//
//	for (i=5;i<323;i++)
//	{
//		bitmapform3[i]= bitmapcode3[i-5];
//		//  bitmapform3[i]=0XFF;
//	};
//
//
//
//
//	//bitmapform4[0] = (BYTE)0X1B;
//	//bitmapform4[1] = (BYTE)0X40;
//	//bitmapform[0] = (BYTE) 0X1C;
//	//bitmapform[1] = (BYTE) 0X26;
//
//	bitmapform4[0] = (BYTE)0X1B;
//	bitmapform4[1] = (BYTE)0X2A;
//	bitmapform4[2] = (BYTE)0X00;//m
//	//	bitmapform4[4] = (BYTE) 0X20;
//	//bitmapform4[5]= (BYTE)0X0F;
//	bitmapform4[3]= (BYTE)0X3f;
//
//	//bitmapform4[6] = (BYTE)0X00;//n2
//	bitmapform4[4] = (BYTE)0x01;
//	//bitmapform4[6] = (BYTE)0X02;
//	//bitmapform4[6] = (BYTE)0X03;
//
//
//	for (i=5;i<323;i++)
//	{
//		//bitmapform4[i]= bitmapcode3[i-7];
//		bitmapform4[i]=0XFF;
//	};
//



	//设置灰色
	DisabelAll();

	//打开端口
	OpenCom();

	//送数据
	if(!WriteFile(hCom,Bitmap,(sizeof(Bitmap)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
	}	

	if(!WriteFile(hCom,bitmapcode,(sizeof(bitmapcode)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
	}	
	if(!WriteFile(hCom,bitmapcode1,(sizeof(bitmapcode1)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
	}	
	if(!WriteFile(hCom,bitmapcode2,(sizeof(bitmapcode2)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
	}	
	if(!WriteFile(hCom,bitmapcode3,(sizeof(bitmapcode3)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
	}
	
	/*if(!WriteFile(hCom,Bitmap2,(sizeof(Bitmap2)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
	}	*/

	//关闭端口
	if(hCom!=NULL)
		CloseHandle(hCom);

	//设置激活
	EnableAll();

}

void CSerialDlg::OnBnClickedButtonblackmark()
{
	//黑标检测
	//AfxMessageBox("黑标检测功能暂时还没加！");


	char blackmark[]="\n\n  \x1b\x0c";

	//设置灰色
	DisabelAll();

	//打开端口
	OpenCom();

	//送数据
	if(!WriteFile(hCom,blackmark,(sizeof(blackmark)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
	}
	
	//关闭端口
	if(hCom!=NULL)
		CloseHandle(hCom);

	//设置激活
	EnableAll();

}


//其它切刀指令
void CSerialDlg::OnBnClickedButtonothercut()
{
	char cut1[]="切刀指令1：1DH 56H 0H\n\n  \x1d\x56\x0  \n\n";

	char cut2[]="切刀指令2(走1CM再切)：1DH 56H 42H 50H \n\n  \x1d\x56\x42\x50  \n\n";

	//设置灰色
	DisabelAll();

	//打开端口
	OpenCom();

	//送数据
	if(!WriteFile(hCom,cut1,(sizeof(cut1)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
	}

	//送数据
	if(!WriteFile(hCom,cut2,(sizeof(cut2)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
	}

	//关闭端口
	if(hCom!=NULL)
		CloseHandle(hCom);

	//设置激活
	EnableAll();}


//字体居中
void CSerialDlg::OnBnClickedButtonleft()
{
	//测试1245A
char iniat[]="\x1b\x40";            //初始化
char fontchang[]="\x1d\x21\x11";	//字体大小 
char fontcenter[]="\x1b\x61\x1";   //居中
char font1[]="中国工商银行\n";     //字体
char fontchang2[]="\x1d\x21\x11";   //字体大小 
char font2[]="韶山路支行\n";
char fontchang3[]="\x1d\x21\x00";   //字体大小 
char font3[]="==========================\n";
char fontchang4[]="\x1d\x21\x11";   //字体大小 
char font4[]="个人业务\n";
char fontchang5[]="\x1d\x21\x44";   //字体大小 
char font5[]="5号\n";				//第几号(num++)
char fontchang6[]="\x1d\x21\x0";   //字体大小 
char font6[]="您前面还有3位顾客\n";
char font7[]="请到休息区等候呼叫\n";
char font8[]="中国工商银行欢迎您！\n";
char fontchang7[]="\x1d\x21\x01";   //字体大小 
char font9[]="2005-10-20 15:46\n";   //打印时间
char font10[]="\x1d\x21\x0 \n\n\n";
char cut[]="\x1b\x69";    //切纸

	//设置灰色
	DisabelAll();

	//打开端口
	OpenCom();

	WriteFile(hCom,iniat,(sizeof(iniat)-1),&dwBytesWritten,NULL);
	WriteFile(hCom,fontchang,(sizeof(fontchang)-1),&dwBytesWritten,NULL);
	WriteFile(hCom,fontcenter,(sizeof(fontcenter)-1),&dwBytesWritten,NULL);
	WriteFile(hCom,font1,(sizeof(font1)-1),&dwBytesWritten,NULL);
	WriteFile(hCom,fontchang2,(sizeof(fontchang2)-1),&dwBytesWritten,NULL);
	WriteFile(hCom,font2,(sizeof(font2)-1),&dwBytesWritten,NULL);
	WriteFile(hCom,fontchang3,(sizeof(fontchang3)-1),&dwBytesWritten,NULL);
	WriteFile(hCom,font3,(sizeof(font3)-1),&dwBytesWritten,NULL);
	WriteFile(hCom,fontchang4,(sizeof(fontchang4)-1),&dwBytesWritten,NULL);
	WriteFile(hCom,font4,(sizeof(font4)-1),&dwBytesWritten,NULL);
	WriteFile(hCom,fontchang5,(sizeof(fontchang5)-1),&dwBytesWritten,NULL);
	WriteFile(hCom,font5,(sizeof(font5)-1),&dwBytesWritten,NULL);
	WriteFile(hCom,fontchang6,(sizeof(fontchang6)-1),&dwBytesWritten,NULL);
	WriteFile(hCom,font6,(sizeof(font6)-1),&dwBytesWritten,NULL);
	WriteFile(hCom,font7,(sizeof(font7)-1),&dwBytesWritten,NULL);
	WriteFile(hCom,font8,(sizeof(font8)-1),&dwBytesWritten,NULL);
	WriteFile(hCom,fontchang7,(sizeof(fontchang7)-1),&dwBytesWritten,NULL);
	WriteFile(hCom,font9,(sizeof(font9)-1),&dwBytesWritten,NULL);
	WriteFile(hCom,font10,(sizeof(font10)-1),&dwBytesWritten,NULL);
	WriteFile(hCom,cut,(sizeof(cut)-1),&dwBytesWritten,NULL);

	//关闭端口
	if(hCom!=NULL)
		CloseHandle(hCom);

	//设置激活
	EnableAll();
}


//字体旋转
void CSerialDlg::OnBnClickedButtonrerver()
{

	AfxMessageBox("字体旋转功能暂没加！");
	return;


	char blackmark[]="\n\n  \x1b\x0c";

	//设置灰色
	DisabelAll();

	//打开端口
	OpenCom();

	//送数据
	if(!WriteFile(hCom,blackmark,(sizeof(blackmark)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("数据无法送住端口!"); 
	}

	//关闭端口
	if(hCom!=NULL)
		CloseHandle(hCom);

	//设置激活
	EnableAll();}
