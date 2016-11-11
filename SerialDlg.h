// SerialDlg.h : ͷ�ļ�
//

#pragma once


// CSerialDlg �Ի���
class CSerialDlg : public CDialog
{
// ����
public:
	CSerialDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SERIAL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

public:
	//�Ի�������
	BOOL bCHECKCUT;
	HANDLE hCom;
	CString csCom;
	DCB dcb;


	DWORD dwBytesWritten;

	//�ļ���
	CString m_filename;

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheckcut();
	afx_msg void OnBnClickedButtonrun();
	// ��ӡ����
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
