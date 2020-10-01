/*
*C++常用绘图操作示例
*包含：直线、多边线段、圆弧、饼图、矩形、圆角矩形、椭圆、多边形、自定义文本的绘制及其前景色、背景色配置
*编写：mengkun   2016/10/18
*/
#include<windows.h>
#include<tchar.h>
BOOLEAN InitWindowClass(HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//主函数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    MSG Message;
    if (!InitWindowClass(hInstance, nCmdShow))
    {
        MessageBox(NULL, _T("创建窗口失败！"), _T("创建窗口"), NULL);
        return 1;
    }
    while (GetMessage(&Message, 0, 0, 0))   //消息循环
    {
        TranslateMessage(&Message);
        DispatchMessage(&Message);
    }
    return (int)Message.wParam;
}
//消息处理函数 
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, UINT wParam, LONG lParam)
{
    HDC hDC;            //定义指向设备上下文的句柄
    PAINTSTRUCT PtStr;  //定义指向包含绘图信息的结构体变量
    HBRUSH hBrush;          //定义指向画刷的句柄
    HPEN hPen;          //定义指向画笔的句柄
    HFONT myFont;   //定义字体句柄  
    LPCWSTR String1 = "我擦这行字居然有背景色！！"; //创建一个变量存储要输出的字符串  
    LPCWSTR String2 = "我擦这行字是斜的有下划线还没背景"; //创建一个变量存储要输出的字符串  
    static POINT myPoint[3];    //定义多边形的坐标.
    static long i = 0;
    long x[3] = { 20,50,60 };   //定义多边形各点的X和Y坐标
    long y[3] = { 40,20,30};
    switch (iMessage)  //处理消息
    {
    case WM_CREATE:
        for (i = 0; i < 2; i++)     //吧多边形的各点坐标存进myPoint中
        {
            myPoint[i].x = x[i];
            myPoint[i].y = y[i];
        }
        break;
    case WM_PAINT:                              //处理绘图消息
        hDC = BeginPaint(hWnd, &PtStr);
        SetMapMode(hDC, MM_TEXT);       //设置映像模式
        //===============================
        //画一条线的示例
        //===============================
        //第一个参数-PS_SOLID:实线；PS_DASH:虚线；PS_DOT:点线
        //第二个参数-线条的宽度(如果是虚线或点线，宽度只能设为1！！！)
        //第三个参数-RGB颜色（分别对应红、绿、蓝，范围：0~255）
        hPen = CreatePen(PS_DOT, 1, RGB(255, 0, 0));    //设置画笔
        SelectObject(hDC, hPen);        //选择画笔
        //第二个参数：画线的起点X坐标
        //第三个参数：画线的起点Y坐标
        MoveToEx(hDC, 100, 200, NULL);      //设置画笔当前位置
        //第二个参数：画线的终点X坐标
        //第三个参数：画线的终点Y坐标
        LineTo(hDC, 300, 400);          //从画笔当前位置画一条线到指定位置
        //===============================
        //画一个圆角矩形的示例
        //===============================
        //这一句参数的含义请参照上面的画线的画笔设置
        hPen = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));  //设置画笔
        //第一个参数-填充模式
        //HS_HORIZONTAL    ----- 水平阴影
        //HS_VERTICAL      |||||        垂直阴影
        //HS_FDIAGONAL \\\\\        45度向下，自左至右阴影
        //HS_BDIAGONAL   /////      从左至右的阴影
        //HS_CROSS       +++++      水平和垂直交叉阴影
        //HS_DIAGCROSS       xxxxx  45度交叉阴影
        //第二个参数：填充颜色
        hBrush = CreateHatchBrush(HS_CROSS, RGB(0, 0, 255));//设置一个【网格状】的画刷
        //如果不需要网状画刷，请使用下面这一句创建画刷：
        //hBrush = CreateSolidBrush(RGB(0, 0, 255));    //设置一个单色填充画刷（只有唯一的一个设置颜色的参数）
        SelectObject(hDC, hBrush);              //选择画刷
        SelectObject(hDC, hPen);                //选择画笔
        //第二、三个参数：圆角矩形的左上角坐标(x,y)
        //第四、五个参数：圆角矩形的右下角坐标(x,y)
        //第七、八个参数：圆【角】的宽度和高度
        RoundRect(hDC, 50, 120, 100, 200, 15, 15); //绘制圆角矩形
        //===============================
        //画一个椭圆弧线的示例
        //===============================
        hPen = CreatePen(PS_SOLID, 3, RGB(0, 255, 0));  //设置画笔(画笔的设定参照上面画线的说明)
        SelectObject(hDC, hPen);                //选择画笔
        //第二、三个参数：圆弧的左上角坐标(x,y)
        //第四、五个参数：圆弧的右下角坐标(x,y)
        //第六、七个参数：圆弧的起始点坐标(x,y)
        //第八、九个参数：圆弧的结束点坐标(x,y)
        Arc(hDC,200,200,300,300,95,5,30,190);   //画一段圆弧
        //===============================
        //画一个饼图的示例
        //===============================
        //画笔和画刷的设置参照上面的程序说明
        hBrush = (HBRUSH)GetStockObject(LTGRAY_BRUSH); //采用系统预定义的灰色画刷
        SelectObject(hDC, hBrush);              //选择画刷
        //这里的参数和圆弧的异曲同工
        Pie(hDC, 250, 50, 300, 100, 250, 50, 300, 50);      //饼形
        //===============================
        //画一个矩形的示例
        //===============================
        //画刷和画笔如果不重新设定，就会沿用上一次（画饼图那里）的设定
        //参数：左上角坐标(x,y)，右下角坐标(x,y)
        Rectangle(hDC, 300, 300, 400, 400);     //绘制矩形
        //===============================
        //画一个椭圆的示例
        //===============================
        //如果当前图形的颜色与上一个画的不一样，就需要重新设定画刷(或画笔)
        hPen = CreatePen(PS_SOLID, 5, RGB(166, 66, 66));    //设置画笔
        hBrush = CreateSolidBrush(RGB(100, 100,255));   //设置一个单色填充画刷
        SelectObject(hDC, hBrush);              //选择画刷
        SelectObject(hDC, hPen);                //选择画笔
        //这里的参数与画矩形的一样
        Ellipse(hDC, 150, 50, 200, 150);        //椭圆
        //===============================
        //画一个多边形的示例
        //===============================
        //Polyline(hDC, myPoint, 3);        //画一个不封闭的形状
        Polygon(hDC, myPoint, 3);       //画一个封闭的形状(可以自己试试这两个语句有什么异同)
        //===============================
        //显示文字的示例
        //===============================
        myFont = CreateFont(        //创建一个自定义字体  
            40,             //字体的高度（字体大小）  
            0,              //由系统根据高宽比选取字体最佳宽度值  
            0,              //文本的倾斜度为0，表示水平  
            0,              //字体的倾斜度为0  
            FW_NORMAL,      //字体的粗度，FW_NORMAL为正常  FW_HEAVY为最粗  
            0,              //非斜体字  
            0,              //无下划线  
            0,              //无删除线  
            GB2312_CHARSET, //表示所用的字符集为ANSI_CHARSET  
            OUT_DEFAULT_PRECIS, //输出精度为缺省精度  
            CLIP_DEFAULT_PRECIS,    //剪裁精度为缺省精度  
            DEFAULT_QUALITY,        //输出质量为缺省值  
            DEFAULT_PITCH | FF_DONTCARE,//字间距和字体系列使用缺省值  
            L"微软雅黑"             //字体名称  
        );
        SetTextColor(hDC, RGB(255, 0, 0));  //设置文本颜色为蓝色  
        SetBkColor(hDC, RGB(150, 50, 50));  //设置背景颜色  
        SelectObject(hDC, myFont);      //将自定义字体选入设备环境  
        TextOutW(hDC, 50,600, String1, wcslen(String1));//使用当前字体输出文本  
        //===============================
        //显示文字的示例二（倾斜的文字）
        //===============================
        myFont = CreateFont(        //创建一个自定义字体  
            40,             //字体的高度（字体大小）  
            0,              //由系统根据高宽比选取字体最佳宽度值  
            100,              //文本的倾斜度为0，表示水平  
            0,              //字体的倾斜度为0  
            FW_NORMAL,      //字体的粗度，FW_NORMAL为正常  FW_HEAVY为最粗  
            0,              //非斜体字  
            1,              //有下划线  
            0,              //无删除线  
            GB2312_CHARSET, //表示所用的字符集为ANSI_CHARSET  
            OUT_DEFAULT_PRECIS, //输出精度为缺省精度  
            CLIP_DEFAULT_PRECIS,    //剪裁精度为缺省精度  
            DEFAULT_QUALITY,        //输出质量为缺省值  
            DEFAULT_PITCH | FF_DONTCARE,//字间距和字体系列使用缺省值  
            L"楷体"             //字体名称  
        );
        SetTextColor(hDC, RGB(61, 145, 0));  //设置文本颜色为翠绿色  
        SetBkMode(hDC, TRANSPARENT);  //设置背景颜色为透明色  
        SelectObject(hDC, myFont);      //将自定义字体选入设备环境  
        TextOutW(hDC, 50,400, String2, wcslen(String2));//使用当前字体输出文本  
        EndPaint(hWnd, &PtStr);                 //结束绘图
        DeleteObject(myFont);   //删除自定义字体，释放内存 
        return 0;
    case WM_DESTROY:                        //结束应用程序
        PostQuitMessage(0);
        return 0;
    default:                                    //其他消息处理程序
        return(DefWindowProc(hWnd, iMessage, wParam, lParam));
        break;
    }
    return 0;
}
BOOLEAN InitWindowClass(HINSTANCE hInstance, int nCmdShow)          //定义窗口类
{
    WNDCLASSEX wcex;
    HWND hWnd;
    TCHAR *szWindowClass = _T("C++常用绘图操作示例");
    TCHAR *szTitle = _T("C++常用绘图操作示例");
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = 0;                     //窗口类型为缺省类型
    wcex.lpfnWndProc = WndProc;     //窗口处理函数为WndProc
    wcex.cbClsExtra = 0;                //窗口类无扩展
    wcex.cbWndExtra = 0;                //窗口实例无扩展
    wcex.hInstance = hInstance;     //当前实例句柄
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
    //窗口的最小化图标为缺省图标
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    //窗口采用箭头光标
    wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    //窗口背景为白色
    wcex.lpszMenuName = NULL;           //窗口中无菜单
    wcex.lpszClassName = szWindowClass;//窗口类名为"窗口示例"
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
    if (!RegisterClassEx(&wcex))        //如果注册失败则发出警告声音
        return FALSE;
    hWnd = CreateWindow(szWindowClass,                          //生成窗口
        szTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,      //窗口左上角的X坐标
        0,                              //窗口左上角的Y坐标
        500,                        //窗口宽度（请根据需要调整）
        700,                        //窗口高度（请根据需要调整）
        NULL,
        NULL,
        hInstance,
        NULL);
    if (!hWnd)
        return FALSE;
    ShowWindow(hWnd, nCmdShow);                 //显示窗口
    UpdateWindow(hWnd);
    return TRUE;
}
