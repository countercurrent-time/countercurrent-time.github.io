/*
*C++���û�ͼ����ʾ��
*������ֱ�ߡ�����߶Ρ�Բ������ͼ�����Ρ�Բ�Ǿ��Ρ���Բ������Ρ��Զ����ı��Ļ��Ƽ���ǰ��ɫ������ɫ����
*��д��mengkun   2016/10/18
*/
#include<windows.h>
#include<tchar.h>
BOOLEAN InitWindowClass(HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//������
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    MSG Message;
    if (!InitWindowClass(hInstance, nCmdShow))
    {
        MessageBox(NULL, _T("��������ʧ�ܣ�"), _T("��������"), NULL);
        return 1;
    }
    while (GetMessage(&Message, 0, 0, 0))   //��Ϣѭ��
    {
        TranslateMessage(&Message);
        DispatchMessage(&Message);
    }
    return (int)Message.wParam;
}
//��Ϣ������ 
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, UINT wParam, LONG lParam)
{
    HDC hDC;            //����ָ���豸�����ĵľ��
    PAINTSTRUCT PtStr;  //����ָ�������ͼ��Ϣ�Ľṹ�����
    HBRUSH hBrush;          //����ָ��ˢ�ľ��
    HPEN hPen;          //����ָ�򻭱ʵľ��
    HFONT myFont;   //����������  
    LPCWSTR String1 = "�Ҳ������־�Ȼ�б���ɫ����"; //����һ�������洢Ҫ������ַ���  
    LPCWSTR String2 = "�Ҳ���������б�����»��߻�û����"; //����һ�������洢Ҫ������ַ���  
    static POINT myPoint[3];    //�������ε�����.
    static long i = 0;
    long x[3] = { 20,50,60 };   //�������θ����X��Y����
    long y[3] = { 40,20,30};
    switch (iMessage)  //������Ϣ
    {
    case WM_CREATE:
        for (i = 0; i < 2; i++)     //�ɶ���εĸ���������myPoint��
        {
            myPoint[i].x = x[i];
            myPoint[i].y = y[i];
        }
        break;
    case WM_PAINT:                              //�����ͼ��Ϣ
        hDC = BeginPaint(hWnd, &PtStr);
        SetMapMode(hDC, MM_TEXT);       //����ӳ��ģʽ
        //===============================
        //��һ���ߵ�ʾ��
        //===============================
        //��һ������-PS_SOLID:ʵ�ߣ�PS_DASH:���ߣ�PS_DOT:����
        //�ڶ�������-�����Ŀ��(��������߻���ߣ����ֻ����Ϊ1������)
        //����������-RGB��ɫ���ֱ��Ӧ�졢�̡�������Χ��0~255��
        hPen = CreatePen(PS_DOT, 1, RGB(255, 0, 0));    //���û���
        SelectObject(hDC, hPen);        //ѡ�񻭱�
        //�ڶ������������ߵ����X����
        //���������������ߵ����Y����
        MoveToEx(hDC, 100, 200, NULL);      //���û��ʵ�ǰλ��
        //�ڶ������������ߵ��յ�X����
        //���������������ߵ��յ�Y����
        LineTo(hDC, 300, 400);          //�ӻ��ʵ�ǰλ�û�һ���ߵ�ָ��λ��
        //===============================
        //��һ��Բ�Ǿ��ε�ʾ��
        //===============================
        //��һ������ĺ������������Ļ��ߵĻ�������
        hPen = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));  //���û���
        //��һ������-���ģʽ
        //HS_HORIZONTAL    ----- ˮƽ��Ӱ
        //HS_VERTICAL      |||||        ��ֱ��Ӱ
        //HS_FDIAGONAL \\\\\        45�����£�����������Ӱ
        //HS_BDIAGONAL   /////      �������ҵ���Ӱ
        //HS_CROSS       +++++      ˮƽ�ʹ�ֱ������Ӱ
        //HS_DIAGCROSS       xxxxx  45�Ƚ�����Ӱ
        //�ڶ��������������ɫ
        hBrush = CreateHatchBrush(HS_CROSS, RGB(0, 0, 255));//����һ��������״���Ļ�ˢ
        //�������Ҫ��״��ˢ����ʹ��������һ�䴴����ˢ��
        //hBrush = CreateSolidBrush(RGB(0, 0, 255));    //����һ����ɫ��仭ˢ��ֻ��Ψһ��һ��������ɫ�Ĳ�����
        SelectObject(hDC, hBrush);              //ѡ��ˢ
        SelectObject(hDC, hPen);                //ѡ�񻭱�
        //�ڶ�������������Բ�Ǿ��ε����Ͻ�����(x,y)
        //���ġ����������Բ�Ǿ��ε����½�����(x,y)
        //���ߡ��˸�������Բ���ǡ��Ŀ�Ⱥ͸߶�
        RoundRect(hDC, 50, 120, 100, 200, 15, 15); //����Բ�Ǿ���
        //===============================
        //��һ����Բ���ߵ�ʾ��
        //===============================
        hPen = CreatePen(PS_SOLID, 3, RGB(0, 255, 0));  //���û���(���ʵ��趨�������滭�ߵ�˵��)
        SelectObject(hDC, hPen);                //ѡ�񻭱�
        //�ڶ�������������Բ�������Ͻ�����(x,y)
        //���ġ����������Բ�������½�����(x,y)
        //�������߸�������Բ������ʼ������(x,y)
        //�ڰˡ��Ÿ�������Բ���Ľ���������(x,y)
        Arc(hDC,200,200,300,300,95,5,30,190);   //��һ��Բ��
        //===============================
        //��һ����ͼ��ʾ��
        //===============================
        //���ʺͻ�ˢ�����ò�������ĳ���˵��
        hBrush = (HBRUSH)GetStockObject(LTGRAY_BRUSH); //����ϵͳԤ����Ļ�ɫ��ˢ
        SelectObject(hDC, hBrush);              //ѡ��ˢ
        //����Ĳ�����Բ��������ͬ��
        Pie(hDC, 250, 50, 300, 100, 250, 50, 300, 50);      //����
        //===============================
        //��һ�����ε�ʾ��
        //===============================
        //��ˢ�ͻ�������������趨���ͻ�������һ�Σ�����ͼ������趨
        //���������Ͻ�����(x,y)�����½�����(x,y)
        Rectangle(hDC, 300, 300, 400, 400);     //���ƾ���
        //===============================
        //��һ����Բ��ʾ��
        //===============================
        //�����ǰͼ�ε���ɫ����һ�����Ĳ�һ��������Ҫ�����趨��ˢ(�򻭱�)
        hPen = CreatePen(PS_SOLID, 5, RGB(166, 66, 66));    //���û���
        hBrush = CreateSolidBrush(RGB(100, 100,255));   //����һ����ɫ��仭ˢ
        SelectObject(hDC, hBrush);              //ѡ��ˢ
        SelectObject(hDC, hPen);                //ѡ�񻭱�
        //����Ĳ����뻭���ε�һ��
        Ellipse(hDC, 150, 50, 200, 150);        //��Բ
        //===============================
        //��һ������ε�ʾ��
        //===============================
        //Polyline(hDC, myPoint, 3);        //��һ������յ���״
        Polygon(hDC, myPoint, 3);       //��һ����յ���״(�����Լ����������������ʲô��ͬ)
        //===============================
        //��ʾ���ֵ�ʾ��
        //===============================
        myFont = CreateFont(        //����һ���Զ�������  
            40,             //����ĸ߶ȣ������С��  
            0,              //��ϵͳ���ݸ߿��ѡȡ������ѿ��ֵ  
            0,              //�ı�����б��Ϊ0����ʾˮƽ  
            0,              //�������б��Ϊ0  
            FW_NORMAL,      //����Ĵֶȣ�FW_NORMALΪ����  FW_HEAVYΪ���  
            0,              //��б����  
            0,              //���»���  
            0,              //��ɾ����  
            GB2312_CHARSET, //��ʾ���õ��ַ���ΪANSI_CHARSET  
            OUT_DEFAULT_PRECIS, //�������Ϊȱʡ����  
            CLIP_DEFAULT_PRECIS,    //���þ���Ϊȱʡ����  
            DEFAULT_QUALITY,        //�������Ϊȱʡֵ  
            DEFAULT_PITCH | FF_DONTCARE,//�ּ�������ϵ��ʹ��ȱʡֵ  
            L"΢���ź�"             //��������  
        );
        SetTextColor(hDC, RGB(255, 0, 0));  //�����ı���ɫΪ��ɫ  
        SetBkColor(hDC, RGB(150, 50, 50));  //���ñ�����ɫ  
        SelectObject(hDC, myFont);      //���Զ�������ѡ���豸����  
        TextOutW(hDC, 50,600, String1, wcslen(String1));//ʹ�õ�ǰ��������ı�  
        //===============================
        //��ʾ���ֵ�ʾ��������б�����֣�
        //===============================
        myFont = CreateFont(        //����һ���Զ�������  
            40,             //����ĸ߶ȣ������С��  
            0,              //��ϵͳ���ݸ߿��ѡȡ������ѿ��ֵ  
            100,              //�ı�����б��Ϊ0����ʾˮƽ  
            0,              //�������б��Ϊ0  
            FW_NORMAL,      //����Ĵֶȣ�FW_NORMALΪ����  FW_HEAVYΪ���  
            0,              //��б����  
            1,              //���»���  
            0,              //��ɾ����  
            GB2312_CHARSET, //��ʾ���õ��ַ���ΪANSI_CHARSET  
            OUT_DEFAULT_PRECIS, //�������Ϊȱʡ����  
            CLIP_DEFAULT_PRECIS,    //���þ���Ϊȱʡ����  
            DEFAULT_QUALITY,        //�������Ϊȱʡֵ  
            DEFAULT_PITCH | FF_DONTCARE,//�ּ�������ϵ��ʹ��ȱʡֵ  
            L"����"             //��������  
        );
        SetTextColor(hDC, RGB(61, 145, 0));  //�����ı���ɫΪ����ɫ  
        SetBkMode(hDC, TRANSPARENT);  //���ñ�����ɫΪ͸��ɫ  
        SelectObject(hDC, myFont);      //���Զ�������ѡ���豸����  
        TextOutW(hDC, 50,400, String2, wcslen(String2));//ʹ�õ�ǰ��������ı�  
        EndPaint(hWnd, &PtStr);                 //������ͼ
        DeleteObject(myFont);   //ɾ���Զ������壬�ͷ��ڴ� 
        return 0;
    case WM_DESTROY:                        //����Ӧ�ó���
        PostQuitMessage(0);
        return 0;
    default:                                    //������Ϣ�������
        return(DefWindowProc(hWnd, iMessage, wParam, lParam));
        break;
    }
    return 0;
}
BOOLEAN InitWindowClass(HINSTANCE hInstance, int nCmdShow)          //���崰����
{
    WNDCLASSEX wcex;
    HWND hWnd;
    TCHAR *szWindowClass = _T("C++���û�ͼ����ʾ��");
    TCHAR *szTitle = _T("C++���û�ͼ����ʾ��");
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = 0;                     //��������Ϊȱʡ����
    wcex.lpfnWndProc = WndProc;     //���ڴ�����ΪWndProc
    wcex.cbClsExtra = 0;                //����������չ
    wcex.cbWndExtra = 0;                //����ʵ������չ
    wcex.hInstance = hInstance;     //��ǰʵ�����
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
    //���ڵ���С��ͼ��Ϊȱʡͼ��
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    //���ڲ��ü�ͷ���
    wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    //���ڱ���Ϊ��ɫ
    wcex.lpszMenuName = NULL;           //�������޲˵�
    wcex.lpszClassName = szWindowClass;//��������Ϊ"����ʾ��"
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
    if (!RegisterClassEx(&wcex))        //���ע��ʧ���򷢳���������
        return FALSE;
    hWnd = CreateWindow(szWindowClass,                          //���ɴ���
        szTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,      //�������Ͻǵ�X����
        0,                              //�������Ͻǵ�Y����
        500,                        //���ڿ�ȣ��������Ҫ������
        700,                        //���ڸ߶ȣ��������Ҫ������
        NULL,
        NULL,
        hInstance,
        NULL);
    if (!hWnd)
        return FALSE;
    ShowWindow(hWnd, nCmdShow);                 //��ʾ����
    UpdateWindow(hWnd);
    return TRUE;
}
