// SerialDlg.h : 头文件
//

#pragma once


// CSerialDlg 对话框
class CSerialDlg : public CDialog
{
// 构造
public:
	CSerialDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SERIAL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

public:
	//对话框数据
	BOOL bCHECKCUT;
	HANDLE hCom;
	CString csCom;
	DCB dcb;


	DWORD dwBytesWritten;

	//文件名
	CString m_filename;

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheckcut();
	afx_msg void OnBnClickedButtonrun();
	// 打印串口
	void OpenCom(void);
	afx_msg void OnBnClickedButtontest();
	afx_msg void OnBnClickedButtonfullcut();
	afx_msg void OnBnClickedButtonparcut();
	afx_msg void OnBnClickedButtoncon();
	afx_msg void OnBnClickedButtonfile();
	void DisabelAll(void);
	void EnableAll(void);
	afx_msg void OnBnClickedButtonmoney();
	afx_msg void OnBnClickedButtonrerun();
	afx_msg void OnBnClickedButtonbarcode();
	afx_msg void OnBnClickedButtondigfont();
	afx_msg void OnBnClickedButtondownloadbit();
	afx_msg void OnBnClickedButtonlogo();
	afx_msg void OnBnClickedButtonstatus();
	afx_msg void OnBnClickedButtondriver();
	afx_msg void OnBnClickedButtonbitmap();
	afx_msg void OnBnClickedButtonblackmark();
	afx_msg void OnBnClickedButtonothercut();
	afx_msg void OnBnClickedButtonleft();
	afx_msg void OnBnClickedButtonrerver();
};
