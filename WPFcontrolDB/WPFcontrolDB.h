#pragma once

#include "resource.h"
#include "pageWPF.h"
//#include <vcclr.h>
#include <string.h>
public ref class WPFPageHost
{
public:
    WPFPageHost();
    static pageWPF^ hostedPage;
  
};

RECT rect;
HWND GetHwnd(HWND parent, int x, int y, int width, int height);
HWND CreateAHorizontalScrollBar(HWND hwndParent, int sbHeight);
HWND dataDisplayLabel, nameLabel, addressLabel, cityLabel, stateLabel, zipLabel;

void WPFButtonClicked(Object ^sender, DBPageEventArgs ^args);
void WPFItemChanged(Object ^sender, DBPageEventArgs ^args);

void CreateDataDisplay(HWND hWnd, int top, int left, int width);
