
// ProcessMFCDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "ProcessMFC.h"
#include "ProcessMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProcessMFCDlg 对话框



CProcessMFCDlg::CProcessMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_PROCESSMFC_DIALOG, pParent)
	, CubeRadio(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProcessMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, Cube, CubeRadio);
	DDV_MinMaxInt(pDX, CubeRadio, 0, 4);
}

BEGIN_MESSAGE_MAP(CProcessMFCDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(Cube, &CProcessMFCDlg::OnBnClickedCube)
	ON_BN_CLICKED(CalcBtn, &CProcessMFCDlg::OnBnClickedCalcbtn)
END_MESSAGE_MAP()


// CProcessMFCDlg 消息处理程序

BOOL CProcessMFCDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CProcessMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
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

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CProcessMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CProcessMFCDlg::OnBnClickedCube()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CProcessMFCDlg::OnBnClickedCalcbtn()
{
	//代表更新数值
	UpdateData(TRUE);
	CString cube_length_str;
	double cube_length;
	CString cuboid_L, cuboid_H, cuboid_W;
	double cuboid_l, cuboid_h, cuboid_w;
	CString sphere_R;
	double sphere_r;
	CString sixPrism_A, sixPrism_H;
	double sixPrism_a, sixPrism_h;
	CString tetrahedron_L;
	double tetrahedron_l;
	CString resultStr;
	double result = 0;
	switch (CubeRadio)
	{
	case 0:
		GetDlgItem(Cube_L)->GetWindowText(cube_length_str);
		cube_length = _ttof(cube_length_str);
		result =  6  / (cube_length );
		break;
	case 1:
		GetDlgItem(Cuboid_L)->GetWindowText(cuboid_L);
		GetDlgItem(Cuboid_H)->GetWindowText(cuboid_H);
		GetDlgItem(Cuboid_W)->GetWindowText(cuboid_W);
		cuboid_l = _ttof(cuboid_L);
		cuboid_h = _ttof(cuboid_H);
		cuboid_w = _ttof(cuboid_W);
		result = (2*(cuboid_l*cuboid_h+ cuboid_h* cuboid_w+ cuboid_w* cuboid_l+0.0))/ (cuboid_l*cuboid_w*cuboid_h + 0.0);

		break;
	case 2:
		GetDlgItem(Sphere_R)->GetWindowText(sphere_R);

		sphere_r = _ttof(sphere_R);
		result = (sphere_r) / 3;


		break;
	case 3:
		GetDlgItem(SixPrism_A)->GetWindowText(sixPrism_A);
		GetDlgItem(SixPrism_H)->GetWindowText(sixPrism_H);
		sixPrism_a = _ttof(sixPrism_A);
		sixPrism_h = _ttof(sixPrism_H);
		result = (2 * sixPrism_h + 2 * sqrt(3 * sixPrism_a)) / sqrt(3 * sixPrism_a*sixPrism_h);


		break;
	case 4:
		GetDlgItem(Tetrahedron_L)->GetWindowText(tetrahedron_L);

		tetrahedron_l = _ttof(tetrahedron_L);
		result = 3 / tetrahedron_l;
		break;
	default:
		return;
	}
	resultStr.Format(_T("%.1lf"), result);
	SetDlgItemText(Result_Edit, resultStr);
	// TODO: 在此添加控件通知处理程序代码
}
