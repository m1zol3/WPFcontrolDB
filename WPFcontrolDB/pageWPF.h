#pragma once
#include "stdafx.h"
 
using namespace System;
using namespace System::Windows;
using namespace System::Windows::Navigation;
using namespace System::Windows::Documents;
using namespace System::Threading;
using namespace System::Windows::Controls;
using namespace System::Windows::Media;
 
public ref class  DBPageEventArgs : EventArgs
{
public:
   // DBPageEventArgs();
    //DBPageEventArgs(bool Okay);

    property bool Okay;

};
public ref class pageWPF : public Grid {
private:
    Label ^ID, ^label1, ^label2, ^label3, ^label4, ^label5, ^label6, ^label7;
    Button ^okayButton, ^cancelButton;
    List myList;
public:
    pageWPF();
    pageWPF(int height, int width);
    ScrollViewer ^ myScroll;
    Button ^ myButton;
    ComboBox ^ myCombo;
    Label ^ CreateLabel(int column, int row, String ^text);
    Button ^CreateButton(int column, int row, String ^text);
    ComboBox ^CreateCombo(int column, int row);
  
};

