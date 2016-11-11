// SerialDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Serial.h"
#include "SerialDlg.h"
#include ".\serialdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//




// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CSerialDlg �Ի���



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


// CSerialDlg ��Ϣ�������

BOOL CSerialDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��\������...\���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	//ѡ���Զ��е�
	((CButton*)GetDlgItem(IDC_CHECKCUT))->SetCheck(TRUE);
	bCHECKCUT=TRUE;

	//���ô�������
	GetDlgItem(IDC_COMBOPORT)->SetWindowText("lpt1");
	GetDlgItem(IDC_COMBOBARD)->SetWindowText("9600");
	GetDlgItem(IDC_COMBOJY)->SetWindowText("N");
	GetDlgItem(IDC_COMBOLENGTH)->SetWindowText("8");
	GetDlgItem(IDC_COMBOEND)->SetWindowText("1");

	//����ģʽ
	GetDlgItem(IDC_COMBOMODE)->SetWindowText("ESC/POSģʽ");

	//��������
	GetDlgItem(IDC_EDITNUM)->SetWindowText("10");

	//���ü��ʱ��
	GetDlgItem(IDC_EDITMINU)->SetWindowText("0");

	//����������ӡ������ʽ
	((CButton*)GetDlgItem(IDC_RADIODIRECT))->SetCheck(TRUE);
	
	//((CButton*)GetDlgItem(IDC_RADIODIRECT))->Get
	return TRUE;  // ���������˿ؼ��Ľ��㣬���򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSerialDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
HCURSOR CSerialDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CSerialDlg::OnBnClickedCheckcut()
{
	// TODO: Add your control notification handler code here
	if(!bCHECKCUT)		//������ѡ��
	{
		((CButton*)GetDlgItem(IDC_CHECKCUT))->SetCheck(TRUE);
		bCHECKCUT=TRUE;

		//���������صļ������
		//AfxMessageBox("������");
	}
	else
	{
		((CButton*)GetDlgItem(IDC_CHECKCUT))->SetCheck(FALSE);
		bCHECKCUT=FALSE;
		//AfxMessageBox("��������");
	}
}


// ��ӡ����
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
	//��ʱ����	
	/*if(!GetCommTimeouts(hCom,&cto))
	{
	AfxMessageBox("��ȡ��ʱ����ʱ�����޷���ʼ������!"); 
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
	AfxMessageBox("���ó�ʱ����ʱ�����޷���ʼ������!"); 
	return;
	}*/

	SetCommTimeouts(hCom,&cto);


	//SetCommMask(hCom,EV_RXCHAR|EV_RXFLAG);

	FillMemory(&dcb,sizeof(dcb),0);
	dcb.DCBlength=sizeof(dcb);


	/*if(!GetCommState(hCom,&dcb))
	{
	AfxMessageBox("�޷�ȡ��DCB���޷���ʼ������!"); 
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
		AfxMessageBox("�޷����ô�������/build���޷���ʼ������!"); 
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
	AfxMessageBox("�޷����ô�������/setcommstate���޷���ʼ������!"); 
	return;
	}*/
	SetCommState(hCom,&dcb);


	/*if(!PurgeComm(hCom,PURGE_TXABORT|PURGE_RXABORT|PURGE_TXCLEAR|PURGE_RXCLEAR))
	{
	AfxMessageBox("puregecomm�����޷���ʼ������!"); 
	return;
	}*/
	PurgeComm(hCom,PURGE_TXABORT|PURGE_RXABORT|PURGE_TXCLEAR|PURGE_RXCLEAR);




}

void CSerialDlg::DisabelAll(void)
{
	//���û�ɫ
	GetDlgItem(IDC_BUTTONRUN)->EnableWindow(FALSE);		     //��ֽ
	GetDlgItem(IDC_BUTTONTEST)->EnableWindow(FALSE);	     //���Ų���
	GetDlgItem(IDC_BUTTONFULLCUT)->EnableWindow(FALSE);	     //ȫ��
	GetDlgItem(IDC_BUTTONPARCUT)->EnableWindow(FALSE);       //����
	GetDlgItem(IDC_BUTTONCON)->EnableWindow(FALSE);		     //��ʼ������ӡ
	GetDlgItem(IDC_BUTTONFILE)->EnableWindow(FALSE);	     //�ļ���ӡ
	GetDlgItem(IDC_BUTTONRERUN)->EnableWindow(FALSE);        //������ֽ
	GetDlgItem(IDC_BUTTONMONEY)->EnableWindow(FALSE);	     //��Ǯ��
	GetDlgItem(IDC_BUTTONBARCODE)->EnableWindow(FALSE);	   	 //�����ӡ
	GetDlgItem(IDC_BUTTONDIGFONT)->EnableWindow(FALSE);		 //�౶����
	GetDlgItem(IDC_BUTTONDOWNLOADBIT)->EnableWindow(FALSE);  //����λͼ
	GetDlgItem(IDC_BUTTONLOGO)->EnableWindow(FALSE);		 //��ӡLOGO
	GetDlgItem(IDC_BUTTONSTATUS)->EnableWindow(FALSE);       //��ӡ��״̬
	GetDlgItem(IDC_BUTTONDRIVER)->EnableWindow(FALSE);		 //������ӡ
	GetDlgItem(IDC_BUTTONBITMAP)->EnableWindow(FALSE);       //ͼ�ʹ�ӡ
	GetDlgItem(IDC_BUTTONBLACKMARK)->EnableWindow(FALSE);     //�ڱ���
	GetDlgItem(IDC_BUTTONOTHERCUT)->EnableWindow(FALSE);      //�����е�
	GetDlgItem(IDC_BUTTONLEFT)->EnableWindow(FALSE);         //�������
	GetDlgItem(IDC_BUTTONRERVER)->EnableWindow(FALSE);       //������ת


	
	GetDlgItem(IDC_EDITNUM)->EnableWindow(FALSE);//����
	GetDlgItem(IDC_EDITMINU)->EnableWindow(FALSE);//����
	GetDlgItem(IDC_RADIODIRECT)->EnableWindow(FALSE);//ֱ�Ӷ˿�
	GetDlgItem(IDC_RADIODRV)->EnableWindow(FALSE);//������ӡ
	GetDlgItem(IDC_CHECKFONT)->EnableWindow(FALSE);//����
	GetDlgItem(IDC_CHECKCUT)->EnableWindow(FALSE);//�е�
	GetDlgItem(IDC_CHECKLOGO)->EnableWindow(FALSE);//ͼƬ

}

void CSerialDlg::EnableAll(void)
{
	//���ü���
	GetDlgItem(IDC_BUTTONRUN)->EnableWindow(TRUE);		     //��ֽ
	GetDlgItem(IDC_BUTTONTEST)->EnableWindow(TRUE);	         //���Ų���
	GetDlgItem(IDC_BUTTONFULLCUT)->EnableWindow(TRUE);	     //ȫ��
	GetDlgItem(IDC_BUTTONPARCUT)->EnableWindow(TRUE);        //����
	GetDlgItem(IDC_BUTTONCON)->EnableWindow(TRUE);		     //��ʼ������ӡ
	GetDlgItem(IDC_BUTTONFILE)->EnableWindow(TRUE);	         //�ļ���ӡ
	GetDlgItem(IDC_BUTTONRERUN)->EnableWindow(TRUE);         //������ֽ
	GetDlgItem(IDC_BUTTONMONEY)->EnableWindow(TRUE);	     //��Ǯ��
	GetDlgItem(IDC_BUTTONBARCODE)->EnableWindow(TRUE);	   	 //�����ӡ
	GetDlgItem(IDC_BUTTONDIGFONT)->EnableWindow(TRUE);		 //�౶����
	GetDlgItem(IDC_BUTTONDOWNLOADBIT)->EnableWindow(TRUE);   //����λͼ
	GetDlgItem(IDC_BUTTONLOGO)->EnableWindow(TRUE);		     //��ӡLOGO
	GetDlgItem(IDC_BUTTONSTATUS)->EnableWindow(TRUE);        //��ӡ��״̬
	GetDlgItem(IDC_BUTTONDRIVER)->EnableWindow(TRUE);		 //������ӡ
	GetDlgItem(IDC_BUTTONBITMAP)->EnableWindow(TRUE);       //ͼ�ʹ�ӡ
	GetDlgItem(IDC_BUTTONBLACKMARK)->EnableWindow(TRUE);       //�ڱ���
	GetDlgItem(IDC_BUTTONOTHERCUT)->EnableWindow(TRUE);      //�����е�
	GetDlgItem(IDC_BUTTONLEFT)->EnableWindow(TRUE);         //�������
	GetDlgItem(IDC_BUTTONRERVER)->EnableWindow(TRUE);       //������ת


	GetDlgItem(IDC_EDITNUM)->EnableWindow(TRUE);//����
	GetDlgItem(IDC_EDITMINU)->EnableWindow(TRUE);//����
	GetDlgItem(IDC_RADIODIRECT)->EnableWindow(TRUE);//ֱ�Ӷ˿�
	GetDlgItem(IDC_RADIODRV)->EnableWindow(TRUE);//������ӡ
	GetDlgItem(IDC_CHECKFONT)->EnableWindow(TRUE);//����
	GetDlgItem(IDC_CHECKCUT)->EnableWindow(TRUE);//�е�
	GetDlgItem(IDC_CHECKLOGO)->EnableWindow(TRUE);//ͼƬ

}



//��ֽ
void CSerialDlg::OnBnClickedButtonrun()
{
	// TODO: Add your control notification handler code here

	//serial
	DWORD serial=((0x5678*0x11)^(0x1234*0x43))&0xffff;


	//
	char run[]="\x0a\x0a\x0a";


	//���û�ɫ
	DisabelAll();
	

	//�򿪶˿�
	OpenCom();

	//��ֽ����
	if(!WriteFile(hCom,run,(sizeof(run)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
		
	}
	//�رն˿�
	if(hCom!=NULL)
	CloseHandle(hCom);


	//���ü���
	EnableAll();


	
}


void CSerialDlg::OnBnClickedButtontest()
{
	// TODO: Add your control notification handler code here
	//
	char run[]="\x1b\x40����ʯ������ƪ���£�����˹��Ϊ���ǹ����еĵ�һƪ��д��ʱ������ȫδ�漰\"��ѧ����\"�����ġ��ڵ�һ�γ����ʱ������������Ҫ��Ҫ���룬������������ˡ���Ϊ������˹����������\"�ױ�Ϸ\"����������������ȥ�������൱��ϸ�Ľ���������֮ǰ��һλ���Ѿ��ʣ�\"��˹����й���������Ҫ������ѧ���ģ�\"���е��Լ�Ҳ�ǲ�������������п϶��Ĵ𰸣��Ǻ��ݷ�ؤ�����ͽ�ܡ�����\"���\"������ȫ���ڡ���ʯ������������С�\n\n\n";
	
	

	//���û�ɫ
	DisabelAll();



	//�򿪶˿�
	OpenCom();

	//��ӡ���Ų���ֽ
	if(!WriteFile(hCom,run,(sizeof(run)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
		
	}
	//�رն˿�
	if(hCom!=NULL)
		CloseHandle(hCom);

	//��ֽ3��
	//OnBnClickedButtonrun();

	//���ü���
	EnableAll();
}

void CSerialDlg::OnBnClickedButtonfullcut()
{
	// TODO: Add your control notification handler code here
	//ȫ��ֽ	
	char run[]="\x1b\x40\x1b\x69\x1";

	//���û�ɫ
	DisabelAll();


	//�򿪶˿�
	OpenCom();

	//��ӡ���Ų���ֽ
	if(!WriteFile(hCom,run,(sizeof(run)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
		
	}
	//�رն˿�
	if(hCom!=NULL)
		CloseHandle(hCom);


	//���ü���
	EnableAll();

}

void CSerialDlg::OnBnClickedButtonparcut()
{
	// TODO: Add your control notification handler code here

	//������ֽ
	char run[]="\x1b\x40\x1b\x6d";


	//���û�ɫ
	DisabelAll();


	//�򿪶˿�
	OpenCom();

	//��ӡ���Ų���ֽ
	if(!WriteFile(hCom,run,(sizeof(run)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
		
	}
	//�رն˿�
	if(hCom!=NULL)
		CloseHandle(hCom);


	//���ü���
	EnableAll();
}

void CSerialDlg::OnBnClickedButtoncon()
{
	// TODO: Add your control notification handler code here

	char run[]="����ʯ������ƪ���£�����˹��Ϊ���ǹ����еĵ�һƪ��д��ʱ������ȫδ�漰\"��ѧ����\"�����ġ��ڵ�һ�γ����ʱ������������Ҫ��Ҫ���룬������������ˡ���Ϊ������˹����������\"�ױ�Ϸ\"����������������ȥ�������൱��ϸ�Ľ���������֮ǰ��һλ���Ѿ��ʣ�\"��˹����й���������Ҫ������ѧ���ģ�\"���е��Լ�Ҳ�ǲ�������������п϶��Ĵ𰸣��Ǻ��ݷ�ؤ�����ͽ�ܡ�����\"���\"������ȫ���ڡ���ʯ������������С�\n\n";
	
	char temp[100];
	int j=0;

	memset(temp,0,100);

	//ȫ��ֽ	
	char fullcut[]="\n\n\n\x1b\x69\x1";
	//������ֽ
	char partcut[]="\n\n\n\x1b\x6d";

	//���û�ɫ
	DisabelAll();
	
	DWORD num=GetDlgItemInt(IDC_EDITNUM);

	//�򿪶˿�
	OpenCom();
	if(hCom==NULL)return;

	//AfxMessageBox("��ʼ�������ԣ�ֱ����ӡ��ϳ���Żָ�!");	
	for(DWORD i=0;i<num;i++)
	{
		j=i+1;
		//ͷ
		sprintf(temp,"��%d�ſ�ʼ��ӡ\n\x0\x0",j);
		WriteFile(hCom,temp,(sizeof(temp)-1),&dwBytesWritten,NULL);
		//��ӡ����
		if(!WriteFile(hCom,run,(sizeof(run)-1),&dwBytesWritten,NULL))
		{
			DWORD dwError=GetLastError();
			AfxMessageBox("�����޷���ס�˿�!"); 			
		}
		if(bCHECKCUT)//��ֽ
			WriteFile(hCom,partcut,(sizeof(partcut)-1),&dwBytesWritten,NULL);
	}
	//AfxMessageBox("�������ԣ���ӡ���!");	
	
	//�رն˿�
	if(hCom!=NULL)
		CloseHandle(hCom);


	//��ֽ3��
	OnBnClickedButtonrun();

	//���ü���	
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
			AfxMessageBox("^_^��ѡ���ļ�.");
			return;
		}

		//���ļ�
//		DWORD  dwPoint;
		DWORD  dwFilelength=0;
		char *chBuff;


		HANDLE	hFile=CreateFile(m_filename,GENERIC_READ,0,NULL,OPEN_EXISTING,0x80,NULL);
		if(hFile==INVALID_HANDLE_VALUE)
		{
			AfxMessageBox("�޷����ļ�!");
			return;
		}

		////��λ�ļ�ͷ
		//dwPoint=SetFilePointer(hFile,0,NULL,FILE_END);
		//if(dwPoint==INVALID_HANDLE_VALUE)
		//{
		//	AfxMessageBox("�޷����ļ�!");
		//	return;
		//}
		//
		dwFilelength=GetFileSize(hFile,NULL);
		chBuff=new char[dwFilelength];
		ReadFile(hFile,chBuff,dwFilelength,&dwBytesWritten,NULL);

		OpenCom();
		if(hCom==INVALID_HANDLE_VALUE)return;

		//д����ӡ����
		if(!WriteFile(hCom,chBuff,dwFilelength,&dwBytesWritten,NULL))
		{
			DWORD dwError=GetLastError();
			AfxMessageBox("�����޷���ס�˿�!"); 
			
		}

		AfxMessageBox("�ļ��������");

		if(hCom!=NULL)CloseHandle(hCom);
		CloseHandle(hFile);

		//release
		if(chBuff!=NULL)
		delete []chBuff;

	}




}


void CSerialDlg::OnBnClickedButtonmoney()
{
	//��Ǯ��
	char plus11[]="\x1b\x40\x1b\x70\x0\x20\x90";
	char plus12[]="\x1b\x40\x1b\x70\x1\x20\x80";

	//���û�ɫ
	DisabelAll();

	//�򿪶˿�
	OpenCom();
    
	//������
	if(!WriteFile(hCom,plus11,(sizeof(plus11)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
	}
	if(!WriteFile(hCom,plus12,(sizeof(plus12)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
	}

	//�رն˿�
	if(hCom!=NULL)
		CloseHandle(hCom);

	//���ü���
	EnableAll();
}

void CSerialDlg::OnBnClickedButtonrerun()
{
	//������ֽ
	char backrun11[]="\x1b\x40\x1b\x6a\xf0";

	//���û�ɫ
	DisabelAll();

	//�򿪶˿�
	OpenCom();

	//������
	if(!WriteFile(hCom,backrun11,(sizeof(backrun11)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
	}	

	//�رն˿�
	if(hCom!=NULL)
		CloseHandle(hCom);

	//���ü���
	EnableAll();




}

void CSerialDlg::OnBnClickedButtonbarcode()
{
	//�����ӡ
	//AfxMessageBox("�����ӡ������ʱ��û�ӣ�");

	char read[]="\n��ӡ���������빦�ܴ�ӡ�����룺\n";   	
	char code39[]="CODE39���룺\n";
	char read2[]="\x1d\x72\x2\x1d\x68\xa2\x1d\x77\x02";/*�˹�ʶ���������*/
	char code39b[]="\x1d\x6b\x45\x0c\x31\x32\x33\x34\x35\36\x37\x38\x39\x41\x42\x43";



	//���û�ɫ
	DisabelAll();

	//�򿪶˿�
	OpenCom();

	//������
	if(!WriteFile(hCom,read,(sizeof(read)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
	}
	if(!WriteFile(hCom,code39,(sizeof(code39)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
	}
	//������
	if(!WriteFile(hCom,read2,(sizeof(read2)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
	}
	if(!WriteFile(hCom,code39b,(sizeof(code39b)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
	}

	//�رն˿�
	if(hCom!=NULL)
		CloseHandle(hCom);

	//���ü���
	EnableAll();



}


void CSerialDlg::OnBnClickedButtondigfont()
{

	//�౶����
	//AfxMessageBox("�౶�����ӡ������ʱ��û�ӣ�");
	char bigfont0[]="\x1d\x21\x00 ���������ӡ\n";
	char bigfont1[]="\x1d\x21\x11 Ҽ�������ӡ\n";
	char bigfont2[]="\x1d\x21\x22 ���������ӡ\n";
	char bigfont3[]="\x1d\x21\x33 ���������ӡ\n";
	char bigfont4[]="\x1d\x21\x44 ���������ӡ\n";
	char bigfont5[]="\x1d\x21\x55 �鱶�����ӡ\n";

	//���û�ɫ
	DisabelAll();

	//�򿪶˿�
	OpenCom();

	//������
	if(!WriteFile(hCom,bigfont0,(sizeof(bigfont0)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
	}
	if(!WriteFile(hCom,bigfont1,(sizeof(bigfont1)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
	}
	if(!WriteFile(hCom,bigfont2,(sizeof(bigfont2)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
	}
	if(!WriteFile(hCom,bigfont3,(sizeof(bigfont3)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
	}
	if(!WriteFile(hCom,bigfont4,(sizeof(bigfont4)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
	}
	if(!WriteFile(hCom,bigfont5,(sizeof(bigfont5)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
	}

	//�رն˿�
	if(hCom!=NULL)
		CloseHandle(hCom);

	//���ü���
	EnableAll();





}







void CSerialDlg::OnBnClickedButtondownloadbit()
{

	//����λͼ
	AfxMessageBox("����λͼ������ʱ��û�ӣ�");

}

void CSerialDlg::OnBnClickedButtonlogo()
{

	//����LOGO
	//AfxMessageBox("����LOGO������ʱ��û�ӣ�");


	char logo[]="��ӡ������ͼƬ��ʼ��ӡ��\n\n\x1d\x2f\x0 \n��ӡͼƬ������\x0a\x0a";

	char logo2[]="���е�����ͼƬ��\nͼƬ1��\n\x1b\x59\x01 \nͼƬ2��\n\x1b\x59\x02 \nͼƬ3��\n\x1b\x59\x03 \nͼƬ4��\n\x1b\x59\x04 \nͼƬ5��\n\x1b\x59\x05 \nͼƬ6��\n\x1b\x59\x06 \n \n \n\x0a\x0a";

	/*LOGָ�
		1BH  ��Y��  01������
		1BH  ��Y��  02������
		1BH  ��Y��  03������
		1BH  ��Y��  04��ũ��
		1BH  ��Y��  05������
		1BH  ��Y��  06������*/

	//���û�ɫ
	DisabelAll();

	//�򿪶˿�
	OpenCom();

	//������
	if(!WriteFile(hCom,logo,(sizeof(logo)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
	}

	if(!WriteFile(hCom,logo2,(sizeof(logo2)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
	}

	//�رն˿�
	if(hCom!=NULL)
		CloseHandle(hCom);

	//���ü���
	EnableAll();


}

void CSerialDlg::OnBnClickedButtonstatus()
{
	//��ӡ��״̬
	//AfxMessageBox("��ӡ��״̬������ʱ��û�ӣ�");


	HMODULE hWinIO=LoadLibrary("WinIo.dll");
	//DWORD 


}

void CSerialDlg::OnBnClickedButtondriver()
{

	//���������ӡ
	//AfxMessageBox("������������ʱ��û�ӣ�");
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

	char Bitmap[]="\nͼ�δ�ӡ��ʼ��\x0a\x0a";
	char Bitmap2[]="\nͼ�δ�ӡ������\x0a\x0a\x0a";
	
	/*AfxMessageBox("ͼ�ʹ�ӡ������ʱ��û�ӣ�");
	return;*/




	///////////////////////////////////////��������/////////////////////////////////////
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
	///////////////////////////////////////��������/////////////////////////////////////



//unsigned char bitmapform[1024];    //���ڴ�ӡͼƬ
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
//	//�γ�ͼ������
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



	//���û�ɫ
	DisabelAll();

	//�򿪶˿�
	OpenCom();

	//������
	if(!WriteFile(hCom,Bitmap,(sizeof(Bitmap)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
	}	

	if(!WriteFile(hCom,bitmapcode,(sizeof(bitmapcode)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
	}	
	if(!WriteFile(hCom,bitmapcode1,(sizeof(bitmapcode1)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
	}	
	if(!WriteFile(hCom,bitmapcode2,(sizeof(bitmapcode2)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
	}	
	if(!WriteFile(hCom,bitmapcode3,(sizeof(bitmapcode3)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
	}
	
	/*if(!WriteFile(hCom,Bitmap2,(sizeof(Bitmap2)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
	}	*/

	//�رն˿�
	if(hCom!=NULL)
		CloseHandle(hCom);

	//���ü���
	EnableAll();

}

void CSerialDlg::OnBnClickedButtonblackmark()
{
	//�ڱ���
	//AfxMessageBox("�ڱ��⹦����ʱ��û�ӣ�");


	char blackmark[]="\n\n  \x1b\x0c";

	//���û�ɫ
	DisabelAll();

	//�򿪶˿�
	OpenCom();

	//������
	if(!WriteFile(hCom,blackmark,(sizeof(blackmark)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
	}
	
	//�رն˿�
	if(hCom!=NULL)
		CloseHandle(hCom);

	//���ü���
	EnableAll();

}


//�����е�ָ��
void CSerialDlg::OnBnClickedButtonothercut()
{
	char cut1[]="�е�ָ��1��1DH 56H 0H\n\n  \x1d\x56\x0  \n\n";

	char cut2[]="�е�ָ��2(��1CM����)��1DH 56H 42H 50H \n\n  \x1d\x56\x42\x50  \n\n";

	//���û�ɫ
	DisabelAll();

	//�򿪶˿�
	OpenCom();

	//������
	if(!WriteFile(hCom,cut1,(sizeof(cut1)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
	}

	//������
	if(!WriteFile(hCom,cut2,(sizeof(cut2)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
	}

	//�رն˿�
	if(hCom!=NULL)
		CloseHandle(hCom);

	//���ü���
	EnableAll();}


//�������
void CSerialDlg::OnBnClickedButtonleft()
{
	//����1245A
char iniat[]="\x1b\x40";            //��ʼ��
char fontchang[]="\x1d\x21\x11";	//�����С 
char fontcenter[]="\x1b\x61\x1";   //����
char font1[]="�й���������\n";     //����
char fontchang2[]="\x1d\x21\x11";   //�����С 
char font2[]="��ɽ·֧��\n";
char fontchang3[]="\x1d\x21\x00";   //�����С 
char font3[]="==========================\n";
char fontchang4[]="\x1d\x21\x11";   //�����С 
char font4[]="����ҵ��\n";
char fontchang5[]="\x1d\x21\x44";   //�����С 
char font5[]="5��\n";				//�ڼ���(num++)
char fontchang6[]="\x1d\x21\x0";   //�����С 
char font6[]="��ǰ�滹��3λ�˿�\n";
char font7[]="�뵽��Ϣ���Ⱥ����\n";
char font8[]="�й��������л�ӭ����\n";
char fontchang7[]="\x1d\x21\x01";   //�����С 
char font9[]="2005-10-20 15:46\n";   //��ӡʱ��
char font10[]="\x1d\x21\x0 \n\n\n";
char cut[]="\x1b\x69";    //��ֽ

	//���û�ɫ
	DisabelAll();

	//�򿪶˿�
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

	//�رն˿�
	if(hCom!=NULL)
		CloseHandle(hCom);

	//���ü���
	EnableAll();
}


//������ת
void CSerialDlg::OnBnClickedButtonrerver()
{

	AfxMessageBox("������ת������û�ӣ�");
	return;


	char blackmark[]="\n\n  \x1b\x0c";

	//���û�ɫ
	DisabelAll();

	//�򿪶˿�
	OpenCom();

	//������
	if(!WriteFile(hCom,blackmark,(sizeof(blackmark)-1),&dwBytesWritten,NULL))
	{
		DWORD dwError=GetLastError();
		AfxMessageBox("�����޷���ס�˿�!"); 
	}

	//�رն˿�
	if(hCom!=NULL)
		CloseHandle(hCom);

	//���ü���
	EnableAll();}
